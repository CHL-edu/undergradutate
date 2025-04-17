#include <iostream>
#include<stdio.h>
/* 问题描述：
给定一个正整数 n，你需要找到所有可能的连续正整数序列，使得这些序列的和等于 n。每个序列至少包含两个数。

输入格式：

一个整数 n（1 ≤ n ≤ 10^6）。

输出格式：

每行输出一个满足条件的连续正整数序列，序列中的数按升序排列，且序列之间按第一个数的升序排列。

如果没有满足条件的序列，输出 None。
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
