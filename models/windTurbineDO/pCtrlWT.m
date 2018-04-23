        % Active power control
        function [p,pAva,varNew] = pCtrlWT(param,var,w,dP,dPlim)
            % Calculate Active Power Output
            pW = var.kWT*param.PF*w^3;    % [W] Available power
            % Output the available power of the wind turbine
            if pW >= param.pRated
                pAva = param.pRated;
            elseif pW <= 0
                pAva = 0;
            else
                pAva = pW;
            end

            dP = min(dP,dPlim); % [W] dP is limited by dPlim
            
            % Get average of wind for start and stop of turbine
            [w,varNew] = avgFilterWT(param,var,w);

            % Calculate gain from wind disturbance to power output
            if(w<param.wMin || w>param.wMax) % Out of normal operating range [wMin wMax] (in reality these should be 10 min mean values)
                p = 0;
            elseif(pW>=param.pRated+dP-dPlim) % In full load operation
                p = max(0,param.pRated+dP-dPlim); % The output power must be positive
            else   
                dP = min(dP,0); % In partial load operation up-regulation is not possible
                p = max(0,pW+dP); % The output power must be positive
            end

        end
