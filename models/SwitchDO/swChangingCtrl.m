        % Switch state changing control
        function [state,varNew] = swChangingCtrl(obj,var,uRef,k)
            if obj.swChOk == 1
                state = uRef;
                var.swState = state;
                var.swChDay = var.swChDay + 1;
                var.swTimer = k+obj.kMin;
            else
                state = var.swState;
            end
            varNew=var;
        end