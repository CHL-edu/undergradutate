#include<stdio.h>
#include<string.h>
struct information{
    int sex;
    char name[20];
}student[100];

int main()
{
    int N;
    scanf("%d",&N);
    for(int i= 0;i<N;i++)
        scanf("%d%s",&student[i].sex,student[i].name);
    
    for(int i = 0;i<=N;i++)
        for(int j = N-1;j > i;j--)
            if(student[i].sex == student[j].sex&&student[j].name[0] !='0')
                {
                	{
                        printf("%s %s\n",student[i].name,student[j].name);
						student[j].name[0]  = '0';
                        break;
                     }
                }
        
        return 0;
    
}
