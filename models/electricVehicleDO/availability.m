        % Calculate if car is available at home or away and the change its
        % state of charge
        function [away, dSOC]  = availability(obj,dayNumber,seed)
            if ~mod(dayNumber,7)
                dayNumber = 7;
            else
                dayNumber = mod(dayNumber,7);
            end
            
            dSOC = zeros(1,length(obj.fromBusiness));
            CommutingAway = zeros(1,length(obj.fromBusiness));
            rng(dayNumber+seed); 
            coder.extrinsic('random'); %The function 'random' is not supported for standalone code generation. See the documentation for coder.extrinsic to learn how you can use this function in simulation.
            q=0;                           %placeholder for q , not allowed without placeholder
            q=random('unif',0,1);
         
            if(q<(obj.CommutingPerYear(dayNumber)/obj.individualDayOfWeekPerYear))
                disp('EV: Commuting activity');
                [CommutingAway,CommutingStart] = getAwayPeriod(obj,obj.toCommutingCDF,obj.fromCommutingCDF);
                % Calculate change in state of charge (SoC), where negative means discharge
                dSOC(CommutingStart) = dSOC(CommutingStart)-obj.CommutingLength*obj.avgMileage;
            end
            rng(dayNumber+1+seed);
            q=random('unif',0,1);
            
            BusinessAway = zeros(1,length(obj.fromBusiness));
            if(q<obj.BusinessPerYear(dayNumber)/obj.individualDayOfWeekPerYear)
                disp('EV: Business away activity');
                [BusinessAway,BusinessStart] = getAwayPeriod(obj,obj.toBusinessCDF,obj.fromBusinessCDF);
                % Calculate change in state of charge (SoC), where negative means discharge
                dSOC(BusinessStart) = dSOC(BusinessStart)-obj.BusinessLength*obj.avgMileage;
            end
            rng(dayNumber+2+seed);
            q=random('unif',0,1);
             
            EducationAway = zeros(1,length(obj.fromBusiness));
            if(q<obj.EducationPerYear(dayNumber)/obj.individualDayOfWeekPerYear)
                disp('EV: Education away activity');
                [EducationAway,EducationStart] = getAwayPeriod(obj,obj.toEducationCDF,obj.fromEducationCDF);
                % Calculate change in state of charge (SoC), where negative means discharge
                dSOC(EducationStart) = dSOC(EducationStart)-obj.EducationLength*obj.avgMileage;
            end
            rng(dayNumber+3+seed);
            q=random('unif',0,1);
            
            EscortEducationAway = zeros(1,length(obj.fromBusiness));
            if(q<obj.EscortEducationPerYear(dayNumber)/obj.individualDayOfWeekPerYear)
                disp('EV: Escort education activity');
                [EscortEducationAway,EscortEducationStart] = getAwayPeriod(obj,obj.toEscortEducationCDF,obj.fromEscortEducationCDF);
                % Calculate change in state of charge (SoC), where negative means discharge
                dSOC(EscortEducationStart) = dSOC(EscortEducationStart)-obj.EscortEducationLength*obj.avgMileage;
            end
            rng(dayNumber+4+seed);
           q=random('unif',0,1);
            
            ShoppingAway = zeros(1,length(obj.fromBusiness));
            if(q<obj.ShoppingPerYear(dayNumber)/obj.individualDayOfWeekPerYear)
                disp('EV: Shopping away activity');
                [ShoppingAway,ShoppingStart] = getAwayPeriod(obj,obj.toShoppingCDF,obj.fromShoppingCDF);
                % Calculate change in state of charge (SoC), where negative means discharge
                dSOC(ShoppingStart) = dSOC(ShoppingStart)-obj.ShoppingLength*obj.avgMileage;
            end
            rng(dayNumber+5+seed);
             q=random('unif',0,1);
             
            OtherEscortAway = zeros(1,length(obj.fromBusiness));
            if(q<obj.OtherEscortPerYear(dayNumber)/obj.individualDayOfWeekPerYear)
                disp('EV: Other escort activity');
                [OtherEscortAway,OtherEscortStart] = getAwayPeriod(obj,obj.toPersonalBusinessOtherEscortCDF,obj.fromPersonalBusinessOtherEscortCDF);
                % Calculate change in state of charge (SoC), where negative means discharge
                dSOC(OtherEscortStart) = dSOC(OtherEscortStart)-obj.OtherEscortLength*obj.avgMileage;
            end
            rng(dayNumber+6+seed);
            q=random('unif',0,1);
             
            PersonalBusinessAway = zeros(1,length(obj.fromBusiness));
            if(q<obj.PersonalBusinessPerYear(dayNumber)/obj.individualDayOfWeekPerYear)
                disp('EV: Personal business activity');
                [PersonalBusinessAway,PersonalBusinessStart] = getAwayPeriod(obj,obj.toPersonalBusinessOtherEscortCDF,obj.fromPersonalBusinessOtherEscortCDF);
                % Calculate change in state of charge (SoC), where negative means discharge
                dSOC(PersonalBusinessStart) = dSOC(PersonalBusinessStart)-obj.PersonalBusinessLength*obj.avgMileage;
            end
            rng(dayNumber+7+seed);
             q=random('unif',0,1);
             
            VisitFriendsPrivateHomeAway = zeros(1,length(obj.fromBusiness));
            if(q<obj.VisitFriendsPrivateHomePerYear(dayNumber)/obj.individualDayOfWeekPerYear)
                disp('EV: Visit friends private home activity');
                [VisitFriendsPrivateHomeAway,VisitFriendsPrivateHomeStart] = getAwayPeriod(obj,obj.toVisitFriendsSportCDF,obj.fromVisitFriendsSportCDF);
                % Calculate change in state of charge (SoC), where negative means discharge
                dSOC(VisitFriendsPrivateHomeStart) = dSOC(VisitFriendsPrivateHomeStart)-obj.VisitFriendsPrivateHomeLength*obj.avgMileage;
            end
            rng(dayNumber+8+seed);
             q=random('unif',0,1);
             
            VisitFriendsElsewhereAway = zeros(1,length(obj.fromBusiness));
            if(q<obj.VisitFriendsElsewherePerYear(dayNumber)/obj.individualDayOfWeekPerYear)
                disp('EV: Visit friends elsewhere activity');
                [VisitFriendsElsewhereAway,VisitFriendsElsewhereStart] = getAwayPeriod(obj,obj.toVisitFriendsSportCDF,obj.fromVisitFriendsSportCDF);
                % Calculate change in state of charge (SoC), where negative means discharge
                dSOC(VisitFriendsElsewhereStart) = dSOC(VisitFriendsElsewhereStart)-obj.VisitFriendsElsewhereLength*obj.avgMileage;
            end
            rng(dayNumber+9+seed);
            q=random('unif',0,1);
            
            SportAway = zeros(1,length(obj.fromBusiness));
            if(q<obj.SportPerYear(dayNumber)/obj.individualDayOfWeekPerYear)
                disp('EV: Sports activity');
                [SportAway,SportStart] = getAwayPeriod(obj,obj.toVisitFriendsSportCDF,obj.fromVisitFriendsSportCDF);
                % Calculate change in state of charge (SoC), where negative means discharge
                dSOC(SportStart) = dSOC(SportStart)-obj.SportLength*obj.avgMileage;
            end
            rng(dayNumber+10+seed);
             q=random('unif',0,1);
            
            HolidayAway = zeros(1,length(obj.fromBusiness));
            if(q<obj.HolidayPerYear(dayNumber)/obj.individualDayOfWeekPerYear)
                disp('EV: Holiday activity');
                [HolidayAway,HolidayStart] = getAwayPeriod(obj,obj.toHolidayCDF,obj.fromHolidayCDF);
                % Calculate change in state of charge (SoC), where negative means discharge
                dSOC(HolidayStart) = dSOC(HolidayStart)-obj.HolidayLength*obj.avgMileage;
            end
            away = CommutingAway|BusinessAway|EducationAway|EscortEducationAway|ShoppingAway|...
                    OtherEscortAway|PersonalBusinessAway|VisitFriendsPrivateHomeAway|...
                        VisitFriendsElsewhereAway|SportAway|HolidayAway;
            away = [away 0 0]; 
        end