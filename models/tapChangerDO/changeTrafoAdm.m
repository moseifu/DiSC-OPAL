        % Change admittance matrix
        function [y1,y2,y3,varNew] = changeTrafoAdm(obj,var)
            % Setup trafo admittances
            Ye = 1/obj.Z;
            n = obj.nomTapRatio - obj.chPrTap*obj.nomTapRatio*var.tapPos;
            c=1/n;
            y1 = (c)*Ye;
            y2 = (c^2-c)*Ye;
            y3 = (1-c)*Ye;
            var.y1 = y1;
            var.y2 = y2;
            var.y3 = y3;
            varNew=var;
        end