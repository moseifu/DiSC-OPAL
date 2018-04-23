        % Set qMode 
        function setQmode(obj,qMode)
            % Input:
            %   - pMode=0: Follow active power reference.
            %   - pMode=1: Active power is controlled as p = pFun(v,vRef) [W]
            
            % Set mode
            obj.qMode = qMode;
        end