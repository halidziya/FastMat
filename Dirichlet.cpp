#include "Dirichlet.h"



double Dirichlet::likelihood(Vector& data)
{
	// not yet implemented
	return 0.0;
}

Vector& Dirichlet::rnd()
{
	Vector& v = lastsample;
	for (auto i = 0; i < d; i++)
	{
		gamma_distribution<double> g(alpha[i], 1);
		v[i] = g(generator);
	}
	double s = v.sum();
	v /= s;
	return v;
}

Dirichlet::Dirichlet(Vector & alpha)
{
	this->alpha = alpha;
	d = alpha.n;
	lastsample = Vector(d);
}

Dirichlet::Dirichlet(Vector&& alpha)
{
	this->alpha = alpha;
	d = alpha.n;
	lastsample = Vector(d);
}

Dirichlet::Dirichlet()
{
	d = 0;
}

Dirichlet::~Dirichlet()
{
}
