#pragma once
#include <random>
#include "Vector.h"
using namespace std;
extern default_random_engine generator;
extern uniform_real_distribution<double> distribution;

template <class T>
class Distribution
{
public:
	virtual double likelihood(T& data) = 0;
	//virtual double loglikelihood() = 0;
	virtual T rnd()=0;
};

Vector urand(int n);
Vector rand(int n, int max);
Vector rand(int n);
double urand();
