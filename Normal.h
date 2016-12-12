#pragma once
#include "Matrix.h"
#include "Distribution.h"


class Normal : public Distribution<Vector>
{
public:
	Vector mu;
	Matrix cholsigma;
	double normalizer;
	Normal(void);
	Normal(int d); // dimensions
	Normal(Vector& mu, Matrix& sigma);
	Normal(Vector&& mu, Matrix&& sigma);
	double sumlogdiag;
	~Normal(void);
	double likelihood(Vector& x);
	Vector& rnd();
};

