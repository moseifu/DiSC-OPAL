       % Low pass filter for simulating initia of rotor
        function [p,varNew] = rotorFilterWT(param,var,u)
            p = u*(param.Ts/(param.rfTau+param.Ts)) + var.pOld*(param.rfTau/(param.rfTau+param.Ts));
            var.pOld = p;
            varNew=var;
        end
        