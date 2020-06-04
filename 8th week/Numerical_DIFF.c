#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.141592653

int main()
{
    double h,xmin,xmax,x,pts2,pts3,pts5;
    char filename[100];
    FILE* fp;

    xmin=0.0, xmax=2.0*PI;

    printf("input a value: ");
    scanf("%lf",&h);

    sprintf(filename,"235pts_sin_diff_h=%.4f.txt",h);
    fp=fopen(filename,"w");

    for(x=xmin;x<xmax;x+=h)
    {
        pts2=(sin(x+h)-sin(x))/h;
        pts3=(sin(x+h)-sin(x-h))/(2.0*h);
        pts5=(-sin(x+2.0*h)+8*sin(x+h)-8*sin(x-h)+sin(x-2.0*h))/(12.0*h);
        fprintf(fp,"%.10f %.10f %.10f %10f\n",x,pts2,pts3,pts5);
    }

    fclose(fp);
    
    return 0;
}