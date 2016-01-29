#include "Normal.h"
#include "util.h"

Normal::Normal(void)
{
	normalizer = -(d * 0.5)*log(2 * M_PI);
}


Normal::~Normal(void)
{
}


Normal::Normal(int d) 
{
	mu = zeros(d);  
	cholsigma = zeros(d,d);
	this->d = d;
	normalizer = -(d * 0.5)*log(2*M_PI);
}

Normal::Normal(Vector& mu, Matrix& sigma)
{
	this->mu = mu;
	cholsigma = sigma.chol();
	this->d = sigma.m;
	normalizer = -(d * 0.5)*log(2 * M_PI);
}

double Normal::likelihood(Vector& x)
{
	Vector v = (x - mu) / cholsigma; // Copy constructor
	double distsq = v*v;
	return   normalizer - cholsigma.sumlogdiag() - 0.5*distsq;
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
		
		return (mu - cholsigma*v);
}