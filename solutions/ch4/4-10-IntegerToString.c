#include<stdio.h>
#include"../../i/strlib.h"

static string IntegerToString(int i);

int main(void)
{
	int i;
	scanf("%d",&i);
	printf("%s\n",IntegerToString(i));
	return 0;
}
static string IntegerToString(int i)
{
	if(i<10) return (CharToString((char)(n+32)));
	else return(Concat(IntegerToString(i/10),CharToString((char)(n%10+32))));
}
