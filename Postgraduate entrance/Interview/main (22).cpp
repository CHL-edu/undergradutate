#include<stdio.h>
int time_num(int num){
    int count = 0;
    for(int i = 0;num/10 !=0;i++){
        count++;
    }
    return count;
}
int main(){
    int beg_t = 0;
    int end_t = 0;
    int pro_h = 0;
    int pro_m = 0;
    int end_h = 0;
    int end_m = 0;
    scanf("%d %d",&beg_t,&pro_m);
    int beg_h =  beg_t/100;
    int beg_m =  beg_t-beg_h*100;

 	int total_m = beg_h*60+beg_m;
 	int end_total_m = total_m+pro_m;
 	end_h = end_total_m/60;
 	end_m = end_total_m%60;
 	if(end_m<10){
    	printf("%d0%d",end_h,end_m);
		}
		else
    		printf("%d%d",end_h,end_m);
}
