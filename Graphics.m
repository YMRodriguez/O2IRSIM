l6= load('/home/yamilmateo/dev/PruebasIRIN/irsim_v1/irsim/outputFiles/layer6Output');
robotWheels= load('/home/yamilmateo/dev/PruebasIRIN/irsim_v1/irsim/outputFiles/robotWheels');
robotContacs= load('/home/yamilmateo/dev/PruebasIRIN/irsim_v1/irsim/outputFiles/robotContacs');

%% LAYER 0 Proximity sensors
% Gráficas
l0= load('/home/yamilmateo/dev/PruebasIRIN/irsim_v1/irsim/outputFiles/layer0Output');
time = l0(:,1);
IR0 = l0(:,2);
IR2 = l0(:,3);
IR4 = l0(:,4);
IR6 = l0(:,5);

IR0_plot= subplot(411);
plot(time,IR0, 'g'), grid
title('Layer0-ProxSensor0'), xlabel('Timesteps'), ylabel('Proximity')
axis([0 2582.6 0 1]);
IR2_plot= subplot(412);
plot(time,IR2, 'b'), grid
title('Layer0-ProxSensor2'), xlabel('Timesteps'), ylabel('Proximity')
axis([0 2582.6 0 1]);
IR4_plot= subplot(413);
plot(time,IR4, 'r'), grid
title('Layer0-ProxSensor4'), xlabel('Timesteps'), ylabel('Proximity')
axis([0 2582.6 0 1]);
IR6_plot= subplot(414);
plot(time,IR6, 'y'), grid
title('Layer0-ProxSensor6'), xlabel('Timesteps'), ylabel('Proximity')
axis([0 2582.6 0 1]);
subplot
%% LAYER 1 Ground Memory
% Gráficas
l1= load('/home/yamilmateo/dev/PruebasIRIN/irsim_v1/irsim/outputFiles/layer1Output');
time = l1(:,1);
GM = l1(:,2);

GM_plot = plot(time,GM, 'b');
grid
title('Layer1-GroundMemory'), xlabel('Timesteps'), ylabel('Ground Memory value')
axis([0 2582.6 0 1.3]);
%% LAYER 2 Light sensors
% Gráficas
l2= load('/home/yamilmateo/dev/PruebasIRIN/irsim_v1/irsim/outputFiles/layer2Output');
time = l2(:,1);
LS0 = l2(:,2);
LS1 = l2(:,3);
LS2 = l2(:,4);
LS3 = l2(:,5);
LS4 = l2(:,6);
LS5 = l2(:,7);
LS6 = l2(:,8);
LS7 = l2(:,9);

LS0_plot = subplot(421);
plot(time, LS0, 'y');
grid
title('Layer2-Light Sensor0'), xlabel('Timesteps'), ylabel('Light')
axis([0 2582.6 0 1]);

LS1_plot = subplot(422);
plot(time, LS1, 'y');
grid
title('Layer2-Light Sensor1'),xlabel('Timesteps'), ylabel('Light')
axis([0 2582.6 0 1]);

LS2_plot = subplot(423);
plot(time, LS2, 'y');
grid
title('Layer2-Light Sensor2'), xlabel('Timesteps'), ylabel('Light')
axis([0 2582.6 0 1]);

LS3_plot = subplot(424);
plot(time, LS3, 'y');
grid
title('Layer2-Light Sensor3'), xlabel('Timesteps'), ylabel('Light')
axis([0 2582.6 0 1]);

LS4_plot = subplot(425);
plot(time, LS4, 'y');
grid
title('Layer2-Light Sensor4'),xlabel('Timesteps'), ylabel('Light')
axis([0 2582.6 0 1]);

LS5_plot = subplot(426);
plot(time, LS5, 'y');
grid
title('Layer2-Light Sensor5'), xlabel('Timesteps'), ylabel('Light')
axis([0 2582.6 0 1]);

LS6_plot = subplot(427);
plot(time, LS6, 'y');
grid
title('Layer2-Light Sensor6'), xlabel('Time(s)'), ylabel('Light')
axis([0 2582.6 0 1]);

LS7_plot = subplot(428);
plot(time, LS7, 'y');
grid
title('Layer2-Light Sensor7'), xlabel('Timesteps'), ylabel('Light')
axis([0 2582.6 0 1]);
%% LAYER 3 BlueLight sensors
% Gráficas
l3= load('/home/yamilmateo/dev/PruebasIRIN/irsim_v1/irsim/outputFiles/layer3Output');
time = l3(:,1);
BL0 = l3(:,2);
BL1 = l3(:,3);
BL2 = l3(:,4);
BL3 = l3(:,5);
BL4 = l3(:,6);
BL5 = l3(:,7);
BL6 = l3(:,8);
BL7 = l3(:,9);

BL0_plot = subplot(421);
plot(time, BL0, 'b');
grid
title('Layer3-Blue Light Sensor0'), xlabel('Timesteps'), ylabel('Blue Light')
axis([0 2582.6 0 1]);

BL1_plot = subplot(422);
plot(time, BL1, 'b');
grid
title('Layer3-Blue Light Sensor1'), xlabel('Timesteps'), ylabel('Blue Light')
axis([0 2582.6 0 1]);

BL2_plot = subplot(423);
plot(time, BL2, 'b');
grid
title('Layer3-Blue Light Sensor2'),xlabel('Timesteps'), ylabel('Blue Light')
axis([0 2582.6 0 1]);

BL3_plot = subplot(424);
plot(time, BL3, 'b');
grid
title('Layer3-Blue Light Sensor3'), xlabel('Timesteps'), ylabel('Blue Light')
axis([0 2582.6 0 1]);

BL4_plot = subplot(425);
plot(time, BL4, 'b');
grid
title('Layer3-Blue Light Sensor4'), xlabel('Timesteps'), ylabel('Blue Light')
axis([0 2582.6 0 1]);

BL5_plot = subplot(426);
plot(time, BL5, 'b');
grid
title('Layer3-Blue Light Sensor5'), xlabel('Timesteps'), ylabel('Blue Light')
axis([0 2582.6 0 1]);

BL6_plot = subplot(427);
plot(time, BL6, 'b');
grid
title('Layer3-Blue Light Sensor6'), xlabel('Timesteps'), ylabel('Blue Light')
axis([0 2582.6 0 1]);

BL7_plot = subplot(428);
plot(time, BL7, 'b');
grid
title('Layer3-Blue Light Sensor7'), xlabel('Timesteps'), ylabel('Blue Light')
axis([0 2582.6 0 1]);
%% LAYER 4 Red Battery sensor
% Gráficas
l4= load('/home/yamilmateo/dev/PruebasIRIN/irsim_v1/irsim/outputFiles/layer4Output');
time = l4(:,1);
RB = l4(:,2);

RB_plot = plot(time,RB, 'r');
grid
title('Layer4-RedBattery'), xlabel('Timesteps'), ylabel('Red battery')
axis([0 2582.6 0 1.1]);
%% LAYER 5 BlueLight sensors
% Gráficas
l5= load('/home/yamilmateo/dev/PruebasIRIN/irsim_v1/irsim/outputFiles/layer5Output');
time = l5(:,1);
RL0 = l5(:,2);
RL1 = l5(:,3);
RL2 = l5(:,4);
RL3 = l5(:,5);
RL4 = l5(:,6);
RL5 = l5(:,7);
RL6 = l5(:,8);
RL7 = l5(:,9);

RL0_plot = subplot(421);
plot(time, RL0, 'r');
grid
title('Layer5-Red Light Sensor0'), xlabel('Timesteps'), ylabel('Red Light')
axis([0 2582.6 0 1]);

RL1_plot = subplot(422);
plot(time, RL1, 'r');
grid
title('Layer5-Red Light Sensor1'), xlabel('Timesteps'), ylabel('Red Light')
axis([0 2582.6 0 1]);

RL2_plot = subplot(423);
plot(time, RL2, 'r');
grid
title('Layer5-Red Light Sensor2'), xlabel('Timesteps'), ylabel('Red Light')
axis([0 2582.6 0 1]);

RL3_plot = subplot(424);
plot(time, RL3, 'r');
grid
title('Layer5-Red Light Sensor3'), xlabel('Timesteps'), ylabel('Red Light')
axis([0 2582.6 0 1]);

RL4_plot = subplot(425);
plot(time, RL4, 'r');
grid
title('Layer5-Red Light Sensor4'), xlabel('Timesteps'), ylabel('Red Light')
axis([0 2582.6 0 1]);

RL5_plot = subplot(426);
plot(time, RL5, 'r');
grid
title('Layer5-Red Light Sensor5'), xlabel('Timesteps'), ylabel('Red Light')
axis([0 2582.6 0 1]);

RL6_plot = subplot(427);
plot(time, RL6, 'r');
grid
title('Layer5-Red Light Sensor6'), xlabel('Timesteps'), ylabel('Red Light')
axis([0 2582.6 0 1]);

RL7_plot = subplot(428);
plot(time, RL7, 'r');
grid
title('Layer5-Red Light Sensor7'), xlabel('Timesteps'), ylabel('Red Light sensor')
axis([0 2582.6 0 1]);
%% LAYER 7 Motors
% Gráficas
l7= load('/home/yamilmateo/dev/PruebasIRIN/irsim_v1/irsim/outputFiles/layer7Output');
time = l7(:,1);
ML = l7(:,20);
MR = l7(:,21);

ML_plot = subplot(211);
plot(time,ML, 'g')
grid
title('Layer7-LeftMotor'), xlabel('Timesteps'), ylabel('Left Motor')
axis([0 2582.6 0 1.5]);
MR_plot = subplot(212);
plot(time,MR, 'b')
grid
title('Layer7-RightMotor'), xlabel('Timesteps'), ylabel('Right Motor')
axis([0 2582.6 0 1.5]);


%% Robot Position
% Gráficas
robotPosition= load('/home/yamilmateo/dev/PruebasIRIN/irsim_v1/irsim/outputFiles/robotPosition');

X = robotPosition(:,2);
Y = robotPosition(:,3);
c = linspace(1,10,length(X));
sz=5;
Pos_plot0 = scatter(X,Y,sz,c );
hold on
plot(X(1),Y(1),'ro','MarkerSize',10) 
grid
title('Recorrido'), ylabel('Mapa')
axis([-1.5 1.5 -1.5 1.5]);
%% Fitness evolution
fitnessLog=load('/home/yamilmateo/dev/PruebasIRIN/irsim_v1/irsim/geneticDataFiles/fitnessAdapted.log');
generation=fitnessLog(:,1);
best=fitnessLog(:,2);
mean=fitnessLog(:,3);
worst=fitnessLog(:,4);

BestPlot=plot(generation,best, '-b');
hold on
MeanPlot= plot(generation,mean, ':r');
hold on 
WorstPlot= plot(generation, worst, '--g');
legend('Best','Mean','Worst')
title('Evolución'), xlabel('Generación'), ylabel('Fitness value')