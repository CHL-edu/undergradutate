#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;
    
    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}

/* 你的代码将被嵌在这里 */
int abs(int N){
	if(N<0)
		N=N*-1;
		return N;
}
int Count_Digit ( const int N, const int D ){
    int list_long = 0;
    int temp_N=abs(N);
    int count_num = 0;
    int same_num = 0;
    for(list_long= 0;temp_N!=0;list_long++){
        temp_N /=10;
    }
    if(list_long == 0&&D==0){
    	return 1;
	}
	else
		if(list_long == 0&&D!=0)
			return 0;
		else{	
			int num_list[list_long];
   		temp_N=abs(N);
  		for(int i = 0;temp_N!=0;i++){
        num_list[i] = temp_N%10;
        temp_N /=10;
    	}
    	for(int i=0;i<list_long;i++){
    	    if(num_list[i]==D)
    	        same_num++;
    	}
    	return same_num;
		}
}
