#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand48(time(NULL));
	int n;
	n=3*drand48()+1;
	int m;

	printf("Rock scissors paper game\nInput one number among (1(scissors), 2(rock), 3(paper)):");
	scanf("%d",&m);
	
	if(m==1)
	{
		if(n==1)
			printf("scissors: draw");
		if(n==2)
			printf("rock: lose");
		if(n==3)
			printf("paper: you win");
	}
	if(m==2)
	{
		if(n==1)
			printf("scissors: you win");
		if(n==2)
			printf("rock: draw");
		if(n==3)
			printf("paper: lose");
	}
	if(m==3)
	{
		if(n==1)
			printf("scissors: lose");
		if(n==2)
			printf("rock: you win");
		if(n==3)
			printf("paper: draw");
	}
	printf("\n");
	return 0;
}
