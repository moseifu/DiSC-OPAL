         % Voltage droop control function
        function qRef = droopSC(param,v,vRef,qFun)
            % Choose between functions
            switch qFun
                % case 'qFun'
                % Input user defined droop control functions and add to
                % class
                otherwise
                    
                    % Choose the default droop control function
                    qRef = defaultDroopSC(param,v,vRef);
            end
        end