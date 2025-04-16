#include<stdio.h>
#include<string.h>
int main()
{
    char p[4][20];
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    
    for(int i = 0; i< 4;i++)
    {
        gets(p[i]);
        if(p[i] == '\0')
            i--;
    }
    
    count1 = strlen(p[0]);
    count2 = strlen(p[1]);
    count3 = strlen(p[2]);
    count4 = strlen(p[3]);
    
    printf("%s" , p[0]+count1-2);
    printf("%s" , p[1]+count2-2);
    printf("%s" , p[2]+count3-2);
    printf("%s" , p[3]+count4-2);
    
    return 0;
}
