         %% Set functions
        % Set Qmode and Q control function
        function setQmode(param,Qmode)
            % Input:
            %   - Qmode=0: Reactive power is to qRef [PU].
            %   - Qmode=1: Reactive power is controlled as q = qFun(v,vRef,sMax) [VAR]
            
            % Set mode
            param.Qmode = Qmode;
        end