#include <iostream>

/* 输入多组数据，每组数据包含两个整数，分别表示矩阵的行数和列数。之后输入矩阵中的数字。程序需要输出该矩阵的转置矩阵。

输入格式
输入包含多组数据。

每组数据的第一行包含两个整数 
m
m 和 
n
n，表示矩阵的行数和列数。

接下来 
m
m 行，每行包含 
n
n 个整数，表示矩阵的元素。

输入以文件结束符（EOF）终止。

输出格式
对于每组数据，输出其转置矩阵。

转置矩阵的输出格式为：每行 
m
m 个整数，共 
n
n 行，整数之间用空格分隔。

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
