syms n;
x=(0.5)^n*(heaviside(n)-heaviside(n-10));
Z=ztrans(x);
simplify(Z)
B=[1024 0 0 0 0 0 0 0 0 0 1];
A=[1024 512 0 0 0 0 0 0 0 0 0];
zplane(B,A),grid on;
legend('zero','polar');