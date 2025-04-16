#include <stdio.h>
#include <string.h>


int main(void) 
{
   char input[1001];
    int str_length , i, j, k, max_length = 0;
	//i，对称长度。j，k 循环变量。 
    gets(input);
    str_length = strlen(input);
    for (i = 1; i <= str_length; i++) 
    {
        for (j = 0; j < str_length + 1 - i; j++)
        {
			 
			for (k = 0; k < i / 2; k++) //是否为i对称长度 
			{
                if (input[j + k] != input[j + i - k - 1])
				{
                    break;
                }
            }
            if (k < i / 2) 
			{
                continue;
            }
            else 
			{
                max_length = i;
            }
        }
    }
    
    printf("%d\n", max_length);

    return 0;
}
