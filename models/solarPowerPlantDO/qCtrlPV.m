% Reactive power control
function q = qCtrlPV(obj,var,p,v,qRef,vRef)
            % Calculate Reactive Power Reference
            if(var.Qmode == 0)
                qRef = p*tan(acos(obj.PF));
            elseif(var.Qmode == 1)
                qRef = qRef;
            elseif(var.Qmode == 2)
                qRef = droopPV(obj,var,v,vRef,'');
            else
                error('Invalid mode for reactive power control.');
            end
            % Calculate Reactive Power Output
            qMax = sqrt(obj.sMax^2-p^2); % [Var] Upper limit on reactive power
            if(abs(qRef)>qMax)
                q = sign(qRef)*qMax;
            else
                q = qRef;
            end
        end
        

