//猪脑子昨天晚上想了半天，也没作对，有两种思路都太过模糊，一落到代码上就有问题，还好今天早上思路清晰了，在这里记录一下。
//最后一个注释中的代码是昨天晚上 的半成品，最后还差一个二元组排序，太麻烦了已放弃
//其他的注释是网上的解法，效率会高一些。搜索大法万岁！！！
#include<stdio.h>
#include"../../i/strlib.h"

static void HeadTailReverse(string str,int start,int end);
static string Reverse(string str);

int main(void)
{
	string str;
	char stri[30];
	str=stri;
	scanf("%s",str);
	printf("%s\n",Reverse(str));
	return 0;
}

static void HeadTailReverse(string str,int start,int end)
{
	char tmp;

	if(start >= end) ;
	else 
	{
		tmp=str[start];
		str[start]=str[end];
		str[end]=tmp;	
		HeadTailReverse(str,++start,--end);//猪脑子变聪明了 嘿嘿
	}
}

static string Reverse(string str)
{
	HeadTailReverse(str,0,(StringLength(str)-1));
	return(str);
}

/*思路是HeadwordRestword分解方式
#include<stdio.h>
#include"../../i/strlib.h"

static string reverse(string str);

int main(void)
{
	
	string str;
	char stri[30];
	str=stri;
	scanf("%s",str);
	printf("%s\n",reverse(str));
	return 0;
}
static string reverse(string str)
{
	if(StringLength(str)==1) return (str);
	else return(Concat(reverse(SubString(str,1,StringLength(str))),CharToString(IthChar(0))));
}

 * /

/*
//原理也是headtail原理，只不过实现方式不一样
#include<stdio.h>
 
//*******递归的方式写字符串长度函数
int my_strlen(char *str)  
{
	if(*str == '\0')    //当传入的字符串中没有字符
		return 0;		//字符串长度为0
	else
		return 1+ my_strlen(str+1);	//运用递归，每递归一次长度加1，直到遍历到的'\0'时结束递归
} 
//*******递归方式写字符串反转******
void reverse_string(char *string)
{
	int len = my_strlen(string);//调用上面的字符串长度函数;
	if(len <= 1)	//当字符串长度小于等于1时，不执行；
		return ;
	else
	{
		char temp = string[0];	 //将第一个字符的值保存在temp中;
		string[0] = string[len-1];//将最后一个字符赋给第一个字符;
		string[len-1] = '\0';	//将最后一个字符的内容赋为'\0';
		reverse_string(string+1);//递归调用下一次反转；
		string[len-1] = temp;	//将temp赋给当前的最后一个字符；
	}
}
 
int main(void)
{
	char ch[] = "abcdefg";
	reverse_string(ch);
	printf("%s ",ch);
	printf("\n");
	getchar();	//缓冲；
	return 0;
}
*/

/*
 另外一种思路
#include<stdio.h>
int reversal();
int main()
{
 reversal();


    printf("\n");
 return 0;
}
int reversal()
{
 char c;
 scanf("%c",&c);
 if(c!='\n')
 {
 
     reversal();


 }
//  reversal();
 printf("%c",c);

}


关于递归：

其在阶乘，连加等地方的用处较多，其特点是可以一种类似暂时存储的作用，比如此题，其可以将先输入的字符保留住，之后输出。这是由于递归是“一层层的输入，一层层的退出”。 
 */
/*
#include<stdio.h>
#include"../../i/strlib.h"

static void exchange(string str,int start,int end);
static void BinaryReverse(string str,int start,int end);
static string Reverse(string str);

int main(void)
{
	string str;
	char stri[30];
	str=stri;
	scanf("%s",str);
	printf("%s\n",Reverse(str));
	return 0;
}

static void exchange(string str,int start,int end)
{
	char tmp;

	if (start>=end) ;
	else
	{
		tmp = str[start];
		str[start] =  str[end];
		str[end] = tmp;
	}
}
static void BinaryReverse(string str,int start,int end)
{
	if(start>=end-1) exchange(str,start,end);
	else 
	{
		int mid ;

		mid=(start+end)/2;
		BinaryReverse(str,start,mid);
		BinaryReverse(str,mid+1,end);
	}
}
static string Reverse(string str)
{
	BinaryReverse(str,0,(StringLength(str)-1));
	return(str);
}
*/
