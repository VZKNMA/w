#include<stdio.h>

typedef enum{Monday,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday}weekdayT;

weekdayT previousday(weekdayT n);
weekdayT nextday(weekdayT n);
weekdayT incrementday(weekdayT n,int delta);

void main()
{
    weekdayT n;
    int delta;

    printf("this program output a day before the day,after the day,and delta days after or before the day:\nyout luckyday's name:");
    scanf("%d",&n);
    n-=1;
    printf("%d\n",previousday(n)+1);
    printf("%d\n",nextday(n)+1);
    printf("the delta is :");
    scanf("%d",&delta);
    printf("%d\n",incrementday(n,delta)+1);
}
weekdayT previousday(weekdayT n)
{
    return((n+6)%7);
}
weekdayT nextday(weekdayT n)
{
    return((n+1)%7);
}
weekdayT incrementday(weekdayT n,int delta)
{
    return((n+delta)%7);
}
