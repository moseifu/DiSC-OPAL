         %% Set functions  
        % Set pMode 
        function setQmode(obj,qMode)
            % Input:
            %   - qMode=0: Follow active power reference.
            %   - qMode=1: Active power is controlled as p = pFun(v,vRef) [W]
            
            % Set mode
            obj.qMode = qMode;
        end