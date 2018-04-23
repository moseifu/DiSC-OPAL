        % Set drain rate (For ideal storage, a = 1)
        function setDrain(obj,a)
            if a<0
                a = 0;
            elseif a>1;
                a = 1;
            end
            obj.a = a;
        end