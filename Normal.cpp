#include "Normal.h"
#include "util.h"
#include <iostream>

Normal::Normal(void):Normal(d)
{
}


Normal::~Normal(void)
{
}


Normal::Normal(int d) 
{
	if ((d < 0) || (d > 1000)) d = 0;
	mu = zeros(d);  
	cholsigma = zeros(d,d);
	this->d = d;
	normalizer = -(d * 0.5)*log(2*M_PI);
	sumlogdiag = 0;
}

Normal::Normal(Vector& mu, Matrix& sigma)
{
	this->mu = mu;
	cholsigma = sigma.chol();
	sumlogdiag = cholsigma.sumlogdiag();
	this->d = sigma.m;
	normalizer = -(d * 0.5)*log(2 * M_PI);
}

double Normal::likelihood(Vector& x)
{
	//Performance critical function
	//Vector& v = (x - mu) / cholsigma; // Copy constructor
	double dist = 0,disti=0;
	Vector dd = x - mu;
	int i, j;
	for (i = 0; i < d; i++) {
		disti = dd.data[i] / cholsigma.data[i*d + i];
		for (j = d - 1; j>i; j--)								 // Subtract  , Triangular matrix , filled upto j
		{
			dd.data[j] -= cholsigma.data[j*d + i] * disti;
		}
		dist += disti*disti;
	}
	//double distsq = v*v;
	return   normalizer - sumlogdiag -0.5*dist; //- 0.5*distsq
	return 0;
}


Vector Normal::rnd()
{

		normal_distribution<double> normal(0, 1);
		Vector& v = buffer.next();
		v.zero();
		for (auto i = 0; i < cholsigma.m; i++)
		{
			v[i] = normal(generator);
		}
		
		return (mu - cholsigma.transpose()*v);
}