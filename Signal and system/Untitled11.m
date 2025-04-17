dt=0.01;
t=-5:dt:5;
ft=(heaviside(t+2)-heaviside(t+1)).*(t+2)+heaviside(t+1)-heaviside(t-1)+(heaviside(t-1)-heaviside(t-2)).*(2-t);
N=2000;
k=-N:N;
w=pi*k/(N*dt);
F=dt*ft*exp(-i*t'*w);
F=abs(F);
plot(w,F),grid on
axis([-5,5,-0.1,3.2])
title('幅度谱');