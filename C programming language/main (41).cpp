#include<stdio.h>
int main()
{
    int M, N, x, i, sum, count;
    scanf("%d %d ", &M, &N);
    
    x = M;
    sum = 0;
    count = 0;
    while(x <= N)
    {
        for(i = 2;i <=x;i++)
        {
            if(x%i == 0)
            break;
            else 
            ;
        }
        if(i == x)
        {
        	sum+= x;
    		count++;
		}
       
        if(x == 1)
        ;
        x++;
    }
    printf("%d %d\n", count, sum);
    return 0;
}
