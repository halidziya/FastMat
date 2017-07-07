#pragma once
#include "Vector.h"
class Matrix :
	public Vector
{
public:
	int m;	// Number of dimensions
	int r;	// Number of rows
	int triangle;


	Matrix(void);
	Matrix(int d);
	Matrix(int r,int m,int real=1);			// refcount
	Matrix(double* data, int d);		// Construct a Matrix from a double array. Row major.
	Matrix(Matrix&& mat);			// Move
	Matrix(const Matrix& mat);			// Copy
									// 1 is standart , 2  is persistent , 0 is abstract
	~Matrix(void);
	
	void readMatrix(const char* filename);
	void writeMatrix(const char* filename);

	

	Vector& operator[](int i);   // Get row
	Vector& operator()(int i);   // Get row
	double& operator()(int i, int j);
	Matrix&operator*(double scalar);
	Matrix& operator*(const Matrix& m);
	Vector& operator*(const Vector& m);
	void   operator=(const Matrix& m);
	Matrix& operator+(Matrix& v);	// Summation
	Matrix& operator-(Matrix& v);	// Subtract
	Matrix& operator/(double scalar); // Scaling
	void operator<=(const Matrix& mat); //Point by Abstract Matrix
	
	void resize(int x,int y);
	void zero();
	void eye();
	double sumlogdiag();
	Vector& mean();
	Matrix& chol();
	Matrix& chol(Vector x); // Incremental cholesky decomposition. The matrix itself should be a decomposition.
	Matrix& transpose();
	Matrix transpose_xy();
	Matrix& inverse();
	Matrix& scatter();
	Matrix& cov();
	Vector& diag();
	Matrix submat(int r1, int r2, int c1, int c2);
	Matrix& qr();
	void print();

	Matrix copy(); //Create real Matrix


	void readBin(string filename);
	void writeBin(string filename);
	friend ostream& operator<<(ostream& os, const Matrix& v);
	friend istream& operator>>(istream& is, Matrix& v);
};

Matrix eye(int d);
Matrix zeros(int d1, int d2);

// You can create a matrix using mat({{1,2,3},{1,3,3},{1,4,3}})
Matrix mat(std::initializer_list<std::initializer_list<double>> numbers);