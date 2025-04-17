k=2;
b=[1];
a=[1,1,-k-2];
zs=roots(b);
ps=roots(a);
plot(real(zs),imag(zs),'blacko',real(ps),imag(ps),'blackx','markersize',12);
axis([-4,3,-2,2]),grid on;
legend('零点','极点');