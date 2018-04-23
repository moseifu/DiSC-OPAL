        % Check if tap change is allowed
        function varNew=tapChAllowed(obj,var,k)
            if var.tapChDay >= obj.nTapPrDay
                var.tapChOk = 0;
            elseif k < var.tapTimer
                var.tapChOk = 0;
            elseif k > var.tapTimer
                var.tapChOk = 1;
            end
        varNew=var;
        end