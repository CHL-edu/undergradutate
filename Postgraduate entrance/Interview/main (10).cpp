#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

/*
给定一个包含多个标识符的文件 abc.in，请判断其中有多少个合法的标识符。合法的标识符需要符合 C 语言的标识符定义规则：

标识符只能由字母（a-z, A-Z）、数字（0-9）和下划线（_）组成。

标识符的第一个字符不能是数字。

标识符不能包含空格或其他特殊字符（如 @, #, -, . 等）。

输入格式:
文件 abc.in 包含若干行，每行一个标识符。

输出格式:
输出一个整数，表示合法标识符的数量。

 run this program using the console pauser or add your own getch, system("pause") or input loop */
bool is_valid_identifier(char *str){
	int flag_1 = 1;
	int flag_2 = 1;
	int flag_3 = 1;	
	if(str[0]>='0'&&str[0]<='9') flag_2 = 0;
	for(int i = 0;i<strlen(str);i++){
		if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')||(str[i]>='0'&&str[i]<='9')||(str[i]=='_'));
		else
			flag_3 = 0;
	}
	return flag_1*flag_2*flag_3;
}
int main(int argc, char** argv) {
	FILE *f = fopen("abc.in","r");
	FILE *fp= fopen("abcd.txt","a");
	int valid_count = 0;
	char *str = (char *)malloc(10*sizeof(char));
	while(fgets(str,100,f)) {
		str[strlen(str)-1] = '\0';
        if (is_valid_identifier(str)) {
            valid_count++;
        }
		memset(str,NULL,0);
	}
	fclose(f);
	memset(str,NULL,0);
	itoa(valid_count,str,100);
	strcat(str,"*");
	fputs(str,fp);
	fclose(fp);
	return 0;
}
