#include<stdio.h>
#include<string.h>
struct information{
    int lenghth;
    char name[10];
}number[20],temp;
int main()
{
    int count = 0;
    for(count = 0;;count++)
        {
        	scanf("%s",number[count].name);
        	if(number[count].name[0] == '#') 
			break;
		}
    
    for(int i = 0; i<count;i++)
        number[i].lenghth = strlen(number[i].name);
    
    for(int m = 0;m<count;m++)
        for(int n= 0;n<count-1;n++)
        {
            if(number[n].lenghth > number[n+1].lenghth)
                {
					temp = number[n];
                	number[n] = number[n+1];
               		number[n+1] = temp;
            	}
        }
    
    for(int i = 0; i<count; i++)
    {
        printf("%s ", number[i].name);
    }
    return 0;
}
