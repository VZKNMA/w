/*other people write I copied it*/
/*
 *Usage of array
 *
 */

#include <stdio.h>
#include "../../i/genlib.h"
#include "../../i/simpio.h"

#define MaxJudges 100
#define MinScore 0.0
#define MaxScore 10.0

static void ReadAllScores(double scores[],int nJudges);
static double GetScore(int judge);
static double Mean(double array[],int n);

int main()
{
  double scores[MaxJudges];
  int nJudges;

  printf("Enter the number of judges: ");
  nJudges=GetInteger();
  if(nJudges>MaxJudges) Error("Too many judges");
  ReadAllScores(scores,nJudges);
  printf("The average score is %.2f\n",Mean(scores,nJudges));
}

static void ReadAllScores(double scores[],int nJudges)
{
  int i,minindex,maxindex;
  double min=10.0;
  double max=0.0;

  for(i=0;i<nJudges;i++){
    scores[i]=GetScore(i);
    if (min>=scores[i]) 
    {
        minindex=i;
        min=scores[i];
    }
    if (max<=scores[i]) 
    {
        maxindex=i;
        max=scores[i];
    }/*
      这个地方出错是因为为了找到数组中的最大最小值并置零：我只顾着在找到极值时把迭代值的下标赋值给暂存值下标，而忘记把迭代值赋值给暂存值了。而迭代求极值的根本就在于暂存值是当前正在进行的迭代过程的动态迭代值。
      */
  }
  scores[minindex]=0.0;
  scores[maxindex]=0.0;
}

static double GetScore(int judge)
{
  double score;
  while(TRUE){
    printf("Score for judge #%d: ",judge);
    score=GetReal();
    if(score>=MinScore && score<=MaxScore) break;
    printf("That score is out of range. Try again.\n");
  }
  return score;
}

static double Mean(double array[],int n)
{
  int i;
  double total=0;
  for(i=0;i<n;i++){
    total+=array[i];
  }
  return (total/(n-2));
}
