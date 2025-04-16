#include <stdio.h>

int main ()
{
	int x = 0;
	double sum =0;
	int cut = 0;
	int number[100];
	scanf("%d",&x);
	while(x != -1)
	{
		number[cut] = x;
		sum+= x;
		cut++;
		scanf("%d",&x);
	}
	if (cut>0)
	{
		int average;
		average = sum/cut ;
		
		printf("%f\n",sum/cut);
		int i;
		for(i = 0;i <cut;i++)
		{
			if(number[i]>average1)
			printf("%d\n",number[i]);
		}
	}
	return 0;
}
