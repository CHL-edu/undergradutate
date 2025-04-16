#include<stdio.h>
#include<string.h>
int main ()
    {
	char a[100][100];
    int lenght[100];
    for(int i = 0;a[i][0] != EOF;i++)
        for(int j= 0;;j++)
        {
            char x = getchar();
            if(x == EOF)
            goto loop;
            a[i][j] = x;
            if(x == '\n')
            {
                a[i][j] = '\0';
                break;
            }
        }
        loop:
    int i;
    for(i = 0;a[i][0] != '\0';i++)
        lenght[i] = strlen(a[i]);
    int y= lenght[0];
    for(int j =0;j<i;j++)
    {
        if(y<lenght[j])
            y = lenght[j];
    }
    int count;
    for(int j =0;j<i;j++)
    {
        if(y==lenght[j])
            count = j;
    }
    printf("%s",a[count]);
    return 0;
}
