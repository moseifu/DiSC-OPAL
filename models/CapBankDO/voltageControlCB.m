        % Voltage control
        function  [uRef,varNew] = voltageControlCB(param,var,v,vRef)
            % Moving average filter on voltage
            [v, varNew] = avgFilterCB(param,var,v);
            var=varNew;
            % Voltage control algorithm
            if v > vRef + param.vHyst && var.stepPos > 0 
                uRef = var.stepPos - 1;
            elseif v < vRef - param.vHyst && var.stepPos < param.nSteps
                uRef = var.stepPos + 1; 
            else
                uRef = var.stepPos;
            end
            
        end