#include<stdio.h>
int main()
{
    int N, count, x, y, step;
    int instr[100];
    int outstr[100];
    scanf("%d", &N);
    for (int k = 0;k<N;k++)
        scanf("%d", &instr[k]);
    
    for(int j = 0;instr[j] != '\0';j++,count++);
	count--;
	
    while( y < N)
{
        for(x = 0, step = 0;x < count;x++)
    {
        if(step <= instr[x]) 
            step = instr[x];
    }
    for(x = 0;x <= count;x++)
    {
        if(instr[x] == step)
        {
            instr[x] = -1;
            outstr[y] = step;
            y++;
        }
    }
}
    for(int j=0;j<N-1;j++)
        printf("%d ",outstr[j]);
    printf("%d",outstr[N-1]);
    return 0;
}
