        % sample electrical vehicle
        function [p,q,e,away,varNew] = sampleEV(param,var,day,v,pRef,qRef,vRef,seed)
            % Input:
            %   - k [-], is the sample number.
            %   - day [day number], is the day of the year 1-365.
            %   - v [-], is the voltage at the connection point.
            %   - pRef [W], is the reference to active power.
            %   - qRef [VAR], is the reference to reactive power.
            %   - vRef [V], is the voltage reference.
            %
            % Output:
            %   - p [W], is the active power output.
            %   - q [VAR], is the reactive power output.
            %   - e [J], is the EV batery energy level.
            %   - away [-]. Indicates if the EV is available for charging.
            
            % If day changes calculate when EV is away from home and how
            % much the state of charge has changed.
            if day ~= var.dayOld
                [away,dSOC,varNew] = availabilityEV(param,var,day,seed);
                var=varNew;
                var.away=away;
                var.dSOC=dSOC;
                var.dayOld = day;
                var.h = 2;
            end
                       
            % Active power control
            [p,e,varNew] = pCtrlEV(param,var,pRef);  
            var=varNew;
            
            % Reactive power control
            [q,varNew] = qCtrlEV(param,var,p,v,qRef,vRef);
            var=varNew;
            
            % Iterate hour of the day.
            if ~mod(var.k,ceil(60*60/param.Ts))
                var.h = var.h + 1;
                var.temp = 0;
            end
            if(var.h>26)  %Otherwise we risc matlab to run into pointer errors later -> crash. 
                var.h=2;
            end
            
            p = -p;                 % Consumption is negative power flow
            q = -q;
            away = var.away(var.h); % Flag can be used by external controller
            varNew=var;
        end
        