        % Voltage droop control function
        function qRef = droopPV(obj,var,v,vRef,qFun)
            % Choose between functions
            switch qFun
                % case 'qFun'
                % Input user defined droop control functions and add to
                % class
                otherwise
                    % Choose the default droop control function
                    qRef = defaultDroopPV(obj,var,v,vRef);
            end
        
        end