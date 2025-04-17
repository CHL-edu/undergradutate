t=-4:0.01:4;
y=abs(sawtooth(pi*0.5*t,0.5));%生成周期三角波，占空比50%
n=[1 3 5 13 49];%将要求谐波级数放入n_max矩阵
N=length(n); %取n_max长度为循环控制变量
for k=1:N
    N=1:2:n(k);
    x=4./((pi*N).^2)*cos(pi * N' * t);%傅里叶变换中的余弦项
    figure;%创建新的图像，以免后画的图被覆盖
    plot(t,y);%画出原图像以对比
    hold on;
    x=x+0.5;%加上系数a0=0.5
    plot(t,x);%画出谐波近似的图像
    hold off;
    axis([-4 4 -0.5 1.5]),grid on;
    title(['最大谐波=',num2str(n(k))]);
end