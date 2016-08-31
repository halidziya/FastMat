#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ostream>
#include <istream>
#include "DebugUtils.h"
#include <thread>
#include "Buffer.h"
#include <stdarg.h>
#include <initializer_list>
#include <fstream>
#define EPS 1e-8 // Floating point equality

class Matrix;
using namespace std;


/*	Vector Types :
	TYPE 0 : Abstract	vector , just a pointer
	TYPE 1 : Standart	vector , allocates deallocates memory automatically
	TYPE 2 : Buffer		vector , calculations are used on top.

	Default assumption for operations is all results are temporary
*/
class Vector{
public:
	double* data;
	int n;
	int type;
	//Default Vector is real , first parameter is the size of the vector
	Vector(int size,int real=1);
	Vector(int size, int real, double fill); // Fill constructor
	~Vector(void);
	
	Vector (const Vector& v);
	Vector (Vector&& v);
	Vector();
	

	void print();
	void zero();
	void fill(double d);
	void resize(int size);
	Vector copy();		// Returns real vector
	Vector unique();	// Returns unique values 


	inline double& operator[](const int i);

	// Sub vector based on indices, it does not allow assignment, it creates a new vector
	Vector operator[](Vector& idx); 

	int		operator()(int i);	 // Return integer
	double operator*(Vector& v); // Inner product
	//Vector operator*(Matrix& m); //
	Vector operator-(Vector& v); // Subtraction
	Vector operator/(Matrix& mat); // Matrix division
	Vector operator/(Vector& vec); // Element-wise division
	void operator=(const Vector& v); // Assignment 
	void operator<<=(const Vector& v); // Abstract Assignment

	// Inplace operations changes actual vector
	void operator-=(const Vector& v); // Inplace subtraction works on arbitrary size
	void operator+=(const Vector& v); // Inplace addition works on arbitrary size
	void transform(double(*f)(double));  // Inplace application of function to each element
	void operator-=(double scalar); // Inplace subtraction works on arbitrary size
	void operator+=(double scalar); // Inplace addition works on arbitrary size
	void operator/=(double scalar); // Inplace subtraction works on arbitrary size
	void operator*=(double scalar); // Inplace addition works on arbitrary size
	void operator*=(const Vector& v); // Inplace addition works on arbitrary size

	
	Vector operator*(double scalar); // Scaling
	Vector operator+(double scalar); // Add scalar to all elements
	Vector operator-(double scalar); // Subtract scalar to all elements
	Vector operator+(Vector& v);	// Summation
	Vector operator/(double scalar); // Elementwise comparison
	Vector operator<(double scalar); // Elementwise comparison
	Vector operator>(double scalar);
	Vector operator<=(double scalar); // Elementwise comparison
	Vector operator>=(double scalar);


	// Outer Product
	Matrix operator>>(Vector& v);
	// Elementwise Product
	Vector operator<<(Vector& v);	
	
	double maximum();
	double minimum();
	double sum();
	double mean();

	// Returns results to buffer, does not change actual vector
	Vector log();					// Elementwise log
	Vector sqrt();					// Elementwise sqrt
	Vector sqr();					// Elementwise sqr
	double norm();					// Euclidian norm
	Vector exp();					// Elementwise log
	Vector apply(double(*f)(double));

	Matrix outer(Vector& v);					// Outer product
	void   put(int idx, Vector& data); // Put,copy a vector to specific location
	Vector append(Vector& v);
	Vector append(double d);


	friend ostream& operator<<(ostream& os, const Vector& v);
	friend istream& operator>>(istream& is, Vector& v);
	void writeBin(string filename);
	void readBin(string filename);
};


// BE CAREFUL ONCE BUFFER IS INITIALIZED IT OPERATES IN 'd' DIMENSIONS
#define BUFF_SIZE 20
extern MultiBuffer<Vector> buffer;
extern MultiBuffer<Vector> absbuffer;
extern MultiBuffer<Matrix> matbuffer;

void init_buffer(int nthreads,int d);
Vector zeros(int d);
Vector ones(int d);


Vector v(std::initializer_list<double> numbers);