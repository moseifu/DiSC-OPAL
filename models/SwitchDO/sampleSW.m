        % sample switch
        function [state,y,varNew] = sampleSW(obj,var,uRef,k,day)
            % Input:
            %   - uRef [-], is the reference to switch state (0=open, 1=closed).
            %   - k [-], is the sample.
            %   - day [-], is the day of the simulation (1-365).
            %
            % Output:
            %   - state [-], is the state of the switch, either open or closed.
            %   - y [-], is the admittance to be put into the grid admittance matrix.
            
            % If day changes reset the number of switches a day
            if day ~= var.dayOld
                var.swChDay = 0;
                var.dayOld = day;
            end
            
            % Switch state control
            [state,varNew] = swCtrl(obj,var,uRef,k);
            y = obj.Y;
        end