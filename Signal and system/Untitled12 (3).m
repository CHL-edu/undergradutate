f=2;
t=0:0.01:3/f;
f1=sin(2*pi*f*t);
f2=sin(2*pi*8*f*t);
subplot(211)
plot(t,f1+1,':',t,f1-1,':',t,f1+f2);grid on;
title('f1(t)+f2(t)');
subplot(212)
plot(t,f1,':',t,-f1,':',t,f1.*f2);grid on;
title('f1(t)*f2(t)');
