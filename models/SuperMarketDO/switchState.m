        % Switch defrost state and update timers
        function varNew=switchState(obj,var,u)
            % Update timers
            varNew=var;
            varNew.readyTimers = var.readyTimers + obj.Ts;
            varNew.defrostTimers = var.defrostTimers + obj.Ts;
            varNew.waitTimers = var.waitTimers + obj.Ts;
            
            % Check for state change
            for i=1:2
                % In ready state
                if (varNew.states(i) == 0 && varNew.readyTimers(i) >= varNew.readyGuards(i)) || (varNew.states(i) == 0 && u(i) == 1)
                    varNew.states(i) = 1;
                    varNew.defrostTimers(i) = 0;
                % In defrost state
                elseif varNew.states(i) == 1 && varNew.defrostTimers(i) >= varNew.defrostGuards(i)
                    varNew.states(i) = 2;
                    varNew.waitTimers(i) = 0;
                % In wait state    
                elseif varNew.states(i) == 2 && varNew.waitTimers(i) >= varNew.waitGuards(i)
                    varNew.states(i) = 0;
                    varNew.readyTimers(i) = 0;
                else
                end
            end
        end