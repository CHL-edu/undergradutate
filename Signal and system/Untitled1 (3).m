a=1;
t=-5:0.1:5;
u=stepfun(t,0);
ft=t.*exp(-a*t).*u;
plot(t,ft),grid on;
axis([-5.1,5.1,0,0.4]);
title('1(1)');