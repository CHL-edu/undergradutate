#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void bublesort(int* ary,int len){
	for(int i = 0;i<len-1;i++){
		for(int j = 0;j<len-1-i;j++){
			if(ary[j] < ary[j+1]){
				int temp = ary[j];
				ary[j]   = ary[j+1];
				ary[j+1] = temp;
			}
		}
	}
}

int cmp(const void *a,const void *b){
	return (*(int*)b-*(int*)a);
}
int main(int argc, char** argv) {
	int* num = (int*)malloc(10*sizeof(int));
	int count = 0;
	memset(num,0,count);
	do{
		scanf("%d",&num[count]);
		count++;
	}while(getchar()!='\n'); 
	bublesort(num,count);
	//qsort(num,count,sizeof(int),cmp);
	for(int i = 0;i<count;i++){
		printf("%d*",num[i]);
	}
	free(num);
	
	return 0;
}
