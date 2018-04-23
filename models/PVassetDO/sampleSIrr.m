        % Sample model
        function [Go,varNew] = sampleSIrr(param,var,time,day,cc)
            % Input:
            %   k [-], is the sample number. Used for zenit angle
            %   day [-], is the Julian day of the year (1-365)
            %   cc [-], is cloud cover (0-1);
            %
            % Output:
            %   Go [w/m^2], is the irradiance on a horizontal surface.
            
            % Global beam and difuse irradiance
            cosz = zenitAngle(param.lat,time,day);
            
            m= optAirmass(cosz,param.p);
            
            Gb = beamIrradiance(cosz,param.t,m);
            
            Gd = diffuseIrradiance(cosz,param.t,m);
            
            
            % Stochastic insolation
            SIF= stochInsolFun(cc);
           
            
            % Total solar irradiation
            G = Gb*SIF + (1-cc)*Gd + cc*param.tau*(Gb+Gd);
            [Go,varNew] = LPFilter(param,var,G);
            [Go,varNew] = WFilter(param,varNew,Go);
        end