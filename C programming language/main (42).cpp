#include<stdio.h>
#include<math.h>
int main()
{
    double a, b, c, step, x1, x2, r1, r2, i1, i2;
    scanf("%lf %lf %lf", &a, &b, &c);
    
    if(a==0&&b==0&&c==0)
    {
        printf("Zero Equation");
        
    }
    if(a==0&&b==0&&c!=0)
    {
        printf("Not An Equation");
        
    }
    if(a==0&&b!=0&&c!=0)
    {
        x1=-c/b;
        printf("%.2lf",x1);
    }
    step = pow(b,2)-4*a*c;
    if(step < 0)
    {
        r1=-b/2/a;
        r2=-b/2/a;
        if(b==0)
		{
			r1=-r1;
        r2=-r2;
		 } 
        i1=sqrt(-step)/2/a;
        i2=-sqrt(-step)/2/a;
        printf("%.2lf+%.2lfi\n" ,r1, i1);
        printf("%.2lf%.2lfi\n" ,r2, i2);
       
    }
    if(step == 0&& a!=0)
    {
        x1=-b/2/a;
        printf("%.2lf",x1);
        
    }
    if(step > 0&&a!=0)
    {
        x1=(-b+sqrt(step))/2/a;
        x2=(-b-sqrt(step))/2/a;
        printf("%.2lf\n" ,x1);
        printf("%.2lf\n" ,x2);
        
    }
    return 0;
    
}
