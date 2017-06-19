#include "Stut.h"
#include <math.h>
#include <iostream>
Stut::Stut(Vector mean,Matrix cov,int dof)
{
	
	mu = mean;
	cholsigma = cov.chol();
	eta = dof;
	normalizer=calculateNormalizer();
	coef1 = 0.5*(eta+d);
}

double Stut::calculateNormalizer()
{
	normalizer=gl_pc[(eta+d)]-(gl_pc[eta] + (d/2.0)*log(eta) +(d/2.0)*log(M_PI))-cholsigma.sumlogdiag();
	coef1 = 0.5*(eta+d);
	return normalizer;
}

Stut::Stut()
{
	coef1 = 0; 
	eta = 0;
	normalizer = 0;
}


Stut::Stut(int d) : Normal(d)
{
	coef1 = 0; 
	eta = 0;
	normalizer = 0;
}


Stut::~Stut(void)
{
}


double Stut::likelihood(Vector& x)
{
	int i, j;
	double dist = 0, disti = 0;
	Vector& dd = buffer.next();
	dd = x;
	dd -= mu; // Faster performance 
	for (i = 0; i < d; i++) {
		disti = dd.data[i] / cholsigma.data[i*d + i];
		for (j = d - 1; j > i; j--)								 // Subtract  , Triangular matrix , filled upto j
		{
			dd.data[j] -= cholsigma.data[j*d + i] * disti;
		}
		dist += disti*disti;
	}
	//Vector v =  (x  - mu)/cholsigma; // Copy constructor
	//double distsq = v*v;
	//if (dist != distsq)
	//	cout << distsq << " :: " << dist << endl;
	return normalizer - coef1*log(1 + dist / eta);
}

Vector Stut::likelihood(Matrix& mat)
{
	int i;
	Vector res(mat.r);
	for(i=0;i<mat.r;i++)
		res[i]=likelihood(mat(i));
	return res;
}


ostream& operator<<(ostream& os, const Stut& t)
{
	os.write((char*) &t.eta,sizeof(double)); 
	os.write((char*) &t.normalizer,sizeof(double)); 
	os.write((char*) &t.coef1,sizeof(double)); 
	os << t.mu;
	os << t.cholsigma;
	return os;
}

istream& operator>>(istream& is, Stut& t)
{
	is.read((char*)&t.eta, sizeof(double));
	is.read((char*)&t.normalizer, sizeof(double));
	is.read((char*)&t.coef1, sizeof(double));
	is >> t.mu;
	is >> t.cholsigma;
	return is;
}