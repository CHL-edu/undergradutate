#include<stdio.h>
#include<stdlib.h>>
#include<time.h>
int main ()
{
	int a;
    int n;
    int N;
    int nN = 0;
    int nfalsein = 0;
    int neliminate = 0;
    int nelimination;
    int x1,y1,x2,y2;
    scanf("%d", &n);
    n*=2;
    char b[n][n];
	srand((unsigned int)time(0));//ĞŞ¸ÄÖÖ×Ó
	for (size_t i = 0; i < 4*n*n; i++)	
	{	
		a = rand()%26;
		if(i%n==0)
		b[][]
		
	}
    char a[n][n];
    char b[n][n];
    for(int i = 0;i < n;i++)
        for(int j = 0; j< n; j++)
        {
	if(j<n-1)
            	scanf("%c ",&a[i][j]);
	if(j==n-1)
            	scanf("%c",&a[i][j]);
	if(a[i][0] == '\n')
	{
	j--;
	}
        }
    for(int i = 0;i < n;i++)
        for(int j = 0; j< n; j++)
        {
            	b[i][j] = a[i][j];
    }
    char c[100];
    int k = 0;
    int m = 0;
    int h = 0;
    int count = 0;
    int nout = 0;
    for(m = 0; m < n; m++)
        for(h = 0; h < n;h++)
        {
			char x = b[m][h];
            int flag = 0;
            for(int q = 0; c[q] !='\0'; q++)
                if(x == c[q])
                    flag =1;
        
            if(flag == 0)
            {
                for(int i = 0;i < n;i++)
                    for(int j = 0; j< n; j++)
                    {
                        if(b[i][j] == x)
                            {
                                count++;
                                c[k++] = x;
                            }
                    }
            }
            nout+=count/2;
            count = 0;
        }

    nelimination = nout;
    scanf("%d", &N);
	while(nN<N&&nfalsein < 3&&neliminate != nelimination)
    {
    	int flag2 = 0;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        x1--;
        y1--;
        x2--;
        y2--;
        if(a[x1][y1] == a[x2][y2]&&a[x1][y1] !='*')
        {
            a[x1][y1] = '*';
            a[x2][y2] = '*';
            neliminate++;
        }
        else
        {
            printf("Uh-oh\n");
            nfalsein++;
            flag2 = 1;
        }
        if(flag2 == 0&&neliminate != nelimination)
        {
			for(int i = 0;i < n;i++)
            	for(int j = 0; j< n; j++)
            	{
            		if(j<n-1)
					printf("%c ",a[i][j]);
					if(j == n-1)
					{
					printf("%c",a[i][j]);
					printf("\n");
					}
            	}
    	}
        nN++;
    }
    if(nfalsein == 3)
    {
        printf("Game Over");
        return 0;
    }
    if(neliminate == nelimination)
    {
        printf("Congratulations!");
        return 0;
    }
}



