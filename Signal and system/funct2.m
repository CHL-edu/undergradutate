function f=funct1(t)
f=stepfun(t,-2)-stepfun(t,0)+(-t+1).*(stepfun(t,0)-stepfun(t,1));
end

