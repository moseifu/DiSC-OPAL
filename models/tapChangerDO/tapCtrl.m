        % Tap position control
        function [y1,y2,y3,varNew] = tapCtrl(obj,var,v,vRef,uRef,k)
            % Compute the tap reference
            if var.mode == 0
                uRef = uRef;
            elseif var.mode == 1
                [uRef,varNew] = voltageControl(obj,var,v,vRef);
                var=varNew;
            else
                error('Invalid mode for tap changing transformer.');
            end
            
            % Check if tap changing is allowed
           
            varNew=tapChAllowed(obj,var,k);
            var=varNew;
            
            % Check if tap has changed
            if uRef ~= var.tapPos
                [y1,y2,y3,varNew] = tapChangingCtrl(obj,var,uRef,k);
            else
                y1 = var.y1;
                y2 = var.y2;
                y3 = var.y3;
            end         
        end