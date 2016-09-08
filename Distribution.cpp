#include "Distribution.h"
default_random_engine generator;
uniform_real_distribution<double> distribution(0.0, 1.0);

double urand()
{
	return rand() / (RAND_MAX + 1.0);
	// return distribution(generator);
}


Vector rand(int n)
{
	Vector rv(n);
	for (auto i = 0;i < n;i++)
		rv[i] = urand();

	return rv;
}



