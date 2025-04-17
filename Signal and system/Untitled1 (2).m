clc;
clear;
syms t;
syms w;
ft=(heaviside(t+2)-heaviside(t+1))*(t+2)+heaviside(t+1)-heaviside(t-1)+(heaviside(t-1)-heaviside(t-2))*(2-t);
Fw=fourier(ft);
subplot(211)
ezplot(w,abs(Fw),[-5,5]),grid on
axis([-5,5,-0.1,3.1]);
title('幅度谱');
phase=atan(imag(Fw)/real(Fw));
subplot(212)
ezplot(w,phase,[-2*pi,2*pi]),grid on
axis([-6.5,6.5,-1,1]);
title('相位谱')

