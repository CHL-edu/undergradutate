#include<stdio.h>
#include<math.h>
#include<string.h>
int main ()
{
    int number, number2;
    int i2=0; 
    int j =0;
	char str[100];
	char str2[100]; 
	int  x, count, count2, i;
    i = 0;
	char y;
    scanf("%d", &number);
    
    number2=number;
    for(count =1;number/10!=0 ; count++)
    {
        number/=10;
    }
    
    count2=count;
    for(x = 0;count>=1;count--)
    {
        x = number2/pow(10,count-1);
        number2-= x*pow(10,count-1);
        y = x+'a';
        switch(count)
            {
                case 1:  if(y=='a'&&count2!=1) break;
				         else {str[i]=y;i++; break;}
                
                case 2: if(y=='a') break;
				        else {str[i]=y;i++;str[i]='S'; i++; break;}
                
                case 3: if(y=='a') {str[i]=y;i++;break;}
                        else {str[i]=y;i++;str[i]='B'; i++; break;}
                
                case 4: if(y=='a') {str[i]=y;i++;break;}
                        else {str[i]=y;i++;str[i]='Q'; i++; break;}
                              
                case 5: if(y=='a') {str[i]=y;i++;break;}
                        else {str[i]=y;i++;str[i]='W'; i++; break;}
                              
                case 6: if(y=='a') {str[i]=y;i++;break;}
                        else {str[i]=y;i++;str[i]='S'; i++; break;}
                              
				case 7: if(y=='a') {str[i]=y;i++;break;}
                        else {str[i]=y;i++;str[i]='B'; i++; break;}
                              
				case 8: if(y=='a') {str[i]=y;i++;break;}
                        else {str[i]=y;i++;str[i]='Q'; i++; break;}
                              
                case 9: if(y=='a') {str[i]=y;i++;break;}
                        else {str[i]=y;i++;str[i]='Y'; i++; break;}
            }
        
    }

   while(i2<=i)
   {
       
       if(str[i2]=='a'&&str[i2+1]=='a')
       {
           i2++;
       }
       else
       {
           str2[j]=str[i2];
           j++;
           i2++;
       }
   }
    
    
    printf("%s", str2);
    return 0;
}

