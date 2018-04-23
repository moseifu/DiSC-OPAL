        % Reactive power control
        function [q,varNew] = qCtrlCB(param,var,v,vRef,uRef)
            % Compute the tap reference
            if var.qMode == 0
                uRef = uRef;   
            elseif var.qMode == 1
               [uRef,varNew] = voltageControlCB(param,var,v,vRef);
               var=varNew;
            else
                error('Invalid reactive control mode only 0 or 1 is allowed.');
            end
            

            % Check if step changing is allowed
            varNew=stepChAllowedCB(param,var);
            var=varNew;
            
            % Check if step has changed
            if uRef ~= var.stepPos
                 [q,varNew] = stepChangingCtrlCB(param,var,uRef);
                 var=varNew;
            else
                q = var.stepPos*var.qStep;
                
            end
        end