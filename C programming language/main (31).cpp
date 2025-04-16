#include <stdio.h>
int main()
{
    int i;
    int j;
    int k = 0;
    int l = 0;
    int e;
    int u=0;
    int na;
    int mb;
    int a[20];
    int b[20];
    int r[40];
    int out[20] = {'0'};
    int flag = 0;
    
    scanf("%d",&na);
    for(i=0;i<na;i++)
        scanf("%d",&a[i]);
    
    scanf("%d",&mb);
    for(j=0;j<mb;j++)
        scanf("%d",&b[j]);
    
    for(i=0;i<na;i++)
        for(j=0;j<mb;j++)
        {
            if(b[j] == a[i]&&r[k-1] != b[j])
            {
                r[k] =a[i];
                k++;
            }
        }
    
    for(int m = 0; m<k;m++)
        for(int n = 0; n<na;n++)
        {
            if(a[n] == r[m])
                a[n] = -1;
        }
    
    for(int m = 0; m<k;m++)
        for(int n = 0; n<mb;n++)
        {
            if(b[n] == r[m])
                b[n] = -1;
        }
    
    for(int c=0;c<na;c++)
    	{
        	if(a[c] != -1)
            	{
            		for( e = 0;out[e] !='\0';e++)
            		{
            			if(out[e] == a[c])
            				{
            					flag = 1;
            					break;
							}
					}
					if(out[e] == '\0')
						flag = 0;
					
					if(flag == 0)
					{
					out[l] = a[c];
            		l++;	
					}
					
            	}
    	}
    
    
    
    for(int c=0;c<mb;c++)
    	{
        	if(b[c] != -1)
            	{
            		for( e = 0;out[e] !='\0';e++)
            		{
            			if(out[e] == b[c])
            				{
            					flag = 1;
            					break;
							}
					}
					if(out[e] == '\0')
						flag = 0;
					
					if(flag == 0)
					{
					out[l] = b[c];
            		l++;	
					}
            	}
    	}
    
	for(u=0; b[u] != '\0'; u++);

	for(int s = 0; s<l-1;s++)
		printf("%d ", out[s]);
		printf("%d", out[l-1]); 
    	
    return 0;
}

//10 3 m 3 5 -15 m
//11 6 4 m m 6 m 8 1
