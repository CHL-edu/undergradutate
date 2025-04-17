t=-5:0.01:5;
T1=2;
N=-50:50;
w1=2*pi/T1;
ft1=4./((pi.*N).^2).*(1-cos(pi.*N))/2;
subplot(211);
stem(N*w1,ft1),grid on
axis([-100,100,-0.1,0.5])
title('T1=2');
 
T2=1;
w2=2*pi/T2;
ft2=4./((pi.*N).^2).*(1-cos(pi.*N))/2;
subplot(212);
stem(N*w2,ft2),grid on
axis([-200,200,-0.1,0.5])
title('T2=1');