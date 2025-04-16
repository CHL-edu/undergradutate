#include<stdio.h>
struct information {
    char number[5];
    char name[10];
    int score[3];
}student[10], brilliant;

int main ()
{
    int N;
    scanf("%d", &N);
    
    for(int i=0;i<N;i++)
    {
    	for(int k = 0;k<5;k++)
		{
			scanf("%c",&student[i].number[k]);
			if(student[i].number[k] == '\n')
			k--;
		}
        scanf("%s", student[i].name);
        for(int j = 0;j<3;j++)
            scanf("%d",&student[i].score[j]);
    }
    
    brilliant = student[0];
    for(int i = 0;i<N;i++)
    {
        if((brilliant.score[0]+brilliant.score[1]+brilliant.score[2])<=( student[i].score[0]+student[i].score[1]+student[i].score[2]))
            brilliant = student[i];
    }
    
    printf("%s ",brilliant.name);
    for(int i = 0;i<5;i++)
        printf("%c",brilliant.number[i]);
    printf(" %d",brilliant.score[0]+brilliant.score[1]+brilliant.score[2]);
        
    return 0;
}
