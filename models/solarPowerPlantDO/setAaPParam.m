%% Set/get functions
        % Set Ångström-Prescott parameters
        function setAaPParam(obj,a,b)
            obj.a = a;
            obj.b = b;
            obj.tau = a/(a+b);  
        end