t=-0.5:0.01:2.5;
u1=stepfun(t,0);
u2=stepfun(t,1);
u3=stepfun(t,2);
ft=u1-2.*u2+u3;
plot(t,ft),grid on;
title('1(4)');