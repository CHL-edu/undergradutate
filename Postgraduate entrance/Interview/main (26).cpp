#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median( ElementType A[], int N );

int main ()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    return 0;
}

/* 你的代码将被嵌在这里 */
void BubbleSort(float *arr, int size) {
int i, j;
float tmp;
for (i = 0; i < size - 1; i++) {
for (j = 0; j < size - i - 1; j++) {
if (arr[j] > arr[j+1]) {
tmp = arr[j];
arr[j] = arr[j+1];
arr[j+1] = tmp;
}
}
}
}
ElementType Median( ElementType A[], int N ){
    float temp_A[N];
    float temp_Max[N];
    int max =0;
    int temp_N = 0;
	for(int i = 0;i<N;i++){
		temp_Max[i] = A[i];
	}
	BubbleSort(temp_Max,N);
	

    
    int middlenum =(N+1)/2;
	return temp_Max[middlenum-1];
}
