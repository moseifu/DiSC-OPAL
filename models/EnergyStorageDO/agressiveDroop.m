          % Agressive droop control function
        function pRef = agressiveDroopES(param,var,v,vRef)
             K = -0.2;
             pRef = obj.sMax*K*(vRef-v);

                
        end