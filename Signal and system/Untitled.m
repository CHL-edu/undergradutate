clc;
eq='D2y+3*Dy+2*y=0';
cond='y(0)=1,Dy(0)=2';
yzi=dsolve(eq,cond);yzi=simplify(yzi)
subplot(311)
ezplot(yzi,[0,8]);grid on
title('零输入响应');

eq1='D2y+3*Dy+2*y=Dx+3*x';
eq2='x=exp(-3*t)*heaviside(t)';
cond='y(-0.001)=0,Dy(-0.001)=0';
yzs=dsolve(eq1,eq2,cond);yzs=simplify(yzs.y)
subplot(312)
ezplot(yzs,[0,8]);grid on
title('零状态响应(1)');

ts=0;te=8;dt=0.01;
sys=tf([1,3],[1,3,2]);
t=ts:dt:te;
f=exp(-3*t).*uCT(t);
y=lsim(sys,f,t);
subplot(313)
plot(t,y),grid on;
axis([0 8 -0.02 0.27]);
xlabel('Time(sec)'),ylabel('y(t)');
title('零状态响应(2)');

