#pragma once
#include "Matrix.h"
#include "Global.h"
#include <random>

class IWishart
{
public:
	Matrix psi;
	default_random_engine generator;
	int df;
	IWishart(Matrix& psi,int df);
	IWishart();
	~IWishart(void);
	double likelihood();
	Matrix rnd();
};

