#include<stdio.h>
int main ()
{
	char word;
    char str[100];
    char str2[100];
    int  count, i;
    int j = 0;
    int k = 0 ;
	count = 0;
	i = 0;
    
    while(word != '.')
    {
        
        if((word = getchar()) != ' '&&word != '.')
            count++;
        else 
        {
            if(count !=0 )
            {
                str[i] = count+'0';
                i++;
                str[i] = ' ';
                i++;
            }
            count=0;
        }
    }
    for( j = 0;j< i-1;j++, k++)
    {
        str2[j] = str[k]  
    }

	        printf("%s",str2);

    return 0;
}
