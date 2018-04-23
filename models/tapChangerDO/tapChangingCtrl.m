        % Tap changing control
        function [y1,y2,y3,varNew] = tapChangingCtrl(obj,var,uRef,k)
            if uRef>var.tapPos && var.tapPos<obj.nTapUp && var.tapChOk == 1
                var.tapPos = var.tapPos + 1;
                [y1,y2,y3,varNew] = changeTrafoAdm(obj,var);
                var=varNew;
                var.tapChDay = var.tapChDay + 1;
                var.tapTimer = k+var.kMin;
            elseif uRef<var.tapPos && var.tapPos>obj.nTapDown && var.tapChOk == 1
                var.tapPos = var.tapPos - 1;
                [y1,y2,y3,varNew] = changeTrafoAdm(obj,var);
                var=varNew;
                var.tapChDay = var.tapChDay + 1; 
                var.tapTimer = k+var.kMin;
            else
                var.tapPos = var.tapPos;
                [y1,y2,y3,varNew] = changeTrafoAdm(obj,var);
            end
        end