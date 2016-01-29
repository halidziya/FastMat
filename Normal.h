#pragma once
#include "Matrix.h"
#include <random>

class Normal
{
public:
	Vector mu;
	Matrix cholsigma;
	default_random_engine generator;
	int d;
	double normalizer;
	Normal(void);
	Normal(int d); // dimensions
	Normal(Vector& mu, Matrix& sigma);

	~Normal(void);
	double likelihood(Vector& x);
	Vector rnd();
};

