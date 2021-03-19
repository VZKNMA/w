#include <stdio.h>
#include <string.h>
#include<stdlib.h>

static char *dstr[] = {"0",
					 "",
					 "ABC",
					 "DEF",
					 "GHI",
					 "JKL",
					 "MNO",
					 "PRS",
					 "TUV",
					 "WXY",
					 ""
};

void ListMnemonics(char *str);

int main(int argc, char *argv[])
{
	ListMnemonics("72");
}

static void sub_mnemonics(char *prefix, char *substr)
{
	if (*substr == 0) {
		printf("%s\n", prefix);
	} else {
		int i;
		char *ds = strdup(dstr[substr[0]-'0']);
		for(i = 0; i < strlen(ds);i++) {
			char buf[10];
			memset(buf,0,10);
			strcat(buf,prefix);
			buf[strlen(buf)] = ds[i];
			buf[strlen(buf)] = 0;
			sub_mnemonics(buf, substr+1);
		}
		free(ds);
	}
}

void ListMnemonics(char *str)
{
	char buf[10];
	memset(buf,0,10);
	sub_mnemonics(buf, str);
}





/* segfault
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

	char s2[]="ABC";
	char s3[]="DEF";
	char s4[]="GHI";
	char s5[]="JKL";
	char s6[]="MNO";
	char s7[]="PRS";
	char s8[]="TUV";
	char s9[]="WXY";

static void ListMnemonics(char *str);

int main(void)
{
	char str[]="723";
	ListMnemonics(str);
	return 0;
}
static void RecursiveMnemonics(char **strArray,char *prefix){
	int i=0;
	while(strArray[i]!=0){
		i++;
	}
	if(strlen(prefix)==i) printf("%s\n",prefix);
	else for(int j=0;j<i;j++){
		prefix[strlen(prefix)]=strArray[strlen(prefix)][j];
		RecursiveMnemonics(strArray,prefix);
		prefix[strlen(prefix)]='\0';
	}
}
static void ListMnemonics(char *str)
{
	char **strArray=(char**)malloc(strlen(str)+1);
	memset(strArray,0,strlen(str)+1);
	char *prefix=(char *)malloc(strlen(str)+1);
	memset(prefix,0,strlen(str)+1);

        for(int i=0;i<strlen(str);i++){
	switch(str[i]){
		case '2':strArray[i]=s2;break;
		case '3':strArray[i]=s3;break;
		case '4':strArray[i]=s4;break;
		case '5':strArray[i]=s5;break;
		case '6':strArray[i]=s6;break;
		case '7':strArray[i]=s7;break;
		case '8':strArray[i]=s8;break;
		case '9':strArray[i]=s9;break;
		default:strArray[i]=NULL;printf("you input a wrong number please check!!!\n");
	}}	
	RecursiveMnemonics(strArray,prefix);
	free(prefix);
	free(strArray);
}
*/