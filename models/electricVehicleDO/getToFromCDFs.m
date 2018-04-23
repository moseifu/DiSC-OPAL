        % To/from CDF's
        function [toCDF,fromCDF] = getToFromCDFs(obj,toPDF,fromPDF)
            toCDF = zeros(1,length(toPDF));
            fromCDF = zeros(1,length(fromPDF));
            toNormalize = sum(toPDF);
            fromNormalize = sum(fromPDF);
            toPDF = toPDF/toNormalize;
            fromPDF = fromPDF/fromNormalize;
            
            toCDF(1) = toPDF(1);
            fromCDF(1) = fromPDF(1);
            for i=2:1:length(toPDF)
                toCDF(i) = toCDF(i-1)+toPDF(i);
                fromCDF(i) = fromCDF(i-1)+fromPDF(i);
            end
        end