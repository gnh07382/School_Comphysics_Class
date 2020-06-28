#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double f(double x)
{
	return pow(x,1.5)*exp(-x);
}

int main()
{
	double x,y;
	int n;
	srand48(time(NULL));

	for(int i=100;i<=10e7;i*=10)
	{
		n=0;

		for(int j=0;j<i;j++)
		{
			x=3.0*drand48();
			y=0.5*drand48();

			if(y<=f(x))
				n++;
		}
		printf("N: %d MC estimated: %.10f\n",i,3*0.5*n/i);
	}
	return 0;
}
