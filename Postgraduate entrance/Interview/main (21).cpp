#include <stdio.h>
#include <stdlib.h>

#define kMaxSize 10
#define NotFound -1

typedef int ElemSet;
typedef int Position;  /* �����±꣬��ʾԪ�ص�λ�� */
typedef struct ArrNode *ArrPtr;
struct ArrNode {
    ElemSet *data; /* �洢���ݵ����飻ElemSet���û�������������� */
    int size;      /* ����Ĵ�С */
};

Position BinarySearch( ArrPtr array, ElemSet x );

int main(void)
{
    int i, n;
    ArrPtr array;
    ElemSet x;
    
    array = (ArrPtr)malloc(sizeof(struct ArrNode));
    scanf("%d", &n);
    array->size = n;
    array->data = (int *)malloc(sizeof(int)*array->size); 
    for (i=0; i<n; i++) {
        scanf("%d", &array->data[i]);
    }
    scanf("%d", &x);
    printf("%d\n", BinarySearch(array, x));
    return 0;
}
/* ��Ĵ��뽫��Ƕ������ */
Position BinarySearch( ArrPtr array, ElemSet x ){
	int low_num = 0;
	int hig_num = array->size;
	int mid  = low_num;
	int flag = 0;

	while(low_num<=hig_num){
		mid =low_num+(-low_num+hig_num)/2;
		if(array->data[mid]==x)	{
			return mid;
		}
		if(array->data[mid]<x){
			low_num =mid+1 ;
		}
		if(array->data[mid]>x){
			hig_num = mid-1;
		}

		
	}
	return -1;
}

