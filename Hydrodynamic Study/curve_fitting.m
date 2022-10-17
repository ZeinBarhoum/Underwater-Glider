alpha1=[-20,-15,-10,-5,0,5,10,15,20];
beta1=[0,0,0,0,0,0,0,0,0];
cd1=[30.1292,20.9971,15.3670,11.7071,10.2483,12.7535,16.8801,22.9779,31.0975];
cl1=[-95.0981,-83.6431,-56.0194,-23.4538,14.1667,50.3722,86.1813,117.0937,136.1510];
csf1=[5.99160,3.0370,1.3500,0.4373,-0.0430,0.6162,2.1149,3.3413,7.0748];
% csf1=[0,0,0,-3,0,0,0,0,0];
cm11=[0.7027,-0.0787,0.1292,-0.3795,0.0879,0.0026,0.0651,0.0794,0.2135];
cm21=[-6.1764,-5.0460,-3.1739,-1.1909,-0.1942,1.2544,3.3153,5.0244,6.5339];
cm31=[0.5059,-0.1036,-0.0122,0.0997,0.0039,0.0013,-0.0646,-0.3987,-0.1660]*-1;


alpha2=[0,0,0,0,0,0,0];
beta2=[15,10,5,0,-5,-10,-15];
cd2=[12.8248,11.8950,10.8211,10.2483,11.0412,11.8911,13.1404];
cl2=[9.1422,12.2332,11.9845,14.1667,13.5640,11.6823,10.1416];
csf2=[-6.1737,-4.1111,-2.2313,-0.0430,2.4811,4.0880,6.1876];
cm12=[0.0593,0.0289,-0.1721,0.0879,0.023,-0.0728,-0.07813];
cm22=[0.7698,0.4368,-0.1014,-0.1942,0.1692,0.4128,0.5376];
cm32=[-2.2385,-1.3217,-0.4220,-0.0039,0.2617,1.3061,2.2701];


alpha3=[5,5,5,5,5,5,5];
beta3=[15,10,5,0,-5,-10,-15];
cd3=[14.3128,13.6532,13.1937,12.7535,13.2794,13.9353,14.6695];
cl3=[39.1954,43.8955,49.0390,50.3722,49.1603,45.6224,40.5555];
csf3=[-7.3711,-5.2434,-2.8379,0.6162,4.0332,6.5779,8.6044];
cm13=[-0.7953,-0.3275,-0.1045,-0.0026,0.0062,0.3299,0.7613]*-1;
cm23=[3.6889,2.9093,1.7945,1.2544,1.7680,2.9844,3.8982];
cm33=[1.7365,0.7185,0.0599,0.0013,-0.1209,-0.6458,-1.6025]*-1;


alpha4=[-5,-5,-5,-5,-5,-5,-5];
beta4=[15,10,5,0,-5,-10,-15];
cd4=[13.7005,12.7567,12.1762,11.7071,12.2082,13.0183,13.9435];
cl4=[-15.7033,-18.7428,-22.4073,-23.4538,-23.1082,-21.7972,-19.0710];
csf4=[-7.0500,-4.8209,-2.3800,0.4373,2.9464,5.2932,7.6186];
cm14=[0.5865,0.2399,0.04863,0.3795,-0.2327,-0.2765,-0.6324]*-1;
cm24=[-2.6496,-2.1840,-1.3855,-1.1909,-1.4695,-2.1745,-2.6370];
cm34=[1.9113,1.0565,0.36211,0.0997,-0.3741,-1.0346,-1.9014]*-1;



alpha=[alpha1,alpha2,alpha3,alpha4]*pi/180;
beta=[beta1,beta2,beta3,beta4]*pi/180;

cd=[cd1,cd2,cd3,cd4];
cl=[cl1,cl2,cl3,cl4];
csf=[csf1,csf2,csf3,csf4];
cm1=[cm11,cm12,cm13,cm14];
cm2=[cm21,cm22,cm23,cm24];
cm3=[cm31,cm32,cm33,cm34];


curvecd=fit([alpha1]'*pi/180,cd1','poly2');
curvecsf=fit([alpha1]'*pi/180,csf1','poly2');
curvecl=fit([alpha1]'*pi/180,cl1','poly3');
curvecm2=fit([alpha1]'*pi/180,cm21','poly3');

figure
plot(curvecd,alpha1'*pi/180,cd1');
legend('original','fitting');
xlabel('alpha (rad)');
ylabel('Cd (Ns^2/m^2)');

figure
plot(curvecl,alpha1'*pi/180,cl1');
legend('original','fitting');
xlabel('alpha (rad)');
ylabel('Cl (Ns^2/m^2)');

figure
plot(curvecsf,alpha1'*pi/180,csf1');
legend('original','fitting');
xlabel('alpha (rad)');
ylabel('Csf (Ns^2/m^2)');

figure
plot(curvecm2,alpha1'*pi/180,cm21');
legend('original','fitting');
xlabel('alpha (rad)');
ylabel('Cm2 (Ns^2/m)');


surffitcd = fit([alpha',beta'],cd','poly22');
surffitcl = fit([alpha',beta'],cl','poly32');
surffitcsf = fit([alpha',beta'],csf','poly23');
surffitcm2 = fit([alpha',beta'],cm2','poly32');
surffitcm3 = fit([alpha',beta'],cm3','poly03');

figure
plot(surffitcd,[alpha',beta'],cd');
xlabel('alpha (rad)');
ylabel('beta (rad)');
zlabel('Cd (Ns^2/m^2)');

figure
plot(surffitcl,[alpha',beta'],cl');
xlabel('alpha (rad)');
ylabel('beta (rad)');
zlabel('Cl (Ns^2/m^2)');

figure
plot(surffitcsf,[alpha',beta'],csf');
xlabel('alpha (rad)');
ylabel('beta (rad)');
zlabel('Csf (Ns^2/m^2)');

figure
plot(surffitcm2,[alpha',beta'],cm2');
xlabel('alpha (rad)');
ylabel('beta (rad)');
zlabel('Cm2 (Ns^2/m)');

figure
plot(surffitcm3,[alpha',beta'],cm3');
xlabel('alpha (rad)');
ylabel('beta (rad)');
zlabel('Cm3 (Ns^2/m)');