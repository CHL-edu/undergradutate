#include <stdio.h>
#include <stdlib.h>

#define kMaxSize 100

typedef int ElemSet;
typedef int Position;  /* 整型下标，表示元素的位置 */
typedef struct ArrNode *ArrPtr;
struct ArrNode {
    ElemSet *data; /* 存储数据的数组；ElemSet是用户定义的数据类型 */
    int size;      /* 数组的大小 */
};

bool DecrSeqInsert( ArrPtr array, ElemSet x );

int main(void)
{
    int i, n;
    ArrPtr array;
    ElemSet x;
    
    array = (ArrPtr)malloc(sizeof(struct ArrNode));
    scanf("%d", &n);
    array->size = n;
    array->data = (int *)malloc(sizeof(int) * kMaxSize);
    for (i=0; i<n; i++) {
        scanf("%d", &array->data[i]);
    }
    scanf("%d", &x);
    if (DecrSeqInsert(array, x) == false) {
        printf("Insertion failed.\n");
    }
    printf("%d", array->data[0]);
    for (i=1; i<array->size; i++) {
        printf(" %d", array->data[i]);
    }
    printf("\n");
    printf("Array size = %d\n", array->size);
    
    return 0;
}
/* 你的代码将被嵌在这里 */
bool DecrSeqInsert( ArrPtr array, ElemSet x ){
	int roll = 0;
	for(roll= 0;array->data[roll]>0;roll++){
		if(array->data[roll]==x){
			return false;
		}
	}
	if(roll >= array->size+1){
		return false;
	}
	if(roll<=array->size){
		array->size++;
		return true;
	}
}
