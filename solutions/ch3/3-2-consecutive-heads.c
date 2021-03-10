#include<stdio.h>
#include<time.h>
#include<stdlib.h>

const double half=RAND_MAX+1.0;

int main(void)
{
	int sigal=0;
	int sum=0;

	srand((int)time(NULL));
	while (sigal < 3)
	{
		if(rand()<=half/2)
		{
			sigal+=1;
			printf("Heads\n");
		}
		else
		{
			printf("Tails\n");
		}
		sum+=1;
	}
	printf("It took %d flips to get 3 consecutive heads.\n",sum);
	return 0;
}
