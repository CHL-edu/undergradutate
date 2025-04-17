clc;clear;
syms t;
syms w;
ft1=heaviside(t)-heaviside(t-1);
Fw1=fourier(ft1,t,w);
subplot(211);
ezplot(w,abs(Fw1)),grid on
axis([-0.1,6.1,-0.1,1.1])
title('门函数的傅里叶变换求平方'); 
ft2=(heaviside(t)-heaviside(t-1))*t+(heaviside(t-1)-heaviside(t-2))*(-t+2);
Fw2=fourier(ft2,t,w);
subplot(212);
ezplot(w,abs(Fw2)),grid on
axis([-0.1,6.1,-0.1,1.1])
title('卷积后三角波的傅里叶变化');