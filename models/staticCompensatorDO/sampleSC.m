        % sample capacitor bank system
        function q = sampleSC(param,v,qRef,vRef)
            % Input:
            %   - v [V], is the voltage magnitude on the bus.
            %   - qRef [VAR], is the reference to reactive power.
            %   - vRef [V], is the voltage reference.
            %
            % Output:
            %   - q [VAR], reactive power output.
            
            if param.onPU == true
                % Convert References to Physical Quantities
                qRef = qRef*param.sBase;
            end
            
            % Reactive power control
             q = qCtrlSC(param,v,qRef,vRef);
            
            if param.onPU == true
                % Normalize Output to Per Unit (PU)
                 q = q/param.sBase;
            end
        end