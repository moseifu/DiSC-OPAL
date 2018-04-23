         % Active power control
        function [p,pAva] = pCtrlPV(param,var,s,dP,dPlim)
            % Calculate Active Power Output
            pS = var.kPV*param.PF*s;      % [W] Available power
            pAva = pS;

            dP = min(dP,dPlim);         % [W] dP is limited by dPlim

            % Calculate gain from solar irradinace to power output
            if(pS>=param.pRated+dP-dPlim) % In full load operation
                p = max(0,param.pRated+dP-dPlim);
            else   
                dP = min(dP,0); % In partial load operation up-regulation is not possible
                p = max(0,pS+dP); % The output power must be positive
            end
        end