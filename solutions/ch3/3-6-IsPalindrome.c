#include<stdio.h>
#include<string.h>

static int IsPalindrome(char * str);
static int Palindrome(char * str,int start,int end);

int main(void)
{
	char str [30] ;

	printf("Please input a string less than 29 letters:");
	scanf("%s",str);
	if(IsPalindrome(str)) printf("this is a palindrome!\n");
	else printf("this is a normal word!\n");
	return 0;
}
static int IsPalindrome(char * str)
{
	int start=0,end=strlen(str)-1;
	return (Palindrome(str,start,end));
}
static int Palindrome(char * str,int start,int end)
{
	if(start>=end) return (1);
	else if(str[start]!=str[end]) return (0);
	else
		return(Palindrome(str,++start,--end));
}
