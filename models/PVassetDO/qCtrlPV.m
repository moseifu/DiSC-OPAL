% Reactive power control
function q = qCtrlPV(param,var,p,v,qRef,vRef)
            % Calculate Reactive Power Reference
            if(var.Qmode == 0)
                qRef = p*tan(acos(param.PF));
            elseif(var.Qmode == 1)
                qRef = qRef;
            elseif(var.Qmode == 2)
                qRef = droopPV(param,var,v,vRef,'');
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
        end
        

