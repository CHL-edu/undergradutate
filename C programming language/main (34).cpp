#include<stdio.h>
int main ()
{
    int N;
    int a[10];
    int step = 0;
    scanf("%d", &N);
    
        for(int t = 0; t < N; t++)
            scanf("%d", &a[t]);
    
    step = a[0];
        for(int t = 0; t < N; t++)
            if(step<=a[t])
                step = a[t];
    
        for(int t = 0; t<= N;t++)
            if(a[t] == step)
            {
                printf("%d %d\n", step, t);
                break;
            }
        
    return 0;
}
