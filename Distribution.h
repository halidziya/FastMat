#pragma once
#include <random>
using namespace std;
extern default_random_engine generator;
template <class T>
class Distribution
{
public:
	virtual double likelihood(T& data) = 0;
	//virtual double loglikelihood() = 0;
	virtual T rnd()=0;
};

