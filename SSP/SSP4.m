clear
clc

%% 信号输入和信噪比设置
num=1000;
signal=zeros(1,num);% 发送信号 0或1
signal(1,:)=1;
SNR_rag=0.1:0.1:60;%信噪比范围
%% 接收机数量：1
result=zeros(1,num);
SNR_result1=zeros(1,length(SNR_rag));
for j=1:length(SNR_rag)
    SNR=SNR_rag(j);
    error=0;
    for i=1:length(signal)
        result(i)=receiver(signal(i),SNR);
        if(result(i)~=signal(i))
        error=error+1; 
        end
    end
    SNR_result1(j)=error/num;
end
plot(SNR_rag,SNR_result1);hold on;
xlabel('SNR');ylabel('误码率');
%% 接收机数量：2
result=zeros(1,num);
SNR_result2=zeros(1,length(SNR_rag));
for j=1:length(SNR_rag)
    SNR=SNR_rag(j);
    error=0;
    for i=1:length(signal)
        M1=receiver(signal(i),SNR);
        M2=receiver(signal(i),SNR);
        result(i)=round((M1+M2)/2);
        if(result(i)~=signal(i))
        error=error+1; 
        end
    end
    SNR_result2(j)=error/num;
end
plot(SNR_rag,SNR_result2);
%% 接收机数量：4
result=zeros(1,num);
SNR_result4=zeros(1,length(SNR_rag));
for j=1:length(SNR_rag)
    SNR=SNR_rag(j);
    error=0;
    for i=1:length(signal)
        M1=receiver(signal(i),SNR);
        M2=receiver(signal(i),SNR);
        M3=receiver(signal(i),SNR);
        M4=receiver(signal(i),SNR);
        result(i)=round((M1+M2+M3+M4)/4);
        if(result(i)~=signal(i))
        error=error+1; 
        end
    end
    SNR_result4(j)=error/num;
end
plot(SNR_rag,SNR_result4);
%% 接收机数量：6
result=zeros(1,num);
SNR_result6=zeros(1,length(SNR_rag));
for j=1:length(SNR_rag)
    SNR=SNR_rag(j);
    error=0;
    for i=1:length(signal)
        M1=receiver(signal(i),SNR);M2=receiver(signal(i),SNR);
        M3=receiver(signal(i),SNR);M4=receiver(signal(i),SNR);
        M5=receiver(signal(i),SNR);M6=receiver(signal(i),SNR);
        result(i)=round((M1+M2+M3+M4+M5+M6)/6);
        if(result(i)~=signal(i))
        error=error+1; 
        end
    end
    SNR_result6(j)=error/num;
end
plot(SNR_rag,SNR_result6);
%% 接收机数量：8
result=zeros(1,num);
SNR_result8=zeros(1,length(SNR_rag));
for j=1:length(SNR_rag)
    SNR=SNR_rag(j);
    error=0;
    for i=1:length(signal)
        M1=receiver(signal(i),SNR);M2=receiver(signal(i),SNR);
        M3=receiver(signal(i),SNR);M4=receiver(signal(i),SNR);
        M5=receiver(signal(i),SNR);M6=receiver(signal(i),SNR);
        M7=receiver(signal(i),SNR);M8=receiver(signal(i),SNR);
        result(i)=round((M1+M2+M3+M4+M5+M6+M7+M8)/8);
        if(result(i)~=signal(i))
        error=error+1; 
        end
    end
    SNR_result8(j)=error/num;
end
plot(SNR_rag,SNR_result8);
%% 接收机数量：16
result=zeros(1,num);
SNR_result16=zeros(1,length(SNR_rag));
for j=1:length(SNR_rag)
    SNR=SNR_rag(j);
    error=0;
    for i=1:length(signal)
        M1=receiver(signal(i),SNR);M2=receiver(signal(i),SNR);
        M3=receiver(signal(i),SNR);M4=receiver(signal(i),SNR);
        M5=receiver(signal(i),SNR);M6=receiver(signal(i),SNR);
        M7=receiver(signal(i),SNR);M8=receiver(signal(i),SNR);
        M9=receiver(signal(i),SNR);M10=receiver(signal(i),SNR);
        M11=receiver(signal(i),SNR);M12=receiver(signal(i),SNR);
        M13=receiver(signal(i),SNR);M14=receiver(signal(i),SNR);
        M15=receiver(signal(i),SNR);M16=receiver(signal(i),SNR);
        result(i)=round((M1+M2+M3+M4+M5+M6+M7+M8+M9+M10+M11+M12+M13+M14+M15+M16)/16);
        if(result(i)~=signal(i))
        error=error+1; 
        end
    end
    SNR_result16(j)=error/num;
end
plot(SNR_rag,SNR_result16);
%% 整理作图
legend('M=1','M=2','M=4','M=6','M=8','M=16');
figure;
subplot(231);
plot(SNR_rag,SNR_result1);
xlabel('SNR');ylabel('误码率');
title('M=1');
subplot(232);
plot(SNR_rag,SNR_result2);
xlabel('SNR');ylabel('误码率');
title('M=2');
subplot(233);
plot(SNR_rag,SNR_result4);
xlabel('SNR');ylabel('误码率');
title('M=4');
subplot(234);
plot(SNR_rag,SNR_result6);
xlabel('SNR');ylabel('误码率');
title('M=6');
subplot(235);
plot(SNR_rag,SNR_result8);
xlabel('SNR');ylabel('误码率');
title('M=8');
subplot(236);
plot(SNR_rag,SNR_result16);
xlabel('SNR');ylabel('误码率');
title('M=16');
%% 构建接收机模型
function result=receiver(signal,SNR)
N0=1;   % N0默认为1，根据SNR调整A0_2
A0_2=SNR*N0/2;

T=10;dt=0.1;
t=0:dt:T;

Ai=sqrt((-2*A0_2)*log(1-rand(1)));
fA=(Ai/A0_2)*exp(-Ai^2/2*A0_2); % A服从瑞利分布
Bi=sqrt((-2*A0_2)*log(1-rand(1)));
fB=(Bi/A0_2)*exp(-Bi^2/2*A0_2); % B服从瑞利分布

PH0=0.5;PH1=0.5;
w0=2*pi*10;
w1=2*pi*1000;                  % w1-w0很大
phi=2*pi*rand(1);
noise=sqrt(N0/2)*randn();      % 噪声功率谱密度等于噪声方差
% 发送信号
if(signal==0)
    s=Bi*sin(w0*t+phi);
else 
    s=Ai*sin(w1*t+phi);
end
% 接收信号
x_H0=Bi*sin(w0*t+phi)+noise;
x_H1=Ai*sin(w1*t+phi)+noise;
% 计算似然
f_slike0=likelihood(s,x_H0,dt,N0);
f_slike1=likelihood(s,x_H1,dt,N0);
% 判决
if(f_slike1/f_slike0>PH0/PH1) % 最小错误概率准则
    result=1;                 % 判决为1
else
    result=0;                 % 判决为0
end
end

%% 似然函数
function y=likelihood(s,x_H,dt,N0)
    M1=x_H-s;
    M2=M1.^2;
    M3=sum(M2)*dt;
    M4=-M3/N0;
    y=exp(M4);
end
