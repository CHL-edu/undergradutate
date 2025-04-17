dt=0.01;
t=-4*pi:0.01:4*pi;
ft=sin(t)./t.*(heaviside(t+4*pi)-heaviside(t-4*pi));
subplot(421);
plot(t,ft),grid on;
axis([-4*pi 4*pi -0.5 1.1])
title('ft的波形图');
N=10000;k=-N:N;
W=pi*k/(N*dt);
Fw=dt*ft*exp(-j*t'*W);
subplot(422);
plot(W,abs(Fw)),grid on
axis([-10 10 -0.5 4]);
title('ft的频谱');

Ts1=4/(3*pi);
ts1=-4*pi:Ts1:4*pi;
fst1=sin(ts1)./ts1.*(heaviside(ts1+4*pi)-heaviside(ts1-4*pi));
subplot(423);
plot(t,ft,':'),hold on;
stem(ts1,fst1),grid on
axis([-4*pi 4*pi -0.5 1.1]);
title('Ts=4*pi/3抽样的信号'),hold off;
Fw1=Ts1*fst1*exp(-j*ts1'*W);
subplot(424);
plot(W,abs(Fw1)),grid on;
axis([-10 10 -0.5 4]);
title('Ts=4*pi/3抽样的频谱');

Ts2=pi; 
ts2=-4*pi:Ts2:4*pi;
fst2=sin(ts2)./ts2.*(heaviside(ts2+4*pi)-heaviside(ts2-4*pi));
subplot(425);
plot(t,ft),hold on;
stem(ts2,fst2),grid on;
axis([-4*pi 4*pi -0.5 1.1]);
xlabel('t/s'),ylabel('fs2(t)');
title('Ts=pi抽样的信号'),hold off;
Fw2=Ts2*fst2*exp(-j*ts2'*W);
subplot(426);
plot(W,abs(Fw2)),grid on;
axis([-10 10 -0.5 5]);
xlabel('w rad/s'),ylabel('Fs2(w)');
title('Ts=pi抽样的频谱');

Ts3=2/(3*pi); 
ts3=-4*pi:Ts3:4*pi;
fst3=sin(ts3)./ts3.*(heaviside(ts3+4*pi)-heaviside(ts3-4*pi));
subplot(427);
plot(t,ft,':'),hold on;
stem(ts3,fst3),grid on;
axis([-4*pi 4*pi -0.5 1.1])
title('Ts=2*pi/3抽样的信号'),hold off;
Fw3=Ts3*fst3*exp(-j*ts3'*W);
subplot(428);
plot(W,abs(Fw3)),grid on
axis([-35 35 -0.5 4]);
title('Ts=2*pi/3抽样的频谱');