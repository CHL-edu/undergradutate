function f=funct13(t)
t=-2:0.01:4;
f=heaviside(t+2)-heavisde(t)+(-t+1).*(heaviside(t)-heavisde(t-1));
end