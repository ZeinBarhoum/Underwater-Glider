function DP=Calculate_velocity_inertial(u)
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here
Cnsts=u(1:22);
Inps=u(23:33);
Vels=u(34:39);
Pos=u(40:45);

jf1=Cnsts(1);jf2=Cnsts(2);jf3=Cnsts(3);jh1=Cnsts(4);jh2=Cnsts(5);jh3=Cnsts(6);
mf1=Cnsts(7);mf2=Cnsts(8);mf3=Cnsts(9);mh=Cnsts(10);mp=Cnsts(11);rbx=Cnsts(12);
m=Cnsts(13);g=Cnsts(14);kd0=Cnsts(15);kd=Cnsts(16);kl0=Cnsts(17);kl=Cnsts(18);
km0=Cnsts(19);km=Cnsts(20);k1=Cnsts(21);k2=Cnsts(22);

rpx=Inps(1);rpy=Inps(2);rpz=Inps(3);mb=Inps(4);
drpx=Inps(5);drpy=Inps(6);drpz=Inps(7);dmb=Inps(8);
d2rpx=Inps(9);d2rpy=Inps(10);d2rpz=Inps(11);

rb=[rbx;0;0];
rp=[rpx;rpy;rpz];
drp=[drpx;drpy;drpz];
d2rp=[d2rpx;d2rpy;d2rpz];

vx=Vels(1);vy=Vels(2);vz=Vels(3);
wx=Vels(4);wy=Vels(5);wz=Vels(6);

v=[vx;vy;vz];
w=[wx;wy;wz];

bx=Pos(1);by=Pos(2);bz=Pos(3);
phi=Pos(4);theta=Pos(5);psi=Pos(6);

b=[bx;by;bz];

R = Calculate_R(phi,theta,psi);
dB=R*v;

R1=Calculate_R1(phi,theta);
dA=R1*w;

DP=[dB;dA];

end

function R = Calculate_R(ph,tet,ps)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here

R=[cos(ps)*cos(tet),-sin(ps)*cos(ph)+cos(ps)*sin(tet)*sin(ph),sin(ps)*sin(ph)+cos(ps)*sin(tet)*cos(ph);
   sin(ps)*cos(tet),cos(ps)*cos(ph)+sin(ps)*sin(tet)*sin(ph),-cos(ps)*sin(ph)+sin(ps)*sin(tet)*cos(ph);
   -sin(tet),cos(tet)*sin(ph),cos(tet)*cos(ph)];


end

function R1 = Calculate_R1(ph,tet)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here

if(abs(cos(tet))<1e-10)
    tet=tet+0.0001;
end

R1=[1,sin(ph)*tan(tet),cos(ph)*tan(tet);
    0,cos(ph),-sin(ph);
    0,sin(ph)/cos(tet),cos(ph)/cos(tet)];


end
