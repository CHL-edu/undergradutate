t=-0.5:0.01:3;
t0=2;w=10;
u1=stepfun(t,0);
ft=sin(w*(t-t0)).*u1;
plot(t,ft),grid on;
title('1(7)');