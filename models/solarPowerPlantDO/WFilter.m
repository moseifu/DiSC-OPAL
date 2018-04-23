 % Window filter function
        function [y,varNew] = WFilter(obj,var,u)
            y = obj.Ts/obj.WFT*u + var.WFyOld - obj.Ts/obj.WFT* var.WFuOld(end);
            var.WFyOld = y;
            var.WFuOld(2:end) = var.WFuOld(1:end-1);
            var.WFuOld(1) = u;
            varNew=var;
        end