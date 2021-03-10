/*notes:这个字符串排列的递归解法并不重要，引导我们找到递归分解方式的通用解题思路才重要 ;
 *    为了产生一个字符串的所有排列，需要认清生成一个较短字符串的各种排列组合能对本问题的解决有何帮助。
 *举例来说，要生成一个5个字母的字符串“abcde”的所有排列组合。在你的解决方案中可以用递归跳跃的思路产生任何一个较短字符串的所有排列。
 *现假定递归调用能解决问题，再一次面临的关键问题是在能生成较短字符穿的排列时，怎样使它有助于解决排列最初的5字母字符串的问题
 *观察5个字母的所有排列一段时间之后，我们得到了一个想法：
 *为了列出一个长度为n的字符串的所有排列，可以依次挑选n个字母中的一个，然后在这个字母的后面列出其余n-1个字母的各种可能的排列组合。
 *    这种解决策略的唯一难点在于其递归的子问题与原问题的形式不尽相同。原问题的形式环境是列出一个字符串的所有排列组合，而子问题的形式
 *环境是列出一个字母后紧跟其余字母的所有排列。随着递归的深入，前面的一个字母会变成2个，3个甚至4个（递归的层层暂存作用），因此，子问题的
 *一般形式是产生该字符串的所有排列组合，让一些字母放在开头的固定位置。
 *    解决这种原问题与子问题之间不对称的问题时，最简单的方式就是定义一个函数ListPermutations作为一个简单的包装函数，然后调用一个辅助函数
 *解决更普遍的情况。
 *    在这个例子中，一个新函数RecursivePermute对应着子问题的一般形式，他能产生一个前K个字母已确定的字符串的所有排列组合。当k=0时，所
 *有的字母都能随意改变位置，这就是最初的问题了。当k增大时，问题会越来越简单，当k等于该字符的长度时，没有字母可以移动，字符串显示不变
 *。当然原问题没有固定的字母。
 */
#include<stdio.h>
#include"../../i/strlib.h"

static void ExchangeCharacters(string str,int p1,int p2);
static void RecursivePermute(string str,int k);
static void ListPermutations(string str);

int main(void)
{
	char s[6]="ABCDE";
	string str=s;

	ListPermutations(str);
	return 0;
}

static void ExchangeCharacters(string str,int p1,int p2)
{
	char tmp;

	tmp = str[p1];
	str[p1] = str[p2];
	str[p2] = tmp;
}

static void RecursivePermute(string str,int k)
{
	int i;
	if(k == StringLength(str))
	{
		printf("%s\n",str);
	}
	else 
	{
		for (i=k;i<StringLength(str);i++)
		{
			ExchangeCharacters(str,k,i);
			RecursivePermute(str,k+1);
			ExchangeCharacters(str,k,i);
		}
	}
}
static void ListPermutations(string str)
{
	RecursivePermute(str,0);
}
