#pragma once
#include "Vector.h"
class Matrix :
	public Vector
{
public:
	int m;
	int r;
	int triangle;


	Matrix(void);
	Matrix(int d);
	Matrix(int r,int m,int real=1);			// refcount
	Matrix(Matrix&& mat);			// Move
	Matrix(const Matrix& mat);			// Copy
									// 1 is standart , 2  is persistent , 0 is abstract
	~Matrix(void);
	
	void readMatrix(char* filename);
	void writeMatrix(char* filename);
	void readBin(char* filename);
	void writeBin(char* filename);
	

	Vector operator[](int i);   // Get row
	Vector operator()(int i);   // Get row
	double& operator()(int i, int j);
	Matrix operator*(double scalar);
	Matrix operator*(const Matrix& m);
	Vector operator*(const Vector& m);
	void   operator=(const Matrix& m);
	Matrix operator+(Matrix& v);	// Summation
	Matrix operator-(Matrix& v);	// Subtract
	Matrix operator/(double scalar); // Scaling
	void operator<=(const Matrix& mat); //Point by Abstract Matrix
	
	void resize(int x,int y);
	void zero();
	void eye();
	double sumlogdiag();
	Vector mean();
	Matrix chol();
	Matrix transpose();
	Matrix inverse();
	Vector diag();
	Matrix submat(int r1, int r2, int c1, int c2);
	Matrix qr();
	void print();

	friend ostream& operator<<(ostream& os, const Matrix& v);
	friend istream& operator>>(istream& is, Matrix& v);
};

Matrix eye(int d);
Matrix zeros(int d1, int d2);