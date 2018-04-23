        % Voltage reactive power droop control function
        function [qRef,varNew] = droopEV(param,var,v,vRef,qFun)
            % Choose between functions
            switch qFun
                % case 'qFun'
                % Input user defined droop control functions and add to
                % class
                otherwise
                    % Choose the default droop control function
                    [qRef,varNew] = defaultDroopEV(param,var,v,vRef);
                    var=varNew;
            end
        
        end