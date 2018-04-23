        % Moving average filter on voltage for the tap changing
        function [vOut,varNew] = avgFilterTC(var,v)
            % Update data
            var.avgFilterBuf(2:end) = var.avgFilterBuf(1:end-1);
            var.avgFilterBuf(1) = v;
            vOut = sum(var.avgFilterBuf)/length(var.avgFilterBuf);
            varNew=var;
        end