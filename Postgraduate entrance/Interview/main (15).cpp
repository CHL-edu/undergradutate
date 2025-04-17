#include <iostream>
#include <stdio.h>
#include <stdlib.h>
/* 给你一串数字，实现其排序，然后将排序后重复的数字只留下一个。即对输入的数字进行去重并输出排序后的结果。

输入格式
输入包含一串数字，数字之间用空格分隔。

输出格式
输出排序后的数字序列，重复的数字只保留一个，数字之间用空格分隔。
run this program using the console pauser or add your own getch, system("pause") or input loop */
void Bubblesort(int *str,int size){
	for(int i = 0;i<size;i++){
		for(int j = i;j<size;j++)
		if(str[i]<=str[j]){
			int temp = str[i];
			str[i] = str[j];
			str[j] = temp;
		}
	}
}

int Doubledelet(int *str,int size){
	for(int i = 0;i<size;i++){
		for(int j =i+1;j<size;j++)
		if(str[i]==str[j]){
			for(int k = j;k<size;k++){
				str[k] = str[k+1];
			}
			size--;
		}
	}
	return size;
}
int main(int argc, char** argv) {
	int *array = (int *)malloc(10*sizeof(int));
	int array_in =0;
	do{
		scanf("%d",&array[array_in]);
		array_in++;
	}while(getchar()!='\n');
	
	Bubblesort(array,array_in);
	
	array_in = Doubledelet(array,array_in);
	
	for(int i = 0;i<array_in-1;i++){
		printf("%d ",array[i]);
	}
	printf("%d",array[array_in-1]);
	return 0;
}
