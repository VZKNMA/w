#include<stdio.h>

static void printSingleStep(int n,char start,char end);
static void printSingleStep0(int n,char start,char end);
static void moveDisks0(int n,char start,char end,char mid);
static void moveDisks(int n,char start,char end,char mid);
int sum=0;
int calls=0;
int sum0=0;
int calls0=0;

int main(void)
{
  moveDisks(3,'A','B','C');
  moveDisks0(3,'A','B','C');
  printf("there are %d times move,and there are %d times Movedisks functioncalls\n",sum,calls);
  printf("there are %d times move,and there are %d times Movedisks0 functioncalls\n",sum0,calls0);
  return 0;
}

static void printSingleStep0(int n,char start,char end)
{
	calls0++;
  printf("Move disk %d from %c to %c\n",n,start,end);
  sum0++;
}

static void moveDisks0(int n,char start,char end,char mid)
{
	calls0++;
  if(n==0) ; 
  else{
    moveDisks0(n-1,start,mid,end);
    printSingleStep0(n,start,end);
    moveDisks0(n-1,mid,end,start);
  }
}
static void printSingleStep(int n,char start,char end)
{
	calls++;
  printf("Move disk %d from %c to %c\n",n,start,end);
  sum++;
}

static void moveDisks(int n,char start,char end,char mid)
{
	calls++;
  if(n==1)
	 printSingleStep(n,start,end) ; 
  else{
    moveDisks(n-1,start,mid,end);
    printSingleStep(n,start,end);
    moveDisks(n-1,mid,end,start);
  }
}
