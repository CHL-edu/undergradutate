t=-0.5:0.01:1;
w=10*pi;
u1=step(t,0);
ft=sin(w*t).*u1;
plot(t,ft),grid on;
title('1(6));
