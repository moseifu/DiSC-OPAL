        % Set Qmode and Q control function
        function setQmode(obj,Qmode)
            % Input:
            %   - Qmode=0: Power factor is kept constantly equal to PF.
            %   - Qmode=1: Reactive power is to qRef [PU].
            %   - Qmode=2: Reactive power is controlled as q = qFun(v,vRef,sMax) [VAR]
            
            % Set mode
            obj.Qmode = Qmode;
        end