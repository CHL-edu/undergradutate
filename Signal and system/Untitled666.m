t=-1:0.01:10;
d=-1:0.01:10-0.01;
u=exp(-t).*sin(t).*stepfun(t,0);
du=diff(u);
plot(d,du);