        %% Set and get functions
        % Set power factor
        function setPF(param,PF)
            if PF<0
                PF = 0;
            elseif PF>1;
                PF = 1;
            end
            param.PF = PF;
        end