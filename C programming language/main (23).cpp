#include <stdio.h>
#include <string.h>


int main(void) 
{
   char input[1001];
    int str_length , i, j, k, max_length = 0;
	//i���ԳƳ��ȡ�j��k ѭ�������� 
    gets(input);
    str_length = strlen(input);
    for (i = 1; i <= str_length; i++) 
    {
        for (j = 0; j < str_length + 1 - i; j++)
        {
			 
			for (k = 0; k < i / 2; k++) //�Ƿ�Ϊi�ԳƳ��� 
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
