        % sample capacitor bank
        function [q,varNew] = sampleCB(param,var,v,vRef,uRef,day)
            % Input:
            %   - v [V], is the voltage at the connection point.
            %   - qRef [VAR], is the reference to active power.
            %   - vRef [V], is the voltage reference for the droop control.
            %
            % Output:
            %   - q [VAR], is the reactive power output    
            
            % If day changes reset the number of steps a day
            if day ~= var.dayOld
                var.stepChDay = 0;
                var.dayOld = day;
            end
            
            % Reactive power control
            [q,varNew] = qCtrlCB(param,var,v,vRef,uRef);
            var=varNew;
            
            % Check if simulation is on PU basis
            if param.onPU == true
                % Normalize Output to Per Unit (PU)
                q = q/param.sBase;
            end
            

        end