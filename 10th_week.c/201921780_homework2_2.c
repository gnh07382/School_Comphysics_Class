#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    int n;
    printf("input N: ");
    scanf("%d",&n);
    
    double a[n][n], b[n][n];
    
    srand48(time(NULL));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            a[i][j]=10.0*drand48()-5.0;
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            b[i][j]=10.0*drand48()-5.0;
    }
   
    printf("\nThe matrix A is\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%.6f ",a[i][j]);
        printf("\n");
    }
    
    printf("\nThe matrix B is\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%.6f ",b[i][j]);
        printf("\n");
    }

    printf("\nThe matrix A+B is\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%.6f ",a[i][j]+b[i][j]);
        printf("\n");
    }
    
    printf("\nThe matrix B-A is\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%.6f ",b[i][j]-a[i][j]);
        printf("\n");
    }

    return 0;
}
