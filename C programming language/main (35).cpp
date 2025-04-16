#include<stdio.h>
#include<string.h>

int main ()
{
    int N = 0;
    int K = 0;
    int j = 1;
    int count = 0, sum = 0;
    int x = 0, y = 0 , z = 0;
    int step1 = 0, step2 = 0, step10 = 0;
    int IF[10000];
    int stepF[10000];
    int OF[10000] = {0};
    int OOF[1000]={0};
    int line = 1;
    int p= 0;
    
    scanf("%d", &N);
    
    while(line <= N)
    {
        scanf("%d", &K);
        sum+=K;
        for(;j<=K;j++,z++)
            {
            	scanf("%d",&IF[z]);
			}
			j=1;
        line++;
    }
    
    for(int w = 0;w<sum; w++) 
    	stepF[w] = IF[w];
        
    for(;x<sum;x++,y++)
        for(int m = x; m < sum;m++)
           {

                if(IF[x] == 0&&OF[y] == 0) 
                    OF[y]= 0;
                if(stepF[x] == IF[m])
                {
                    OF[y]=OF[y] + 1;
                    IF[m]=0;
                }
            }
    
    for(int q = 0;q < sum; q++)
    {
        if(OF[q] >= step1)
            step1 = OF[q];
    }
    
    for(int q = 0;q < sum; q++, p++)
    {
        if(OF[q] == step1)
         OOF[p] = stepF[q];
    }
    
        for(int q = 0;q <= p; q++)
    {
        if(OOF[q] >= step10)
            step10 = OOF[q];
    }
    
    printf("%d %d\n",step10,step1);
    return 0;
}
