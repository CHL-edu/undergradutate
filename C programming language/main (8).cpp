#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;

    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

/* 你的代码将被嵌在这里 */

int IsTheNumber ( const int N )
{
    int sqrt_N;
    int flag1 = 0;
    int flag2 = 0;
    char a[1000];
    int count = 0;
    int n = N;
    
    sqrt_N = sqrt(N);
    if(N == sqrt_N*sqrt_N)
        flag1 = 1;
    for(int i = 0; n!= 0;i++)
    {
        a[i] = n%10;
        n/= 10;
        count++;
    }
    for(int i = 0;i<count;i++)
        for(int j = i+1; j<count;j++)
        {
            if(a[i] == a[j])
                flag2 = 1;
        }
    if(N==0)
        flag2 = 0;
    if(flag1 == 1&&flag2 ==1)
        return 1;
    else
        return 0;
}
