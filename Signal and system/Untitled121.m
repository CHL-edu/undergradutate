f=sym('exp(-3*t)*heaviside(t)');
L=laplace(f);
Yzis=(s+5)/(s^2+3*s+2);
yzi=ilaplace(Yzis)
subplot(211);
ezplot(yzi,[0,8]);grid on;
title('zero input');
Yzss=(s+3)*fs/(s^2+3*s+2);
yzs=ilaplace(Yzss)
subplot(212);
ezplot(yzs,[0,8]);grid on;
title('zero state');