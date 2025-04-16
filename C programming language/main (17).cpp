




#include<stdio.h>
struct informatiion{
    char number[5];
    char name[10];
    int score[10];
}people[10],underpeople[10],temp;

int main ()
{
    double average = 0.0;
    int j = 0;
    int N;
    scanf("%d", &N);
    
    for(int i = 0;i<N;i++)
    {
    	for(int k = 0;k<5;k++)
		{
			scanf("%c",&people[i].number[k]);
			if(people[i].number[k] == '\n')
			k--;
		}
        scanf("%s%d",people[i].name,people[i].score);
	}
    for(int i = 0;i<N;i++)
        average+=people[i].score[0];
    average/=1.0*N;
    
    for(int i = 0;i<N;i++)
        {
            if(people[i].score[0] < average)
            {
                underpeople[j] = people[i];
                j++;
            }
        }
    
    for(int m = 0;m<j;m++)
        for(int n = 0;n<j;n++)
            if(underpeople[n].number[4] > underpeople[n+1].number[4])
            {
				if(n+1 < j)
					{
					temp = underpeople[n];
                	underpeople[n] = underpeople[n+1];
                	underpeople[n+1] = temp;
                	}
            }
    
    printf("%.2lf\n",average);
    for(int m = 0;m<j;m++)
		{
			printf("%s ",underpeople[m].name);
			for(int k = 0;k<5;k++)
			{
				printf("%c",underpeople[m].number[k]);
			}
			printf("\n");
		}
    
    return 0;
}
