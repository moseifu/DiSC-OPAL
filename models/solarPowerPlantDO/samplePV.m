        % sample solar PV system
        function [p,q,pAva,varNew] = samplePV(obj,var,s,v,dP,dPlim,qRef,vRef)  
            % Input:
            %   - s [w/m^2], is the solar irradiance.
            %   - v [V], is the voltage at the connection point.
            %   - dP [W], is the reference to active power change.
            %   - dPlim [W], is the reference to derated power.
            %   - qRef [VAR], is the reactive power reference.
            %   - vRef [V], is the voltage reference.
            %
            % Output:
            %   - p [W], is the active power output
            %   - q [VAR], is the reactive power output
            %   - pAva [W], is the available power
            
            % Active power control
            [p,pAva] = pCtrlPV(obj,var,s,dP,dPlim);
            
            
            % Reactive power control
            q = qCtrlPV(obj,var,p,v,qRef,vRef);
            varNew=var;
            
            if obj.onPU == true
                % Normalize Output to Per Unit (PU)
                p = p/obj.sBase;
                q = q/obj.sBase;   
            end            
        end