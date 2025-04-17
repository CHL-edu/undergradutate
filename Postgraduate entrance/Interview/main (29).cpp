#include <stdio.h>

#define MAXN 10

double f( int n, double a[], double x );

int main()
{
    int n, i;
    double a[MAXN], x;
    
    scanf("%d %lf", &n, &x);
    for ( i=0; i<=n; i++ )
        scanf("%lf", &a[i]);
    printf("%.1f\n", f(n, a, x));
    return 0;
}

/* 你的代码将被嵌在这里 */
double power(double base, int exponent) {
    double result = 1.0;
    int k = 0;
    for (k = 0; k < exponent; k++) {
        result *= base;
    }
    return result;
}
long long quickPow(long long a, long long b) {
    long long ans = 1, c = a;
    while (b) {
        if (b & 1)
            ans *= c;
        c *= c; // 或者 c = c * c;
        b >>= 1;
    }
    return ans;
}
double f( int n, double a[], double x )
{
    double sum = 0.0;
    int j = 0;
    if(n<=1000){
	for(j = 0;j<=n;j++)
   	 	{
			sum+= a[j]*power(x,j);
    	}
    	return sum;
	}
	else{
			for(j = 0;j<=n;j++)
   	 	{
			sum+= a[j]*quickPow(x,j);
    	}
    	return sum;
	}
	
    
}
