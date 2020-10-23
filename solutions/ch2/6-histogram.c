#include<stdio.h>

int main(void)
{
    int score[11]={0,0,0,0,0,0,0,0,0,0,0};
    
    for(int i=0;i<10;i++)
    {
        int tmp;

        printf("input score #%d ?:",i+1);
        scanf("%d",&tmp);
        tmp/=10;
        switch(tmp)
        {
            case 0: score[0]++;break;
            case 1: score[1]++;break;
            case 2: score[2]++;break;
            case 3: score[3]++;break;
            case 4: score[4]++;break;
            case 5: score[5]++;break;
            case 6: score[6]++;break;
            case 7: score[7]++;break;
            case 8: score[8]++;break;
            case 9: score[9]++;break;
            case 10: score[10]++;break;
            default: printf("wrong input try again"); break;
        }
    }
    for(int i=0;i<11;i++)
    {
        printf("%d:",i*10);
        for(int j=0;j<score[i];j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
