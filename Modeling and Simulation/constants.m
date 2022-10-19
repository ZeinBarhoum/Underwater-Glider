clear;
m=50;
mh=40;
mp=9;
mf1=5;
mf2=60;
mf3=70;

jh1=5;
jh2=6;
jh3=4;


jf1=4;
jf2=6;
jf3=5;

g=9.81;

kd0=2.15;
kd=25;

kl0=0;
kl=132.5;

km0=0;
km=-100;

k1=50;
k2=50;

rbx=0;

Cnst=[jf1,jf2,jf3,jh1,jh2,jh3,mf1,mf2,mf3,mh,mp,rbx,m,g,kd0,kd,kl0,kl,km0,km,k1,k2];

mb0=1;
rpx0=0;
rpy0=0;
rpz0=0.05;

water_density=1000;

BE_rpm2mmps=6/60;
BE_syringe_d=26;
BE_syringe_r=BE_syringe_d/2000;
BE_syringe_A=pi*(BE_syringe_r^2);
BE_mm2ml=BE_syringe_A*1000;
BE_mm2cc=BE_mm2ml;
BE_cc2g=water_density/1000;
BE_rpm2kgps=BE_rpm2mmps*BE_mm2cc*BE_cc2g/1000;


MM_rpms2mmpss=6/60;
MM_mm2mm=49.39/217;
MM_MM_rpms2mpss=MM_rpms2mmpss*MM_mm2mm/1000;

RM_rpm2radps=2*pi/60;
RM_sintet2y=2;
RM_costet2z=2;
