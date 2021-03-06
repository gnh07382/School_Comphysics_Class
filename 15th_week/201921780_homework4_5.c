#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x)
{
	return exp(-1.0*pow(x,2)); 
}
int main()
{
	double x, xmin=-2.0 ,xmax=2.0 , h,result1,result2,result3;
	int num;
	for(num=10;num<=100;num+=10)
	{	
		result1=0, result2=0, result3=0;

		h=(xmax-xmin)/num;
		for(int i=0;i<num;i++)
			result1+=h*f(xmin+i*h);

		h=(xmax-xmin)/num;
		for(int i=0;i<num;i++)
			result2+=h*f(xmin+i*h);
		result2+=0.5*h*(f(2.0)-f(-2.0));
		
		h=(xmax-xmin)/(2.0*num);
		for(int i=0;i<num;i++)
			result3+=(h/3.0)*(f(xmin+2.0*h*i)+4.0*f(xmin+2.0*h*i+h)+f(xmin+2.0*h*i+2.0*h));

		printf("N: %d rectangle: %10f trapeziod: %10f simpson: %10f\n",num, result1,result2,result3);
	}
	return 0;
}
