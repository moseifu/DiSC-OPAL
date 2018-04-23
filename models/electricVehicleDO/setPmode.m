        % Set pMode 
        function setPmode(obj,pMode)
            % Input:
            %   - pMode=0: Charge as fast as possible, i.e., pRef = pRated.
            %   - pMode=1: Follow power reference
            
            % Set mode
            obj.pMode = pMode;
        end