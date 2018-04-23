% Script for testing wind speed class
clc; clear; close all;
rng(1);

% Setup
param.Ts = 60*10;
param.z = 35;
vMean = 12;
ws = windSpeed(param);

%% Simulate
N = 3000;
w = zeros(1,N);
ws.setNumVdhSpec(20);

for i=1:N
    w(i) = ws.sample(i,vMean);
end

%% Plotting
figure
plot(w)
ylabel('Wind Speed [m/s]')
xlabel('Time [samples]')

%%Saving to file
filename = sprintf('wind_%.2f.mat',vMean);
t=0:ws.Ts:(N-1)*ws.Ts;
output=[t; w];
save(filename,'output','-v7.3');