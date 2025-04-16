#include <stdio.h>
#include <string.h>

#define MAXN 20

bool palindrome( char *s );

int main()
{
    char s[MAXN];

    scanf("%s", s);
    if ( palindrome(s)==true )
        printf("Yes\n");
    else
        printf("No\n");
    printf("%s\n", s);

    return 0;
}

/* 你的代码将被嵌在这里 */



bool palindrome( char *s )
{
    int count = 0;
    int i = 0;
    
    for(count = 0;*(s + count )!= '\0';count++);
    
    if(count%2 != 0)
    {
        for(i = 0; i<count/2 ; i++)
        {
            if(*(s +count/2+ i) != *(s +count/2-i))
                break;
        }
        if(i == count/2)
            return true;
        else
            return false;
    }
    else
    {
        for(i = 0; i<count/2 ; i++)
        {
            if(*(s +count/2-i-1) != *(s +count/2+i))
                break;
        }
        if(i == count/2)
            return true;
        else
            return false;
    }
}
