a=[1 0.2 -0.24];
b=[1 1];
n=-50:50;
x1=impDT(n);
h=filter(b,a,x1);
nx=-50:50;
nh=-50:50;
x=uCT(nx);
y=conv(x,h);
ny1=nx(1)+nx(1);
ny=ny1+(0:(length(nx)+length(nh)-2));
stem(ny,y,'fill');
xlabel('n');
axis([-10,30,-0.1,2.2])