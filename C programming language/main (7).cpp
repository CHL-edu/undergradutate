#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist();

int main()
{
    struct ListNode *p, *head = NULL;

    head = createlist();
    for ( p = head; p != NULL; p = p->next )
        printf("%d ", p->data);
    printf("\n");

    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode *createlist()
{
	struct ListNode *pp,*p;
	pp = (struct ListNode *)malloc(sizeof(struct ListNode));
	p = (struct ListNode *)malloc(sizeof(struct ListNode));
	scanf("%d",&pp->data);
	pp->next = NULL;
	p->next = pp;
	scanf("%d",&p->data);
	while(p->data !=-1)
	{
		pp = p;
		p = (struct ListNode *)malloc(sizeof(struct ListNode));
		p->next = pp;
		scanf("%d",&p->data);
	}
	return pp;
}

