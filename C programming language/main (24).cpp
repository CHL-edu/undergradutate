#include<stdio.h>
#include<string.h>
int main ()
{
    char s[1001];
    gets(s);
    char x;
    int i = 0;
    int m = 0;
    int flag = 0;
    
    while(s[i] != '\0')
    {
        x = s[i];
        for(m = i+1; s[m] != '\0';m++)
            {
			if(s[m] == x)
                    {
                    	if(flag  <= (m-i+1))
							flag  = m-i+1;
							break;
					}
            }
            i++;
    }
    if(flag == 0)
    printf("1");
    else
    if(flag == 2)
    printf("%d", strlen(s));
    printf("%d", flag);
    return 0;
}
