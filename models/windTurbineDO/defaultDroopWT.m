        % Default droop control function
        function qRef = defaultDroopWT(param,var,v,vRef)
            % defaultQDroop is a reactive power droop control.
            %
            %   Input:
            %       - v is the bus voltage [PU].
            %       - vRef is the voltage reference [PU].
            %
            %   Output:
            %       - qRef is the reactive power reference [VAR].
            vMax = param.vBase * 1.1;
            vMin = param.vBase * 0.9;
            k = -2/(vMax-vMin);
            qRef = param.sMax*k*(v-vRef);
        end