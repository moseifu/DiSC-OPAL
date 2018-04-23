        % Switch state control
        function [state,varNew] = swCtrl(obj,var,uRef,k)
            
            % Check if switch state changing is allowed
            varNew=swChAllowed(obj,var,k);
            var=varNew;
            
            % Check if switch state has changed
            if uRef ~= var.swState
               [state,varNew] = swChangingCtrl(obj,var,uRef,k);
               var=varNew;
            else
                state = var.swState;
            end   
            varNew=var;
        end
        