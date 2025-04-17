b=[1];
a=[1,1,0.25];
figure
sys1=tf(b,a);
subplot(211)
bode(sys1),grid on
b=[1];
a=[1,1,1];
sys2=tf(b,a);
subplot(212)
bode(sys2),grid on