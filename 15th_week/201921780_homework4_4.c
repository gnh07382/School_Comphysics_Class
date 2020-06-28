#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x)
{
	return sin(x)*cos(x);
}

int main()
{
    double h, start=0, end=2.0*M_PI, x, p3,p5;
    char title[100];

    printf("Input h value: ");
    scanf("%lf",&h);
    sprintf(title,"35pts_prob4_h=%.4f",h);
    FILE* fp=fopen(title,"w");

    for(x=start;x<end+h;x+=h)
    {
        p3=(f(x+h)+f(x-h)-2.0*f(x))/pow(h,2);
        p5=(-f(x+2.0*h)+16.0*f(x+h)-30.0*f(x)+16.0*f(x-h)-f(x-2.0*h))/(12.0*pow(h,2));
        
        fprintf(fp,"%.10f %.10f %.10f\n",x,p3,p5);
    }

    fclose(fp);
    return 0;
}
