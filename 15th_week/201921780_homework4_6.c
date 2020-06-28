#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double f(double x, double y)
{
	return exp(-1.0*pow(x+y,2));
}
int main()
{
	srand48(time(NULL));
	double x,y,z;
	int count;
	for(int i=10; i<=10e7; i*=10)
	{
		count=0;
		for(int j=1;j<=i;j++)
		{
			x=4.0*drand48()-2.0;
			y=4.0*drand48()-2.0;
			z=1.0*drand48();
			
			if(f(x,y)>=z)
				count++;
		}
		printf("N: %d, MC estimated: %.10f\n",i,16*count/(double)i );
	}
	return 0;
}
