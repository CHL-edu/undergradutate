w=-3*pi:0.01:3*pi;
b=[1];
a=[1,1,k-2];
k=3;
H=freqs(b,a,w);
subplot(211)
plot(w,abs(H)),grid on
xlabel('\omega(rad/s)'),ylabel('|H(\omega)|')
title('k=3时H的幅频特性')
subplot(212)
plot(w,angle(H)),grid on
xlabel('\omega(rad/s)'),ylabel('\phi(\omega)')
title('k=3时H的相频特性')
