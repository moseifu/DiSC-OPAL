        % Voltage droop control function
        function qRef = droopWT(param,var,v,vRef,qFun)
            % Choose between functions
            switch qFun
                % case 'qFun'
                % Input user defined droop control functions and add to
                % class
                otherwise
                    % Choose the default droop control function
                    qRef = defaultDroopWT(param,var,v,vRef);
            end
