        function [p,q,e,varNew] = sampleES(param,var,v,pRef,qRef,vRef)
            % Input:
            %   - v, is the voltage at the connection point.
            %   - pRef, is the reference to active power.
            %   - vRef, is the voltage reference for the droop control
            %
            % Output:
            %   - p [W], is the active power consumption
            %   - q [VAR], is the reactive power output
            %   - e [J], is the energy storage energy level
              
              
             % Active power control and energy level
             [p,e,varNew] = pCtrlES(param,var,v,vRef,pRef);
             var=varNew;
             
             
             % Reactive power control
             q = qCtrlES(param,var,p,v,qRef,vRef);
             
             p = -p;   % Negative is consumption
             q = q;
              
            

        end