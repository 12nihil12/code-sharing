%% m1 sonar
x=[0.02011 0.03991 0.05959 0.07959];
yo=[0.061 0.124 0.186 0.249];
ye=[0.061 0.124 0.186 0.249]; 
err=[0.001 0.001 0.001 0.001]; 
figure('Name', 'm1-stat-sonar')
plot(x,ye, 'r')
hold on
errorbar(x,yo, err, 'o b')
xlabel('Dm [kg]')
ylabel('Dh [m]')

%%m1 calibro

x=[0.02011 0.03991 0.05959 0.07959];
yo=[0.073 0.136 0.200 0.258]; 
ye=[0.074 0.136 0.197 0.260];
err=[0.001 0.001 0.001 0.001]; 
figure('Name', 'm1-stat-calibro')
plot(x,ye, 'm')
hold on
errorbar(x,yo, err, 'o k')
xlabel('Dm [kg]')
ylabel('Dh [m]')

%%m1 confronto

x=[0.02011 0.03991 0.05959 0.07959];
yoc=[0.073 0.136 0.200 0.258]; 
yec=[0.074 0.136 0.197 0.260];
yos=[0.061 0.124 0.186 0.249];
yes=[0.061 0.124 0.186 0.249]; 
err=[0.001 0.001 0.001 0.001]; 
figure('Name', 'm1-sonar/calibro')
plot(x,yes,'r -')
hold on
plot(x,yec, 'm -')
hold on
errorbar(x,yos,err,'o b')
hold on
errorbar(x,yoc,err, 'k o ')
xlabel('Dm [kg]')
ylabel('Dh [m]')


%% m2 sonar 
x=[0.02008 0.03991 0.05985 0.07958 0.09964 0.11962 0.13948 0.15941 0.17962];
yo=[0.0069 0.0150 0.0226 0.0303 0.0378 0.0455 0.0539 0.0614 0.0691]; 
ye=[0.0063 0.0142 0.0221 0.0299 0.0379 0.0458 0.0536 0.0615 0.0695]; 
err=[0.0005 0.0006 0.0004 0.0005 0.0004 0.0005 0.0004 0.0004 0.0005]; 
figure('Name', 'm2-stat-sonar')
plot(x,ye,'r')
hold on
errorbar(x,yo,err,'b o')
xlabel('Dm [kg]')
ylabel('Dh [m]')


%% m2 calibro

x=[0.03991 0.09964 0.13948 0.17962];
yo=[0.0142 0.0363 0.0526 0.0681]; 
ye=[0.0139 0.0370 0.0524 0.06796]; 
err=[0.0003 0.0005 0.0008 0.0002 ]; 
figure('Name','m2-stat-calibro')
plot(x,ye,'m')
hold on
errorbar(x,yo, err, 'o k')
xlabel('Dm [kg]')
ylabel('Dh [m]')


%% m2 confronto

xs=[0.02008 0.03991 0.05985 0.07958 0.09964 0.11962 0.13948 0.15941 0.17962];
yos=[0.0069 0.0150 0.0226 0.0303 0.0378 0.0455 0.0539 0.0614 0.0691]; 
yes=[0.0063 0.0142 0.0221 0.0299 0.0379 0.0458 0.0536 0.0615 0.0695]; 
errs=[0.0005 0.0006 0.0004 0.0005 0.0004 0.0005 0.0004 0.0004 0.0005];
xc=[0.03991 0.09964 0.13948 0.17962];
yoc=[0.0142 0.0363 0.0526 0.0681]; 
yec=[0.0139 0.0370 0.0524 0.06796];  
errc=[0.0003 0.0005 0.0008 0.0002 ]; 
figure('Name', 'm2-sonar/calibro')
plot(xs,yes,'r -')
hold on
plot(xc,yec, 'm -')
hold on
errorbar(xs,yos,errs,'b o')
hold on
errorbar(xc,yoc,errc, 'k o ')
xlabel('Dm [kg]')
ylabel('Dh [m]')
