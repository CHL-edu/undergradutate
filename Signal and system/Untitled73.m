N=256;  t=linspace(-2,2,N);
f=1/2*exp(-2*t).*heaviside(t);           %建立时间信号f(t)
f1=1/2*exp(-2*(t-0.5)).*heaviside(t-0.5);  %建立时间信号f(t-0.3)
dt=4/(N-1);  M=401;
w=linspace(-2*pi,2*pi,M);
F=f*exp(-j*t'*w)*dt;                %求信号f(t)的傅立叶变换
F1=f1*exp(-j*t'*w)*dt;          %求信号f(t-0.5)的傅立叶变换
subplot(3,1,1);
plot(t,f,t,f1,'r'),grid on 
xlabel('t');ylabel('f'),
title('f(t),f(t-0.5)')
subplot(3,1,2);
plot(w,abs(F),w,abs(F1),'r'),grid on
xlabel('w');
ylabel(' f(t)和f(t-0.5)幅度谱');
subplot(3,1,3);
plot(w,angle(F),w,angle(F1),'r'),grid on
xlabel('w');
ylabel(' f(t)和f(t-0.5)相位谱')