#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

/*
����һ�����������ʶ�����ļ� abc.in�����ж������ж��ٸ��Ϸ��ı�ʶ�����Ϸ��ı�ʶ����Ҫ���� C ���Եı�ʶ���������

��ʶ��ֻ������ĸ��a-z, A-Z�������֣�0-9�����»��ߣ�_����ɡ�

��ʶ���ĵ�һ���ַ����������֡�

��ʶ�����ܰ����ո�����������ַ����� @, #, -, . �ȣ���

�����ʽ:
�ļ� abc.in ���������У�ÿ��һ����ʶ����

�����ʽ:
���һ����������ʾ�Ϸ���ʶ����������

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
