        % Set guard times
        function setGuards(obj,readyGuards,defrostGuards,waitGuards)
            obj.readyGuards = readyGuards;
            obj.defrostGuards = defrostGuards;
            obj.waitGuards = waitGuards;
        end