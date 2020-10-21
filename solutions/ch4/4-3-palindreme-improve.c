//改进isplindreme()减少重复计算-字符串长度 用指针运算代替字符串函数
#include <stdio.h>
#include "genlib.h"
#include <string.h>

int ispalindreme(string str);
int checkpalindreme(string str,int len);

void main()
{
	char word[44];//此处原计划的语句为string word; 但提示段错误访问超出内存 故修改 但未修改配套函数的参量类型 函数竟然运行正确
			//应该好好看看第二章以求完全理解 以后也可以处理类似的问题
	printf("please input a word to see if it is a palindreme:");
	scanf("%s",&word);
	if (ispalindreme(word)) printf("is a palindreme\n");
	else printf("is a palin word\n");
}
int ispalindreme(string str)
{
	return (checkpalindreme(str,strlen(str)));
}


int checkpalindreme(string str,int len)
{
	if (len<=1) return (1);
	else return (str[0]==str[len-1]&&checkpalindreme(str+1,len-2));
}
