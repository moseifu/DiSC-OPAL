        % Default droop control function
        function [y,varNew]  = defaultDroopEV(param,var,v,vRef)
            % defaultDroop is a active power droop control.
            %
            %   Input:
            %       - v is the bus voltage [PU or V].
            %       - vRef is the voltage reference [PU or V].
            %
            %   Output:
            %       - pRef is the active power reference [VAR].
            vMax = param.vBase * 1.1;
            vMin = param.vBase * 0.9;
            K = -2/(vMax-vMin);
            y = param.sMax*K*(vRef-v); 
            varNew=var;
        end