#include<stdio.h>
#include<string.h>
int main()
{
	int max = 0;
	char a[1000];
	gets(a);
	int k = strlen(a);
	if(k%2 == 0);
	if(k%2 != 0)
	k++;
	for(int i = k/2;i>=0;i--)
		for(int j = 0;j<k/2;j++)
		{
			if(a[j]==a[j+i-1])
				{
					max = i;
					printf("%d",max);
					return 0;
				}
		}
	printf("0");
    return 0;
}
//Is PAT&TAP dymmetric?
