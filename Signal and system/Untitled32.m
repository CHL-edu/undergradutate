k=0;
b=[1];
a=[1,1,k-2];
zs=roots(b);
ps=roots(a);
subplot(321);
plot(real(zs),imag(zs),'blacko',real(ps),imag(ps),'blackx','markersize',12);
axis([-4,3,-2,2]),grid on;
legend('零点','极点');
k=1;
b=[1];
a=[1,1,k-2];
zs=roots(b);
ps=roots(a);
subplot(322);
plot(real(zs),imag(zs),'blacko',real(ps),imag(ps),'blackx','markersize',12);
axis([-4,3,-2,2]),grid on;
legend('零点','极点');
k=2;
b=[1];
a=[1,1,k-2];
zs=roots(b);
ps=roots(a);
subplot(323);
plot(real(zs),imag(zs),'blacko',real(ps),imag(ps),'blackx','markersize',12);
axis([-4,3,-2,2]),grid on;
legend('零点','极点');
k=9/4;
b=[1];
a=[1,1,k-2];
zs=roots(b);
ps=roots(a);
subplot(324);
plot(real(zs),imag(zs),'blacko',real(ps),imag(ps),'blackx','markersize',12);
axis([-4,3,-2,2]),grid on;
legend('零点','极点');
k=3;
b=[1];
a=[1,1,k-2];
zs=roots(b);
ps=roots(a);
subplot(325);
plot(real(zs),imag(zs),'blacko',real(ps),imag(ps),'blackx','markersize',12);
axis([-4,3,-2,2]),grid on;
legend('零点','极点');
