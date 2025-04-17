syms n z;
X=z/(z-1);
H=(z+1)/(z^2+0.2*z-0.24);
Y=X*H;
y=iztrans(Y);
ezplot(n,y),grid on