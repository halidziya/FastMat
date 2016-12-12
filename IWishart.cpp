#include "IWishart.h"


IWishart::IWishart(Matrix& psi,int df):df(df)
{
	this->psi = psi;
}

Matrix& IWishart::rnd()
{

	chi_squared_distribution<double> chi(df);
	normal_distribution<double> normal(0, 1);
	Matrix& X = matbuffer.next();
	X.zero();
	for (auto i = 0; i < psi.m; i++)
	{
		chi = chi_squared_distribution<double>(df-i);
		X(i,i) = sqrt(chi(generator));
		for (auto j = i+1; j < psi.m; j++)
		{
			X(i,j) = normal(generator);
		}
	}
	//  Transposed as compare to MATLAB
	Matrix& T = X.inverse()*this->psi.chol();
	Matrix& wish = matbuffer.next();
	wish = T.transpose()*T;
	matbuffer.next();
	return wish;
}


double IWishart::likelihood(Matrix& mat)
{
	// Not implemented yet
	return 0;
}

IWishart::~IWishart()
{
}

// Default version
IWishart::IWishart() 
{
	psi = eye(d);
	df = d+2;
}