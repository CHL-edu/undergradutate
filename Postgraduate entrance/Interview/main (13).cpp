#include <iostream>
#include<stdio.h>
#include<stdlib.h> 

/* 根据描述，生成题目与测试点：问题描述

给你一个年份，还有一个数字n，以1月1日为第一天，然后你根据n的值来求出是几月几号。

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
