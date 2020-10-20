/*
gcc 11-compute-pi-quarter-circle.c -lm -o a  
-lm used when you use gcc to deal with sqrt function I do not know why ?????
 */
#include<stdio.h>
#include<math.h>

#define radius 2.0
#define num 100
#define w radius/num

int main()
{
   double approximation;

   for (int n=0;n<num;n++)
   {
        approximation+=(w)*(sqrt(radius*radius-((w/2)+n*(w))*((w/2)+n*(w))));
   }
   printf("this program compute the value of pi by evaluate the area of quarter circle which radius is 2 inchs\n");
   printf("        and the pi is %f\n",approximation); 
   return(0);
}
/*
这篇文章主要介绍了C语言中的开方实现,包括一道要求精度的整数开方的题目

关于C语言中的开方计算，首先想到的当然是sqrt()函数，让我们先来回顾一下它的基本用法：
头文件：#include <math.h>

sqrt() 用来求给定值的平方根，其原型为：
double sqrt(double x);

参数

x 为要计算平方根的值。

如果 x < 0，将会导致 domain error 错误，并把全局变量 errno 的值为设置为 EDOM。

返回值

返回 x 平方根。

注意，使用 GCC 编译时请加入-lm。 ?????????

实例计算200 的平方根值。

#include <math.h>
main(){
  double root;
  root = sqrt(200);
  printf("answer is %f\n", root);
}

输出结果：
answer is 14.142136

题目
求整数N的开方，精度在0.001
general idea:  test if mid*mid equals to N*N

二分法
若N大于1,则从[1, N]开始，low = 1, high = N, mid = low + (high - low) >> 1开始进行数值逼近

若N小于1,则从[N, 1]开始，low = 0, high = N, mid = low + (high - low) >> 1开始进行数值逼近

代码
** 
  * 创新工厂2014年校招算法题目，求整数N的开方，精度为0.001 
  */
   
 #include <stdio.h> 
 #include <stdlib.h> 
 #include <math.h> 
   
 #define ACCURACY 0.001 
   
 double newSqrt(double n) 
 { 
   double low, high, mid, tmp; 
   
   // 获取上下界 
   if (n > 1)  { 
     low = 1; 
     high = n; 
   } else { 
     low = n; 
     high = 1; 
   } 
   
   // 二分法求开方 
   while (low <= high) { 
     mid = (low + high) / 2.000; 
   
     tmp = mid * mid; 
   
     if (tmp - n <= ACCURACY && tmp -n >= ACCURACY * -1) { 
       return mid; 
     } else if (tmp > n) { 
       high = mid; 
     } else { 
       low = mid; 
     } 
   } 
   
   return -1.000; 
 } 
   
 int main(void) 
 { 
   double n, res; 
  /* eof is what??????????*/ 
   while (scanf("%lf", &n) != EOF) { 
     res = newSqrt(n); 
     printf("%lf\n", res); 
   } 
   
   return 0; 
 } 
   */
