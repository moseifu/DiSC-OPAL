% Solar Zenit angle
function cosz = zenitAngle(lat,time,day)
     dAng = declinationAngle(day);
     Ha = angleHour(time);
    cosz = sin(lat*pi/180)*sin(dAng)+cos(lat*pi/180)*cos(dAng)*cos(Ha);
end