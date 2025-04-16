#include<stdio.h>
int main ()
{
    char s1[85];
    char s2[85];
    gets(s1);
    gets(s2);
    
    char x;
    int count2 = 0;
    int count1 =0;
    int count = 0;
    int j = 0;
    for(count1  = 0; s1[count1] !='\0';count1++);
    for(count2  = 0; s2[count2] !='\0';count2++);
    x=s2[0];
    
    for(int m = 0; m<count1;m++)
        for(int k =0 ;s1[k] !='\0'; k++)
        {
            if(s1[k] == x)
                for(j = 0; j<count2;j++)
                {
                    if(s1[k+j] != s2[j])
                        break;
                }
            if(j == count2)
                {
				for(int n = 0; n<count1;n++)
                    s1[k+n] = s1[k+n+count2];
                    j=0;
				}
        }
        
    for(count = 0; s1[count] !='\0';count++);
    if(s1[count-1] == ' ')
    	for(int b = 0; b<count-1;b++)
    		printf("%c", s1[b]);
    	else
    		printf("%s",s2);
    return 0;
    
}
