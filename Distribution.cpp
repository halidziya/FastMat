#include "Distribution.h"
default_random_engine generator;
uniform_real_distribution<double> distribution(0.0, 1.0);

double urand()
{
	return distribution(generator);
}

Vector rand(int n, int max)
{
	Vector v(n);
	for (auto i = 0;i < n;i++)
		v[i] = rand() % max;

	return v;
}


Vector rand(int n)
{
	Vector rv(n);
	for (auto i = 0;i < n;i++)
		rv[i] = urand();

	return rv;
}



