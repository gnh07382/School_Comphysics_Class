#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Vx(double vx)
{
	return -vx;
}
double Vy(double vy)
{
	return -9.8-vy;
}
int main()
{
	double t, t0, tN=3.0, vx, vx0=10, vy, vy0=10, h, k1, k2, k3, k4, m1, m2, m3, m4;
	int N;
	FILE* fp=fopen("RK4_1d_prob","w");

	N=100;
	h=(tN-t0)/N;
	t=t0, vx=vx0, vy=vy0;
	for(int i=0;i<N;i++)
	{
		fprintf(fp,"%.10f %.10f %.10f\n",t,vx,vy);
		k1=h*Vx(vx), m1=h*Vy(vy);
		k2=h*Vx(vx+k1/2.0), m2=h*Vy(vy+m1/2.0);
		k3=h*Vx(vx+k2/2.0), m3=h*Vy(vy+m2/2.0);
		k4=h*Vx(vx+k3), m4=h*Vy(vy+m3);
		vx+=(k1+2.0*k2+2.0*k3+k4)/6.0, vy+=(m1+2.0*m2+2.0*m3+m4)/6.0;
		t+=h;
	}
	fprintf(fp,"%.10f %.10f %.10f\n",t,vx,vy);
	fclose(fp);
	return 0;
}
