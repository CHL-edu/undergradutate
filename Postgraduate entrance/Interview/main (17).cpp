#include <iostream>
#include <stdio.h>
#include <stdlib.h>
/* ����9���������������е����ֵ������ĸ��������ܳ���1e8��10��8�η�������������Ҫ����С�������λ��

�����ʽ
�������9����������ÿ����֮���ÿո������

�����ʽ
���һ������������ʾ�����9�����е����ֵ������С�������λ��
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
