#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x)
{
	return 9.8-pow(x,2.0);
}
int main()
{
	double t, t0, tN=3.0, x, x0=0, h, k1, k2, k3, k4;
	int N;
	FILE* fp=fopen("RK4_fall_result","w");

	N=100;
	h=(tN-t0)/N;
	t=t0, x=x0;
	for(int i=0;i<N;i++)
	{
		fprintf(fp,"%.10f %.10f\n",t,x);
		k1=h*f(x);
		k2=h*f(x+k1/2.0);
		k3=h*f(x+k2/2.0);
		k4=h*f(x+k3);
		x+=(k1+2.0*k2+2.0*k3+k4)/6.0;
		t+=h;
	}
	fprintf(fp,"%.10f %.10f\n",t,x);
	return 0;
}
