#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char name[40];
    char title[15];
    char ssnum [12];
    double salary;
    int withholding; 
} * employT;

typedef struct{
    int empnum;
    employT * array;
} * payrollT;
/*records defined below is for malloc,because I didn't know how to use malloc with pointers*/
typedef struct{
    char name[40];
    char title[15];
    char ssnum [12];
    double salary;
    int withholding; 
} employTe;

typedef struct{
    int empnum;
    employT * array;
}payrollTe;

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

    payroll=malloc(sizeof(payrollTe));
    printf("how many employees:");
    scanf("%d",&(payroll->empnum));
    /*
       I first uses &payroll->empnum;and it lead to a segment fault whick means wrong address.
       but I think there is nothing wrong with that.because -> is prior to & and the associativity is
       ok.maybe is because ???????????????
    printf("It works\n");
    */
    payroll->array=malloc((payroll->empnum)*sizeof(employTe));     
    for(int i=0;i<payroll->empnum;i++)
    {
        printf("Employee #%d:\n",i+1);
        /*
        printf("Name:");
        scanf("%s",(payroll->array[i]->name));
        code above is wrong,because 
        left operands represents for a piece of memory that contains value
        and a pointer actually represents for a piece of memory that contains value's address.
        When you use -> (select operator) or * (dereference operator) continuously, 
        you only get the value of the memory space pointed to by the pointer. 
        This value is only a left operand and cannot be associated with other left operands. 
        You need to use The cast operator restores the attributes of the original data type. 
        That is, the left operand obtained by using pointers will sometimes be deprived of the original attributes or functions 
        of its data type, such as a pointer to a pointer whose basic type is a record. 
        The specific theoretical explanation is not clear, which involves the internal C language The principle, 
        I should continue to understand in depth in the future study.
        */
        printf("Name:");
        scanf("%s",((employT)((payroll->array)+i))->name);
        printf("Title:");
        scanf("%s",((employT)((payroll->array)+i))->title);
        printf("Ssnum:");
        scanf("%s",((employT)((payroll->array)+i))->ssnum);
        printf("Salary:");
        scanf("%lf",&(((employT)((payroll->array)+i))->salary));
        printf("Withholding:");
        scanf("%d",&(((employT)((payroll->array)+i))->withholding));
    }
    return payroll;
}
void displayPayroll(payrollT payroll)
{
    printf("check this out!\nthere are %d employees\n",payroll->empnum);
    for(int i=0;i<payroll->empnum;i++)
    {
        printf("Employee #%d:\n",i+1);/*此处应修改对应的指针数组关系笔记以求获得正确清晰的理解*/
        printf("Name:%s\n",((employT)((payroll->array)+i))->name);
        printf("Title:%s\n",((employT)((payroll->array)+i))->title);
        printf("Ssnum:%s\n",((employT)((payroll->array)+i))->ssnum);
        printf("Salary:%lf\n",((employT)((payroll->array)+i))->salary);
        printf("Withholding:%d\n",((employT)((payroll->array)+i))->withholding);
    }
}
void freePayroll(payrollT payroll)
{
    for(int i=0;i<payroll->empnum;i++)
    {
        free(((employT)(payroll->array)+i));
    }
    free(payroll);
}
