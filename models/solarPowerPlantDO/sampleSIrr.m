        % Sample model
        function [Go,varNew] = sampleSIrr(obj,var,time,day,cc)
            % Input:
            %   k [-], is the sample number. Used for zenit angle
            %   day [-], is the Julian day of the year (1-365)
            %   cc [-], is cloud cover (0-1);
            %
            % Output:
            %   Go [w/m^2], is the irradiance on a horizontal surface.
            
            % Global beam and difuse irradiance
            cosz = zenitAngle(obj.lat,time,day);
            
            m= optAirmass(cosz,obj.p);
            
            Gb = beamIrradiance(cosz,obj.t,m);
            
            Gd = diffuseIrradiance(cosz,obj.t,m);
            
            
            % Stochastic insolation
            SIF= stochInsolFun(cc);
           
            
            % Total solar irradiation
            G = Gb*SIF + (1-cc)*Gd + cc*obj.tau*(Gb+Gd);
            [Go,varNew] = LPFilter(obj,var,G);
            [Go,varNew] = WFilter(obj,varNew,Go);
        end