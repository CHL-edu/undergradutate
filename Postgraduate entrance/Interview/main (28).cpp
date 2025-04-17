#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node {
    int Data; /* 存储结点数据 */
    PtrToNode Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

int FactorialSum( List L );

int main()
{
    int N;
    List L, p;

    scanf("%d", &N);
    L = NULL;
    for (int i=0; i<N; i++ ) {
        p = (List)malloc(sizeof(struct Node));
        scanf("%d", &p->Data);
        p->Next = L;  L = p;
    }
    printf("%d\n", FactorialSum(L));

    return 0;
}

/* 你的代码将被嵌在这里 */
int Fac(int x){
	int factorial = 1;
    for (int i=1; i<=x; i++ ) {
		factorial *= i;
    } 
    return factorial;
}
int FactorialSum( List L ){
	int sum = 0;
	while(1){
		if(!L) break;
		sum+=Fac(L->Data);
		if(L->Next==NULL) break;
		L = L->Next;	
	}
    return sum;
}
