        % sample wind turbine
        function [p,q,pAva,varNew] = sampleWT(obj,var,wt,v,dP,dPlim,qRef,vRef)
            % Input:
            %   - w [m/s], is the wind speed.
            %   - v [PU], is the voltage at the connection point.
            %   - dP [PU], is the reference to active power change (curtailment).
            %   - dPlim [PU], is the reference to derated power (derate).
            %   - qRef [PU], is the reactive power reference.
            %   - vRef [PU], is the voltage reference.
            %
            % Output:
            %   - p [W], is active power outpur.
            %   - q [VAR], is reactive power output.
            %   - pAva [W], is the available active power.
            
            %TODO: NEEDS TO BE DONE EXTERNALLY TO SIMULINK
            % Spatial filter
            % wt = spatialFilter(obj,w);
            
            % Active power control
            [p,pAva,varNew] = pCtrlWT(obj,var,wt,dP,dPlim);
             var=varNew;
            
            % Reactive power control
            q = qCtrlWT(obj,var,p,v,qRef,vRef);
                        
            [p,varNew] = rotorFilterWT(obj,var,p);
            var=varNew;
        end