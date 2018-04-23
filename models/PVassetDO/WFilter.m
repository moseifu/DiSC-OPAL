 % Window filter function
        function [y,varNew] = WFilter(param,var,u)
            y = param.Ts/param.WFT*u + var.WFyOld - param.Ts/param.WFT* var.WFuOld(end);
            var.WFyOld = y;
            var.WFuOld(2:end) = var.WFuOld(1:end-1);
            var.WFuOld(1) = u;
            varNew=var;
        end