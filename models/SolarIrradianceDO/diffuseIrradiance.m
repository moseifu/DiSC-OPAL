% Diffuse irradiance
function Gd = diffuseIrradiance(cosz,t,m)
    S = 1353;   % Solar constant from NASA
    Gd = 0.3*(1-t^m)*S*cosz;
    
end