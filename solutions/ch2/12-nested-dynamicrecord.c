#include<stdio.h>
#include"../../i/genlib.h"

typedef struct{
    char name[40];
    char title[15];
    char ssnum [12];
    double salary;
    int withholding; 
} * employT;

typedef struct{
    int empnum;
    employT * * array;
} * payrollT;

payrollT getPayroll(void);
void displayPayroll(payrollT payroll);
void freePayroll(payrollT payroll);

int main(void)
{
    payrollT payroll;

    payroll=getPayroll();
    displayPayroll(payroll);
    freePayroll(payroll);
    return 0;
}
payrollT getPayroll(void)
{
    payrollT payroll;

    payroll=New(payrollT);
    printf("how many employees:");
    scanf("%d",&payroll->empnum);
    for(int i=0;i<payroll->empnum;i++)
    {
        payroll->array[i]=New(employT);
        printf("Employee #%d:\n",i+1);
        printf("Name:");
        scanf("%s",&payroll->array[i]->name);
        printf("Title:");
        scanf("%s",&payroll->array[i]->title);
        printf("Ssnum:");
        scanf("%s",&payroll->array[i]->ssnum);
        printf("Salary:");
        scanf("%lf",&payroll->array[i]->salary);
        printf("Withholding:");
        scanf("%d",&payroll->array[i]->withholding);
    }
    return payroll;
}
void displayPayroll(payrollT payroll)
{
    printf("check this out!\nthere are %d employees\n",payroll->empnum);
    for(int i=0;i<payroll->empnum;i++)
    {
        printf("Employee #%d:\n",i+1);
        printf("Name:""%s",payroll->array[i]->name);
        printf("Title:""%s",payroll->array[i]->title);
        printf("Ssnum:""%s",payroll->array[i]->ssnum);
        printf("Salary:""%lf",payroll->array[i]->salary);
        printf("Withholding:""%d",payroll->array[i]->withholding);
    }
}
void freePayroll(payrollT payroll)
{
    for(int i=0;i<payroll->empnum;i++)
    {
        free(payroll->array[i]);
    }
    free(payroll);
}
