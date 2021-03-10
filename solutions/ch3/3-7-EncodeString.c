//gcc 3-7-EncodeString.c  -L ../../l -l cs -o a.out
#include<stdio.h>
#include"../../i/strlib.h"
#include"../../i/genlib.h"

static string EncodeString(string str,int key);

int main(void)
{
	char str [90];
	string mes=str;//string is a pointer ,need to have a right address value
	int key;
	printf("This program encodes messages using a cyclic cipher.\nTo stop,enter 0 as the key.\n");
	while(1)
	{
	printf("Enter the key:");
	scanf("%d",&key);
	if(key==0) break;
	while(getchar()!='\n');
	printf("Enter a message:");
	scanf("%s",mes);//this is a bug that haven't been solved,input:"i love you" output 'i',mes can not get the space character.
	printf("Encoded message:%s\n",EncodeString(mes,key));
	}
	return 0;
}
static string EncodeString(string str,int key)
{
	for(int i=0;i<StringLength(str);i++)
	{
		if (IthChar(str,i)>='a'&&IthChar(str,i)<='z'||IthChar(str,i)>='A'&&IthChar(str,i)<='Z')
		{
			if((IthChar(str,i)+key)>'z'&&(IthChar(str,i)<='z')||(IthChar(str,i)+key)>'Z'&&(IthChar(str,i)<='Z'))
				str[i]=(IthChar(str,i)+key)-26;
			else
				str[i]=IthChar(str,i)+key;
				
		}
	}
	return(str);
}
