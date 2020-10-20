#include<stdio.h>

#define max 999999

void under10(int n);
void under100(int n);
void under1000(int n);
void under10000(int n);
void under100000(int n);
void under1000000(int n);

void main()
{
    int n;

    printf("this program reads number(postive integer)from user and output as english text,stopping when input is negative\n?");
    scanf("%d,n");
    while(1)
    {
        if(n<0) break;
        if(n>max) printf("you are too rich,how about give me some?\n");
        under1000000(n);
    }
}
void under10(int n)
{
    switch(n)
    {
        case 0: printf("zero"); break;
        case 1: printf("one"); break;
        case 2: printf("two"); break;
        case 3: printf("three"); break;
        case 4: printf("four"); break;
        case 5: printf("five"); break;
        case 6: printf("six"); break;
        case 7: printf("seven"); break;
        case 8: printf("eight"); break;
        case 9: printf("nine"); break;
        case 10: printf("ten"); break;
        default : printf("Illegal call to under10"); break;
    }
}
void under100(int n)
{
    switch(n)
    {
        case 11: printf("eleven"); break;
    }
}
void under1000(int n);
void under10000(int n);
void under100000(int n);
void under1000000(int n);
