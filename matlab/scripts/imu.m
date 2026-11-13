%%
clear;
clc;
%%
w_tab = readtable("C:\Users\eoencue1\Desktop\Messungen\3\OpenEarable-0427-R-GYROSCOPE.csv");
a_tab = readtable("C:\Users\eoencue1\Desktop\Messungen\3\OpenEarable-0427-R-ACCELEROMETER.csv");
%%

w_data = table2array(w_tab);
a_data = table2array(a_tab);

%%
N = 750;
t = (0:N-1)' / 50;
dt = 1/50;
alpha = 0.99;

accel = [t, a_data(2:N+1, 2:4)];
gyro  = [t, deg2rad(w_data(1:N, 2:4))];

t0 = t(1);
t_end = t(N);

%%
a0   = mean(accel(1:50, 2:4), 1)';
a0   = a0 / norm(a0);
u    = [0; 0; 1];
n    = cross(a0, u);
phi0 = atan2(norm(n), dot(a0, u));
n    = n / norm(n);
q0   = [cos(phi0/2); n*sin(phi0/2)];