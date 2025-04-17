
I = im2double(imread('fuzzytree.jpg'));
figure();
subplot(2,2,1);
imshow(I);
title('原始图片');
 
% 模拟加噪
LEN = 21;
THETA = 11;
PSF = fspecial('motion', LEN, THETA);
blurred = imfilter(I, PSF, 'conv', 'circular');
noise_mean = 0;
noise_var = 0.0001;
blurred_noisy = imnoise(blurred, 'gaussian', ...
                  noise_mean, noise_var);
subplot(2,2,2);
imshow(blurred_noisy)
title('模拟模糊和噪点')
 
% 假设没有噪音，请尝试恢复。
estimated_nsr = 0;
wnr2 = deconvwnr(blurred_noisy, PSF, estimated_nsr);
subplot(2,2,3);
imshow(wnr2)
title('使用NSR = 0,恢复模糊的图像')
 
% 使用估计的NSR恢复模糊的噪点图像
estimated_nsr = noise_var / var(I(:));
wnr3 = deconvwnr(blurred_noisy, PSF, estimated_nsr);
subplot(2,2,4);
imshow(wnr3)
title('使用估计的NSR恢复模糊的噪点图像');