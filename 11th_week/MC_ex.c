#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    double x,y;
    int n,c;
    srand48(time(NULL));

    for(n=10;n<=1e7;n*=10)
    {
        c=0;
        for(int i=0;i<n;i++)
        {
            x=2.0*drand48()-1.0;
            y=drand48();

            if(y<=sin(1.0/x)*sin(1.0/x))
                c++;
        }
        
         printf("Number of points: %d, MC estimated: %f, error: %f\n",n,2.*c/n,fabs(1.346914-2.*c/n));
    }

    return 0;
}
