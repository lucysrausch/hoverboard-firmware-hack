function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.fcn["BLDC_controller_initialize"] = {file: "D:\\git\\hoverboard-firmware-hack\\01_Matlab\\BLDC_controller_ert_rtw\\BLDC_controller.c",
	stack: 16,
	stackTotal: 16};
	 this.metricsArray.fcn["BLDC_controller_step"] = {file: "D:\\git\\hoverboard-firmware-hack\\01_Matlab\\BLDC_controller_ert_rtw\\BLDC_controller.c",
	stack: 60,
	stackTotal: 69};
	 this.metricsArray.fcn["div_nde_s32_floor"] = {file: "D:\\git\\hoverboard-firmware-hack\\01_Matlab\\BLDC_controller_ert_rtw\\BLDC_controller.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["intrp1d_s16s32s32u8u32n31l_s"] = {file: "D:\\git\\hoverboard-firmware-hack\\01_Matlab\\BLDC_controller_ert_rtw\\BLDC_controller.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["plook_u8s32u32n31_evenc_s"] = {file: "D:\\git\\hoverboard-firmware-hack\\01_Matlab\\BLDC_controller_ert_rtw\\BLDC_controller.c",
	stack: 9,
	stackTotal: 9};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="BLDC_controller_metrics.html">Global Memory: 0(bytes) Maximum Stack: 60(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
