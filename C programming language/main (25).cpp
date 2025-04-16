#include<stdio.h>
#include<string.h>
int main ()
{
    char s[101];
    char s1[101];
    int N = 0;
    int count = 1;
    int length = 0;
    
    gets(s);
    strcpy(s1,s);
    scanf("%d", &N);
    length = strlen(s);
    while(count <= N)
    {
        for(int k = 0; k<length;k++)
            s[k]=s[k+1];
        s[length-1] = s1[0];
        strcpy(s1,s);
        count++;
    }
    printf("%s", s);
    return 0;
}
