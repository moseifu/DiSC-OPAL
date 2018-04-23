% Stochastic insolation function (SIF)
function SIF = stochInsolFun(cc)
    % Simulates the irradic behavior of clouds on irradiance 
    % Input:
    %   cc [-], is the cloud cover (0-1)
    %
    % Output:
    %   SIF [-], is the state, either 0 or 1
    r = rand(1);
    if r<cc
        SIF = 0;
    else
        SIF = 1;
    end
end