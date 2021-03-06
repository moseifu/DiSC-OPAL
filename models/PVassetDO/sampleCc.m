        % Sample model
        function [cc,variNew] = sampleCc(param,vari)
            if vari.n > param.M
                vari.n = 1;
            end
            r = rand(1);
            if vari.ccOld(vari.n) == 1
                if r < vari.P(1)
                    vari.ccOld(vari.n) = 0;
                else
                    vari.ccOld(vari.n) = 1;
                end
            elseif vari.ccOld(vari.n) == 0
                if r < vari.P(2)
                    vari.ccOld(vari.n) = 1;
                else
                    vari.ccOld(vari.n) = 0;
                end

            end
            cc = sum(vari.ccOld)/param.M;
            vari.n = vari.n+1; 
            variNew=vari;
        end