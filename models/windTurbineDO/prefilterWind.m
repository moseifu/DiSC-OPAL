
function wt = prefilterWind(w, Ts, r, pRated, rho, wRated, bLimit, eta)
    
    % Calculate the radius of the swept area
    cpMax = bLimit*eta;
    A = pRated/(0.5*rho*cpMax*wRated^3);
    r = sqrt(A/pi);

    wt=zeros(1,length(w));
    xOldsf=zeros(2,1);
    wOld=0;
    
    for i=1:length(w)
        [wt(i), xOldsf, wOld]=spatialFilter(w(i), Ts, r, xOldsf, wOld);
    end

end

% Spatial low pass filter
function [wt, xOldsf1, wOld1] = spatialFilter(w, Ts, r, xOldsf0, wOld0)
            if w<=0
                w= 0.001;
            end
            
            % This filter averages the wind speed over the area swept by
            % the rotor.
            a = 30;         % [-], is an empirical factor between 0 and 55
            gamma = 1.3;    % [-], is an empirical factor
            b = gamma*(r/w);
            
            % Create filter
            [A,B,C,D] = tf2ss([b sqrt(2)],[b^2 sqrt(2)*b/sqrt(a)+b*sqrt(a) sqrt(2)]);
            sys = ss(A,B,C,D); % Needs to be on ss form to use initial conditions in lsim
            
            % Run filter
            t = 0:Ts:Ts;
            [y,~,x] = lsim(sys,[wOld0 w],t, xOldsf0);
            xOldsf1 = x(end,:);
            wt = y(end);
            wOld1 = w;
end