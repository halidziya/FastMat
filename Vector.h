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
#define EPS 1e-8 // Floating point equality

class Matrix;
using namespace std;


/*	Vector Types :
	TYPE 0 : Abstract	vector , just a pointer
	TYPE 1 : Standart	vector , allocates deallocates memory automatically
	TYPE 2 : Buffer		vector , calculations are used on top.

*/

class Vector{
public:
	double* data;
	int n;
	int type;
	Vector(int size,int real=1);
	Vector(int size, int real, double fill); // Fill constructor
	~Vector(void);
	
	Vector (const Vector& v);
	Vector (Vector&& v);
	Vector();
	

	void print();
	void zero();
	void resize(int size);
	Vector copy();		// Returns real vector
	Vector unique();	// Returns unique values 


	inline double& operator[](const int i);
	int		operator()(int i);	 // Return integer
	double operator*(Vector& v); // Inner product
	//Vector operator*(Matrix& m); //
	Vector operator-(Vector& v); // Subtraction
	Vector operator/(Matrix& mat); // Matrix division
	Vector operator/(Vector& vec); // Element-wise division
	void operator=(const Vector& v); // Assignment 
	void operator<=(const Vector& v); // Abstract Assignment
	Vector operator*(double scalar); // Scaling
	Vector operator+(double scalar); // Add scalar to all elements
	Vector operator+(Vector& v);	// Summation
	Vector operator/(double scalar); // Scaling
	Matrix operator>>(Vector& v);	// Outer product
	Vector operator<<(Vector& v);	// Elementwise Product
	double maximum();
	double sum();
	double mean();
	Vector elog();					// Elementwise log
	Vector esqrt();					// Elementwise sqrt
	Vector esqr();					// Elementwise sqr
	double norm();					// Euclidian norm
	
	Matrix outer(Vector& v);					// Outer product
	void   put(int idx, Vector& data); // Put,copy a vector to specific location
	Vector append(Vector& v);

	friend ostream& operator<<(ostream& os, const Vector& v);
	friend istream& operator>>(istream& is, Vector& v);
};


// BE CAREFUL ONCE BUFFER IS INITIALIZED IT OPERATES IN 'd' DIMENSIONS
#define BUFF_SIZE 20
extern MultiBuffer<Vector> buffer;
extern MultiBuffer<Vector> absbuffer;
extern MultiBuffer<Matrix> matbuffer;

void init_buffer(int nthreads,int d);
Vector zeros(int d);



Vector v(std::initializer_list<double> numbers);