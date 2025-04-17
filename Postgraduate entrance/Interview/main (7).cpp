#include <stdio.h>
#include <stdlib.h>

void automorphic(int begin,int end)
{
	int out_dex =0;
	for(int i =begin;i<=end;i++){
		int mul = i*i;
		int last_num =mul%10;
		if(last_num==i%10){
			printf("%d ",i);
			out_dex++;
		}
		if(out_dex == 4){
			printf("\n");
			out_dex = 0;	
		}
	}
}
int main()
{
    int m,n;
    printf("please input two integer 10<=m<n<200000\n");
    scanf("%d %d",&m,&n);
    automorphic(m,n);
    return 0;
}

