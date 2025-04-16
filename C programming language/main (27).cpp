#include<stdio.h>
#include<string.h>
int main()
{
    int repeat = 0;
    int ncount = 0;
    int m = 0;
    int flag =0;
    scanf("%d", &repeat);
    char *p[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    char ch[10];
    
    while(ncount++ <= repeat)
    {
        gets(ch);
        for(m=0;m<7&&ch[0] != '\0'; m++)
            if(strcmp(ch,*(p+m)) == 0)
            {
                printf("%d\n", m+1);
                flag = 1;
            }
        if(m ==7&&flag == 0&&ch[0] != '\0')
            printf("-1\n");
            flag = 0;
    }
    
    return 0;
}
