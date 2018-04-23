        % set mean and variance of cloud cover model for the Matlab version
        function setMeanVar(param,mean,var)
            param.mean = mean;
            param.var = var;
            % Setup model
            f = @(x) param.var - 2*(1-param.mean)^2*param.mean^2*x ...
                *(1-(1-param.mean)*param.mean*x*(1-...
                exp(-1/((1-param.mean)*param.mean) * 1/x)));
            x = fzero(f,1);
            param.A1_m = param.mean*x;
            param.A0_m = (param.A1_m - param.mean*param.A1_m)/param.mean;
            W1 = param.mean;
            W0 = 1-param.mean;
            % Transition probability matrix
            param.P(1,1) = W0+W1*exp((-param.Aobs/param.N)*((param.A0_m+param.A1_m)/(param.A0_m*param.A1_m)));
            param.P(1,2) = W1-W1*exp((-param.Aobs/param.N)*((param.A0_m+param.A1_m)/(param.A0_m*param.A1_m)));
            param.P(2,1) = W0-W0*exp((-param.Aobs/param.N)*((param.A0_m+param.A1_m)/(param.A0_m*param.A1_m)));
            param.P(2,2) = W1+W0*exp((-param.Aobs/param.N)*((param.A0_m+param.A1_m)/(param.A0_m*param.A1_m)));
        end