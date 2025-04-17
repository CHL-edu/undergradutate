#include <stdio.h>
#include <stdlib.h>

typedef int ElemSet;
typedef struct ListNode *Position; /* 指针即结点位置 */
struct ListNode {
    ElemSet data;  /* 存储数据*/
    Position next; /* 线性表中下一个元素的位置 */
};
typedef struct HeadNode *List;
struct HeadNode {
    Position head; /* 单链表头指针 */
    int length;    /* 表长 */
};

void Insert (List list, int i, ElemSet x);
void Remove ( List list, int i );

int main(void)
{
    int i, n, x;
    Position p;
    List list;
    
    list = (List)malloc(sizeof(struct HeadNode));
    list->head = (Position)malloc(sizeof(struct ListNode)); /* 创建空头结点 */;
    list->head->next = NULL;
    list->length = 0;
    scanf("%d: ", &n);
    for (i=1; i<=n; i++) {
        scanf("%d", &x);
        Insert(list, i, x);
    }
    scanf("%d", &i);
    if (scanf("%d", &x)!=EOF) {
        Insert(list, i, x);
    }
    else {
        Remove(list, i);
    }
    printf("%d:", list->length);
    p = list->head->next;
    while (p != NULL) {
        printf(" %d", p->data);
        p = p->next;
    }
    return 0;
}
/* 你的代码将被嵌在这里 */
void Insert(List list, int i, ElemSet x) {
    // 检查插入位置是否合法
    if (i < 1 || i > list->length + 1) {
        return; // 插入位置不合法，直接返回
    }

    // 创建新结点
    Position newNode = (Position)malloc(sizeof(struct ListNode));
    newNode->data = x;
    newNode->next = NULL;

    // 找到第 i-1 个结点
    Position p = list->head;
    for (int j = 0; j < i - 1; j++) {
        p = p->next;
    }

    // 插入新结点
    newNode->next = p->next;
    p->next = newNode;

    // 更新表长
    list->length++;
}
void Remove(List list, int i) {
    // 检查删除位置是否合法
    if (i < 1 || i > list->length) {
        return; // 删除位置不合法，直接返回
    }

    // 找到第 i-1 个结点
    Position p = list->head;
    for (int j = 0; j < i - 1; j++) {
        p = p->next;
    }

    // 删除第 i 个结点
    Position temp = p->next; // temp 指向第 i 个结点
    p->next = temp->next;   // 将第 i-1 个结点的 next 指向第 i+1 个结点
    free(temp);             // 释放第 i 个结点的内存

    // 更新表长
    list->length--;
}
