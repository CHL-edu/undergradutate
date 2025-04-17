#include <iostream>
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
/* 编写一个C语言程序，实现以下功能：

将输入的字符串中的所有小写字母转换为大写字母。

统计输入字符串中数字、字母（包括转换后的大写字母）和其他符号（如标点符号、空格等）的个数。

输入格式：

一行字符串，长度不超过100。

输出格式：

第一行输出转换后的字符串。

第二行输出统计结果，格式为：字母个数 数字个数 符号个数

run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char *str = (char*)malloc(10*sizeof(char));
	gets(str);
	int count_num = 0;
	int count  = strlen(str);
	int count_a   = 0;
	for(int i = 0;str[i]!='\0';i++){
		if(str[i]>='0'&&str[i]<='9'){
			count_num++;
		}
		if(str[i]>='a'&&str[i]<='z'){
			str[i]+='A'-'a';
			count_a++;
		}
		else
			if(str[i]>='A'&&str[i]<='Z'){
				count_a++;
			}
	}
	printf("%s\n",str);
	printf("%d %d %d\n",count_a,count_num,count-count_a-count_num);	
	
	return 0;
}
