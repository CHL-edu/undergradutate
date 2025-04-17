#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "1.h"
//求最大公共子串
char* strdiv(char* strout,char *str,int start,int end){
	int L = strlen(str);
	memset(strout,NULL,end-start);
	for(int i = start;i<end;i++){
		strout[i-start] = str[i];
	}	
}

char* lcs(char *str1,char *str2){
	int sameA = strspn(str1,str2);
	int L_1 = strlen(str1);
	int L_2 = strlen(str2);
	for(int i = 0;i<L_1;i++){	
		for(int j = L_1;j>i;j--){
			char* str_temp = (char*)malloc((j-i)*sizeof(char));
			strdiv(str_temp,str1,i,j);			
			if(strstr(str2,str_temp)!=NULL) return str_temp;
		}
	}
	return NULL;
}
int main(int argc, char** argv) {
	char* str1 = (char*)malloc(10*sizeof(char));
	char* str2 = (char*)malloc(10*sizeof(char));
	char* same = (char*)malloc(10*sizeof(char));
	gets(str1);
	gets(str2);
	strcpy(same,lcs(str1,str2));
	puts(same);
	stud();
	return 0;
}
