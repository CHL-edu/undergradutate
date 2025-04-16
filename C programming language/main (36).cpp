#include<stdio.h>
int main ()
{
    int N, K;
    int a[100];
    
    scanf("%d %d", &N, &K);
    
    for (int k = 0;k<N;k++)
        scanf("%d", &a[k]);
    
    for(int j =0; j< K; j++)
        for(int i = 0; i<N-1; i++)
        {
            if(a[i]>a[i+1])
            {
                int step;
                step = a[i];
                a[i]=a[i+1];
                a[i+1]=step;
            }
        }
    for(int t=0;t<N-1;t++)
        printf("%d ",a[t]);
        printf("%d", a[N-1]) ;
    return 0;
}
