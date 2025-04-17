#include <stdio.h>
#include <stdlib.h>

typedef int ElemSet;
typedef struct ListNode *Position; /* ָ�뼴���λ�� */
struct ListNode {
    ElemSet data;  /* �洢����*/
    Position next; /* ���Ա�����һ��Ԫ�ص�λ�� */
};
typedef struct HeadNode *List;
struct HeadNode {
    Position head; /* ������ͷָ�� */
    int length;    /* �� */
};

void Insert (List list, int i, ElemSet x);
void Remove ( List list, int i );

int main(void)
{
    int i, n, x;
    Position p;
    List list;
    
    list = (List)malloc(sizeof(struct HeadNode));
    list->head = (Position)malloc(sizeof(struct ListNode)); /* ������ͷ��� */;
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
/* ��Ĵ��뽫��Ƕ������ */
void Insert(List list, int i, ElemSet x) {
    // ������λ���Ƿ�Ϸ�
    if (i < 1 || i > list->length + 1) {
        return; // ����λ�ò��Ϸ���ֱ�ӷ���
    }

    // �����½��
    Position newNode = (Position)malloc(sizeof(struct ListNode));
    newNode->data = x;
    newNode->next = NULL;

    // �ҵ��� i-1 �����
    Position p = list->head;
    for (int j = 0; j < i - 1; j++) {
        p = p->next;
    }

    // �����½��
    newNode->next = p->next;
    p->next = newNode;

    // ���±�
    list->length++;
}
void Remove(List list, int i) {
    // ���ɾ��λ���Ƿ�Ϸ�
    if (i < 1 || i > list->length) {
        return; // ɾ��λ�ò��Ϸ���ֱ�ӷ���
    }

    // �ҵ��� i-1 �����
    Position p = list->head;
    for (int j = 0; j < i - 1; j++) {
        p = p->next;
    }

    // ɾ���� i �����
    Position temp = p->next; // temp ָ��� i �����
    p->next = temp->next;   // ���� i-1 ������ next ָ��� i+1 �����
    free(temp);             // �ͷŵ� i �������ڴ�

    // ���±�
    list->length--;
}
