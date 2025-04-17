Ts=1/4;
dt=0.1;
t1=-pi:dt:pi;
ft=cos(0.2*pi*t1).*(heaviside(t1+pi)-heaviside(t1-pi));
subplot(221);
plot(t1,ft),grid on;
axis([-3,3,-0.1,1.1]);
title('ft波形图');
N=500;k=-N:N;W=pi*k/(N*dt);
Fw=dt*ft*exp(-j*t1'*W);
subplot(222);
plot(W,abs(Fw)),grid on
axis([-20,20,-0.1,3])
title('ft的频谱');
t2=-pi:Ts:pi;
fst=cos(0.2*pi*t2).*(heaviside(t2+pi)-heaviside(t2-pi));
subplot(223);
plot(t1,ft),hold on;
stem(t2,fst),grid on;
axis([-2.5,2.5,-0.1,1.1]);
title('抽样后的信号波形'),hold off;
Fsw=Ts*fst*exp(-j*t2'*W);
subplot(224);
plot(W,abs(Fsw)),grid on;
axis([-30,30,-0.1,3])
title('抽样信号的频谱');