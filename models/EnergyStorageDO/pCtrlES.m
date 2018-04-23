         % Active power control
        function [p,e,varNew] = pCtrlES(param,var,v,vRef,pRef)
           
            % Calculate Active Power Output and energy level
            if var.pMode == 0
             elseif var.pMode == 1
                 %v = avgFilter(obj,v);
                 pRef = droopPES(param,var,v,vRef,'A');
             else
                 error('Invalid mode for active power control.');
            end
             
             % Handle constraint on charge rate
             if abs(pRef - var.pOld) > param.pRate
                 pRef = var.pOld + param.pRate*sign(pRef - var.pOld);
             end
             
             % Handle constraints on maximum and minimum levels
             if var.eOld >= param.eRated && pRef >= 0
                 e = param.eRated;
                 p = 0;
             elseif var.eOld <= 0 && pRef <= 0
                 e = 0;
                 p = 0;
             else
                 if pRef <= param.pRatedMin
                     p = param.pRatedMin;
                 elseif pRef >= param.pRatedMax
                     p = param.pRatedMax;
                 else
                     p = pRef;
                 end
                 if p >= 0
                     e = param.a*var.eOld + param.Ts*param.etaIn*p;
                 else
                     e = param.a*var.eOld + param.Ts*param.etaOut*p;
                end
             end
             var.pOld = p;
             var.eOld = e;
             varNew=var;
        end
        