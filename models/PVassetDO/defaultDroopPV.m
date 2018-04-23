        function qRef = defaultDroopPV(obj,var,v,vRef)
            % defaultQDroop is a reactive power droop control.
            %
            %   Input:
            %       - v is the bus voltage [PU].
            %       - vRef is the voltage reference [PU].
            %
            %   Output:
            %       - qRef is the reactive power reference [VAR].
            vMax = obj.vBase * 1.1;
            vMin = obj.vBase * 0.9;
            k = -2/(vMax-vMin);
            qRef = obj.sMax*k*(v-vRef);
        end