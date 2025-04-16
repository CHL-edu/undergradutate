#include<stdio.h>
struct information {
    char name[10];
    int birthday[8];
    char phonenumber[18];
}people[10], temp;

int main()
{
    int N;
    scanf("%d", &N);
    
    for(int i = 0; i<N; i++)
    {
        scanf("%s", people[i].name);
        scanf("%d", people[i].birthday);
        scanf("%s", people[i].phonenumber);
    }
    for(int m = 0;m < N;m++)
        for(int n = 0; n < N;n++)
        {
            if(people[n].birthday[0] > people[n+1].birthday[0])
            {
				if(n+1 < N)
					{
					temp = people[n];
                	people[n] = people[n+1];
                	people[n+1] = temp;
                	}
            }
        }
    for(int m = 0;m < N;m++)
    	printf("%s %d %s\n", people[m].name, people[m].birthday[0],people[m].phonenumber);
    return 0;
}
