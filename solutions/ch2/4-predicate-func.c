#include <stdio.h>

#define allocated 10

static int issorted(int array[],int eff);
static void sorted(int array[],int eff);

int main(void)
{
    int effective;
    int array[allocated];
    
    printf("this program sort your array which can contain 10 integer in nondecreasing order and test it to make sure the order is fine\n"
            "so now enter the effective size:");
    scanf("%d",&effective);
    for (int n=0;n<effective;n++)
    {
        printf("?");
        scanf("%d",&array[n]);
    }
    sorted(array,effective);
    for (int n=0;n<effective;n++)
    {
        printf("%d\n",array[n]);
    }
    printf("the array's sort status is %d\n",issorted(array,effective));
    return (0);
}

static int issorted(int array[],int eff)
{
    for(int n=0;n<eff;n++)
    {
        if(array[n]>array[n+1]) return(0);
    }
    return(1);
}
static void sorted(int array[],int eff)
{/*
  The idea of this function is to find the minimum value of the current array during each iteration of the inner loop, 
and then exchange the value of the starting element of the inner loop and the value of the smallest element in the array 
to increase the startindex while reducing the inner iteration Range, until startindex=endindex, 
that is, the sorting goal is reached and the outer loop is jumped out.
  */
    int tmp,tmpindex,startindex,endindex;
    startindex=0;
    endindex=eff-1;
    tmpindex=startindex;
    tmp=array[startindex];

    for(startindex;startindex!=endindex-1;startindex++)
    {
        for(int j=startindex;j<=endindex;j++)
        {
            if(tmp>array[j])
            {
                tmpindex=j;
                tmp=array[j];
            }
        }
        tmp=array[startindex];
        array[startindex]=array[tmpindex];
        array[tmpindex]=tmp;
    }
}
