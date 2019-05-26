function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtDW"] = {file: "D:\\Work_home\\Projects_STM32\\01_Motor_control\\BLDC_controller_ert_rtw\\BLDC_controller.c",
	size: 88};
	 this.metricsArray.var["rtP"] = {file: "D:\\Work_home\\Projects_STM32\\01_Motor_control\\BLDC_controller_ert_rtw\\BLDC_controller_data.c",
	size: 91};
	 this.metricsArray.var["rtPrevZCX"] = {file: "D:\\Work_home\\Projects_STM32\\01_Motor_control\\BLDC_controller_ert_rtw\\BLDC_controller.c",
	size: 4};
	 this.metricsArray.var["rtU"] = {file: "D:\\Work_home\\Projects_STM32\\01_Motor_control\\BLDC_controller_ert_rtw\\BLDC_controller.c",
	size: 14};
	 this.metricsArray.var["rtY"] = {file: "D:\\Work_home\\Projects_STM32\\01_Motor_control\\BLDC_controller_ert_rtw\\BLDC_controller.c",
	size: 40};
	 this.metricsArray.fcn["BLDC_controller.c:Edge_counter"] = {file: "D:\\Work_home\\Projects_STM32\\01_Motor_control\\BLDC_controller_ert_rtw\\BLDC_controller.c",
	stack: 2,
	stackTotal: 2};
	 this.metricsArray.fcn["BLDC_controller.c:Edge_counter_Disable"] = {file: "D:\\Work_home\\Projects_STM32\\01_Motor_control\\BLDC_controller_ert_rtw\\BLDC_controller.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["BLDC_controller.c:Edge_counter_Reset"] = {file: "D:\\Work_home\\Projects_STM32\\01_Motor_control\\BLDC_controller_ert_rtw\\BLDC_controller.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["BLDC_controller.c:F01_03_Direction_Detection"] = {file: "D:\\Work_home\\Projects_STM32\\01_Motor_control\\BLDC_controller_ert_rtw\\BLDC_controller.c",
	stack: 1,
	stackTotal: 1};
	 this.metricsArray.fcn["BLDC_controller.c:F02_Electrical_Angle_Ca_Disable"] = {file: "D:\\Work_home\\Projects_STM32\\01_Motor_control\\BLDC_controller_ert_rtw\\BLDC_controller.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["BLDC_controller.c:F02_Electrical_Angle_Calculatio"] = {file: "D:\\Work_home\\Projects_STM32\\01_Motor_control\\BLDC_controller_ert_rtw\\BLDC_controller.c",
	stack: 11,
	stackTotal: 20};
	 this.metricsArray.fcn["BLDC_controller.c:F03_01_Pure_Trapezoidal_Method"] = {file: "D:\\Work_home\\Projects_STM32\\01_Motor_control\\BLDC_controller_ert_rtw\\BLDC_controller.c",
	stack: 5,
	stackTotal: 14};
	 this.metricsArray.fcn["BLDC_controller.c:F03_02_Sinusoidal3rd_Method"] = {file: "D:\\Work_home\\Projects_STM32\\01_Motor_control\\BLDC_controller_ert_rtw\\BLDC_controller.c",
	stack: 5,
	stackTotal: 14};
	 this.metricsArray.fcn["BLDC_controller.c:F03_02_Sinusoidal_Method"] = {file: "D:\\Work_home\\Projects_STM32\\01_Motor_control\\BLDC_controller_ert_rtw\\BLDC_controller.c",
	stack: 5,
	stackTotal: 14};
	 this.metricsArray.fcn["BLDC_controller.c:Moving_Average_Filter"] = {file: "D:\\Work_home\\Projects_STM32\\01_Motor_control\\BLDC_controller_ert_rtw\\BLDC_controller.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["BLDC_controller.c:Raw_Speed_calculation"] = {file: "D:\\Work_home\\Projects_STM32\\01_Motor_control\\BLDC_controller_ert_rtw\\BLDC_controller.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["BLDC_controller.c:div_nde_s32_floor"] = {file: "D:\\Work_home\\Projects_STM32\\01_Motor_control\\BLDC_controller_ert_rtw\\BLDC_controller.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["BLDC_controller.c:intrp1d_s16s32s32u8u32n31l_s"] = {file: "D:\\Work_home\\Projects_STM32\\01_Motor_control\\BLDC_controller_ert_rtw\\BLDC_controller.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["BLDC_controller.c:plook_u8s32u32n31_evenc_s"] = {file: "D:\\Work_home\\Projects_STM32\\01_Motor_control\\BLDC_controller_ert_rtw\\BLDC_controller.c",
	stack: 9,
	stackTotal: 9};
	 this.metricsArray.fcn["BLDC_controller.c:rising_edge"] = {file: "D:\\Work_home\\Projects_STM32\\01_Motor_control\\BLDC_controller_ert_rtw\\BLDC_controller.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["BLDC_controller.c:rising_edge_f"] = {file: "D:\\Work_home\\Projects_STM32\\01_Motor_control\\BLDC_controller_ert_rtw\\BLDC_controller.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["BLDC_controller_initialize"] = {file: "D:\\Work_home\\Projects_STM32\\01_Motor_control\\BLDC_controller_ert_rtw\\BLDC_controller.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["BLDC_controller_step"] = {file: "D:\\Work_home\\Projects_STM32\\01_Motor_control\\BLDC_controller_ert_rtw\\BLDC_controller.c",
	stack: 32,
	stackTotal: 52};
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
	 this.codeMetricsSummary = '<a href="BLDC_controller_metrics.html">Global Memory: 237(bytes) Maximum Stack: 32(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
