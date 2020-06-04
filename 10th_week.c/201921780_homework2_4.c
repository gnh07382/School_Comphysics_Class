#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double h, start=0, end=1.5, x, p3,p5;
    char title[100];

    printf("Input h value: ");
    scanf("%lf",&h);
    sprintf(title,"35pts_expxx_double_diff_h=%.4f",h);
    FILE* fp=fopen(title,"w");

    for(x=start;x<end+h;x+=h)
    {
        p3=(exp(pow(x+h,2))+exp(pow(x-h,2))-2.0*exp(pow(x,2)))/pow(h,2);
        p5=(-exp(pow(x+2.0*h,2))+16.0*exp(pow(x+h,2))-30.0*exp(pow(x,2))+16.0*exp(pow(x-h,2))-exp(pow(x-2.0*h,2)))/(12.0*pow(h,2));
        
       fprintf(fp,"%.10f %.10f %.10f\n",x,p3,p5);
    }

    fclose(fp);
    return 0;
}
