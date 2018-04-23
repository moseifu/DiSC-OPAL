        % Check if step change is allowed
        function varNew=stepChAllowedCB(param,var)
            if var.stepChDay >= param.nStepPrDay
                var.stepOk = 0;
            elseif var.k < var.stepTimer
                var.stepOk = 0;
            elseif var.k > var.stepTimer
                var.stepOk = 1;
            end
            varNew=var;
        end