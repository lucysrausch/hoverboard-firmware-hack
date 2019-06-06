function CodeDefine() { 
this.def = new Array();
this.def["rtM_"] = {file: "ert_main_c.html",line:29,type:"var"};
this.def["rtMPtr"] = {file: "ert_main_c.html",line:30,type:"var"};
this.def["rtP"] = {file: "ert_main_c.html",line:31,type:"var"};
this.def["rtDW"] = {file: "ert_main_c.html",line:88,type:"var"};
this.def["rtU"] = {file: "ert_main_c.html",line:89,type:"var"};
this.def["rtY"] = {file: "ert_main_c.html",line:90,type:"var"};
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:104,type:"fcn"};
this.def["main"] = {file: "ert_main_c.html",line:140,type:"fcn"};
this.def["plook_u8s32u32n31_evenc_s"] = {file: "BLDC_controller_c.html",line:93,type:"fcn"};
this.def["intrp1d_s16s32s32u8u32n31l_s"] = {file: "BLDC_controller_c.html",line:127,type:"fcn"};
this.def["div_nde_s32_floor"] = {file: "BLDC_controller_c.html",line:143,type:"fcn"};
this.def["BLDC_controller_step"] = {file: "BLDC_controller_c.html",line:150,type:"fcn"};
this.def["BLDC_controller_initialize"] = {file: "BLDC_controller_c.html",line:663,type:"fcn"};
this.def["RT_MODEL"] = {file: "BLDC_controller_h.html",line:35,type:"type"};
this.def["DW"] = {file: "BLDC_controller_h.html",line:58,type:"type"};
this.def["ConstP"] = {file: "BLDC_controller_h.html",line:116,type:"type"};
this.def["ExtU"] = {file: "BLDC_controller_h.html",line:124,type:"type"};
this.def["ExtY"] = {file: "BLDC_controller_h.html",line:133,type:"type"};
this.def["P"] = {file: "BLDC_controller_h.html",line:173,type:"type"};
this.def["rtConstP"] = {file: "BLDC_controller_data_c.html",line:27,type:"var"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:55,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:56,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:57,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:58,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:59,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:60,type:"type"};
this.def["int64_T"] = {file: "rtwtypes_h.html",line:61,type:"type"};
this.def["uint64_T"] = {file: "rtwtypes_h.html",line:62,type:"type"};
this.def["real32_T"] = {file: "rtwtypes_h.html",line:63,type:"type"};
this.def["real64_T"] = {file: "rtwtypes_h.html",line:64,type:"type"};
this.def["real_T"] = {file: "rtwtypes_h.html",line:70,type:"type"};
this.def["time_T"] = {file: "rtwtypes_h.html",line:71,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:72,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:73,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:74,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:75,type:"type"};
this.def["ulonglong_T"] = {file: "rtwtypes_h.html",line:76,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:77,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:78,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:79,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:100,type:"type"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_c.html"] = "../ert_main.c";
	this.html2Root["ert_main_c.html"] = "ert_main_c.html";
	this.html2SrcPath["BLDC_controller_c.html"] = "../BLDC_controller.c";
	this.html2Root["BLDC_controller_c.html"] = "BLDC_controller_c.html";
	this.html2SrcPath["BLDC_controller_h.html"] = "../BLDC_controller.h";
	this.html2Root["BLDC_controller_h.html"] = "BLDC_controller_h.html";
	this.html2SrcPath["BLDC_controller_data_c.html"] = "../BLDC_controller_data.c";
	this.html2Root["BLDC_controller_data_c.html"] = "BLDC_controller_data_c.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"ert_main_c.html","BLDC_controller_c.html","BLDC_controller_h.html","BLDC_controller_data_c.html","rtwtypes_h.html"];
