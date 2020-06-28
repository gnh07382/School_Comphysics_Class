#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x)
{
	return sin(x)+cos(x);
}
int main()
{
    double h, start=0, end=2*M_PI, x, p2,p3,p5;
    char title[100];

    printf("Input h value: ");
    scanf("%lf",&h);
    sprintf(title,"235pts_prob3_h=%.4f",h);
    FILE* fp=fopen(title,"w");

    for(x=start;x<end+h;x+=h)
    {
        p2=(f(x+h)-f(x))/h;
        p3=(f(x+h)-f(x-h))/(2.0*h);
        p5=(-f(x+2.0*h)+8.0*f(x+h)-8.0*f(x-h)+f(x-2.0*h))/(12.0*h);
        
       fprintf(fp,"%.10f %.10f %.10f %.10f\n",x,p2,p3,p5);
    }

    fclose(fp);
    return 0;
}
