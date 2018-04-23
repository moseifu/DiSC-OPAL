        % Voltage control
        function [uRef,varNew] = voltageControl(obj,var,v,vRef)
            % Moving average filter on voltage
           [ v,varNew] = avgFilterTC(var,v);
           var=varNew;
            if v > vRef + var.vHyst && var.tapPos > obj.nTapDown 
                uRef = var.tapPos - 1;
            elseif v < vRef - var.vHyst && var.tapPos < obj.nTapUp
                uRef = var.tapPos + 1; 
            else
                uRef = var.tapPos;
            end
            
        end