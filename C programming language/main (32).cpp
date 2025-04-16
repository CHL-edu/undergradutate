#include<stdio.h>
#include<math.h>
int main()
{
    int x;
    int y;
    int sum = 0; 
    int leng = 8;
    char s[35];
	for(int i = 0; i<32;i++)
		scanf("%c", &s[i]);
    int count = 0;
    int k = 0;
    
    while(count < 32)
    {
        for(k = count;k-count < leng;k++)
        {
            if(s[k] == 49)
            {
                sum+=pow(2,leng - 1 -k+count);
            }
        }
        if(count < 24)
            printf("%d.",sum);
        else
            printf("%d",sum);
        sum = 0;
        count+=8;
    }
    return 0;
}
