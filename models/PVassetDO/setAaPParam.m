%% Set/get functions
        % Set Ångström-Prescott parameters
        function setAaPParam(param,a,b)
            param.a = a;
            param.b = b;
            param.tau = a/(a+b);  
        end