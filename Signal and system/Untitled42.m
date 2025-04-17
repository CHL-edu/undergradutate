a=[1 0.2 -0.24];
b=[1 1];
n=0:30;
x=impDT(n);
y=filter(b,a,x);
subplot(211);
stem(n,y,'fill');xlabel('n');
axis([-0.2,30,-0.1,1.1])
title('filter函数求单位样值响应');
subplot(212);
impz(b,a,30);
axis([-0.2,30,-0.1,1.1])
title('impz函数求单位样值响应');