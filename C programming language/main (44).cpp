#include <stdio.h>


int main() 
{
	int  ch, flag = 1;
	while ((ch = getchar()) != EOF &&ch != '\n')
	{
		if(ch == ' ')
			{
			printf(" ");	
			flag = 1; 
			} 
		else
		{
			if (flag != 0 && ch >= 'a' &&ch <= 'z')
			printf("%c", ch - 32);
			else
			printf("%c",ch);
			flag = 0;
		}
	}
	return 0;
}
