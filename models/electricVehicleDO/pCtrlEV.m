        % Active power control
        function [p,e,varNew] = pCtrlEV(param,var,pRef)
            if var.away(var.h) == 1 && var.away(var.h-1) == 0
                if var.temp == 0
                    var.eOld = max(0,var.eOld+var.eOld*sum(var.dSOC)/100);
                end
                p = 0;
                e = 0;
                var.temp = 1;
            elseif var.away(var.h) == 1
                p = 0;
                e = 0;
            elseif var.away(var.h) == 0
                if var.pMode == 0
                    pRef = param.pRated;
                elseif var.pMode == 1
                    pRef = pRef;
                else
                    error('Invalid mode for active power control.');
                end
                [p,e,varNew] = chargingEV(param,var,pRef);
                var=varNew;

            else
                p = 0;
                e = 0;
            end
            varNew=var;
        end