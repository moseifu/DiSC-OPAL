        % set mean and variance of cloud cover model for the Matlab version
        function setMeanVar(obj,mean,var)
            obj.mean = mean;
            obj.var = var;
            % Setup model
            f = @(x) obj.var - 2*(1-obj.mean)^2*obj.mean^2*x ...
                *(1-(1-obj.mean)*obj.mean*x*(1-...
                exp(-1/((1-obj.mean)*obj.mean) * 1/x)));
            x = fzero(f,1);
            obj.A1_m = obj.mean*x;
            obj.A0_m = (obj.A1_m - obj.mean*obj.A1_m)/obj.mean;
            W1 = obj.mean;
            W0 = 1-obj.mean;
            % Transition probability matrix
            obj.P(1,1) = W0+W1*exp((-obj.Aobs/obj.N)*((obj.A0_m+obj.A1_m)/(obj.A0_m*obj.A1_m)));
            obj.P(1,2) = W1-W1*exp((-obj.Aobs/obj.N)*((obj.A0_m+obj.A1_m)/(obj.A0_m*obj.A1_m)));
            obj.P(2,1) = W0-W0*exp((-obj.Aobs/obj.N)*((obj.A0_m+obj.A1_m)/(obj.A0_m*obj.A1_m)));
            obj.P(2,2) = W1+W0*exp((-obj.Aobs/obj.N)*((obj.A0_m+obj.A1_m)/(obj.A0_m*obj.A1_m)));
        end