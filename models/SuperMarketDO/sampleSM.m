       % Run supermarket
        function  [p,q,timeReady,timeDefrost,varNew] = sampleSM(obj,var,exeDefrost,pRS);
            % Input:
            %   - exeDefrost [-], is the external control signal to execute defrost cycles.
            %   - pRS [W], is the power consumption of the refrigeration system, this should be provided as data.
            %
            % Output:
            %   - p [W], is the active power consumption of the supermarket.
            %   - q [VAR], is the reactive power consumption of the supermarket.
            %   - timeReady [s], is the time until defrost cycles are ready to be executed.
            %   - timeDefrost [s], is the time until the defrost cycles will be executed by the supermarket.
            
            % Power and time flexibility from defrost cycle
             [pDF,timeReady,timeDefrost,varNew] = pCtrlDefrost(obj,var,exeDefrost);
              
            % Normalize output to per unit (PU)
            if obj.onPU == true
                p = -(pRS + pDF)/obj.sBase;
                q = p*tan(acos(obj.PF))/obj.sBase;
            else
                p = -(pRS + pDF);
                q = p*tan(acos(obj.PF));
            end
            
        end