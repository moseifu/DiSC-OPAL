function [away, dSOC,varNew]  = availabilityEV(param,var,dayNumber,seed)
   
            if ~mod(dayNumber,7)
                dayNumber = 7;
            else
                dayNumber = mod(dayNumber,7);
            end
            
            dSOC = zeros(1,length(var.fromBusiness));
            CommutingAway = zeros(1,length(var.fromBusiness));
            rng(dayNumber+seed); 
            coder.extrinsic('random'); %The function 'random' is not supported for standalone code generation. See the documentation for coder.extrinsic to learn how you can use this function in simulation.
            q=0;                           %placeholder for q , not allowed without placeholder
            q=random('unif',0,1)
            if(q<(var.CommutingPerYear(dayNumber)/var.individualDayOfWeekPerYear))
                disp('EV: Commuting activity');
                [CommutingAway,CommutingStart] = getAwayPeriod(param,var.toCommutingCDF,var.fromCommutingCDF);
                % Calculate change in state of charge (SoC), where negative means discharge
                dSOC(CommutingStart) = dSOC(CommutingStart)-var.CommutingLength*param.avgMileage;
            end
            rng(dayNumber+1+seed);
            q=random('unif',0,1);
            BusinessAway = zeros(1,length(var.fromBusiness));
            if(q<var.BusinessPerYear(dayNumber)/var.individualDayOfWeekPerYear)
                disp('EV: Business away activity');
                [BusinessAway,BusinessStart] = getAwayPeriod(param,var.toBusinessCDF,var.fromBusinessCDF);
                % Calculate change in state of charge (SoC), where negative means discharge
                dSOC(BusinessStart) = dSOC(BusinessStart)-var.BusinessLength*param.avgMileage;
            end
            rng(dayNumber+2+seed);
            q=random('unif',0,1);
            EducationAway = zeros(1,length(var.fromBusiness));
            if(q<var.EducationPerYear(dayNumber)/var.individualDayOfWeekPerYear)
                disp('EV: Education away activity');
                [EducationAway,EducationStart] = getAwayPeriod(var,var.toEducationCDF,var.fromEducationCDF);
                % Calculate change in state of charge (SoC), where negative means discharge
                dSOC(EducationStart) = dSOC(EducationStart)-var.EducationLength*param.avgMileage;
            end
            rng(dayNumber+3+seed);
            q=random('unif',0,1);
            EscortEducationAway = zeros(1,length(var.fromBusiness));
            if(q<var.EscortEducationPerYear(dayNumber)/var.individualDayOfWeekPerYear)
                disp('EV: Escort education activity');
                [EscortEducationAway,EscortEducationStart] = getAwayPeriod(param,var.toEscortEducationCDF,var.fromEscortEducationCDF);
                % Calculate change in state of charge (SoC), where negative means discharge
                dSOC(EscortEducationStart) = dSOC(EscortEducationStart)-var.EscortEducationLength*param.avgMileage;
            end
            rng(dayNumber+4+seed);
            q=random('unif',0,1);
            ShoppingAway = zeros(1,length(var.fromBusiness));
            if(q<var.ShoppingPerYear(dayNumber)/var.individualDayOfWeekPerYear)
                disp('EV: Shopping away activity');
                [ShoppingAway,ShoppingStart] = getAwayPeriod(param,var.toShoppingCDF,var.fromShoppingCDF);
                % Calculate change in state of charge (SoC), where negative means discharge
                dSOC(ShoppingStart) = dSOC(ShoppingStart)-var.ShoppingLength*param.avgMileage;
            end
            rng(dayNumber+5+seed);
            q=random('unif',0,1);
            OtherEscortAway = zeros(1,length(var.fromBusiness));
            if(q<var.OtherEscortPerYear(dayNumber)/var.individualDayOfWeekPerYear)
                disp('EV: Other escort activity');
                [OtherEscortAway,OtherEscortStart] = getAwayPeriod(param,var.toPersonalBusinessOtherEscortCDF,var.fromPersonalBusinessOtherEscortCDF);
                % Calculate change in state of charge (SoC), where negative means discharge
                dSOC(OtherEscortStart) = dSOC(OtherEscortStart)-var.OtherEscortLength*param.avgMileage;
            end
            rng(dayNumber+6+seed);
            q=random('unif',0,1);
            PersonalBusinessAway = zeros(1,length(var.fromBusiness));
            if(q<var.PersonalBusinessPerYear(dayNumber)/var.individualDayOfWeekPerYear)
                disp('EV: Personal business activity');
                [PersonalBusinessAway,PersonalBusinessStart] = getAwayPeriod(param,var.toPersonalBusinessOtherEscortCDF,var.fromPersonalBusinessOtherEscortCDF);
                % Calculate change in state of charge (SoC), where negative means discharge
                dSOC(PersonalBusinessStart) = dSOC(PersonalBusinessStart)-var.PersonalBusinessLength*param.avgMileage;
            end
            rng(dayNumber+7+seed);
            q=random('unif',0,1);
            VisitFriendsPrivateHomeAway = zeros(1,length(var.fromBusiness));
            if(q<var.VisitFriendsPrivateHomePerYear(dayNumber)/var.individualDayOfWeekPerYear)
                disp('EV: Visit friends private home activity');
                [VisitFriendsPrivateHomeAway,VisitFriendsPrivateHomeStart] = getAwayPeriod(param,var.toVisitFriendsSportCDF,var.fromVisitFriendsSportCDF);
                % Calculate change in state of charge (SoC), where negative means discharge
                dSOC(VisitFriendsPrivateHomeStart) = dSOC(VisitFriendsPrivateHomeStart)-var.VisitFriendsPrivateHomeLength*param.avgMileage;
            end
            rng(dayNumber+8+seed);
            q=random('unif',0,1);
            VisitFriendsElsewhereAway = zeros(1,length(var.fromBusiness));
            if(q<var.VisitFriendsElsewherePerYear(dayNumber)/var.individualDayOfWeekPerYear)
                disp('EV: Visit friends elsewhere activity');
                [VisitFriendsElsewhereAway,VisitFriendsElsewhereStart] = getAwayPeriod(param,var.toVisitFriendsSportCDF,var.fromVisitFriendsSportCDF);
                % Calculate change in state of charge (SoC), where negative means discharge
                dSOC(VisitFriendsElsewhereStart) = dSOC(VisitFriendsElsewhereStart)-var.VisitFriendsElsewhereLength*param.avgMileage;
            end
            rng(dayNumber+9+seed);
            q=random('unif',0,1);
            SportAway = zeros(1,length(var.fromBusiness));
            if(q<var.SportPerYear(dayNumber)/var.individualDayOfWeekPerYear)
                disp('EV: Sports activity');
                [SportAway,SportStart] = getAwayPeriod(param,var.toVisitFriendsSportCDF,var.fromVisitFriendsSportCDF);
                % Calculate change in state of charge (SoC), where negative means discharge
                dSOC(SportStart) = dSOC(SportStart)-var.SportLength*param.avgMileage;
            end
            rng(dayNumber+10+seed);
            q=random('unif',0,1);
            HolidayAway = zeros(1,length(var.fromBusiness));
            if(q<var.HolidayPerYear(dayNumber)/var.individualDayOfWeekPerYear)
                disp('EV: Holiday activity');
                [HolidayAway,HolidayStart] = getAwayPeriod(param,var.toHolidayCDF,var.fromHolidayCDF);
                % Calculate change in state of charge (SoC), where negative means discharge
                dSOC(HolidayStart) = dSOC(HolidayStart)-var.HolidayLength*param.avgMileage;
            end
            away = CommutingAway|BusinessAway|EducationAway|EscortEducationAway|ShoppingAway|...
                    OtherEscortAway|PersonalBusinessAway|VisitFriendsPrivateHomeAway|...
                        VisitFriendsElsewhereAway|SportAway|HolidayAway;
            away = [away 0 0]; 
            
            varNew=var;
        end