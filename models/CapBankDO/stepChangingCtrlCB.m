        % Step changing control
        function  [q,varNew] = stepChangingCtrlCB(param,var,uRef)
               
            if uRef>var.stepPos && var.stepPos<param.nSteps && var.stepOk == 1
                var.stepPos = var.stepPos + 1;
                q = var.stepPos*var.qStep;
                var.stepChDay = var.stepChDay + 1;
                var.stepTimer = var.k+var.kMin;
                
            elseif uRef<var.stepPos && var.stepPos>0 && var.stepOk == 1
                var.stepPos = var.stepPos - 1;
                q = var.stepPos*var.qStep;
                var.stepChDay = var.stepChDay + 1; 
                var.stepTimer = var.k+var.kMin;
            else
                var.stepPos = var.stepPos;
                q = var.stepPos*var.qStep;
            end
            
            varNew=var;
        end