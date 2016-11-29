#include "Wishart.h"



Wishart::Wishart(Matrix& sigma,int df)
{
	Vinv = sigma.inverse();
	vcholsumlogdiag =  sigma.chol().sumlogdiag();
	this->df = df;
	gamd = gamlnd(df, d);
}

double Wishart::likelihood(Matrix& s)
{
	return (df - d - 1)* s.chol().sumlogdiag() -0.5 * (Vinv*s).diag().sum() - log(df*d/2)  + log(2) - df * vcholsumlogdiag - gamd;
}


Matrix& Wishart::rnd()
{
	// Not yet implemented
	return NULLMAT;
}

Wishart::~Wishart()
{
}
