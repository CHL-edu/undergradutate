#include <iostream>
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
/* ��дһ��C���Գ���ʵ�����¹��ܣ�

��������ַ����е�����Сд��ĸת��Ϊ��д��ĸ��

ͳ�������ַ��������֡���ĸ������ת����Ĵ�д��ĸ�����������ţ�������š��ո�ȣ��ĸ�����

�����ʽ��

һ���ַ��������Ȳ�����100��

�����ʽ��

��һ�����ת������ַ�����

�ڶ������ͳ�ƽ������ʽΪ����ĸ���� ���ָ��� ���Ÿ���

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
