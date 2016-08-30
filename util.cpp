/* C implementations of useful functions.
 * Written by Tom Minka (unless otherwise noted).
 */

#define _USE_MATH_DEFINES 1
#include <stdlib.h>
#include <float.h>
#include "util.h"
#include <math.h>

#ifdef _MSC_VER
#define finite _finite
#define isnan _isnan
#endif

double gammaln(double x)
{
  #define M_lnSqrt2PI 0.91893853320467274178
  static double gamma_series[] = {
    76.18009172947146,
    -86.50532032941677,
    24.01409824083091,
    -1.231739572450155,
    0.1208650973866179e-2,
    -0.5395239384953e-5
  };
  int i;
  double denom, x1, series;
  if(x < 0) return NAN;
  if(x == 0) return INFINITY;
  if(!finite(x)) return x;
  /* Lanczos method */
  denom = x+1;
  x1 = x + 5.5;
  series = 1.000000000190015;
  for(i = 0; i < 6; i++) {
    series += gamma_series[i] / denom;
    denom += 1.0;
  }
  return( M_lnSqrt2PI + (x+0.5)*log(x1) - x1 + log(series/x) );
}



double urand()
{
	return rand() / ((double) (RAND_MAX+1.0));
}




Vector gl_pc;
/* With 0.5 increments */
// x/2 is actual gammaln parameter
void precomputeGammaLn(int size) 
{
	int i;
	new (&gl_pc) Vector(size);
	for (i=0;i<gl_pc.n;i++)
		gl_pc[i] = gammaln(i/2.0);
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


int sample(Vector& v)
{
	double d = 0;
	double r = urand();
	int n = v.n;
	int i;
	for (i = 0; i < n;i++)
	{
		d += v[i];
		if (d > r)
			break;
	}
	return i;
}

int sampleFromLog(Vector & v)
{
	int n = v.n;
	double max = v.maximum();
	v -= max;
	v.transform(exp); // In-place use transform
	v /= v.sum();
	return sample(v);
}

vector<int> trange(int max, int nparts, int id)
{
	int chunksize = ceil( (1.0*max) / nparts);
	int start = chunksize*id;
	int end = start+chunksize;
	end = (end > max) ? max : end;
	return vector<int>({ start, end });
}


double harmean(double x,double y)
{
	return 1.0/((1.0/x)+(1.0/y));
}


boolean checkVectors(Vector& v1, Vector& v2)
{
	int iscopy = 1;
	if (v1.data == v2.data)
		printf("Points to same address\n");
	else
	{
		if (v1.n == v2.n)
		{
			for (auto i = 0; i < v1.n; i++)
				if (v1.data[i] != v2.data[i])
					iscopy = 0;
		}
		
		if (iscopy)
			printf("Copy vectors\n");
		else
			printf("Different vectors");
	}
	return iscopy;
}