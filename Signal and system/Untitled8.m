t=-0.5:0.01:5;
w=10;t0=2;
u1=stepfun(t,t0);
ft=sin(w*(t-t0)).*u1;
plot(t,ft),grid on;
title('1(9)');