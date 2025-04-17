syms x y1
y1=x*sin(x)*log(x);
dy1=diff(y1)
syms a x y2
y2=x^5-a*x^2+0.5*x^0.5;
int(y2,'x')
syms x y3
y3=(x*exp(x))/(1+x)^2;
int(y3,0,1)