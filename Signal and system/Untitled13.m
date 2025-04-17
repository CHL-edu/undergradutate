syms t s
Yzis=(s+5)/(s^2+3*s+2);
yzi=ilaplace(Yzis)
subplot(211);
ezplot(yzi,[0,8]),grid on;
title('零输入响应');
ft=exp(-3*t)*heaviside(t);
Fs=laplace(ft);
Yzss=(s+3)*Fs/(s^2+3*s+2);
yzs=ilaplace(Yzss)
subplot(212);
ezplot(yzs,[0,8]),grid on;
title('零状态响应');