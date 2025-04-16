#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *getodd( struct ListNode **L );
void printlist( struct ListNode *L )
{
     struct ListNode *p = L;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode *L, *Odd;
    L = readlist();
    Odd = getodd(&L);
	for ( p = head; p != NULL; p = p->next )
        printf("%d %s %d\n", p->num, p->name, p->score);

    return 0;
}

/* 你的代码将被嵌在这里 */

struct ListNode *readlist()
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
    return N->next;
}





struct ListNode *getodd( struct ListNode **L )
{
    struct ListNode*prior = L,  *pnew = L;
    struct ListNode *out;
    out = (struct ListNode *)malloc(sizeof(struct ListNode));
    if(*L->data &2 != 0)
        out->data = *L->data;
        out->next = (struct ListNode *)malloc(sizeof(struct ListNode))
        out = out->next;
        
        *L = *L->next;
    }
    
        prior = *L;
        pnew = prior->next;
     while(pnew->data !=-1)
        {
            for(;pnew->data %2 != 0;)
        {
            out->data = pnew->data;
            out->next = (struct ListNode *)malloc(sizeof(struct ListNode))
            out = out->next;
            
            pnew = pnew->next;
            prior->next = pnew;
        }
            prior  = pnew;
            pnew = pnew->next;
        }
    return out;
}
