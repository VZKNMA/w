#include<stdio.h>

int main(void)
{
    int score[11]={0,0,0,0,0,0,0,0,0,0,0};
    int tmp;
    
    for(int i=0;i<12;i++)
    {

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
    tmp=0;
    for(int i=0;i<11;i++)
    {
        if(tmp<score[i]) tmp=score[i];
    }
    for(int i=tmp;i>0;i--)
    {
        
    for(int j=0;j<11;j++)
    {
       if(i==score[j]) 
       {
            printf("  *");
            score[j]-=1;
       }
       else printf("   ");
    }
    printf("\n");
    }
    printf("  0 10 20 30 40 50 60 70 80 90 100\n"); 
    return 0;
}
