% set mean and variance of cloud cover model
        function variNew=setMeanVarInternal(obj,vari,mean,var,x)
            vari.mean = mean;
            vari.var = var;
            vari.A1_m = vari.mean*x;
            vari.A0_m = (vari.A1_m - vari.mean*vari.A1_m)/vari.mean;
            W1 = vari.mean;
            W0 = 1-vari.mean;
            
            % Transition probability matrix
            vari.P(1,1) = W0+W1*exp((-obj.Aobs/obj.M)*((vari.A0_m+vari.A1_m)/(vari.A0_m*vari.A1_m)));
            vari.P(1,2) = W1-W1*exp((-obj.Aobs/obj.M)*((vari.A0_m+vari.A1_m)/(vari.A0_m*vari.A1_m)));
            vari.P(2,1) = W0-W0*exp((-obj.Aobs/obj.M)*((vari.A0_m+vari.A1_m)/(vari.A0_m*vari.A1_m)));
            vari.P(2,2) = W1+W0*exp((-obj.Aobs/obj.M)*((vari.A0_m+vari.A1_m)/(vari.A0_m*vari.A1_m)));
            variNew=vari;
        end