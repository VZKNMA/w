#include<stdio.h>
#include<stdlib.h>
#include<time.h>

static double aveofrandom01(int Ntrials);
//变量ave是随机数与0.5的差值之和，以减小ave在循环累加中溢出的概率
static double rand01(void);
//random number between 0 and 1


const double half=2*(RAND_MAX/2+0.5);

int main(void)
{
	int Ntrials;

	srand((int)time(NULL));
	printf("This program averages a series of random numbers between 0 and 1.\nHow many trails:");
	scanf("%d",&Ntrials);
	printf("The average value after %d trails is %f\n",Ntrials,aveofrandom01(Ntrials));
	return 0;
}
static double aveofrandom01(int Ntrials)
{
	double ave;
	for (int i=0;i<Ntrials;i++)
	{
		ave+=rand01()-0.5;
	}
	return (ave/Ntrials+0.5);
}
static double rand01(void)
{
	return (rand()/half);
}
