t=-0.1:0.01:3;
w=10;
u1=stepfun(t,0);
ft=sin(w*t).*u1;
plot(t,ft),grid on;
title('1(6)');