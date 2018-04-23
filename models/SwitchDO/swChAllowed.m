        % Check if switch state change is allowed
        function varNew=swChAllowed(obj,var,k)
            if var.swChDay >= obj.nSwPrDay
                var.swChOk = 0;
            elseif k < var.swTimer
                var.swChOk = 0;
            elseif k > var.swTimer
                var.swChOk = 1;
            end
          varNew=var;
        end