         % Voltage active power droop control function
        function pRef = droopPES(param,var,v,vRef,pFun)
           
             % Choose between functions
             switch pFun
                 case 'A'
                    pRef = agressiveDroopES(param,var,v,vRef);
                 % Input user defined droop control functions and add to
                 % class
                 otherwise
                     
                     % Choose the default droop control function
                     pRef = defaultDroop(param,var,v,vRef);
             end
        
        end