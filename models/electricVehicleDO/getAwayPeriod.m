       % Mobility model functions
        % Away period
        function [away,awayStart] = getAwayPeriod(param,toCDF,fromCDF)
            away = zeros(1,24);
            % Pick from distribution
            eventTime1 = find(rand<toCDF,1,'first');
            eventTime2 = find(rand<fromCDF,1,'first');
            awayStart = min(eventTime1,eventTime2);
            % Away hours
            z=max(eventTime1,eventTime2);
            for i = awayStart(1):z(1)
                away(i) = 1;
            end
        end