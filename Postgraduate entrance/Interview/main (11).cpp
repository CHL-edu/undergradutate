#include <iostream>
#include<stdio.h>
/* ����������
����һ�������� n������Ҫ�ҵ����п��ܵ��������������У�ʹ����Щ���еĺ͵��� n��ÿ���������ٰ�����������

�����ʽ��

һ������ n��1 �� n �� 10^6����

�����ʽ��

ÿ�����һ�������������������������У������е������������У�������֮�䰴��һ�������������С�

���û���������������У���� None��
run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int input = 0;
	scanf("%d",&input);
	int count = 1;
	int sum  = 0;
	int flag  = 0;
	for(int j=1;j<=input/2;j++){
		for(int i = j;i<=input/2+1;i++){
			if(input==sum+i){
				flag = 1;
				for(int k = j;k<j+count-1;k++) printf("%d+",k);
				printf("%d\n",j+count-1);	
			}
			sum+=i;
			count++;
		} 
		sum = 0;
		count = 1;
	}
	if(flag!=1)
		printf("None");		
	return 0;
}
