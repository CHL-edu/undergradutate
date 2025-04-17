dt=0.01;
t=-2:dt:2;
N=2000;
k=-N:N;
w=pi*k/(N*dt); %Differentiation
ft=(heaviside(t+2)-heaviside(t+1)).*(t+2)+heaviside(t+1)-heaviside(t-1)+(heaviside(t-1)-heaviside(t-2)).*(2-t);
F=dt*ft*exp(-j*t'*w);
F=abs(F);
plot(w,F),grid on;
axis equal;
title('amplitude spectrum');
xlabel('angular frequency w'),ylabel('F(w)');