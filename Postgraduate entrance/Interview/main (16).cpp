#include <iostream>

/* ����������ݣ�ÿ�����ݰ��������������ֱ��ʾ�����������������֮����������е����֡�������Ҫ����þ����ת�þ���

�����ʽ
��������������ݡ�

ÿ�����ݵĵ�һ�а����������� 
m
m �� 
n
n����ʾ�����������������

������ 
m
m �У�ÿ�а��� 
n
n ����������ʾ�����Ԫ�ء�

�������ļ���������EOF����ֹ��

�����ʽ
����ÿ�����ݣ������ת�þ���

ת�þ���������ʽΪ��ÿ�� 
m
m ���������� 
n
n �У�����֮���ÿո�ָ���

run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int m, n = 0;
	scanf("%d %d",&m,&n);
	int array[m][n] = {'0'};
	int array_T[n][m] = {'0'};
	for(int i = 0;i<m;i++){
		for(int j = 0;j<n;j++){
			scanf("%d",&array[i][j]);
		} 
	} 
	for(int i = 0;i<m;i++){
		for(int j = 0;j<n;j++){
			array_T[j][i] = array[i][j];
		} 
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			printf("%d ",array_T[i][j]);
		} 
		printf("\n");
	} 
	return 0;
}
