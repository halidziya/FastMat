#include "Vector.h"
#include "Matrix.h"
#include <new>

MultiBuffer<Vector> buffer;
MultiBuffer<Vector> absbuffer(1,BUFF_SIZE,0,0);
MultiBuffer<Matrix> matbuffer;
Matrix NULLMAT;
int d = 0; // dimensions
void init_buffer(int nthreads,int d)
{
	NULLMAT = zeros(0,0);
	nthreads = nthreads + 1; // And one master thread
	new (&matbuffer) MultiBuffer<Matrix>(nthreads,BUFF_SIZE,d,2);
	new (&buffer) MultiBuffer<Vector>(nthreads,BUFF_SIZE,d,2);
	new (&absbuffer) MultiBuffer<Vector>(nthreads,BUFF_SIZE,d,0); // Not a real buffer
}

Vector::Vector(int size,int real):n(size)
{
	if (real && size > 0) // Buffer or real vector
		//if (CBLAS)
		//	data = (double*) mkl_malloc(sizeof(double)*size,64);
		//else
			data = (double*)malloc(sizeof(double)*size);

	if (size == 0)
		type = 0; // Abstract
	else
		this->type = real;

	n = size;
}

Vector::Vector(int size, int real, double fill) : Vector(size,real) // Fill constructor
{
	for (auto i = 0; i < n; i++)
		data[i] = fill;
}




Vector Vector::append(Vector& v)
{
	Vector res(this->n + v.n);
	res.put(0, *this);
	res.put(this->n, v);
	return res;
}

Vector Vector::append(double d)
{
	Vector res(this->n + 1);
	res.put(0, *this);
	res.data[n] = 1;
	return res;
}




Vector::Vector():n(0){type=0;data=NULL;} // Not yet real

Vector::~Vector()
{
	if (type == 1)
		//if (CBLAS)
		//	mkl_free(data);
		//else
			free(data);
}

double Vector::norm()
{
	double res = 0;
	for (auto i = 0; i < n; i++)
		res += data[i] * data[i];
	return ::sqrt(res);
}

void Vector::zero()
{
	memset(data,0,sizeof(double)*n);
}

void Vector::fill(double d)
{
	for (auto i = 0;i < n;i++)
		data[i] = d;
}


double Vector::operator*(Vector& v) // Dot product
{
	int i;
	double res=0;
	for(i=0;i<n;i++)
		res += data[i] * v.data[i];

	return res;
}

/*Vector Vector::operator*(Matrix& m)
{
	Vector& v2 = buffer.get();
	double res = 0;

	for (auto k = 0; k < m.m; k++) {
		res = 0;
		for (auto j = 0; j < m.m; j++)
			res += data[k] * m.data[k*m.m + j]; // Iterate 
		v2.data[k] = res;
	}
	return buffer.next();
}*/


double& Vector::operator[](const int i){
		return data[i];
}

Vector Vector::operator[](Vector & idx)
{
	Vector result(idx.n);
	for (int i = 0;i < idx.n;i++)
		result[i] = data[idx(i)];
	return result;
}

/* Return integer value */
int Vector::operator()(int i){
		return (int) (data[i]+0.5);
}


void Vector::print()
{
	int i;
	printf("\n[");
	for(i=0;i<n;i++)
		printf("%f ",data[i]);
	printf("]\n");
}

Vector::Vector(Vector&& v)
{
	n = v.n;
	data  = v.data;
	v.data = NULL;
	v.n = 0;
	v.type = 0; // No longer valid vector
	type = 1; // Owns the resource
}

Vector::Vector(const Vector& v)
{

	n = v.n;
	type = v.type;
	switch (type) // Real or Buffer
	{
	case 0:
		data = v.data;
		break;
	case 1: // Deep copy
		//if (CBLAS)
		//	data  = (double*) mkl_malloc(sizeof(double)*n,64);
		//else
			data = (double*) malloc(sizeof(double)*n);
		memcpy(data,v.data,sizeof(double)*n);
		break;
	case 2: // Buffer is persistent keep a abstract vector to point
		type = 0;
		data = v.data;
		break;
	}
}

Vector::Vector(vector<double> v) : Vector(v.size(), 1)
{	
	for (int i = 0; i < n; i++)
		data[i] = v[i];
}

Vector::Vector(double * v, int n) : Vector(n, 1)
{
	for (int i = 0; i < n; i++)
		data[i] = v[i];
}

Vector::Vector(int * v, int n) : Vector(n, 1)
{
	for (int i = 0; i < n; i++)
		data[i] = v[i];
}



void Vector::operator=(const Vector& v)
{
	switch (v.type) // Real or Buffer
	{
	case 0:
	case 1:
	case 2:
		if (!data) // if size is same
		{
			//if (CBLAS)
			//	data = (double*)mkl_malloc(sizeof(double)*v.n,64);
			//else
				data = (double*)malloc(sizeof(double)*v.n);
			if (type == 0)
				type = 1;
		}
		else if (n!=v.n)
			//if (CBLAS)
			//	data = (double*) mkl_realloc(data,v.n*sizeof(double));
			//else
				data = (double*)realloc(data,sizeof(double)*v.n);
		memcpy(data,v.data,sizeof(double)*v.n);
		break;
	}
	n = v.n;
}

// Abstract assignment
void Vector::operator<<=(const Vector& v)
{
	n = v.n;
	type = 0;
	data = v.data;
}

void Vector::operator-=(const Vector & v)
{
	for (auto i = 0;i < n;i++)
		data[i] -= v.data[i];
}

void Vector::operator*=(const Vector & v)
{
	for (auto i = 0;i < n;i++)
		data[i] *= v.data[i];
}

void Vector::operator+=(const Vector & v)
{
	for (auto i = 0;i < n;i++)
		data[i] += v.data[i];
}


// Inplace application of function to each element
void Vector::transform(double(*f)(double))
{
	for (auto i = 0;i < n;i++)
		data[i] = f(data[i]);
}


void Vector::operator-=(double scalar)
{
	for (auto i = 0;i < n;i++)
		data[i] -= scalar;
}

void Vector::operator+=(double scalar)
{
	for (auto i = 0;i < n;i++)
		data[i] += scalar;
}

void Vector::operator/=(double scalar)
{
	for (auto i = 0;i < n;i++)
		data[i] /= scalar;
}

void Vector::operator*=(double scalar)
{
	for (auto i = 0;i < n;i++)
		data[i] *= scalar;
}






Vector  Vector::copy()
{
	Vector res(n);
	memcpy(res.data,data,n*sizeof(double));
	return res;
}


void Vector::resize(int size)
{
	n  = size;
	//if (CBLAS)
	//	data = (double*) mkl_realloc(data,sizeof(double)*size);
	//else
		data = (double*)realloc(data, sizeof(double)*size);
	type = 1;
}

/* Divide cholesky version */

Vector& Vector::operator/(Matrix& mat) // Be careful it modifies the original data
{
	int i,j;
	Vector& v = buffer.get();

	// Vector res(n,3);
	if (mat.triangle && mat.m == n)
	{
		for(j=0;j<n;j++) // Transpose
		{
		 v[j] = data[j] / mat.data[j*mat.m + j]; // Diagonal element can be solved directly
		 for(i=mat.m-1;i>j;i--)								 // Subtract  , Triangular matrix , filled upto j
		 {
			data[i] -= mat.data[i*mat.m + j] * v.data[j];
		 }
		}
	}
	else
	{
		v*mat.inverse(); // !! Check
	}

	return buffer.next();
}

Vector& Vector::operator/(Vector& vec)
{
	Vector v = buffer.get();
	for (auto i = 0; i < n; i++)
		v.data[i] = this->data[i] / vec.data[i];
	return buffer.next();
}




Vector Vector::unique()
{
	Vector res(n); // result Vector
	int nq,i,j;
	bool inthelist;

	res.data[0] = data[0];
	nq = 1;
	for(i=1;i<n;i++)
	{
		if ( res.data[nq-1]==data[i] ) continue; // More likely similar to last one , Floating point comparison catched in below
		 inthelist = 0;
		for(j=0;j<nq;j++)
			if (fabs(res.data[j] - data[i]) < EPS)
			{
				inthelist = 1;
				continue; // It is in the list

			}
		if (inthelist) continue;
		res.data[nq] = data[i];
		nq++;
	}
	res.resize(nq);
	return res;
}

Vector& Vector::operator*(double scalar)
{
	Vector& r = buffer.get();
	for(int i=0;i<n;i++)
		r.data[i]= data[i] * scalar;
	return buffer.next();
}

Vector& Vector::operator-(Vector& v)
{
	Vector& r = buffer.get();
	/*if (CBLAS)
	{
		cblas_dcopy(this->n, this->data, 1, r.data, 1);
		cblas_daxpy(v.n, -1.0, v.data, 1, r.data, 1);
	}
	else {*/
		for (int i = 0; i < n; i++)
			r.data[i] = data[i] - v.data[i];
	//}
	return buffer.next();
}

Vector& Vector::operator+(Vector& v)
{
	Vector& r = buffer.get();
	/*if (CBLAS)
	{
		cblas_dcopy(this->n, this->data, 1, r.data, 1);
		cblas_daxpy(v.n, 1.0, v.data, 1, r.data, 1);
	}
	else
	{*/
		for (int i = 0; i < n; i++)
			r.data[i] = data[i] + v.data[i];
	//}
	return buffer.next();
}


Vector& Vector::operator/(double scalar)
{
	Vector& r = buffer.get();
	double divval = 1.0/scalar;
	for(int i=0;i<n;i++)
		r.data[i]= data[i] * divval;
	return buffer.next();
}

Vector& Vector::operator<(double scalar)
{
	Vector& r = buffer.get();
	for (int i = 0; i<n; i++)
		r.data[i] = data[i] < scalar;
	return buffer.next();
}

Vector& Vector::operator>(double scalar)
{
	Vector& r = buffer.get();
	for (int i = 0; i<n; i++)
		r.data[i] = data[i] >= scalar;
	return buffer.next();
}

Vector& Vector::operator<=(double scalar)
{
	Vector& r = buffer.get();
	for (int i = 0; i<n; i++)
		r.data[i] = data[i] < scalar;
	return buffer.next();
}

Vector& Vector::operator>=(double scalar)
{
	Vector& r = buffer.get();
	for (int i = 0; i<n; i++)
		r.data[i] = data[i] >= scalar;
	return buffer.next();
}


Vector& Vector::operator+(double scalar)
{
	Vector& r = buffer.get();
	for (int i = 0; i<n; i++)
		r.data[i] = data[i] + scalar;
	return buffer.next();
}

Vector& Vector::operator-(double scalar)
{
	Vector& r = buffer.get();
	for (int i = 0; i<n; i++)
		r.data[i] = data[i] - scalar;
	return buffer.next();
}


Vector& Vector::exp()
{
	Vector& r = buffer.get();
	for (int i = 0; i<n; i++)
		r.data[i] = ::exp(data[i]);
	return buffer.next();
}

Matrix& Vector::operator>>(Vector& v) // Outer product
{
	int i,j,vn;
	Matrix& mat = matbuffer.get();
	memset(mat.data, 0.0, mat.n*sizeof(double));
	/*if (CBLAS)
	{
		cblas_dger(CblasRowMajor, mat.r, mat.m, 1.0, this->data, 1, v.data, 1, mat.data, v.n);
	}
	else
	{*/
		vn = v.n;
		for (j = 0; j < n; j++)
			for (i = 0; i < vn; i++)
				mat.data[j*vn + i] = v.data[i] * data[j];
	//}
	return matbuffer.next();
}

Matrix& Vector::outer(Vector& v) {
	return operator>>(v);
}


Vector& Vector::operator<<(Vector& v) // Elementwise product
{
	Vector& vec = buffer.get();
	for (auto i = 0; i<v.n; i++)
		vec.data[i] = v.data[i] * data[i];
	return buffer.next();
}



Vector& Vector::apply(double(*f)(double)) {
	Vector& vec = buffer.get();
	for (auto i = 0; i < n; i++)
		vec.data[i] = f(data[i]); // Use global namespace function
	return buffer.next();
}


Vector& Vector::log() // Elementwise log
{
	return apply(::log);
}

Vector& Vector::sqrt()
{
	return apply(::sqrt);
}

double sqr(double val){
	return val*val;
}

Vector& Vector::sqr()
{
	return apply(::sqr);
}


double Vector::sum() // Sum of all elements
{	
	double s=0;
	for (auto i = 0; i < n; i++)
		s += data[i];
	return s;

}

double Vector::mean() // mean
{
	double s = 0;
	for (auto i = 0; i < n; i++)
		s += data[i];
	return s/n;
}

double Vector::maximum()
{
	double val  = data[0];
	for(int i=0;i<n;i++)
		if (val<data[i])
			val = data[i];

	return val;
}

double Vector::minimum()
{
	double val = data[0];
	for (int i = 0;i<n;i++)
		if (val>data[i])
			val = data[i];

	return val;
}


void Vector::put(int idx, Vector& dt)
{
	if ((idx + dt.n) <= n)
	{
		memcpy(data + idx, dt.data, dt.n*sizeof(double));
	}
	else printf("Size mismatch\n");
}



ostream& operator<<(ostream& os, const Vector& v)
{   // It does not save type , it save as real vector always
	int one = 1;
	os.write((char*) &v.n,sizeof(int)); 
	os.write((char*) &one,sizeof(int)); 
	os.write((char*) v.data,sizeof(double)*v.n); 
	
	return os;
}

istream& operator>>(istream& is, Vector& v)
{   // It does not save type , it save as real vector always
	int one = 1;
	is.read((char*)&v.n, sizeof(int));
	is.read((char*)&one, sizeof(int));
	v.resize(v.n);
	is.read((char*)v.data, sizeof(double)*v.n);
	v.type = 1;
	return is;
}


void Vector::writeBin(string filename)
{
	ofstream likefile(filename, ios::out | ios::binary);
	likefile << *this;
	likefile.close();
}

void Vector::readBin(string filename)
{
	ifstream mfile(filename, ios::in | ios::binary);
	mfile >> *this;
	mfile.close();
}


Vector zeros(int d)
{
	Vector v(d);
	v.zero();
	return v; // Should call move constructor
}

Vector ones(int d)
{
	Vector v(d);
	v.fill(1);
	return v; // Should call move constructor
}



// You can create your vector using v({1,2,3})
Vector v(std::initializer_list<double> numbers) { 
	
	int size = numbers.size();
	Vector v(size);
	int i = 0;
	for (auto num : numbers)
		v[i++] = num;
	return v;
}