        % Default droop control function
        function qRef = defaultDroopSC(param,v,vRef)
            % defaultQDroop is a reactive power droop control.
            %
            %   Input:
            %       - v is the bus voltage [PU].
            %       - vRef is the voltage reference [PU].
            %
            %   Output:
            %       - qRef is the reactive power reference [VAR].
            vMax = 1.1;
            vMin = 0.9;

            k = -2/(vMax-vMin);
            qRef = max(param.qRatedMax,abs(param.qRatedMin))*k*(v-vRef)/param.vBase;
        end