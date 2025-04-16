#include <stdio.h>

int reverse( int number );

int main()
{
    int n;

    scanf("%d", &n);
    printf("%d\n", reverse(n));

    return 0;
}







int reverse( int number )
{
    int s, t , x, count, count2;
    count2 = 0;
    int lines[100];
    int linet[100];
    
    if(number<=0)
    for(s = 0,t =0; number !=0; count++,s++,number= number/10)
    {
        x = number%10;
        lines[s] = x;
    }
    
    for(int i = 0;i <= count; i++,s--)
       {
        int count2 = 0;
        if(lines[s]==0);
        else 
        {
            linet[i] = lines[s];
            count2++;
        }
       }
    if(number<0)
        printf("-");
    for(int i = 0;i <= count2; i++)
        printf("%d",linet[i]);
    return 0;
    
}
