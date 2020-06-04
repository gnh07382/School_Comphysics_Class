#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    double h,xmin,xmax,x,pts3,pts5;
    FILE* fp;

    xmin=0.0, xmax=2.0*M_PI;

    h=0.1;
    fp=fopen("35pts_tan_diff_h=0.1000.txt","w");

    for(x=xmin; x<xmax; x+=h)
    {
        pts3=(tan(x+h)+tan(x-h)-2.0*tan(x))/pow(h,2);
        pts5=(-tan(x+2.0*h)+16.0*tan(x+h)-30.0*tan(x)+16*tan(x-h)-tan(x-2.0*h))/(12.0*pow(h,2));
        fprintf(fp,"%.10f %.10f %.10f\n",x,pts3,pts5); 
    }
    fclose(fp);

    return 0;
}