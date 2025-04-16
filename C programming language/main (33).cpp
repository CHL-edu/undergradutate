#include<stdio.h>
#include<string.h>
int main(){
	int i,j;
	char s[5][108],t[85];
	for(i=0;i<5;i++)
		scanf("%s",s[i]);
	for(i=0;i<4;i++)
		for(j=0;j<4-i;j++)
			if(strcmp(s[j],s[j+1])>0)
            {
				strcpy(t,s[j]);
				strcpy(s[j],s[j+1]);
				strcpy(s[j+1],t);
			}
	printf("After sorted:\n");
	for(i=0;i<5;i++)
		printf("%s\n",s[i]);
	return 0;
} 


