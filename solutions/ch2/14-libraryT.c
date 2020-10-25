#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char bookname[10];
    char *  authorname[5];
    int libnumber;
    char * subtitle[5];
    char publisher[10];
    int age;
    int circulation;
}* bookT;

typedef struct{
    bookT library[1000];
} * libraryT;

static void searchbysubject(libraryT lib,char sub[]);

int main(void)
{
    libraryT libdata;
    char sub[5];
    printf("P I A subtitle you want to search:");
    scanf("%s",sub);
    searchbysubject(libdata,sub);
    return 0;
}
static void searchbysubject(libraryT lib,char sub[])
{
  for(int i=0;i<1000;i++)
  {
    int tmp=strcmp((((bookT)(lib[i]))->subtitle)[0],sub);
    if(!tmp)
    {
        printf("%s",((bookT)lib[i])->bookname);
        printf("%s",((char *)*(((bookT)lib[i])->authorname)));
        printf("%d",((bookT)lib[i])->libnumber);
    }
  }
}
