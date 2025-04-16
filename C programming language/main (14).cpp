#include <stdio.h>
#include <stdlib.h>

struct stud_node {
     int    num;
     char   name[20];
     int    score;
     struct stud_node *next;
};

struct stud_node *createlist();
struct stud_node *deletelist( struct stud_node *head, int min_score );

int main()
{
    int min_score;
    struct stud_node *p, *head = NULL;

    head = createlist();
    scanf("%d", &min_score);
    head = deletelist(head, min_score);
    for ( p = head; p != NULL; p = p->next )
        printf("%d %s %d\n", p->num, p->name, p->score);

    return 0;
}

/* 你的代码将被嵌在这里 */



struct stud_node *createlist()
{
	struct stud_node *N;
	N = (struct stud_node *)malloc(sizeof(struct stud_node));
    struct stud_node *pp;
    pp = (struct stud_node *)malloc(sizeof(struct stud_node));
	N->next = pp;
	scanf("%d", &pp->num);
	if(pp->num == 0)
	{
		return N;
	}
    while(pp->num != 0)
    {
        scanf("%s%d",pp->name, &pp->score);
        pp->next = (struct stud_node *)malloc(sizeof(struct stud_node));
        pp = pp->next;
        pp->next = NULL;
        scanf("%d", &pp->num);
    }
    return N;
}



struct stud_node *deletelist( struct stud_node *head, int min_score )
{
    struct stud_node *pnew = head->next,*prior = head;
    while(pnew->num != 0)
    {
    	if(pnew->score < min_score)
    	{
    		prior->next = pnew->next;
    		pnew = pnew->next;
		}
		if(pnew->score >= min_score&&pnew != NULL)
		{
			prior = prior->next;
			pnew = pnew->next;
		}
	}
	prior->next = NULL;
	return head->next;
}
