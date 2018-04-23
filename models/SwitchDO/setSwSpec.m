        %% Set functions
        % Set tap specifications
        function setSwSpec(obj,nrSwPrDay,tMin)
            % Input:
            %   - nrSwPrDay [-], is the number of switches per day
            %   - tMin [s], is the minimum time between switches
            obj.nSwPrDay = nrSwPrDay;
            obj.tMin = tMin;
            obj.kMin = ceil(tMin/obj.Ts);
        end