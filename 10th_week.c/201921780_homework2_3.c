#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double h, start=0, end=1.5, x, p2,p3,p5;
    char title[100];

    printf("Input h value: ");
    scanf("%lf",&h);
    sprintf(title,"235pts_expxxx_derivs_h=%.4f",h);
    FILE* fp=fopen(title,"w");

    for(x=start;x<end+h;x+=h)
    {
        p2=(exp(pow(x+h,3))-exp(pow(x,3)))/h;
        p3=(exp(pow(x+h,3))-exp(pow(x-h,3)))/(2.0*h);
        p5=(-exp(pow(x+2.0*h,3))+8.0*exp(pow(x+h,3))-8.0*exp(pow(x-h,3))+exp(pow(x-2.0*h,3)))/(12.0*h);
        
       fprintf(fp,"%.10f %.10f %.10f %.10f\n",x,p2,p3,p5);
    }

    fclose(fp);
    return 0;
}
