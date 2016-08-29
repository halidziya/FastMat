#pragma once
#include "Distribution.h"
#include "Matrix.h"

using namespace std;

class Dirichlet : public Distribution<Vector>
{
public:
	gamma_distribution<double> distribution;
	int d;
	Vector alpha;
	double likelihood(Vector& alpha);
	Vector rnd();
	Dirichlet(Vector& alpha);
	Dirichlet();
	~Dirichlet();
private :
	Vector lastsample; // Used to extend lifetime of objects
};

