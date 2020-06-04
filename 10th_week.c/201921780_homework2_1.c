#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    int n,j,k;
    double m;

    printf("input N: ");
    scanf("%d",&n);

    double a[n];
    srand48(time(NULL));

    for(int i=0;i<n;i++)
    {
        a[i]=3.0*drand48();
    }

    printf("original array\n");

    for(int i=0;i<n;i++)
    {
        printf("%.6f ",a[i]);
    }

    for(j=1;j<n;j++)
    {
        m=a[j];

        for(k=j-1;k>=0&&a[k]>m;k--)
        {
            a[k+1]=a[k];
        }
        a[k+1]=m;
    }

    printf("\n\nafter sort\n");
   
    for(int i=0;i<n;i++)
    {
        printf("%.6f ",a[i]);
    }
    printf("\n");

    return 0;
}
