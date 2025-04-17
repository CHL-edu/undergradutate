clear 
close 
clc
M=16;                  % 天线数
K=3;                   % 信源数
theta=[30 45 60];       % 信号入射角度
d=0.3;                 % 天线间距
N=1000;                % 采样数
E=0;   D=1;     % 噪声均值、方差
SNR=100;
pp=zeros(100,N);pp1=zeros(100,N);
N = 1000;
n = 0:N-1;
f0 = 2000;
for q=1:100
   s = [1*sin(2*pi*f0 *n/(8*f0));...
    2*sin(2*pi*2*f0 *n/(8*f0));...
    3*sin(2*pi*3*f0 *n/(8*f0))
    ];  % 生成源信号
    A=exp(-1i*2*pi*d*[0:M-1].'*sin(theta*pi/180));   % 方向向量
    e=sqrt(D/2)*(randn(M,N)+1i*randn(M,N));       % 噪声
    Y=A*s+e;                                         % 接收信号
    % LMS算法
    L=200;
    de=s(1,:);
    mu=0.0005;
    w=zeros(M,1);
    for k=1:N
        y(k)=w'*Y(:,k);                              % 预测下一个采样和误差
    e(k)=de(k)-y(k);                                 % 误差
    w=w+mu*Y(:,k)*conj(e(k));                        % 调整权向量
    end
end
 
% 波束形成
beam=zeros(1,L);
for i=1:L
    a=exp(-1i*2*pi*d*[0:M-1].'*sin(-pi/2+pi*(i-1)/L));
    beam(i)=20*log10(abs(w'*a));
end
 
figure
angle=-90:180/200:(90-180/200);
plot(angle,beam);
grid on
xlabel('方向角/degree');
ylabel('幅度响应/dB');
figure
for k=1:N
    en(k)=(abs(e(k))).^2;
end
semilogy(en);hold on
xlabel('N');
ylabel('MSE');
