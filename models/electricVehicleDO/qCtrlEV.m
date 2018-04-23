        % Reactive power control
        function [q,varNew] = qCtrlEV(param,var,p,v,qRef,vRef)
            % Calculate Reactive Power Reference
            if(var.qMode == 0)
                qRef = p*tan(acos(param.PF));
            elseif(var.qMode == 1)
                qRef = qRef;
            elseif(var.qMode == 2)
               [qRef,varNew] = droopEV(param,var,v,vRef,'');
               var=varNew;
            else
                error('Invalid mode for reactive power control.');
            end
            % Calculate Reactive Power Output
            qMax = sqrt(param.sMax^2-p^2); % [Var] Upper limit on reactive power
            if(abs(qRef)>qMax)
                q = sign(qRef)*qMax;
            else
                q = qRef;
            end
            varNew=var;
        end