        % Battery charging
        function [p,e,varNew] = chargingEV(param,var,pRef)

            % Handle constraint on charge rate
            if abs(pRef - var.pOld) > param.pRate
                pRef = var.pOld + param.pRate*sign(pRef - var.pOld);
            end
            
            if var.eOld >= param.eRated && pRef > 0
                e = param.eRated;
                p = 0;
            elseif var.eOld <= 0 && pRef < 0
                e = 0;
                p = 0;
            else
                if pRef <= 0
                    p = 0;
                elseif pRef >= param.pRated
                    p = param.pRated;
                else
                    p = pRef;
                end
                e = param.a*var.eOld + param.Ts*param.eta*p;
            end
            var.eOld = e;
            var.pOld = p;
            varNew=var;
        end
