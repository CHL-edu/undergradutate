#include <stdio.h>
#define IN 1
#define OUT 0

int main()
{
	int x,nline,ncount,nword,state;
	
	state = OUT;
	
ncount = 0;
	
	while ((x = getchar() )!= EOF)
	{
		ncount++;
		
		if (x == '\n')
		nline++;
		
		if (x == ' '||x == '\n'||x == '\t')
		state = OUT;
		else if (state == OUT)
		{
			state = IN;
			
			nword++;
		}
	}
	printf("%d %d %d\n", nline, nword, ncount);
	return 0;
	
}
