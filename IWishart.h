#pragma once
#include "Matrix.h"
#include "Global.h"
#include "Distribution.h"

class IWishart : public Distribution<Matrix>
{
public:
	Matrix psi;
	int df;
	IWishart(Matrix& psi,int df);
	IWishart();
	~IWishart(void);
	double likelihood(Matrix& mat);
	Matrix& rnd();
};

