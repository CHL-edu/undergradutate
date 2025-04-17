clc;
n=0:40;
a=3*pi/7;
c=8*pi;
A=2;
x1=A*cos(a*n-c);
subplot(211)
stem(n,x1,'fill'),xlabel('n'),grid on
title('x1(n)')
b=1/8;
x2=exp(1i*(b*n-pi));
subplot(212)
stem(n,x2,'fill'),xlabel('n'),grid on
title('x2(n)')