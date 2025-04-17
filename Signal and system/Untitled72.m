dt=0.01;
t=-2:dt:2;
f=1/2*exp(-2*t).*heaviside(t);          
f1=1/2*exp(-2*(t-0.5)).*heaviside(t-0.5);  
w=-2*pi:dt:2*pi;
F=f*exp(-j*t'*w)*dt;          
F1=f1*exp(-j*t'*w)*dt; 
subplot(3,1,1);
plot(t,f,t,f1,'r'),grid on 
title('f(t),f(t-0.5)')
subplot(3,1,2);
plot(w,abs(F),w,abs(F1),'r'),grid on
subplot(3,1,3);
plot(w,angle(F),w,angle(F1),'r'),grid on