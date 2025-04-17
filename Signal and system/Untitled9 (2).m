t=-5:0.01:5;
k=2;
ft=k*exp(1i*(t+pi/4));
subplot(2,2,1);plot(t,real(ft));title('2.实部');grid on;
subplot(2,2,2);plot(t,imag(ft));title('2.虚部');grid on;
subplot(2,2,3);plot(t,abs(ft));title('2.模');grid on;
subplot(2,2,4);plot(t,angle(ft));title('2.幅角');grid on;
