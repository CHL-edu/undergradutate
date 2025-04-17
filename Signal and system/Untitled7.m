dt=0.01;
t=-2:dt:2;
f=1/2*exp(-2*t).*heaviside(t);  
401;w=-2*pi:dt:2*pi;
F=f*exp(-j*t'*w)*dt;           
F1=abs(F);P1=angle(F);        
subplot(3,1,1);
plot(t,f);grid on
title('f(t)')
subplot(3,1,2);
plot(w,F1);grid on
subplot(3,1,3);
plot(w,P1);grid on 