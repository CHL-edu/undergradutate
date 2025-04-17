#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char *str = (char*)malloc(10*sizeof(char));
	char *str1 = (char*)malloc(10*sizeof(char));
	//memset(str,NULL,sizeof(str));
	//memset(str1,NULL,sizeof(str1));
	gets(str);
	strcpy(str1,str);
	strrev(str1);
	if(strcmp(str,str1) == 0) printf("1");
    return 0;
}


