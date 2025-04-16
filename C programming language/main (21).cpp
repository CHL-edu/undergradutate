#include <stdio.h>

#define MAXS 10

char *match( char *s, char ch1, char ch2 );

int main()
{
    char str[MAXS], ch_start, ch_end, *p;

    scanf("%s\n", str);
    scanf("%c %c", &ch_start, &ch_end);
    p = match(str, ch_start, ch_end);
    printf("%s\n", p);

    return 0;
}

/* 你的代码将被嵌在这里 */


char *match( char *s, char ch1, char ch2 )
{
    int count = 0;
    int i = 0;
    int j = 0;
    for(count = 0;*(s + count )!= '\0';count++);
    for(i = 0; i < count ;i++)
    {
        if(*(s + i ) == ch1)
            break;
    }
    if(i == count)
    {
        printf("\n");
        return s+i;
    }
    for(j = 0; j < count ;j++)
    {
        if(*(s + j ) == ch2)
            break;
    }
    if(j == count)
    {
        for(int k = i; k < count; k++)
            printf("%c", *(s + k));
        printf("\n");
        return s+i;
    }
    else
    {
        if(i > j)
            {
            printf("\n");
            return s+i;
            }
        else
        {
            for(int k = i; k <= j; k++)
                printf("%c", *(s + k));
            printf("\n");
            return s+i;
        }
    }
    
}
