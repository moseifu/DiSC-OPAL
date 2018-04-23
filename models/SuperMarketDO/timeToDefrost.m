        % Check time to ready and time to defrost
        function  [timeReady,timeDefrost] = timeToDefrost(obj,var)
          timeReady = zeros(2,1);
          timeDefrost = zeros(2,1);
            
          for i=1:2
                 % Ready state
                if var.states(i) == 0
                    timeReady(i) = 0;
                    timeDefrost(i) = var.readyGuards(i)-var.readyTimers(i);
                % Defrost state    
                elseif var.states(i) == 1
                     timeReady(i) = var.defrostGuards(i) + var.waitGuards(i) - var.defrostTimers(i);
                     timeDefrost(i) = var.defrostGuards(i) + var.waitGuards(i) + var.readyGuards(i) - var.defrostTimers(i);
                 % Wait state
                 elseif var.states(i) == 2
                    timeReady(i) = var.waitGuards(i) - var.waitTimers(i);
                    timeDefrost(i) = var.waitGuards(i) + var.readyGuards(i) - var.waitTimers(i);
                else
                 
                     error('Something went wrong...')
                 end
          end
                    
         end