#include <stdio.h>

void Print_Factorial ( const int N );

int main()
{
    int N;
    
    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}

/* 你的代码将被嵌在这里 */
void Print_Factorial ( const int N ){
	if(N<0){
		printf("Invalid input");
	}
	else{	
		long double N_j =1;
		for(int i = 1;i<=N;i++)
			N_j*=i;	
		printf("%.0Lf",N_j);			
	} 

}

