        % Set pMode 
        function setPmode(obj,pMode)
            % Input:
            %   - pMode=0: Follow active power reference.
            %   - pMode=1: Active power is controlled as p = pFun(v,vRef) [W]
            
            % Set mode
            obj.pMode = pMode;
        end