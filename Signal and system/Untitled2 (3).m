syms w;
Fw=10/(3+j*w)-4/(5+j*w);
ft=ifourier(Fw);
ezplot(ft),grid on
axis([-0.1,2.7,-0.1,6.1]);
title('时域信号图');