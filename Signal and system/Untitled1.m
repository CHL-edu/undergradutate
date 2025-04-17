n1=-10:0;
a1=0.5;
x1=-(a1.^n1);
subplot(211)
stem(n1,x1,'fill'),grid on
xlabel('n'),title('x1(n)=-(1/2)^n*u(-n)')
axis([-10,1,-1100,100])
n2=-1:10;
a2=0.5;
x2=a2.^(n2+1);
subplot(212)
stem(n2,x2,'fill'),grid on
xlabel('n'),title('x2(n)=(1/2)^(n+1)*u(n+1)')
axis([-1,10,-0.1,1.1])
