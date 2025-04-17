t=-0.5:0.01:2.5;
u1=stepfun(t,0);
u2=stepfun(t,2);
ft=(1+cos(pi*t)).*(u1-u2);
plot(t,ft),grid on;
title('1(3)');