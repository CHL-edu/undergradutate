#include <iostream>
#include<stdio.h>
#include<stdlib.h> 

/* ����������������Ŀ����Ե㣺��������

����һ����ݣ�����һ������n����1��1��Ϊ��һ�죬Ȼ�������n��ֵ������Ǽ��¼��š�

run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int year,days = 0;
	scanf("%d %d",&year,&days);
	
	int flag_Feb = 0;
	if(year%4==0&&year%100!=0) flag_Feb = 1;
	
	int compare[2][12]={{1,2,3,4,5,6,7,8,9,10,11,12},
						{31,28+flag_Feb,31,30,31,30,31,31,30,31,30,31}};
	
	int month = 1;
	int day   = 1;
	int count = 0;
	for(int i = 1;i<=12;i++){
		if(days<=count+compare[1][i-1]){
			month = i;
			day   =  days - count;
			break;
		}
		count+=compare[1][i-1];
	}
	if(month<10)
		printf("0%d %d",month,day);
	else
		printf("%d %d",month,day);
	return 0;
}
