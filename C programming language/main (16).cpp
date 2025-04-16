#include<stdio.h>
struct information{
    char name[30];
    double number[1];
}Book[10], maxtemp, mintemp;

int main ()
{
    int N;
    int flag = 0;
    scanf("%d", &N);
    for(int i =0;i<N;i++)
    {
        for(int k = 0,flag = 0;flag !=2;k++)
		{
			scanf("%c",&Book[i].name[k]);
			if(Book[i].name[k] == '\n')
			{
				k--;
				flag++;
			}
			
		}
        scanf("%lf",&Book[i].number[0]);
    }
    
    maxtemp.number[0] = Book[0].number[0];
    for(int nmax = 0; nmax<N;nmax++)
    {
        if(maxtemp.number[0] <= Book[nmax].number[0])
            maxtemp = Book[nmax];
    }
    
    mintemp.number[0] = Book[0].number[0];
    for(int nmin = 0; nmin<N;nmin++)
    {
        if(mintemp.number[0] >= Book[nmin].number[0])
            mintemp = Book[nmin];
    }
    
    printf("%.2lf, %s",maxtemp.number[0],maxtemp.name);
    printf("%.2lf, %s",mintemp.number[0],mintemp.name);
    
    return 0;
}
