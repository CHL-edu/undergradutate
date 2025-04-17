#include <iostream>
#include <stdio.h>
#include <stdlib.h>
/* 输入9个浮点数，求其中的最大值。输入的浮点数不能超过1e8（10的8次方），且输出结果要保留小数点后两位。

输入格式
输入包含9个浮点数，每个数之间用空格隔开。

输出格式
输出一个浮点数，表示输入的9个数中的最大值，保留小数点后两位。
run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	float *num = (float *)malloc(10*sizeof(float));
    for (int i = 0; i < 9; i++) {
        scanf("%f", &num[i]);
    }
	float max = num[0];
	for(int i = 0;i<17;i+=2){
		if(max<=num[i]){
			max = num[i];
		}
	}
	printf("%.2f",max);
	return 0;
}
