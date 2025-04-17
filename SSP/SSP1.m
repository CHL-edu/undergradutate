clear;
clc;
%===============================仿真场景===================================
Distance=10000;
T=1;
t=600;
Vx=-15;
QQ = 20;%100米wgn(1,1,20)
H=[1 0 0;0 1 0];
Q=[1 0 0;0 1 T;0 0 1];
eXk(:,t)=[0 0 0]';eXz(:,t)=[0 0 0]';eeXz(:,t)=[0 0]';
N=10;
for i=1:N
    for j=1:t
        Zk(:,j)=[2000+wgn(1,1,40);10000+Vx*T*(j-1)+wgn(1,1,QQ)];
    end
    for j=1:t
        if j==1
            Xk(:,1)=[Zk(1,1),Zk(2,1),0]';Xk1(:,1)=Xk(:,1);
            Xk(:,2)=[Zk(1,2),Zk(2,2),(Zk(2,2)-Zk(2,1))/T]';Xk1(:,2)=Xk(:,2);
            Pk=[Distance,0,0;0,Distance,Distance/T;0,Distance/T,2*Distance/T];
        else
            if j>2
                Xk1(:,j)=Q*Xk(:,j-1);%预测
                Pk1=Q*Pk*Q';%预测误差协方差
                Kk=Pk1*H'*inv(H*Pk1*H'+Distance*eye(2));%kalman增益
                Xk(:,j)=Xk1(:,j)+Kk*(Zk(:,j)-H*Xk1(:,j));%滤波
                Pk=(eye(3)-Kk*H)*Pk1;%滤波协方差
            end
        end
        %%
        %1000次求平均
        eXk(:,j)=eXk(:,j)+Xk(:,j)/N;%滤波
        eXz(:,j)=eXz(:,j)+([2000;10000+Vx*(j-1)*T;0]-Xk(:,j))/N;%滤波误差均值
        eeXz(:,j)=eeXz(:,j)+[(2000-Xk(1,j))^2;(10000+Vx*(j-1)*T-Xk(2,j))^2]/N;%滤波误差标准差
    end
end
%===========================绘图====================================
%真实轨迹和测量轨迹
dTT = 0.1;
j=0:dTT:t;
plot(10000+Vx*(j-1)*T,j-j+2000,'b');
hold on
scatter(Zk(2,:),Zk(1,:));
legend('真实','测量');xlim([500,10500]);view(90,-90);
title('测量轨迹');xlabel('Y(米)');ylabel('X(米)');
%滤波单次仿真和蒙特卡洛仿真
figure;
plot(Xk(2,:),Xk(1,:),'b',eXk(2,:),eXk(1,:),'r');title('滤波数据曲线');view(90,-90)
legend('单次','1000次');
xlabel('Y(米)');ylabel('X(米)');
%
j=1:t;
figure;subplot(211);plot(j,eXz(2,:));title('X滤波误差均值曲线');
xlabel('采样次数');ylabel('X(米)');
subplot(212);
for j=1:t
    eeXz(1,j)=sqrt(eeXz(1,j)-eXz(1,j)^2);
    eeXz(2,j)=sqrt(eeXz(2,j)-eXz(2,j)^2);
end
j=1:t;
plot(j,eeXz(2,:));title('x滤波误差标准差曲线');
xlabel('采样次数');ylabel('X(米)');
figure;subplot(211);plot(j,eXz(1,:));
title('y滤波误差均值曲线');xlabel('采样次数');ylabel('Y(米)');
subplot(212);plot(j,eeXz(1,1:600));title('y滤波误差标准差曲线');
xlabel('采样次数');ylabel('Y(米)');
figure;subplot(211);plot(Xk(3,1:300));title('单次滤波速度估计');
xlabel('采样次数');ylabel('V');
subplot(212);plot(j,eXk(3,1:600));title('1000次滤波速度估计');
xlabel('采样次数');ylabel('V');
%% 构建模型
t = 1:t;
k=length(t);
xx=zeros(1,length(t));
yy=zeros(1,length(t));
xx(:)=2000;%初始位置
yy(:)=10000;
v0=-15;%初始速度
a=0;%加速度
v=v0+a*t;
SS=v0*t+a.*t.*t/2;
yy=yy+SS;
%% 加入观测噪声
xx=xx+wgn(1,1,QQ);
yy=yy+wgn(1,1,QQ);
%% 最小二乘模型
HLSM=zeros(k,3);
for i=1:k
    HLSM(:,1)=1;
    HLSM(i,2)=t(i);
    HLSM(i,3)=0.5*t(i)*t(i);
end
zk=xx';
RLSM=(inv(HLSM'*HLSM))*HLSM'*zk;
disp(['初始位置 (2000,10000) 初速度' num2str(v0) 'm/s 加速度' num2str(a) 'm/s2']);
disp(['**********************************************************************************************']);
disp('最小二乘法：');
disp(['x轴：初始位置' num2str(RLSM(1)) 'm 初速度' num2str(RLSM(2)) 'm/s 加速度' num2str(RLSM(3)) 'm/s2']);
zk=yy';
RLSM=(inv(HLSM'*HLSM))*HLSM'*zk;
disp(['y轴：初始位置' num2str(RLSM(1)) 'm 初速度' num2str(RLSM(2)) 'm/s 加速度' num2str(RLSM(3)) 'm/s2']);
disp(['**********************************************************************************************']);
%% 最大似然模型
syms t;
xx=xx(1)+wgn(1,1,QQ);
yy=yy(1)+v0*t+0.5*a*t*t+wgn(1,1,QQ);
syms a b c;
s=a+b*t+0.5*c*t.*t;
aa=1;bb=t;cc=0.5*t.*t;%手工求导
rmle1=int((xx-s)*aa,t,1,k);
rmle2=int((xx-s)*bb,t,1,k);
rmle3=int((xx-s)*cc,t,1,k);
[RMLE1,RMLE2,RMLE3]=solve(rmle1,rmle2,rmle3,a,b,c);
disp('最大似然法：');
disp(['x轴：初始位置' num2str(double(RMLE1)) 'm 初速度' num2str(double(RMLE2)) 'm/s 加速度' num2str(double(RMLE3)) 'm/s2']);
rmle1=int((yy-s)*aa,t,1,k);
rmle2=int((yy-s)*bb,t,1,k);
rmle3=int((yy-s)*cc,t,1,k);
[RMLE1,RMLE2,RMLE3]=solve(rmle1,rmle2,rmle3,a,b,c);
disp(['y轴：初始位置' num2str(double(RMLE1)) 'm 初速度' num2str(double(RMLE2)) 'm/s 加速度' num2str(double(RMLE3)) 'm/s2']);

