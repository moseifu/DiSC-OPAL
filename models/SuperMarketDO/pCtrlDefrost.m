          % Defrost cycles
          
        function [pDF,timeReady,timeDefrost,varNew] = pCtrlDefrost(obj,var,exeDefrost)
            % Input:
            %   - k [-], is the sample
            %   - exeDefrost [-], is the input that can start a defrost
            %     cycle. It is a vector with as many entries as
            %     controllable defrost cycles. A 1 in a entry indicates
            %     activation
            %
            % Output:
            %   - pDF [W], is the aggregated power consumption of all
            %     defrost cycles.
            %   - timeDefrost [s], is the time until a defrost is ready for
            %     activation. It is a vector with as many entries as
            %     controllable defrost cycles.
            
            % Get time to ready state and time to defrost
            [timeReady,timeDefrost] = timeToDefrost(obj,var);
            
            % Check defrost state and timers
             varNew=switchState(obj,var,exeDefrost);
             
            %Output power
            varNew.pVec = zeros(2,1); %set on properties
            for i=1:2
                if varNew.states(i) == 1
                    varNew.pVec(i) = obj.pDefrost(i);
                else
                    varNew.pVec(i) = 0;
                end
            end
            pDF = sum(varNew.pVec);
            
            
        end
        