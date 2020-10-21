#include<stdio.h>

#define pi 3.14159

static void readin(float *h,float* r);
static void solveproblem(float *a,float *v,float *h,float *r);
static void displayresult(float *a,float *v);

void main()
{
   float a,v,h,r;
   
   readin(&h,&r);
   solveproblem(&a,&v,&h,&r);
   displayresult(&a,&v);
}
static void readin(float *h,float* r)
{
    printf("P I h:");
    scanf("%f",h);
    printf("P I r:");
    scanf("%f",r);
}
static void solveproblem(float *a,float *v,float *h,float *r)
{
    *a=2*pi*(*h)*(*r);
    *v=pi*(*h)*(*r)*(*r);
}
static void displayresult(float *a,float *v)
{
    printf("the surface area is %f\n",*a);
    printf("the volume is %f\n",*v);
}
