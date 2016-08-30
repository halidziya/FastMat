#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

Matrix::Matrix(void)
{
	triangle = false;
	r = 0;
	m = 0;
}


void Matrix::resize(int x, int y)
{
	r = x;
	m = y;
	n = x*y;
	if ((type && n > 0) || (type == 0 && n > 0)) // Buffer or real vector
	{
		data = (double*)realloc(data, sizeof(double)*n);
		if (type == 0) //Changes if it is resized. 
			type = 1;
	}

	if (n == 0)
		type = 0; // Abstract

}


Matrix::~Matrix(void)
{
	// Vector destructor takes care of it
}

Matrix::Matrix(int r,int m,int real) : Vector(r*m,real)
{
	this->r = r;
	this->m = m;
	triangle = false;
}


Matrix::Matrix(int r) : Vector(r*r)
{
	this->r = r;
	this->m = r;
	triangle = false;
}




void Matrix::zero()
{
	memset(data,0,r*m*sizeof(double));
}

void Matrix::eye()
{
	memset(data, 0, r*m*sizeof(double));
	int s = r < m ? r : m;
	for (auto i = 0; i < s; i++)
		data[i*m + i] = 1;
}

void Matrix::readMatrix(char* filename)
{
	ifstream file(filename);
	int i,j;
	if (!file.is_open())
		printf("Could not operfile...\n");
	else
	{
		printf("Reading %s...\n",filename);
		file >> r >> m;
		data = (double*) malloc(sizeof(double)*r*m);
		type = 1;
		for(i=0;i<r;i++)
			for(j=0;j<m;j++)
				file >> data[i*m+j];
		file.close();
	}
}

void Matrix::writeMatrix(char* filename)
{
	ofstream file(filename);
	int i,j;
	file << r << " " << m << endl;
	for (i=0;i<r;i++)
	{
		for(j=0;j<m;j++)
			file << data[i*m+j] << " ";
		file << endl;
	}
	file.close();
}


void Matrix::readBin(char* filename)
{
	FILE* file;
	fopen_s(&file,filename,"rb");
	if (file==NULL)
		printf("Could not open file... %s\n",filename);
	else
	{
		printf("Reading %s...\n",filename);
		fread(&r,sizeof(int),1,file);
		fread(&m,sizeof(int),1,file);
		n = r*m;
		type = 1;
		data  = (double*) malloc(sizeof(double)*n);
		fread(data,sizeof(double),n,file);
		fclose(file);
	}
}

void Matrix::writeBin(char* filename)
{
	FILE* file;
	fopen_s(&file,filename,"wb");
	fwrite(&r,sizeof(int),1,file);
	fwrite(&m,sizeof(int),1,file);

	n = r*m;

	fwrite(data,sizeof(double),n,file);
	fclose(file);
}


/* Get Row */
Vector Matrix::operator[](int i){ 
	absbuffer.get().data = data + m*i;
	return absbuffer.next();
}

Vector Matrix::operator()(int i) {
	absbuffer.get().data = data + m*i;
	return absbuffer.next();
}



double& Matrix::operator()(int i,int j) {
	return data[i*m + j];
}

double Matrix::sumlogdiag()
{
	int d = r<m?r:m; //Smaller
	int i;
	double sum=0;
	for(i=0;i<d;i++)
		sum += ::log(data[i+m*i]);
	return sum;
}


/* Cholesky decomposition of square matrix */
Matrix Matrix::chol()
{
	double s = 0;
	int i,j,k;
	Matrix& mat = matbuffer.get();
	// double debug;
	mat.zero();
    for ( i = 0; i < m ; i++)
	{
        for ( j = 0; j < i; j++) {
            for (s=0,k = 0; k < j; k++)
                s += mat.data[i* m  + k] * mat.data[j* m  + k];
            mat.data[i* m  + j] = ( (data[i* m  + j] - s) / mat.data[j* m  + j] ) ;
//		if (mat.data[i*m + j]!=mat.data[i*m + j])
//			printf("ERROR Matrix is singular\n");
        }

	for (s=0,k = 0; k < i; k++)
		s += mat.data[i* m  + k] * mat.data[i* m  + k];
	mat.data[i*m + i] = ::sqrt(data[i* m  + i] - s);


	}


	mat.triangle = true;
	return matbuffer.next();
}


Matrix Matrix::qr()
{
	// Modified gram schimit
	double s = 0;
	int i, j;
	Matrix& Q = matbuffer.next();
	Matrix& R = matbuffer.next();
	Matrix& v = this->transpose(); // Work on row  vectors
	Q.zero();
	R.zero();
	


	for (i = 0; i < r; i++)
	{

		for (j = 0; j < i; j++)
		{
			R(j,i) = Q(j)*v(i);
			v(i) = v(i) - Q(j) * R(j, i);
		}

		double normval = v(i).norm();
		R(i)[i] = normval;
		Q(i) = v(i) / normval;
	}

	return R;
}


Vector Matrix::diag()
{
	Vector& vec = buffer.get();
	int lowdim = r < m ? r : m;
	for (auto i = 0; i < lowdim; i++)
		vec.data[i] = this->data[i*m + i];
	return buffer.next();
}

Vector Matrix::mean()
{
	Vector& vec = buffer.get();
	vec.zero();
	for (auto i = 0; i < r; i++)
	for (auto j = 0; j < m; j++)
		vec.data[j] += this->data[i*m + j]/r;
	return buffer.next();
}


Matrix Matrix::operator*(double scalar)
{
	int i;
	Matrix& mati = matbuffer.get();
	for(i=0;i<n;i++)
		mati.data[i] = data[i]*scalar;
	return matbuffer.next();
}

Matrix Matrix::transpose()
{
	Matrix mati = matbuffer.get();
	double res = 0;

	for (auto i = 0; i < r; i++)
		for (auto j = 0; j < m; j++) {
			mati.data[i*m + j] = data[j*m + i];
		}
	return matbuffer.next();
}


Matrix Matrix::inverse()
{
	
	//Gaussian Elemination
	Matrix my(this->m);
	my = *this;
	Matrix&  inv = matbuffer.get();
	inv.eye();
	for (auto i = 0; i < r; i++) {
		inv(i) = inv(i) / my(i)[i];
		my(i) = my(i) / my(i)[i];
		for (auto j = 0; j < m; j++) {
			if (i != j) {
				inv(j) = inv(j) - inv(i)*my(j)[i];
				my(j) = my(j) - my(i)*my(j)[i];
			}
		}
	}
	return matbuffer.next();
}

Matrix Matrix::scatter() // Calculate covariance of data matrix
{
	Matrix meansc = matbuffer.next(); // Allocate this matrix first
	Vector& v = this->mean();
	meansc = (v >> v)*r;
	Matrix mati = matbuffer.get();
	mati.zero();

	for (auto i = 0; i < r; i++) //
		for (auto j = 0; j < m; j++) {
			for (auto k = 0; k < m; k++) {
				mati.data[j*m + k] += data[i*m + j] * data[i*m + k];
			}
		}

	mati -= meansc;
	return matbuffer.next();
}

Matrix Matrix::cov()
{
	return this->scatter() / (r - 1);
}


Matrix Matrix::operator*(const Matrix& mat)
{
	int i;
	Matrix& mati = matbuffer.get();
	double res = 0;

	for (i = 0; i < r; i++)
		for (auto j = 0; j < m; j++) {
			res = 0;
			for (auto k = 0; k < m; k++)
				res += mat.data[i*m + k] * data[k*m + j];
			mati.data[i*m + j] = res;
		}
	return matbuffer.next();
}

Vector Matrix::operator*(const Vector& v)
{
	Vector& v2 = buffer.get();
	double res = 0;

	for (auto j = 0; j < m; j++) {
		res = 0;
		for (auto k = 0; k < m; k++)
			res += v.data[k] * data[k*m + j];
		v2.data[j] = res;
	}
	return buffer.next();
}



Matrix Matrix::operator/(double scalar)
{
	int i;
	Matrix& mati = matbuffer.get();
	double divone = 1.0/scalar;
	for(i=0;i<n;i++)
		mati.data[i] = data[i]*divone;
	return matbuffer.next();
}

Matrix Matrix::operator+(Matrix& mat)
{
	int i;
	Matrix& mati = matbuffer.get();
	for(i=0;i<n;i++)
		mati.data[i] = data[i]+mat.data[i];
	return matbuffer.next();
}

Matrix Matrix::operator-(Matrix& mat)
{
	int i;
	Matrix& mati = matbuffer.get();
	for(i=0;i<n;i++)
		mati.data[i] = data[i]-mat.data[i];
	return matbuffer.next();
}

void  Matrix::operator=(const Matrix& mat)
{
	Vector::operator=(mat);
	triangle = mat.triangle;
	m = mat.m;
	r = mat.r;
}

void Matrix::operator<=(const Matrix& mat) {
	n = mat.n;
	type = 0;
	data = mat.data;
	m = mat.m;
	r = mat.r;
}


Matrix Matrix::submat(int r1, int r2, int c1, int c2)
{

	if (r2 > r)
		r2 = r;
	if (c2 > m)
		c2 = m;

	int rows = r2 - r1;
	int cols = c2 - c1;

	if (rows < 0 || cols < 0)
		return NULL;

	Matrix mat(rows, cols , 2); // Persistent memory use with caution
	for (auto i = 0; i < rows && ((i+r1) < r); i++)
		for (auto j = 0; j < cols && ((j+c1) < m); j++)
			mat.data[i*mat.m + j]= data[ (r1 + i)*m + c1 + j];
	return mat;
}



void Matrix::print()
{
	for (int i = 0; i < r; i++) {
		printf( "|");
		for (int j = 0; j < m; j++)
			printf(" %.2f", data[i*m + j]);
		printf("|\n");
	}
}

// ????
Matrix::Matrix(Matrix&& mat) : Vector(mat)
{
	triangle = mat.triangle;
	m = mat.m;
	r = mat.r;
}

Matrix::Matrix(const Matrix& mat) : Vector(mat) , r(mat.r) , m(mat.m) , triangle(mat.triangle)
{
}


ostream& operator<<(ostream& os, const Matrix& v)
{   // It does not save type , it save as real vector always
		os.write((char*)&v.r, sizeof(int));
		os.write((char*)&v.m, sizeof(int));
		os.write((char*)v.data, sizeof(double)*v.n);
		// os.write((char*) &v.triangle,sizeof(int));  // Not used greatly
		
	return os;
}

istream& operator>>(istream& is, Matrix& v)
{   // It does not save type , it save as real vector always
	// istream need to be binary
	
	is.read((char*)&v.r, sizeof(int));
	is.read((char*)&v.m, sizeof(int));
	v.resize(v.r,v.m);
	is.read((char*)v.data, sizeof(double)*v.n);
	v.type = 1; // Real
	return is;
}




Matrix eye(int d)
{ 
	Matrix m(d);
	m.eye();
	return m;
}

Matrix zeros(int d1, int d2)
{
	Matrix m(d1,d2);
	m.zero();
	return m;
}


// You can create a matrix using mat({{1,2,3},{1,3,3},{1,4,3}})
Matrix mat(std::initializer_list<std::initializer_list<double>> numbers) {

	int size = numbers.size();
	Matrix m(size, size); // To do : It only supports square matrices now
	int i = 0;
	for (auto nums : numbers)
		for (auto val : nums)
		{
			m.data[i] = val;
			i = i + 1;
		}
	return m;
}