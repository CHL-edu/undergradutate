a=[1 0.2 -0.24];
b=[1 1];
[H,w]=freqz(b,a,400,'whole');
Hm=abs(H);
Hp=angle(H);
subplot(211)
plot(w,Hm);
xlabel ('\omega(rad/ s)');
ylabel('幅度');
title('离散系统幅频特性曲线');
subplot(212);
plot(w,Hp);
xlabel('\omega(rad/s)');
ylabel('相位');
title('离散系统相频特性曲线');
