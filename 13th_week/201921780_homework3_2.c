#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	double x,y,z;
	int n,cnt;
	srand48(time(NULL));

	for(n=100; n<=10e7; n*=10)
	{
		for(int i=0;i<n;i++)
		{
			x=4.0*drand48()-2.0;
			y=4.0*drand48()-2.0;
			z=4.0*drand48()-2.0;
		
			if(pow(x,2)+pow(y,2)+pow(z,2)<=4)
				cnt++;
		}

		printf("N: %d estimated volume: %.10f error: %.10f\n",n,64.0*cnt/n,fabs((32.0/3.0)*M_PI-64.0*cnt/n));
	}
}
