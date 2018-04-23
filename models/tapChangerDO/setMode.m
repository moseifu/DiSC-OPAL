        %% Set functions
        % Set mode 
        function varNew=setMode(var,mode)
            % Input:
            %   - pMode=0: Follow tap position reference.
            %   - pMode=1: Tap position is controlled according to voltage
            
            % Set mode
            var.mode = mode;
            varNew=var;
        end