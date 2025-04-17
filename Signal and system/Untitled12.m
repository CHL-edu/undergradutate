t=0:0.001:8;
sys=tf([1,3],[1,3,2]);
h=impulse(sys,t);
g=step(sys,t);
y1=lsim(sys,h,t);
subplot(311)
plot(t,y1),grid on
axis([-0.1,8,-0.1,0.8])
xlabel('Time(sec)'),ylabel('h(t)')
title('冲激响应')
subplot(312)
plot(t,g),grid on
axis([-0.1,8,-0.1,1.6])
xlabel('Time(sec)'),ylabel('g(t)');
title ('阶跃响应')
f=exp(-3*t).*heaviside(t);
ht=conv(f,h)*0.001;
n=length(ht);
t1=(0:n-1)*0.001;
subplot(313)
plot(t1,ht),grid on;
title('e(t)*h(t)');
axis([-0.1,8,-0.05,0.3])