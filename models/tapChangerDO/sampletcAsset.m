         function [y1,y2,y3,varNew] = sampletcAsset(obj,var,v,vRef,uRef,k,day)
            % Input:
            %   - v, is the voltage at the connection point.
            %   - vRef, is the voltage reference for the voltage
            %     control.
            %   - uRef, is the reference to tap position.
            %   - k, is the sample.
            %   - day, is the day of the simulation (1-365).
            % 
            % Output:
            %   - y1, y2, y3, is the transformer admittances between busses,
            %     from ground to primary side bus and from ground to
            %     secondary side bus, respectively.
          
            
            % If day changes reset the number of tap changes a day
            if day ~= var.dayOld
                var.tapChDay = 0;
                var.dayOld = day;
            end
            
            % Tap position control
            [y1,y2,y3,varNew] = tapCtrl(obj,var,v,vRef,uRef,k);
        end