% Script for testing wind speed class
clc; clear; close all;
rng(1);

% Parameters
rho = 1.225;                % [kg/m^3]. Is the density of air (at 15 degrees C)
bLimit = 0.593;             % [-]. Betz limit
eta = 0.9;                  % [-]. Effiency of the wind power system
r=10;                       % [m]. Radius of swept area
pRated = 100e3;
wRated = 12;

% Setup
param.Ts = 1;
param.z = 35;
vMean = 9;
ws = windSpeed(param);

%% Simulate
N = 3000;
w = zeros(1,N);
ws.setNumVdhSpec(20);

for i=1:N
    w(i) = ws.sample(i,vMean);
end

%%Saving to file
filename = sprintf('wind_%.2f.mat',vMean);
t=0:ws.Ts:(N-1)*ws.Ts;
output=[t; w];
save(filename,'output','-v7.3');

%%Generate prefiltered windfile thingy
wt = prefilterWind(w, ws.Ts, r, pRated, rho, wRated, bLimit, eta);
filename = sprintf('windpf_%.2f.mat',vMean);
t=0:ws.Ts:(N-1)*ws.Ts;
output=[t; w];
save(filename,'output','-v7.3');

%% Plotting
figure
plot(t,w,'r',t,wt,'b')
ylabel('Wind Speed [m/s]')
xlabel('Time [samples]')

