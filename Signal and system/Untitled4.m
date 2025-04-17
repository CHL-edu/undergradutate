a=[1 0.2 -0.24];
b=[1 1];
n=-10:30;
x=uCT(n);
y=filter(b,a,x);
stem(n,y,'fill');
xlabel('n');
axis([-10,30,-0.1,2.3])
title('x(n)为单位阶跃序列时系统的零状态响应')