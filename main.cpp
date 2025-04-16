#include <stdio.h>
int main ()
{
    char insert, insert2;
	int ncount;
    ncount = 0;
    while((insert2 = getchar()) != EOF )
    {
    	if(ncount == 0);
    	else break;
    	if(insert2 == '\n')
    	{printf("0 ");
    	break;
    	goto loop;
		}
    	
	}
    while((insert = getchar()) != EOF )
        {
        
		if(insert == '\n')
        	{
        	if(insert == ' '&&ncount == 0)
        	{
			printf("%d ",ncount);		
			break;
			}	
            if(ncount == 0) break;
            
			printf("%d ",ncount);
			
			break;
			}
			
        if(insert != ' ')
        
		ncount++;
		
		else if(ncount == 0);
		
		else {printf("%d ",ncount);
		
		ncount=0;
		
        }
		}
    loop:return 0;
}
