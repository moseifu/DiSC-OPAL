    % Low pass filter function (Own LP filter implemented)
        function [y,varNew] = LPFilter(obj,var,u)
            y = u*(obj.Ts/(obj.LPtau+obj.Ts)) + var.LPyOld*(obj.LPtau/(obj.LPtau+obj.Ts));
            var.LPyOld = y;
            varNew=var;
        end