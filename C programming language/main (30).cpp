#include <stdio.h>
#define MAXN 10

void f( long int x, char *p );

int main()
{
    long int x;
    char s[MAXN] = "";

    scanf("%ld", &x);
    f(x, s);
    printf("%s\n", s);

    return 0;
}

/* 你的代码将被嵌在这里 */





void f( long int x, char *p )
{
  int i;
  int m;
  if (x<0)
  {
     x = -x;
     *p = '-';
     p ++;
  }
  if (x==0)
     *p = '0';
  for (i=0; i<MAXN; i++)
  {
     m = x % 16;
     x = x / 16;
     if (m<MAXN)
        *(p + MAXN - 1 -i) = m + '0';
     else
        *(p + MAXN - 1 -i) = m + 'A' - 10;
     if (x==0)
     {
        m = MAXN - 1 -i;
        break;
     }
  }
  for (i=0; i<MAXN-m; i++)
  {
     *(p + i) = *(p + m + i);
     *(p + m + i) = 0;
  }
}

