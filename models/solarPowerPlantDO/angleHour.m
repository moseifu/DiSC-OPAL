% Angle hour
function Ha = angleHour(time)
    Ha = (12-time/(60*60))*15*pi/180; % pi/180 to get it in rad [rad]
    
end