#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x)
{
	return -9.8-9.8*x;
}
int main()
{
	double t, t0=0, tN=10.0, x, x0=3.0, vx, vx0=0.0, h, k1, k2, k3, k4, m1, m2, m3, m4;
	int N;

	scanf("%d",&N);
	h=(tN-t0)/N;
	
	char txt[100];
	sprintf(txt,"RK4_2d_prob8_h%.4f",h);
	FILE* fp=fopen(txt,"w");
	
	t=t0, x=x0, vx=vx0;
	
	for(int i=0;i<N;i++)
	{
		fprintf(fp,"%.10f %.10f %.10f\n",t,vx,x);
		k1=h*vx, m1=h*f(x);
		k2=h*(vx+m1/2.0), m2=h*f(x+k1/2.0);
		k3=h*(vx+m2/2.0), m3=h*f(x+k2/2.0);
		k4=h*(vx+m3), m4=h*f(x+k3);
		x+=(k1+2.0*k2+2.0*k3+k4)/6.0, vx+=(m1+2.0*m2+2.0*m3+m4)/6.0;
		t+=h;
	}
	fprintf(fp,"%.10f %.10f %.10f\n",t,vx,x);
	fclose(fp);
	return 0;
}
