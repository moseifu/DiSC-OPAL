        % Moving average filter for the start and stop procidure of the
        % wind turbine
        function [wOut,varNew] = avgFilterWT(param,var,w)
            % Update data
            var.avgFilterBuf(2:end) = var.avgFilterBuf(1:end-1);
            var.avgFilterBuf(1) = w;
            wOut = sum(var.avgFilterBuf)/length(var.avgFilterBuf);
            varNew=var;
        end