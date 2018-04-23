% Declination angle
function Ang = declinationAngle(day)
    % Input
    %   - day, is the julian day of the year
    %
    % Output
    %   - Ang [rad], is the declination angle in radians.
    
    % Two different methods of approximating the declenation angle is
    % provided. The latter one being the most precise.

    % Equation (1.3.3) from book
    Ang = 23.45*sin((360/365)*(284+day)*pi/180)*pi/180;
   
end