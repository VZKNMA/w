#include <stdio.h>
#include <string.h>

char * sortedarray(char array[],int n);
int findstringinsortedarray(char *key,char array[],int n);
static int binarysearch(char *key , char array[],int low, int heigh);

void main()
{
	char *array,*key;
	char arrays[26]={'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n'};
	char keywords[]={"qwer"};
	array=arrays;
	key=keywords;
	int validvalue=25;

	array=sortedarray(array,validvalue);
	printf("the match string is %s and this is a matched string:\n",keywords);
	printf("                                                    ");
	for (int i=0;i<5;i++)//此处无法理解为什么i要设置成5要包括字符结束标志
	{
		printf("%c",*(array+findstringinsortedarray(key,array,validvalue)+i));
	}
	printf("\n");
}
char * sortedarray(char array[],int n)
{
	for (int i=0;i<n-1;i++)
	{
		int k=0;
		for (int j=0;j<n-1;j++)
		{ 
			if (array[j]>array[j+1])
			{
				array[j]^=array[j+1];
				array[j+1]^=array[j];
				array[j]^=array[j+1];
			}
			else k++;
			if (k=n-1)
				return (&array[0]);
		}
	}
	return (&array[0]);
}
int findstringinsortedarray(char *key,char array[],int n)
{
	return (binarysearch(key,array,0,n-1));
}
static int binarysearch(char *key , char array[],int low, int heigh)
{
	int mid,cmp;

	if(low>heigh) return (-1);
	mid=(low+heigh)/2;
	cmp=strcmp(key,array+mid);
	if(cmp==0) return (mid);
	if (cmp<0) return (binarysearch(key,array,low,mid-1));
	else return (binarysearch(key,array,mid+1,heigh));
}
