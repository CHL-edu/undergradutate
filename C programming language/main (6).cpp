#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
//struct ListNode *deletem( struct ListNode *L, int m );

int main()
{
    //int m;
    struct ListNode *L = readlist();
    //scanf("%d", &m);
    //L = deletem(L, m);
	for(int i = 0;i<5;i++)
	{
		printf("%d\n",L->data);
		L=L->next;
		
	}

    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode *readlist()
{
	struct ListNode *head, *justhead;
	head = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *HHHH;
	HHHH = head;
	justhead = head;
	scanf("%d", &head->data);
	while(head->data != -1)
	{	
		head = (struct ListNode *)malloc(sizeof(struct ListNode));
		justhead->next = head;
		justhead = head;
		scanf("%d", &head->data);
	}
	head = NULL;
	return HHHH;
}

//struct ListNode *deletem( struct ListNode *L, int m ) *HHHH->next->date


