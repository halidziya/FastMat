#pragma once
#include "Distribution.h"
#include "Matrix.h"
#include "util.h"
#include "Global.h"
class Wishart : public Distribution<Matrix>
{
public:
	Wishart(Matrix& sigma, int df);
	int df;
	double vcholsumlogdiag;
	double gamd;
	Matrix Vinv;
	// Calculate likelihood of the scatter matrix
	double likelihood(Matrix& s);
	//virtual double loglikelihood() = 0;
	Matrix& rnd();

	~Wishart();
};

