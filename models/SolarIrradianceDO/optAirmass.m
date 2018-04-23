% Optical airmass
function m = optAirmass(cosz,p)
    m = p/(101.3*cosz);
    if m < 0
        m = 0;
    end
    
end