#include<stdio.h>
#include<stdlib.h>

static int * indexarray(int n);

int main(void)
{
    int max;
    int *array;

    printf("this program make a dynamically allocated integer array with n elements,each of which is initialized to its index"
            "\nplease input n");
    scanf("%d",&max);
    array=indexarray(max);
    printf("here is the array:\n");
    for(int i=0;i<max;i++)
    {
        printf("%d\t",array[i]);
        if (i!=0&&!(i%15)) printf("\n");
    }
    printf("\n");
    free(array);
    return 0;
}
static int * indexarray(int n)
{
    int * array;
    array=malloc(n);
    for(int i=0;i<n;i++)
    {
        *(array+i)=i;
    }
    return array;
}
