#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;
    
    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

/* 你的代码将被嵌在这里 */
int IsTheNumber ( const int N ){
	int maxnumber =10;
	int N_temp = N;
	int flag_is_square = 0;
	int flag_is_binum  = 0;
	int number[maxnumber];
	for(int i = 0;i<maxnumber;i++)
		number[i]=-1;
	for(int i = 0;N_temp!=0;i++){
			number[i]=N_temp%10;	
			N_temp=(N_temp-number[i])/10;
		}
		
	for(int i = 1;i<=(N+1)/2;i++)
		if(N==i*i)
			flag_is_square=1;
	for(int i = 0;i<maxnumber&&number[i]!=-1;i++)
		for(int j = 0;j<maxnumber;j++)
			if(number[j] == number[i])
				flag_is_binum+=1;
	
	if(flag_is_square==1&&flag_is_binum>=4)
		return 1;
	else
		return 0;
}
