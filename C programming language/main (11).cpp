#include <stdio.h>
#define MAXN 20

void strmcpy( char *t, int m, char *s );


int main()
{
    char t[MAXN], s[MAXN];
    int m =14;
	for(int k = 0;;k++)
	 {
	 scanf("%c", &t[k]);
	 if(t[k] == '\n')
	 {	
	 	t[k] = '\0';
	 	break;
	 }
	 }
    strmcpy( t, m, s );
    printf("%s\n", s);

    return 0;
}

/* 你的代码将被嵌在这里 */
#include<string.h>
void strmcpy( char *t, int m, char *s )
{
    int i=0;
    int k = 0;
    int flag = 0;
    for(i=0;t[i] !='\0';i++);
    if(m>i)
    {
        s=NULL;
        flag = 1;
    }
    if(m == i)
    {
    	s[0] = t[m-1];
    	flag = 1;
	}
	if(flag == 0)
    {
	for(int j = 0; j < i ; j++)
    {
    		if(j>=m-1)
    		{
    			s[k] = t[j];
    			k++;
			}
    }	
	}
}
