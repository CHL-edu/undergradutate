#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist();
struct ListNode *deleteeven( struct ListNode *head );
void printlist( struct ListNode *head )
{
     struct ListNode *p = head;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode *head,*p;

    head = createlist();
    head = deleteeven(head);
	for ( p = head; p != NULL; p = p->next )
        printf("%d\n", p->data);

    return 0;
}

/* 你的代码将被嵌在这里 */


struct ListNode *createlist()
{
	struct ListNode *N;
	N = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *pp;
    pp = (struct ListNode *)malloc(sizeof(struct ListNode));
	N->next = pp;
	scanf("%d", &pp->data);
	if(pp->data == -1)
	{
		return N;
	}
    while(pp->data != -1)
    {
        pp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        pp = pp->next;
        pp->next = NULL;
        scanf("%d", &pp->data);
    }
    pp = NULL;
    return N;
}



struct ListNode *deleteeven( struct ListNode *head )
{
    struct ListNode *pnew = head->next,*prior = head;
    while(prior->data != -1&&pnew->data != -1)
    {
    	if(pnew->data%2 == 0)
    	{
    		prior->next = pnew->next;
    		pnew = pnew->next;
		}
		if(pnew->data%2 != 0&&pnew->data != -1)
		{
			prior = prior->next;
			pnew = pnew->next;
		}
	}
	prior->next = NULL;
	if(prior->data == -1)
	{
		prior = NULL;
	}
	return head->next;
}
