//I hate the people who write the code without comments.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ListPermutations(char *str);
void ListPermutations2(char *str);

int main(int argc, char *argv[])
{
	char str[] = "AABB";
	ListPermutations(str);
	printf("-------------------------------\n");
	ListPermutations2(str);
	return 0;
}

static void ExchangeChar(char *str, int p1, int p2)
{
	char temp;

	temp = str[p1];
	str[p1] = str[p2];
	str[p2] = temp;
}

static void RecursivePermute(char *str, int k)
{
	int i;

	if (strlen(str) == k) {
		printf("%s\n", str);
	} else {
		for (i = k; i < strlen(str);i++) {
			ExchangeChar(str, k, i);
			RecursivePermute(str, k+1);
			ExchangeChar(str, k, i);
		}
	}
}

void ListPermutations(char *str)
{
	RecursivePermute(str,0);
}

//剔除str中的相同元素，并把所有的不同元素依次存储在buf中
static char *setstr(char *str)
{
	char buf[10];
	int i;
	int flag;
	char *p = NULL;
	
	p = buf;
	memset(buf,0,10);
	flag = 0;
	
	for (i = 0; i < strlen(str);i++) 
	{
		int j;
		for (j = 0; j < strlen(buf); j++) 
		{
			if (buf[j] == str[i]) 
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1) 
		{
			flag = 0;
			continue;
		}
		*p++ = str[i];
	}
	return strdup(buf);
}
//str是后缀，c是后缀集合中的元素，函数的作用是删除后缀中第一个出现的元素c，并挨个迁移覆写字符串分隔符形成新的字符串str
static void delchar(char *str, char c)
{
	int i;
	char *p;
	
	p = str;
	
	for (i = 0; i < strlen(str); i++) {
		if (p[i] == c) {
			p = p+i;//使p指向当前的重合位置
			for (p;*p!=0;p++) {
				*p=*(p+1);
			}
			//*p = 0;
			break;
		}
	}
}

//此处子问题的一般形式为若给出的的字符串中含有重复字母，则列出不重复字母集合中的每一个字母作为前缀，并且前缀后面紧跟余下字符的所有组合
//至于这样为啥能避免重复，需要考虑在基本的递归过程中是怎样实现交换两个相同字母造成列举重复字符串的现象
static void RecursivePermute3(char *prefix, char*substr)
{
	char *set = setstr(substr);
	int i;

	if (strlen(set) == 1) {
		char rbuf[10];
		memset(rbuf,0,10);
		strcat(rbuf,prefix);
		strcat(rbuf,substr);
		printf("%s\n", rbuf);
	} else {
		for (i = 0; i < strlen(set); i++) {
			char buf[2]; 
			char *tmp = NULL;
			int j;

			buf[0] = set[i];
			buf[1] = 0;
			strcat(prefix,buf);//向前缀中添加一个后缀集合中的元素防止重复

			tmp = strdup(substr);//做了一个拷贝对拷贝做改动，后缀不受影响	

 			delchar(tmp, set[i]);//删除后缀中刚刚添加到前缀中的元素

			RecursivePermute3(prefix, tmp);//第二次调用时 prefix=A tmp=ABC

			prefix[strlen(prefix)-1] = 0;//删除前缀中刚刚添加的元素，为列举不同前缀的循环做准备
			free(tmp);
		}
	}
	free(set);
}


void ListPermutations2(char *str)
{
	char *p;int i;char *tmp;
	char *buf = (char *)malloc(strlen(str)+1);
	memset(buf,0,strlen(str)+1);//制作前缀

 	RecursivePermute3(buf,str);
 
	free(buf);
}
