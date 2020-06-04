#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x)
{
	return 1.0/x;
}
int main()
{
	double t, t0=1.0 ,tN=10.0 ,x ,x0=1.0 ,h ,k1 ,k2 ,k3 ,k4;
	int N;
	FILE* fp=fopen("RK4_1d_ex2","w");

	N=50;
	h=(tN-t0)/N;

	t=t0, x=x0;
	for(int i=0;i<N;i++)
	{
		fprintf(fp, "%.10f %.10f\n",t,x);
		k1 =h*f(x);
		k2 =h*f(x+k1/2.0);
		k3 =h*f(x+k2/2.0);
		k4 =h*f(x+k3);
		x=x+(k1+2.0*k2+2.0*k3+k4)/6.0;
		t+=h;
	}
	fprintf(fp,"%.10f %.10f\n",t,x);
	fclose(fp);
	return 0;
}
