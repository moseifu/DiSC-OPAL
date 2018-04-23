        % Moving average filter on voltage active power droop control
        function vOut = avgFilter(obj,v)
            % Update data
            obj.avgFilterBuf(2:end) = obj.avgFilterBuf(1:end-1);
            obj.avgFilterBuf(1) = v;
            vOut = sum(obj.avgFilterBuf)/length(obj.avgFilterBuf);
        end
        