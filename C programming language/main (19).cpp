#include <stdio.h>
#define MAXN 10

struct student{
    int num;
    char name[20];
    int score;
    char grade;
};

int set_grade( struct student *p, int n );

int main()
{   struct student stu[MAXN], *ptr;
    int n, i, count;

    ptr = stu;
    scanf("%d\n", &n);
    for(i = 0; i < n; i++){
       scanf("%d%s%d", &stu[i].num, stu[i].name, &stu[i].score);
    } 
   count = set_grade(ptr, n);
   printf("The count for failed (<60): %d\n", count);
   printf("The grades:\n"); 
   for(i = 0; i < n; i++)
       printf("%d %s %c\n", stu[i].num, stu[i].name, stu[i].grade);
    return 0;
}



int set_grade( struct student *p, int n )
{
    int nn = 0;
   
    for(int i = 0; i < n ;i++)
    {
        if((p->score) <=100&&(p->score )>=85)
            p->grade = 'A';
        if((p->score )<=84&&(p->score ) >=70)
            p->grade = 'B';
        if((p->score ) <=69&&(p->score ) >=60)
            p->grade = 'C';
        if((p->score ) <=59&&(p->score ) >=0)
        {
            p->grade = 'D';
            nn ++;
        }
        p++;
    }
    return nn;
}
