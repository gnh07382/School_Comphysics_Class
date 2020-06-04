#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.141592653

int main()
{
    double h,xmin,xmax,x,pts2,pts3,pts5;
    char filename[100];
    FILE* fp;

    xmin=0.0, xmax= M_PI;

    h=0.1;
    sprintf(filename,"235pts_tan_diff_h=%.4f.txt",h);
    fp=fopen(filename,"w");

    for(x=xmin;x<xmax;x+=h)
    {
        pts2=(tan(x+h)-tan(x))/h;
        pts3=(tan(x+h)-tan(x-h))/(2.0*h);
        pts5=(-tan(x+2.0*h)+8.0*tan(x+h)-8.0*tan(x-h)+tan(x-2.0*h))/(12.0*h);
        fprintf(fp,"%.10f %.10f %.10f %10f\n",x,pts2,pts3,pts5);
    }

    fclose(fp);
    
    return 0;
}