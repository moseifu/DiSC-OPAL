        % Set tap specifications
        function setTapSpec(obj,var,nrTapUp,nrTapDown,nrTapPrDay,tMin,chPrTap,hyst)
            % Input:
            %   - nrTapUp, is the number of tap positions upwards (Default 5)
            %   - nrTapDown, is the number of tap positions downwards (Default 5)
            %   - nrTapPrDay, is the maximum number of tap changes per day (Default 10)
            %   - tmin, is the minimum time between taps (Default 5 min, 5*60)
            %   - chPrTap, is the change in ratio from nomial position on a
            %     per unit basis (Default 0.0125, equal to 1.25%)
            %   - hyst, is the hysterisis on the voltage when applying
            %     voltage control (Default is 0.03 p.u.)
            
            obj.nTapUp = nrTapUp;
            obj.nTapDown = -nrTapDown;
            obj.nTapPrDay = nrTapPrDay;
            obj.tMin = tMin;
            obj.kMin = tMin/obj.Ts;
            obj.chPrTap = chPrTap;
            var.vHyst = hyst*obj.vBase;
        end
