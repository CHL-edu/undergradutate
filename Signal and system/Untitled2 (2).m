eq1='D2y+3*Dy+2*y=Dx+3*x';
eq2='x=exp(-3*t)*Heaviside(t)';
cond='y(-0.001)=0,Dy(-0.001)=0';
yzs=dsolve(eq1,eq2,cond);yzs=simplify(yzs.y)