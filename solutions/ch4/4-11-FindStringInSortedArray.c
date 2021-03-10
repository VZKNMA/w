#include<stdio.h>
#include"../../i/strlib.h"

static string * Find(string str,string array[]);

int main(void)
{
	string array[5]={"abc","123","456","789","ace"};
	char s[4]="ace";
	string str=s;
	
	printf("find string :%s int arrar is same to %s\n",*(Find(str,array)),str);
	return 0;
}
static string * Find(string str,string array[])
{
	string * pointerValue;
	if(StringCompare(array[0],str)==0) 
	{
		pointerValue=array;
		return(pointerValue);
	}
	else
	{
		return(Find(str,array+1));
	}
}	
