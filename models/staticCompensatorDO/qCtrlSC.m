   % Reactive power control
        function q = qCtrlSC(param,v,qRef,vRef)
           
            % Calculate Reactive Power Reference
             if(param.Qmode == 0)
                qRef = qRef;
             elseif(param.Qmode == 1)
                 qRef = droopSC(param,v,vRef,'');
             else
                 error('Invalid mode for reactive power control.');
            end
             % Calculate Reactive Power Output and limit
            if qRef>param.qRatedMax
                 q = param.qRatedMax;
             elseif qRef < param.qRatedMin;
                 q = param.qRatedMin;
             else
                 q = qRef;
             end
        end