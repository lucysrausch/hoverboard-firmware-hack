// Copyright 2016 The MathWorks, Inc.

//Poll for metrics.js on 5 second intervals
function getCodeMetricsByPolling(ctThreshold, intervalPeriod){
    if(ctThreshold === undefined){
        ctThreshold = 1000;
    }
    if(intervalPeriod === undefined){
        intervalPeriod = 5000;
    }
    var intervalId;
    var ct=0;
    //function to get code metrics
    function getCodeMetrics(){
        cm = CodeMetrics.instance;
        var alink = document.getElementById("metricsLocation");
        alink.innerHTML = cm.codeMetricsSummary;
    }
    if (typeof CodeMetrics !== "undefined"){
        getCodeMetrics();
    }
    else{
        intervalId = window.setInterval(function(){
            //Try reinclude metrics to check if CodeMetrics are available
            ct = ct + 1;
            if (ct > ctThreshold){
                // Clear if elapsed time is 1000x5 seconds
                clearInterval(intervalId);
                var alink = document.getElementById("metricsLocation");
                alink.innerHTML = 'Error generating code metrics';
            }
            else{
                var metricsScript = document.getElementById('metrics');
                if(metricsScript !== null){
                    metricsScript.parentNode.removeChild(metricsScript);
                }
                var jsElm = document.createElement("script");
                jsElm.type = "application/javascript";
                jsElm.src = "metrics.js";
                jsElm.id = "metrics";
                document.getElementsByTagName('head')[0].appendChild(jsElm);
                if (typeof CodeMetrics !== "undefined"){
                    clearInterval(intervalId);
                    getCodeMetrics();
                }
            }
        }, intervalPeriod);
	}
 }