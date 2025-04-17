clear
clc
%% 参数设置
N = 167;     % 设置数据长度为N
t = (1:N);   % 生成时间轴
a = 1;       % 状态转移方程
b = 0;       % 控制输入
c = 1;       % 观测
x = 0;       % 设置初值 初始的均值和方差
sigma2 = 1;

V = 1;      % 设置生成的信号的噪声标准差
Q = 1;       % 设置状态转移方差Q和观测方差R
R = 1;       

%% 初始化
data = xlsread('data.xls');
real_signal = data';       % 真实信号
z           = zeros(1,N); % 观测数据

x_filter = zeros(1,N);    % 存储卡尔曼估计的结果，缓存起来用于画图形
K        = zeros(1,N);    % 存储卡尔曼预测中的增益k，缓存起来用于画图形

for i=1:N
   z(i) = real_signal(i) + normrnd(0, V);
end

%% 卡尔曼滤波
for i=1:N
    % 预测步
    x_ = a*x + b;            %预测当前状态
    sigma2_ = a*sigma2*a'+Q;

    % 更新步
    k = sigma2_*c'/(c*sigma2_*c'+R);
    x = x_ + k*(z(i) - c*x_);
    sigma2 = (1-k*c)*sigma2_;

    % 存储滤波结果
    x_filter(i) = x;
    K(i) = k;
end

%% 展示
% 卡尔曼增益k
plot(t, K);legend('K');
% 画出波形， 真实值 - 观测值 - 卡尔曼估计值
figure(2)
plot(t, real_signal, 'b', t, z, 'g', t, x_filter, 'r')
legend('真实值','观察值','滤波值');

