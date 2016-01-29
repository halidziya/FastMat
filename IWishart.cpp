#include "IWishart.h"


IWishart::IWishart(Matrix& psi,int df):psi(psi),df(df)
{
}

Matrix IWishart::rnd()
{

	chi_squared_distribution<double> chi(df);
	normal_distribution<double> normal(0, 1);
	Matrix& X = matbuffer.next();
	X.zero();
	for (auto i = 0; i < psi.m; i++)
	{
		X(i,i) = sqrt(chi(generator));
		for (auto j = i+1; j < psi.m; j++)
		{
			X(i,j) = normal(generator);
		}
	}

	
	Matrix& fet = X*psi.qr().chol().inverse();
	Matrix& T = fet.qr().inverse();
	Matrix& wish = matbuffer.next();
	wish = T.transpose()*T;
	matbuffer.next();
	return wish;
}


double IWishart::likelihood()
{
	// Not implemented yet
	return 0;
}

IWishart::~IWishart()
{
}

IWishart::IWishart()
{
	psi = Psi;
	df = m;
}