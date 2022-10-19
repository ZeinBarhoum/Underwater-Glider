syms vx vy vz wx wy wz mh jh1 jh2 jh3 mp rpx rpy rpz drpx drpy drpz rbx mb dmb mf1 mf2 mf3 jf1 jf2 jf3 real;
v=[vx;vy;vz];
w=[wx;wy;wz];
rp=[rpx;rpy;rpz];
rb=[rbx;0;0];
srp=skew(rp);
srb=skew(rb);
drp=[drpx;drpy;drpz];
drb=[0;0;0];
jf=[jf1,0,0;
    0,jf2,0;
    0,0,jf3];
mf=[mf1,0,0;
    0,mf2,0;
    0,0,mf3];
jh=[jh1,0,0;
    0,jh2,0;
    0,0,jh3];
Ah=[mh*eye(3),0*eye(3);
    0*eye(3),jh];
Th=0.5*dot([v;w],Ah*[v;w]);

Ap=[mp*eye(3),-mp*srp,mp*eye(3);
    mp*srp,-mp*srp*srp,mp*srp;
    mp*eye(3),-mp*srp,mp*eye(3)];
Tp=0.5*dot([v;w;drp],Ap*[v;w;drp]);

Ab=[mb*eye(3),-mb*srb,mb*eye(3);
    mb*srb,-mb*srb*srb,mb*srb;
    mb*eye(3),-mb*srb,mb*eye(3)];
Tb=0.5*dot([v;w;drb],Ab*[v;w;drb]);

Af=[mf,0*eye(3);
    0*eye(3),jf];
Tf=0.5*dot([v;w],Af*[v;w]);
T=Th+Tp+Tb+Tf;
Px=diff(T,vx);
Py=diff(T,vy);
Pz=diff(T,vz);
PIx=diff(T,wx);
PIy=diff(T,wy);
PIz=diff(T,wz);
Ppx=diff(T,drpx);
Ppy=diff(T,drpy);
Ppz=diff(T,drpz);
A=Px;
I1=[diff(A,vx),diff(A,vy),diff(A,vz),diff(A,wx),diff(A,wy),diff(A,wz),diff(A,drpx),diff(A,drpy),diff(A,drpz)];

A=Py;
I2=[diff(A,vx),diff(A,vy),diff(A,vz),diff(A,wx),diff(A,wy),diff(A,wz),diff(A,drpx),diff(A,drpy),diff(A,drpz)];

A=Pz;
I3=[diff(A,vx),diff(A,vy),diff(A,vz),diff(A,wx),diff(A,wy),diff(A,wz),diff(A,drpx),diff(A,drpy),diff(A,drpz)];

A=PIx;
I4=[diff(A,vx),diff(A,vy),diff(A,vz),diff(A,wx),diff(A,wy),diff(A,wz),diff(A,drpx),diff(A,drpy),diff(A,drpz)];

A=PIy;
I5=[diff(A,vx),diff(A,vy),diff(A,vz),diff(A,wx),diff(A,wy),diff(A,wz),diff(A,drpx),diff(A,drpy),diff(A,drpz)];

A=PIz;
I6=[diff(A,vx),diff(A,vy),diff(A,vz),diff(A,wx),diff(A,wy),diff(A,wz),diff(A,drpx),diff(A,drpy),diff(A,drpz)];

A=Ppx;
I7=[diff(A,vx),diff(A,vy),diff(A,vz),diff(A,wx),diff(A,wy),diff(A,wz),diff(A,drpx),diff(A,drpy),diff(A,drpz)];

A=Ppy;
I8=[diff(A,vx),diff(A,vy),diff(A,vz),diff(A,wx),diff(A,wy),diff(A,wz),diff(A,drpx),diff(A,drpy),diff(A,drpz)];

A=Ppz;
I9=[diff(A,vx),diff(A,vy),diff(A,vz),diff(A,wx),diff(A,wy),diff(A,wz),diff(A,drpx),diff(A,drpy),diff(A,drpz)];

I=simplify([I1;I2;I3;I4;I5;I6;I7;I8;I9]);
Iinv=simplify(inv(I));
dIinv=simplify(diff(Iinv,rpx)*drpx+diff(Iinv,rpy)*drpy+diff(Iinv,rpz)*drpz+diff(Iinv,mb)*dmb);


matlabFunction(I,'File','Calculate_I');
matlabFunction(Iinv,'File','Calculate_Iinv');
matlabFunction(dIinv,'File','Calculate_dIinv');