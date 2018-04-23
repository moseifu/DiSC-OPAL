% Beam irradiation
function Gb = beamIrradiance(cosz,t,m)
    S = 1353;   % Solar constant from NASA
    Gb = S*cosz*t^m;
    if Gb < 0
        Gb = 0;
    end
    
end