function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <S2>/Abs1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1660"] = "BLDC_controller.c:179,182,183,185,188";
	/* <S2>/F02_Electrical_Angle_Calculation */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:215"] = "BLDC_controller.c:384,450";
	/* <S2>/If1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:434"] = "BLDC_controller.c:363,366,367,368,369,372,373,383,453,672,673&BLDC_controller.h:52";
	/* <S7>/F01_03_Direction_Detection */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:38"] = "BLDC_controller.c:216,253";
	/* <S7>/If2 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1313"] = "BLDC_controller.c:206,215";
	/* <S7>/z_ctrlTypSel1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:208"] = "BLDC_controller.c:364,368,456,458,555,571&BLDC_controller.h:176&ert_main.c:93";
	/* <S8>/Action Port */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:221"] = "BLDC_controller.c:385";
	/* <S8>/Constant16 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1464"] = "BLDC_controller.c:389,400";
	/* <S8>/Constant2 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1465"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=BLDCmotorControl_R2017b:2687:1465";
	/* <S8>/Divide4 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1466"] = "BLDC_controller.c:412,417";
	/* <S8>/Divide5 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1467"] = "BLDC_controller.c:413,418";
	/* <S8>/Logical
Operator2 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1668"] = "BLDC_controller.c:423,427";
	/* <S8>/Math
Function */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:623"] = "BLDC_controller.c:443,444";
	/* <S8>/Product2 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:545"] = "BLDC_controller.c:439,441";
	/* <S8>/Product6 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1474"] = "BLDC_controller.c:414,417";
	/* <S8>/Relational
Operator4 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1670"] = "BLDC_controller.c:425,427";
	/* <S8>/Relational
Operator7 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1475"] = "BLDC_controller.c:395,400";
	/* <S8>/Scope */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:262"] = "msg=rtwMsg_reducedBlock&block=BLDCmotorControl_R2017b:2687:262";
	/* <S8>/Sum1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1476"] = "BLDC_controller.c:398,403,405";
	/* <S8>/Sum2 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1477"] = "BLDC_controller.c:415,417,418";
	/* <S8>/Sum3 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:546"] = "BLDC_controller.c:437,441";
	/* <S8>/Switch3 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1478"] = "BLDC_controller.c:387,400,401,403,408";
	/* <S8>/Switch_PhaAdv */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:514"] = "BLDC_controller.c:420,427,444,446,449&BLDC_controller.h:39";
	/* <S8>/a_elecAngle1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1479"] = "BLDC_controller.c:411,417,418";
	/* <S8>/a_elecPeriod1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:512"] = "BLDC_controller.c:421,427&BLDC_controller.h:179&ert_main.c:98";
	/* <S8>/a_elecPeriod2 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:547"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=BLDCmotorControl_R2017b:2687:547";
	/* <S8>/a_phaAdv_M2 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:521"] = "BLDC_controller.c:433,434,435&BLDC_controller.h:159&ert_main.c:68";
	/* <S8>/n_motPhaAdvEna */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1671"] = "BLDC_controller.c:422,427&BLDC_controller.h:150&ert_main.c:53";
	/* <S8>/r_phaAdvDC_XA */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:522"] = "BLDC_controller.c:428,429,430,431&BLDC_controller.h:156&ert_main.c:63";
	/* <S8>/a_elecAngleAdv */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:278"] = "BLDC_controller.c:374,375";
	/* <S8>/a_elecAngle */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:279"] = "BLDC_controller.c:378,380";
	/* <S9>/F03_01_Pure_Trapezoidal_Method */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:285"] = "BLDC_controller.c:460,479";
	/* <S9>/F03_02_Sinusoidal_Method */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:305"] = "BLDC_controller.c:483,502";
	/* <S9>/F03_03_Sinusoidal3rd_Method */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:295"] = "BLDC_controller.c:506,525";
	/* <S9>/Merge */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:345"] = "BLDC_controller.h:41";
	/* <S9>/Merge1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:346"] = "BLDC_controller.h:42";
	/* <S9>/Merge2 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:347"] = "BLDC_controller.h:43";
	/* <S9>/Switch Case */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:348"] = "BLDC_controller.c:455,458,459,482,505,529";
	/* <S10>/Constant1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:370"] = "BLDC_controller.c:618,621,624,627,654,657";
	/* <S10>/Divide1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:373"] = "BLDC_controller.c:619,621,625,627,655,657";
	/* <S10>/Divide2 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:374"] = "BLDC_controller.c:559,610,611,612";
	/* <S10>/Divide4 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:375"] = "BLDC_controller.c:560,573,574,575";
	/* <S10>/Switch1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:401"] = "BLDC_controller.c:551,571,573,574,575,610,611,612,615";
	/* <S10>/z_commutMap_M1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:411"] = "BLDC_controller.c:558,568,577,578,580,583,584,585,587,590,592,596,599,602,606,609,610,611,612&BLDC_controller.h:108&BLDC_controller_data.c:86";
	/* <S11>/Bitwise
Operator */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1535"] = "BLDC_controller.c:190,198,199";
	/* <S11>/UnitDelay */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:31"] = "BLDC_controller.c:194,199,629,632&BLDC_controller.h:53";
	/* <S11>/UnitDelay1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:32"] = "BLDC_controller.c:195,199,634,637&BLDC_controller.h:54";
	/* <S11>/UnitDelay2 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:33"] = "BLDC_controller.c:196,200,639,642&BLDC_controller.h:55";
	/* <S12>/Selector */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:14"] = "BLDC_controller.c:224,227,249,251,396,401,403,404,405,566,577,584,594,599,604";
	/* <S12>/Sum */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:15"] = "BLDC_controller.c:169,176,177,397,403,404,405";
	/* <S12>/g_Ha */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:17"] = "BLDC_controller.c:170,176,390,404";
	/* <S12>/g_Hb */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:18"] = "BLDC_controller.c:171,177,391,404,405";
	/* <S12>/vec_hallToPos */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:22"] = "BLDC_controller.c:223,227,248,251,388,401,403,552,577,584,593,599,603&BLDC_controller.h:113&BLDC_controller_data.c:92";
	/* <S13>/Action Port */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1314"] = "BLDC_controller.c:217";
	/* <S13>/Constant20 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:42"] = "BLDC_controller.c:231,239";
	/* <S13>/Constant23 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:43"] = "BLDC_controller.c:232,242";
	/* <S13>/Constant24 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:44"] = "BLDC_controller.c:233,240";
	/* <S13>/Constant8 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:45"] = "BLDC_controller.c:234,239";
	/* <S13>/Logical
Operator3 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:48"] = "BLDC_controller.c:235,239";
	/* <S13>/Relational
Operator1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:49"] = "BLDC_controller.c:236,239";
	/* <S13>/Relational
Operator6 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:50"] = "BLDC_controller.c:237,239";
	/* <S13>/Sum2 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:51"] = "BLDC_controller.c:222,227";
	/* <S13>/Switch2 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:52"] = "BLDC_controller.c:230,239,240,242,245&BLDC_controller.h:50";
	/* <S13>/UnitDelay1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1631"] = "BLDC_controller.c:219,220&BLDC_controller.h:49";
	/* <S13>/UnitDelay2 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1318"] = "BLDC_controller.c:225,228,247,251&BLDC_controller.h:51";
	/* <S14>/Abs2 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1366"] = "BLDC_controller.c:345,346,347,349,352";
	/* <S14>/CTRL_COMM */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1321"] = "BLDC_controller.c:553,571";
	/* <S14>/Constant6 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:64"] = "BLDC_controller.c:203,254,262";
	/* <S14>/Counter_Hold_and_Error_Calculation */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1340"] = "BLDC_controller.c:256,274,681,688";
	/* <S14>/If1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1339"] = "BLDC_controller.c:202,215,291";
	/* <S14>/Logical
Operator2 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1325"] = "BLDC_controller.c:557,571,572";
	/* <S14>/Relational
Operator1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1524"] = "BLDC_controller.c:561,571,572";
	/* <S14>/Relational
Operator3 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1326"] = "BLDC_controller.c:562,571";
	/* <S14>/Relational
Operator4 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1327"] = "BLDC_controller.c:563,571";
	/* <S14>/Scope2 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:141"] = "msg=rtwMsg_reducedBlock&block=BLDCmotorControl_R2017b:2687:141";
	/* <S14>/Sign */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1525"] = "BLDC_controller.c:531,532,533,535,538";
	/* <S14>/Sign1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1526"] = "BLDC_controller.c:540,543,544,546,549";
	/* <S14>/Sum1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:142"] = "BLDC_controller.c:209,254,265,288,293,294,304,306";
	/* <S14>/UnitDelay1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1507"] = "BLDC_controller.c:212,259,266,647,648&BLDC_controller.h:47";
	/* <S14>/dz_counter */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1518"] = "BLDC_controller.c:354,355,356,358,359,564,572&BLDC_controller.h:57,162,165&ert_main.c:73,78";
	/* <S14>/n_commDeacv */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1328"] = "BLDC_controller.c:336,337,338,340,341,565,572&BLDC_controller.h:56,144,147&ert_main.c:43,48";
	/* <S14>/r_commDCDeacv */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1329"] = "BLDC_controller.c:554,571&BLDC_controller.h:153&ert_main.c:58";
	/* <S15>/z_counterRawPrev */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1341"] = "BLDC_controller.c:207,259,264&BLDC_controller.h:44";
	/* <S15>/Action Port */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1344"] = "BLDC_controller.c:257";
	/* <S15>/Sum4 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1454"] = "BLDC_controller.c:261,269&BLDC_controller.h:45";
	/* <S15>/z_counter2 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:169"] = "BLDC_controller.c:267,269,271,272,682,683&BLDC_controller.h:48,170&ert_main.c:85";
	/* <S15>/z_counter */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1358"] = "BLDC_controller.c:685,686&BLDC_controller.h:169&ert_main.c:84";
	/* <S16>/Abs5 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1672"] = "BLDC_controller.c:327,328,329,331,334";
	/* <S16>/Constant1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1637"] = "BLDC_controller.c:297,307";
	/* <S16>/Constant2 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1433"] = "BLDC_controller.c:315,324";
	/* <S16>/Constant3 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1434"] = "BLDC_controller.c:316,325";
	/* <S16>/Divide1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1435"] = "BLDC_controller.c:318,324,325";
	/* <S16>/Divide2 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1436"] = "BLDC_controller.c:314,324,325";
	/* <S16>/Divide3 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1437"] = "BLDC_controller.c:319,324";
	/* <S16>/Divide4 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1438"] = "BLDC_controller.c:301,309";
	/* <S16>/Logical
Operator1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1627"] = "BLDC_controller.c:300,306";
	/* <S16>/Relational
Operator2 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1624"] = "BLDC_controller.c:302,306";
	/* <S16>/Relational
Operator5 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1628"] = "BLDC_controller.c:303,306";
	/* <S16>/Sum1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1443"] = "BLDC_controller.c:320,324";
	/* <S16>/Sum2 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1444"] = "BLDC_controller.c:321,324";
	/* <S16>/Switch1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1638"] = "BLDC_controller.c:296,306,307,309,312";
	/* <S16>/UnitDelay2 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1446"] = "BLDC_controller.c:322,324,650,651&BLDC_controller.h:40";
	/* <S16>/cf_spdCoef */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1447"] = "BLDC_controller.c:298,309&BLDC_controller.h:138&ert_main.c:33";
	/* <S16>/cf_speedFilt */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1448"] = "BLDC_controller.c:317,324,325&BLDC_controller.h:141&ert_main.c:38";
	/* <S16>/z_maxCntRst */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1625"] = "BLDC_controller.c:299,306&BLDC_controller.h:171&ert_main.c:86";
	/* <S17>/Constant1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1651:1616"] = "BLDC_controller.c:204,276,283,285&BLDC_controller.h:172&ert_main.c:87";
	/* <S17>/Constant23 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1651:1617"] = "BLDC_controller.c:205,254,263";
	/* <S17>/Relational
Operator1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1651:1618"] = "BLDC_controller.c:208,276";
	/* <S17>/Switch1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1651:1619"] = "BLDC_controller.c:210,215,254,288";
	/* <S17>/Switch2 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1651:1620"] = "BLDC_controller.c:211,276,277,280,282,285";
	/* <S17>/UnitDelay1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:1651:1621"] = "BLDC_controller.c:213,276,278,280,644,645,678,679&BLDC_controller.h:46,173&ert_main.c:88";
	/* <S18>/Action Port */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:287"] = "BLDC_controller.c:461";
	/* <S18>/a_trapElecAngle_XA */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:288"] = "BLDC_controller.c:463,464,465";
	/* <S18>/r_trapPhaA_M1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:289"] = "BLDC_controller.c:467,468,469&BLDC_controller.h:63&BLDC_controller_data.c:29";
	/* <S18>/r_trapPhaB_M1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:290"] = "BLDC_controller.c:471,472,473&BLDC_controller.h:68&BLDC_controller_data.c:34";
	/* <S18>/r_trapPhaC_M1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:291"] = "BLDC_controller.c:475,476,477&BLDC_controller.h:73&BLDC_controller_data.c:39";
	/* <S19>/Action Port */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:307"] = "BLDC_controller.c:484";
	/* <S19>/a_sinElecAngle_XA */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:308"] = "BLDC_controller.c:486,487,488";
	/* <S19>/r_sinPhaA_M1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:309"] = "BLDC_controller.c:490,491,492&BLDC_controller.h:78&BLDC_controller_data.c:44";
	/* <S19>/r_sinPhaB_M1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:310"] = "BLDC_controller.c:494,495,496&BLDC_controller.h:83&BLDC_controller_data.c:51";
	/* <S19>/r_sinPhaC_M1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:311"] = "BLDC_controller.c:498,499,500&BLDC_controller.h:88&BLDC_controller_data.c:58";
	/* <S20>/Action Port */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:297"] = "BLDC_controller.c:507";
	/* <S20>/a_sinElecAngle_XA */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:298"] = "BLDC_controller.c:509,510,511";
	/* <S20>/r_sin3PhaA_M1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:299"] = "BLDC_controller.c:513,514,515&BLDC_controller.h:93&BLDC_controller_data.c:65";
	/* <S20>/r_sin3PhaB_M1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:300"] = "BLDC_controller.c:517,518,519&BLDC_controller.h:98&BLDC_controller_data.c:72";
	/* <S20>/r_sin3PhaC_M1 */
	this.urlHashMap["BLDCmotorControl_R2017b:2687:301"] = "BLDC_controller.c:521,522,523&BLDC_controller.h:103&BLDC_controller_data.c:79";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "BLDC_controller"};
	this.sidHashMap["BLDC_controller"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "BLDCmotorControl_R2017b:29"};
	this.sidHashMap["BLDCmotorControl_R2017b:29"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "BLDCmotorControl_R2017b:2687"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S3>"] = {sid: "BLDCmotorControl_R2017b:1831"};
	this.sidHashMap["BLDCmotorControl_R2017b:1831"] = {rtwname: "<S3>"};
	this.rtwnameHashMap["<S4>"] = {sid: "BLDCmotorControl_R2017b:1834"};
	this.sidHashMap["BLDCmotorControl_R2017b:1834"] = {rtwname: "<S4>"};
	this.rtwnameHashMap["<S5>"] = {sid: "BLDCmotorControl_R2017b:1837"};
	this.sidHashMap["BLDCmotorControl_R2017b:1837"] = {rtwname: "<S5>"};
	this.rtwnameHashMap["<S6>"] = {sid: "BLDCmotorControl_R2017b:1828"};
	this.sidHashMap["BLDCmotorControl_R2017b:1828"] = {rtwname: "<S6>"};
	this.rtwnameHashMap["<S7>"] = {sid: "BLDCmotorControl_R2017b:2687:6"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:6"] = {rtwname: "<S7>"};
	this.rtwnameHashMap["<S8>"] = {sid: "BLDCmotorControl_R2017b:2687:215"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:215"] = {rtwname: "<S8>"};
	this.rtwnameHashMap["<S9>"] = {sid: "BLDCmotorControl_R2017b:2687:282"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:282"] = {rtwname: "<S9>"};
	this.rtwnameHashMap["<S10>"] = {sid: "BLDCmotorControl_R2017b:2687:361"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:361"] = {rtwname: "<S10>"};
	this.rtwnameHashMap["<S11>"] = {sid: "BLDCmotorControl_R2017b:2687:26"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:26"] = {rtwname: "<S11>"};
	this.rtwnameHashMap["<S12>"] = {sid: "BLDCmotorControl_R2017b:2687:10"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:10"] = {rtwname: "<S12>"};
	this.rtwnameHashMap["<S13>"] = {sid: "BLDCmotorControl_R2017b:2687:38"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:38"] = {rtwname: "<S13>"};
	this.rtwnameHashMap["<S14>"] = {sid: "BLDCmotorControl_R2017b:2687:59"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:59"] = {rtwname: "<S14>"};
	this.rtwnameHashMap["<S15>"] = {sid: "BLDCmotorControl_R2017b:2687:1340"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1340"] = {rtwname: "<S15>"};
	this.rtwnameHashMap["<S16>"] = {sid: "BLDCmotorControl_R2017b:2687:1401"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1401"] = {rtwname: "<S16>"};
	this.rtwnameHashMap["<S17>"] = {sid: "BLDCmotorControl_R2017b:2687:1651"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1651"] = {rtwname: "<S17>"};
	this.rtwnameHashMap["<S18>"] = {sid: "BLDCmotorControl_R2017b:2687:285"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:285"] = {rtwname: "<S18>"};
	this.rtwnameHashMap["<S19>"] = {sid: "BLDCmotorControl_R2017b:2687:305"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:305"] = {rtwname: "<S19>"};
	this.rtwnameHashMap["<S20>"] = {sid: "BLDCmotorControl_R2017b:2687:295"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:295"] = {rtwname: "<S20>"};
	this.rtwnameHashMap["<S21>"] = {sid: "BLDCmotorControl_R2017b:2687:349"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:349"] = {rtwname: "<S21>"};
	this.rtwnameHashMap["<S22>"] = {sid: "BLDCmotorControl_R2017b:2687:352"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:352"] = {rtwname: "<S22>"};
	this.rtwnameHashMap["<S23>"] = {sid: "BLDCmotorControl_R2017b:2687:355"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:355"] = {rtwname: "<S23>"};
	this.rtwnameHashMap["<S1>/b_hallA "] = {sid: "BLDCmotorControl_R2017b:365"};
	this.sidHashMap["BLDCmotorControl_R2017b:365"] = {rtwname: "<S1>/b_hallA "};
	this.rtwnameHashMap["<S1>/b_hallB"] = {sid: "BLDCmotorControl_R2017b:1277"};
	this.sidHashMap["BLDCmotorControl_R2017b:1277"] = {rtwname: "<S1>/b_hallB"};
	this.rtwnameHashMap["<S1>/b_hallC"] = {sid: "BLDCmotorControl_R2017b:1278"};
	this.sidHashMap["BLDCmotorControl_R2017b:1278"] = {rtwname: "<S1>/b_hallC"};
	this.rtwnameHashMap["<S1>/r_DC"] = {sid: "BLDCmotorControl_R2017b:1766"};
	this.sidHashMap["BLDCmotorControl_R2017b:1766"] = {rtwname: "<S1>/r_DC"};
	this.rtwnameHashMap["<S1>/BLDC_controller"] = {sid: "BLDCmotorControl_R2017b:2687"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687"] = {rtwname: "<S1>/BLDC_controller"};
	this.rtwnameHashMap["<S1>/From1"] = {sid: "BLDCmotorControl_R2017b:1759"};
	this.sidHashMap["BLDCmotorControl_R2017b:1759"] = {rtwname: "<S1>/From1"};
	this.rtwnameHashMap["<S1>/From18"] = {sid: "BLDCmotorControl_R2017b:2688"};
	this.sidHashMap["BLDCmotorControl_R2017b:2688"] = {rtwname: "<S1>/From18"};
	this.rtwnameHashMap["<S1>/From19"] = {sid: "BLDCmotorControl_R2017b:2689"};
	this.sidHashMap["BLDCmotorControl_R2017b:2689"] = {rtwname: "<S1>/From19"};
	this.rtwnameHashMap["<S1>/From20"] = {sid: "BLDCmotorControl_R2017b:2690"};
	this.sidHashMap["BLDCmotorControl_R2017b:2690"] = {rtwname: "<S1>/From20"};
	this.rtwnameHashMap["<S1>/From21"] = {sid: "BLDCmotorControl_R2017b:2691"};
	this.sidHashMap["BLDCmotorControl_R2017b:2691"] = {rtwname: "<S1>/From21"};
	this.rtwnameHashMap["<S1>/From5"] = {sid: "BLDCmotorControl_R2017b:1760"};
	this.sidHashMap["BLDCmotorControl_R2017b:1760"] = {rtwname: "<S1>/From5"};
	this.rtwnameHashMap["<S1>/From6"] = {sid: "BLDCmotorControl_R2017b:1761"};
	this.sidHashMap["BLDCmotorControl_R2017b:1761"] = {rtwname: "<S1>/From6"};
	this.rtwnameHashMap["<S1>/From7"] = {sid: "BLDCmotorControl_R2017b:1763"};
	this.sidHashMap["BLDCmotorControl_R2017b:1763"] = {rtwname: "<S1>/From7"};
	this.rtwnameHashMap["<S1>/From8"] = {sid: "BLDCmotorControl_R2017b:2462"};
	this.sidHashMap["BLDCmotorControl_R2017b:2462"] = {rtwname: "<S1>/From8"};
	this.rtwnameHashMap["<S1>/Goto"] = {sid: "BLDCmotorControl_R2017b:1765"};
	this.sidHashMap["BLDCmotorControl_R2017b:1765"] = {rtwname: "<S1>/Goto"};
	this.rtwnameHashMap["<S1>/Goto1"] = {sid: "BLDCmotorControl_R2017b:443"};
	this.sidHashMap["BLDCmotorControl_R2017b:443"] = {rtwname: "<S1>/Goto1"};
	this.rtwnameHashMap["<S1>/Goto18"] = {sid: "BLDCmotorControl_R2017b:2692"};
	this.sidHashMap["BLDCmotorControl_R2017b:2692"] = {rtwname: "<S1>/Goto18"};
	this.rtwnameHashMap["<S1>/Goto19"] = {sid: "BLDCmotorControl_R2017b:2693"};
	this.sidHashMap["BLDCmotorControl_R2017b:2693"] = {rtwname: "<S1>/Goto19"};
	this.rtwnameHashMap["<S1>/Goto2"] = {sid: "BLDCmotorControl_R2017b:444"};
	this.sidHashMap["BLDCmotorControl_R2017b:444"] = {rtwname: "<S1>/Goto2"};
	this.rtwnameHashMap["<S1>/Goto20"] = {sid: "BLDCmotorControl_R2017b:2694"};
	this.sidHashMap["BLDCmotorControl_R2017b:2694"] = {rtwname: "<S1>/Goto20"};
	this.rtwnameHashMap["<S1>/Goto21"] = {sid: "BLDCmotorControl_R2017b:2695"};
	this.sidHashMap["BLDCmotorControl_R2017b:2695"] = {rtwname: "<S1>/Goto21"};
	this.rtwnameHashMap["<S1>/Goto22"] = {sid: "BLDCmotorControl_R2017b:2696"};
	this.sidHashMap["BLDCmotorControl_R2017b:2696"] = {rtwname: "<S1>/Goto22"};
	this.rtwnameHashMap["<S1>/Goto3"] = {sid: "BLDCmotorControl_R2017b:445"};
	this.sidHashMap["BLDCmotorControl_R2017b:445"] = {rtwname: "<S1>/Goto3"};
	this.rtwnameHashMap["<S1>/signal_log1"] = {sid: "BLDCmotorControl_R2017b:1831"};
	this.sidHashMap["BLDCmotorControl_R2017b:1831"] = {rtwname: "<S1>/signal_log1"};
	this.rtwnameHashMap["<S1>/signal_log2"] = {sid: "BLDCmotorControl_R2017b:1834"};
	this.sidHashMap["BLDCmotorControl_R2017b:1834"] = {rtwname: "<S1>/signal_log2"};
	this.rtwnameHashMap["<S1>/signal_log3"] = {sid: "BLDCmotorControl_R2017b:1837"};
	this.sidHashMap["BLDCmotorControl_R2017b:1837"] = {rtwname: "<S1>/signal_log3"};
	this.rtwnameHashMap["<S1>/signal_log6"] = {sid: "BLDCmotorControl_R2017b:1828"};
	this.sidHashMap["BLDCmotorControl_R2017b:1828"] = {rtwname: "<S1>/signal_log6"};
	this.rtwnameHashMap["<S1>/DC_phaA"] = {sid: "BLDCmotorControl_R2017b:39"};
	this.sidHashMap["BLDCmotorControl_R2017b:39"] = {rtwname: "<S1>/DC_phaA"};
	this.rtwnameHashMap["<S1>/DC_phaB"] = {sid: "BLDCmotorControl_R2017b:1762"};
	this.sidHashMap["BLDCmotorControl_R2017b:1762"] = {rtwname: "<S1>/DC_phaB"};
	this.rtwnameHashMap["<S1>/DC_phaC"] = {sid: "BLDCmotorControl_R2017b:1764"};
	this.sidHashMap["BLDCmotorControl_R2017b:1764"] = {rtwname: "<S1>/DC_phaC"};
	this.rtwnameHashMap["<S1>/n_mot"] = {sid: "BLDCmotorControl_R2017b:628"};
	this.sidHashMap["BLDCmotorControl_R2017b:628"] = {rtwname: "<S1>/n_mot"};
	this.rtwnameHashMap["<S1>/a_elecAngle"] = {sid: "BLDCmotorControl_R2017b:2463"};
	this.sidHashMap["BLDCmotorControl_R2017b:2463"] = {rtwname: "<S1>/a_elecAngle"};
	this.rtwnameHashMap["<S2>/b_hallA "] = {sid: "BLDCmotorControl_R2017b:2687:2"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:2"] = {rtwname: "<S2>/b_hallA "};
	this.rtwnameHashMap["<S2>/b_hallB"] = {sid: "BLDCmotorControl_R2017b:2687:3"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:3"] = {rtwname: "<S2>/b_hallB"};
	this.rtwnameHashMap["<S2>/b_hallC"] = {sid: "BLDCmotorControl_R2017b:2687:4"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:4"] = {rtwname: "<S2>/b_hallC"};
	this.rtwnameHashMap["<S2>/r_DC"] = {sid: "BLDCmotorControl_R2017b:2687:5"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:5"] = {rtwname: "<S2>/r_DC"};
	this.rtwnameHashMap["<S2>/Abs1"] = {sid: "BLDCmotorControl_R2017b:2687:1660"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1660"] = {rtwname: "<S2>/Abs1"};
	this.rtwnameHashMap["<S2>/F01_Preliminary_Calculations"] = {sid: "BLDCmotorControl_R2017b:2687:6"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:6"] = {rtwname: "<S2>/F01_Preliminary_Calculations"};
	this.rtwnameHashMap["<S2>/F02_Electrical_Angle_Calculation"] = {sid: "BLDCmotorControl_R2017b:2687:215"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:215"] = {rtwname: "<S2>/F02_Electrical_Angle_Calculation"};
	this.rtwnameHashMap["<S2>/F03_Control_Method_Selection"] = {sid: "BLDCmotorControl_R2017b:2687:282"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:282"] = {rtwname: "<S2>/F03_Control_Method_Selection"};
	this.rtwnameHashMap["<S2>/F04_Control_Type_Management"] = {sid: "BLDCmotorControl_R2017b:2687:361"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:361"] = {rtwname: "<S2>/F04_Control_Type_Management"};
	this.rtwnameHashMap["<S2>/From"] = {sid: "BLDCmotorControl_R2017b:2687:416"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:416"] = {rtwname: "<S2>/From"};
	this.rtwnameHashMap["<S2>/From1"] = {sid: "BLDCmotorControl_R2017b:2687:417"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:417"] = {rtwname: "<S2>/From1"};
	this.rtwnameHashMap["<S2>/From10"] = {sid: "BLDCmotorControl_R2017b:2687:1379"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1379"] = {rtwname: "<S2>/From10"};
	this.rtwnameHashMap["<S2>/From11"] = {sid: "BLDCmotorControl_R2017b:2687:1667"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1667"] = {rtwname: "<S2>/From11"};
	this.rtwnameHashMap["<S2>/From2"] = {sid: "BLDCmotorControl_R2017b:2687:418"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:418"] = {rtwname: "<S2>/From2"};
	this.rtwnameHashMap["<S2>/From3"] = {sid: "BLDCmotorControl_R2017b:2687:419"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:419"] = {rtwname: "<S2>/From3"};
	this.rtwnameHashMap["<S2>/From4"] = {sid: "BLDCmotorControl_R2017b:2687:420"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:420"] = {rtwname: "<S2>/From4"};
	this.rtwnameHashMap["<S2>/From5"] = {sid: "BLDCmotorControl_R2017b:2687:421"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:421"] = {rtwname: "<S2>/From5"};
	this.rtwnameHashMap["<S2>/From6"] = {sid: "BLDCmotorControl_R2017b:2687:422"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:422"] = {rtwname: "<S2>/From6"};
	this.rtwnameHashMap["<S2>/From7"] = {sid: "BLDCmotorControl_R2017b:2687:423"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:423"] = {rtwname: "<S2>/From7"};
	this.rtwnameHashMap["<S2>/From8"] = {sid: "BLDCmotorControl_R2017b:2687:424"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:424"] = {rtwname: "<S2>/From8"};
	this.rtwnameHashMap["<S2>/From9"] = {sid: "BLDCmotorControl_R2017b:2687:537"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:537"] = {rtwname: "<S2>/From9"};
	this.rtwnameHashMap["<S2>/Goto"] = {sid: "BLDCmotorControl_R2017b:2687:425"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:425"] = {rtwname: "<S2>/Goto"};
	this.rtwnameHashMap["<S2>/Goto1"] = {sid: "BLDCmotorControl_R2017b:2687:426"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:426"] = {rtwname: "<S2>/Goto1"};
	this.rtwnameHashMap["<S2>/Goto2"] = {sid: "BLDCmotorControl_R2017b:2687:427"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:427"] = {rtwname: "<S2>/Goto2"};
	this.rtwnameHashMap["<S2>/Goto3"] = {sid: "BLDCmotorControl_R2017b:2687:428"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:428"] = {rtwname: "<S2>/Goto3"};
	this.rtwnameHashMap["<S2>/Goto4"] = {sid: "BLDCmotorControl_R2017b:2687:429"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:429"] = {rtwname: "<S2>/Goto4"};
	this.rtwnameHashMap["<S2>/Goto5"] = {sid: "BLDCmotorControl_R2017b:2687:430"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:430"] = {rtwname: "<S2>/Goto5"};
	this.rtwnameHashMap["<S2>/Goto6"] = {sid: "BLDCmotorControl_R2017b:2687:431"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:431"] = {rtwname: "<S2>/Goto6"};
	this.rtwnameHashMap["<S2>/Goto7"] = {sid: "BLDCmotorControl_R2017b:2687:432"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:432"] = {rtwname: "<S2>/Goto7"};
	this.rtwnameHashMap["<S2>/Goto8"] = {sid: "BLDCmotorControl_R2017b:2687:433"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:433"] = {rtwname: "<S2>/Goto8"};
	this.rtwnameHashMap["<S2>/Goto9"] = {sid: "BLDCmotorControl_R2017b:2687:1659"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1659"] = {rtwname: "<S2>/Goto9"};
	this.rtwnameHashMap["<S2>/If1"] = {sid: "BLDCmotorControl_R2017b:2687:434"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:434"] = {rtwname: "<S2>/If1"};
	this.rtwnameHashMap["<S2>/Implemented_control_methods"] = {sid: "BLDCmotorControl_R2017b:2687:457"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:457"] = {rtwname: "<S2>/Implemented_control_methods"};
	this.rtwnameHashMap["<S2>/Model_Info"] = {sid: "BLDCmotorControl_R2017b:2687:589"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:589"] = {rtwname: "<S2>/Model_Info"};
	this.rtwnameHashMap["<S2>/DC_phaA"] = {sid: "BLDCmotorControl_R2017b:2687:447"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:447"] = {rtwname: "<S2>/DC_phaA"};
	this.rtwnameHashMap["<S2>/DC_phaB"] = {sid: "BLDCmotorControl_R2017b:2687:448"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:448"] = {rtwname: "<S2>/DC_phaB"};
	this.rtwnameHashMap["<S2>/DC_phaC"] = {sid: "BLDCmotorControl_R2017b:2687:449"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:449"] = {rtwname: "<S2>/DC_phaC"};
	this.rtwnameHashMap["<S2>/n_mot"] = {sid: "BLDCmotorControl_R2017b:2687:450"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:450"] = {rtwname: "<S2>/n_mot"};
	this.rtwnameHashMap["<S2>/a_elecAngle"] = {sid: "BLDCmotorControl_R2017b:2687:451"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:451"] = {rtwname: "<S2>/a_elecAngle"};
	this.rtwnameHashMap["<S3>/b_hallB"] = {sid: "BLDCmotorControl_R2017b:1832"};
	this.sidHashMap["BLDCmotorControl_R2017b:1832"] = {rtwname: "<S3>/b_hallB"};
	this.rtwnameHashMap["<S3>/Terminator_1"] = {sid: "BLDCmotorControl_R2017b:1833"};
	this.sidHashMap["BLDCmotorControl_R2017b:1833"] = {rtwname: "<S3>/Terminator_1"};
	this.rtwnameHashMap["<S4>/b_hallC"] = {sid: "BLDCmotorControl_R2017b:1835"};
	this.sidHashMap["BLDCmotorControl_R2017b:1835"] = {rtwname: "<S4>/b_hallC"};
	this.rtwnameHashMap["<S4>/Terminator_1"] = {sid: "BLDCmotorControl_R2017b:1836"};
	this.sidHashMap["BLDCmotorControl_R2017b:1836"] = {rtwname: "<S4>/Terminator_1"};
	this.rtwnameHashMap["<S5>/r_DC"] = {sid: "BLDCmotorControl_R2017b:1838"};
	this.sidHashMap["BLDCmotorControl_R2017b:1838"] = {rtwname: "<S5>/r_DC"};
	this.rtwnameHashMap["<S5>/Terminator_1"] = {sid: "BLDCmotorControl_R2017b:1839"};
	this.sidHashMap["BLDCmotorControl_R2017b:1839"] = {rtwname: "<S5>/Terminator_1"};
	this.rtwnameHashMap["<S6>/b_hallA"] = {sid: "BLDCmotorControl_R2017b:1829"};
	this.sidHashMap["BLDCmotorControl_R2017b:1829"] = {rtwname: "<S6>/b_hallA"};
	this.rtwnameHashMap["<S6>/Terminator_1"] = {sid: "BLDCmotorControl_R2017b:1830"};
	this.sidHashMap["BLDCmotorControl_R2017b:1830"] = {rtwname: "<S6>/Terminator_1"};
	this.rtwnameHashMap["<S7>/b_hallA"] = {sid: "BLDCmotorControl_R2017b:2687:7"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:7"] = {rtwname: "<S7>/b_hallA"};
	this.rtwnameHashMap["<S7>/b_hallB"] = {sid: "BLDCmotorControl_R2017b:2687:8"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:8"] = {rtwname: "<S7>/b_hallB"};
	this.rtwnameHashMap["<S7>/b_hallC"] = {sid: "BLDCmotorControl_R2017b:2687:9"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:9"] = {rtwname: "<S7>/b_hallC"};
	this.rtwnameHashMap["<S7>/r_DC"] = {sid: "BLDCmotorControl_R2017b:2687:1375"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1375"] = {rtwname: "<S7>/r_DC"};
	this.rtwnameHashMap["<S7>/r_DCabs"] = {sid: "BLDCmotorControl_R2017b:2687:1661"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1661"] = {rtwname: "<S7>/r_DCabs"};
	this.rtwnameHashMap["<S7>/F01_01_Edge_Detector"] = {sid: "BLDCmotorControl_R2017b:2687:26"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:26"] = {rtwname: "<S7>/F01_01_Edge_Detector"};
	this.rtwnameHashMap["<S7>/F01_02_Position_Calculation"] = {sid: "BLDCmotorControl_R2017b:2687:10"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:10"] = {rtwname: "<S7>/F01_02_Position_Calculation"};
	this.rtwnameHashMap["<S7>/F01_03_Direction_Detection"] = {sid: "BLDCmotorControl_R2017b:2687:38"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:38"] = {rtwname: "<S7>/F01_03_Direction_Detection"};
	this.rtwnameHashMap["<S7>/F01_04_Speed_Calculation"] = {sid: "BLDCmotorControl_R2017b:2687:59"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:59"] = {rtwname: "<S7>/F01_04_Speed_Calculation"};
	this.rtwnameHashMap["<S7>/From"] = {sid: "BLDCmotorControl_R2017b:2687:1377"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1377"] = {rtwname: "<S7>/From"};
	this.rtwnameHashMap["<S7>/From1"] = {sid: "BLDCmotorControl_R2017b:2687:179"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:179"] = {rtwname: "<S7>/From1"};
	this.rtwnameHashMap["<S7>/From10"] = {sid: "BLDCmotorControl_R2017b:2687:180"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:180"] = {rtwname: "<S7>/From10"};
	this.rtwnameHashMap["<S7>/From11"] = {sid: "BLDCmotorControl_R2017b:2687:1378"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1378"] = {rtwname: "<S7>/From11"};
	this.rtwnameHashMap["<S7>/From12"] = {sid: "BLDCmotorControl_R2017b:2687:1481"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1481"] = {rtwname: "<S7>/From12"};
	this.rtwnameHashMap["<S7>/From13"] = {sid: "BLDCmotorControl_R2017b:2687:183"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:183"] = {rtwname: "<S7>/From13"};
	this.rtwnameHashMap["<S7>/From14"] = {sid: "BLDCmotorControl_R2017b:2687:184"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:184"] = {rtwname: "<S7>/From14"};
	this.rtwnameHashMap["<S7>/From15"] = {sid: "BLDCmotorControl_R2017b:2687:1633"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1633"] = {rtwname: "<S7>/From15"};
	this.rtwnameHashMap["<S7>/From16"] = {sid: "BLDCmotorControl_R2017b:2687:1482"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1482"] = {rtwname: "<S7>/From16"};
	this.rtwnameHashMap["<S7>/From17"] = {sid: "BLDCmotorControl_R2017b:2687:1666"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1666"] = {rtwname: "<S7>/From17"};
	this.rtwnameHashMap["<S7>/From18"] = {sid: "BLDCmotorControl_R2017b:2687:1382"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1382"] = {rtwname: "<S7>/From18"};
	this.rtwnameHashMap["<S7>/From19"] = {sid: "BLDCmotorControl_R2017b:2687:1678"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1678"] = {rtwname: "<S7>/From19"};
	this.rtwnameHashMap["<S7>/From2"] = {sid: "BLDCmotorControl_R2017b:2687:186"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:186"] = {rtwname: "<S7>/From2"};
	this.rtwnameHashMap["<S7>/From3"] = {sid: "BLDCmotorControl_R2017b:2687:187"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:187"] = {rtwname: "<S7>/From3"};
	this.rtwnameHashMap["<S7>/From36"] = {sid: "BLDCmotorControl_R2017b:2687:188"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:188"] = {rtwname: "<S7>/From36"};
	this.rtwnameHashMap["<S7>/From38"] = {sid: "BLDCmotorControl_R2017b:2687:189"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:189"] = {rtwname: "<S7>/From38"};
	this.rtwnameHashMap["<S7>/From4"] = {sid: "BLDCmotorControl_R2017b:2687:190"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:190"] = {rtwname: "<S7>/From4"};
	this.rtwnameHashMap["<S7>/From5"] = {sid: "BLDCmotorControl_R2017b:2687:191"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:191"] = {rtwname: "<S7>/From5"};
	this.rtwnameHashMap["<S7>/From6"] = {sid: "BLDCmotorControl_R2017b:2687:192"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:192"] = {rtwname: "<S7>/From6"};
	this.rtwnameHashMap["<S7>/From7"] = {sid: "BLDCmotorControl_R2017b:2687:193"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:193"] = {rtwname: "<S7>/From7"};
	this.rtwnameHashMap["<S7>/From8"] = {sid: "BLDCmotorControl_R2017b:2687:194"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:194"] = {rtwname: "<S7>/From8"};
	this.rtwnameHashMap["<S7>/From9"] = {sid: "BLDCmotorControl_R2017b:2687:195"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:195"] = {rtwname: "<S7>/From9"};
	this.rtwnameHashMap["<S7>/Goto"] = {sid: "BLDCmotorControl_R2017b:2687:196"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:196"] = {rtwname: "<S7>/Goto"};
	this.rtwnameHashMap["<S7>/Goto1"] = {sid: "BLDCmotorControl_R2017b:2687:197"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:197"] = {rtwname: "<S7>/Goto1"};
	this.rtwnameHashMap["<S7>/Goto10"] = {sid: "BLDCmotorControl_R2017b:2687:1662"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1662"] = {rtwname: "<S7>/Goto10"};
	this.rtwnameHashMap["<S7>/Goto11"] = {sid: "BLDCmotorControl_R2017b:2687:1677"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1677"] = {rtwname: "<S7>/Goto11"};
	this.rtwnameHashMap["<S7>/Goto16"] = {sid: "BLDCmotorControl_R2017b:2687:198"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:198"] = {rtwname: "<S7>/Goto16"};
	this.rtwnameHashMap["<S7>/Goto18"] = {sid: "BLDCmotorControl_R2017b:2687:1376"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1376"] = {rtwname: "<S7>/Goto18"};
	this.rtwnameHashMap["<S7>/Goto2"] = {sid: "BLDCmotorControl_R2017b:2687:199"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:199"] = {rtwname: "<S7>/Goto2"};
	this.rtwnameHashMap["<S7>/Goto21"] = {sid: "BLDCmotorControl_R2017b:2687:200"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:200"] = {rtwname: "<S7>/Goto21"};
	this.rtwnameHashMap["<S7>/Goto3"] = {sid: "BLDCmotorControl_R2017b:2687:1384"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1384"] = {rtwname: "<S7>/Goto3"};
	this.rtwnameHashMap["<S7>/Goto4"] = {sid: "BLDCmotorControl_R2017b:2687:202"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:202"] = {rtwname: "<S7>/Goto4"};
	this.rtwnameHashMap["<S7>/Goto5"] = {sid: "BLDCmotorControl_R2017b:2687:1489"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1489"] = {rtwname: "<S7>/Goto5"};
	this.rtwnameHashMap["<S7>/Goto6"] = {sid: "BLDCmotorControl_R2017b:2687:1490"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1490"] = {rtwname: "<S7>/Goto6"};
	this.rtwnameHashMap["<S7>/Goto7"] = {sid: "BLDCmotorControl_R2017b:2687:205"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:205"] = {rtwname: "<S7>/Goto7"};
	this.rtwnameHashMap["<S7>/Goto8"] = {sid: "BLDCmotorControl_R2017b:2687:206"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:206"] = {rtwname: "<S7>/Goto8"};
	this.rtwnameHashMap["<S7>/Goto9"] = {sid: "BLDCmotorControl_R2017b:2687:1634"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1634"] = {rtwname: "<S7>/Goto9"};
	this.rtwnameHashMap["<S7>/If2"] = {sid: "BLDCmotorControl_R2017b:2687:1313"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1313"] = {rtwname: "<S7>/If2"};
	this.rtwnameHashMap["<S7>/z_ctrlTypSel1"] = {sid: "BLDCmotorControl_R2017b:2687:208"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:208"] = {rtwname: "<S7>/z_ctrlTypSel1"};
	this.rtwnameHashMap["<S7>/z_ctrlTypSel"] = {sid: "BLDCmotorControl_R2017b:2687:209"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:209"] = {rtwname: "<S7>/z_ctrlTypSel"};
	this.rtwnameHashMap["<S7>/z_pos"] = {sid: "BLDCmotorControl_R2017b:2687:210"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:210"] = {rtwname: "<S7>/z_pos"};
	this.rtwnameHashMap["<S7>/z_dir"] = {sid: "BLDCmotorControl_R2017b:2687:211"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:211"] = {rtwname: "<S7>/z_dir"};
	this.rtwnameHashMap["<S7>/z_counter"] = {sid: "BLDCmotorControl_R2017b:2687:1483"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1483"] = {rtwname: "<S7>/z_counter"};
	this.rtwnameHashMap["<S7>/z_counterRaw"] = {sid: "BLDCmotorControl_R2017b:2687:1484"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1484"] = {rtwname: "<S7>/z_counterRaw"};
	this.rtwnameHashMap["<S7>/n_motAbs"] = {sid: "BLDCmotorControl_R2017b:2687:1679"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1679"] = {rtwname: "<S7>/n_motAbs"};
	this.rtwnameHashMap["<S7>/b_advCtrlEna"] = {sid: "BLDCmotorControl_R2017b:2687:1383"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1383"] = {rtwname: "<S7>/b_advCtrlEna"};
	this.rtwnameHashMap["<S7>/n_mot "] = {sid: "BLDCmotorControl_R2017b:2687:212"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:212"] = {rtwname: "<S7>/n_mot "};
	this.rtwnameHashMap["<S8>/r_DCabs"] = {sid: "BLDCmotorControl_R2017b:2687:535"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:535"] = {rtwname: "<S8>/r_DCabs"};
	this.rtwnameHashMap["<S8>/z_pos"] = {sid: "BLDCmotorControl_R2017b:2687:216"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:216"] = {rtwname: "<S8>/z_pos"};
	this.rtwnameHashMap["<S8>/z_dir"] = {sid: "BLDCmotorControl_R2017b:2687:217"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:217"] = {rtwname: "<S8>/z_dir"};
	this.rtwnameHashMap["<S8>/z_counter"] = {sid: "BLDCmotorControl_R2017b:2687:1460"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1460"] = {rtwname: "<S8>/z_counter"};
	this.rtwnameHashMap["<S8>/z_counterRaw"] = {sid: "BLDCmotorControl_R2017b:2687:1461"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1461"] = {rtwname: "<S8>/z_counterRaw"};
	this.rtwnameHashMap["<S8>/n_motAbs"] = {sid: "BLDCmotorControl_R2017b:2687:1680"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1680"] = {rtwname: "<S8>/n_motAbs"};
	this.rtwnameHashMap["<S8>/Action Port"] = {sid: "BLDCmotorControl_R2017b:2687:221"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:221"] = {rtwname: "<S8>/Action Port"};
	this.rtwnameHashMap["<S8>/Constant16"] = {sid: "BLDCmotorControl_R2017b:2687:1464"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1464"] = {rtwname: "<S8>/Constant16"};
	this.rtwnameHashMap["<S8>/Constant2"] = {sid: "BLDCmotorControl_R2017b:2687:1465"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1465"] = {rtwname: "<S8>/Constant2"};
	this.rtwnameHashMap["<S8>/Divide4"] = {sid: "BLDCmotorControl_R2017b:2687:1466"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1466"] = {rtwname: "<S8>/Divide4"};
	this.rtwnameHashMap["<S8>/Divide5"] = {sid: "BLDCmotorControl_R2017b:2687:1467"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1467"] = {rtwname: "<S8>/Divide5"};
	this.rtwnameHashMap["<S8>/From1"] = {sid: "BLDCmotorControl_R2017b:2687:1669"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1669"] = {rtwname: "<S8>/From1"};
	this.rtwnameHashMap["<S8>/From10"] = {sid: "BLDCmotorControl_R2017b:2687:231"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:231"] = {rtwname: "<S8>/From10"};
	this.rtwnameHashMap["<S8>/From11"] = {sid: "BLDCmotorControl_R2017b:2687:518"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:518"] = {rtwname: "<S8>/From11"};
	this.rtwnameHashMap["<S8>/From12"] = {sid: "BLDCmotorControl_R2017b:2687:534"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:534"] = {rtwname: "<S8>/From12"};
	this.rtwnameHashMap["<S8>/From2"] = {sid: "BLDCmotorControl_R2017b:2687:232"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:232"] = {rtwname: "<S8>/From2"};
	this.rtwnameHashMap["<S8>/From3"] = {sid: "BLDCmotorControl_R2017b:2687:233"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:233"] = {rtwname: "<S8>/From3"};
	this.rtwnameHashMap["<S8>/From5"] = {sid: "BLDCmotorControl_R2017b:2687:235"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:235"] = {rtwname: "<S8>/From5"};
	this.rtwnameHashMap["<S8>/From51"] = {sid: "BLDCmotorControl_R2017b:2687:1468"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1468"] = {rtwname: "<S8>/From51"};
	this.rtwnameHashMap["<S8>/From52"] = {sid: "BLDCmotorControl_R2017b:2687:1469"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1469"] = {rtwname: "<S8>/From52"};
	this.rtwnameHashMap["<S8>/From53"] = {sid: "BLDCmotorControl_R2017b:2687:1470"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1470"] = {rtwname: "<S8>/From53"};
	this.rtwnameHashMap["<S8>/From54"] = {sid: "BLDCmotorControl_R2017b:2687:1471"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1471"] = {rtwname: "<S8>/From54"};
	this.rtwnameHashMap["<S8>/From59"] = {sid: "BLDCmotorControl_R2017b:2687:1472"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1472"] = {rtwname: "<S8>/From59"};
	this.rtwnameHashMap["<S8>/From6"] = {sid: "BLDCmotorControl_R2017b:2687:241"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:241"] = {rtwname: "<S8>/From6"};
	this.rtwnameHashMap["<S8>/From7"] = {sid: "BLDCmotorControl_R2017b:2687:542"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:542"] = {rtwname: "<S8>/From7"};
	this.rtwnameHashMap["<S8>/From9"] = {sid: "BLDCmotorControl_R2017b:2687:543"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:543"] = {rtwname: "<S8>/From9"};
	this.rtwnameHashMap["<S8>/Goto"] = {sid: "BLDCmotorControl_R2017b:2687:242"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:242"] = {rtwname: "<S8>/Goto"};
	this.rtwnameHashMap["<S8>/Goto1"] = {sid: "BLDCmotorControl_R2017b:2687:243"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:243"] = {rtwname: "<S8>/Goto1"};
	this.rtwnameHashMap["<S8>/Goto2"] = {sid: "BLDCmotorControl_R2017b:2687:1462"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1462"] = {rtwname: "<S8>/Goto2"};
	this.rtwnameHashMap["<S8>/Goto3"] = {sid: "BLDCmotorControl_R2017b:2687:1463"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1463"] = {rtwname: "<S8>/Goto3"};
	this.rtwnameHashMap["<S8>/Goto4"] = {sid: "BLDCmotorControl_R2017b:2687:1681"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1681"] = {rtwname: "<S8>/Goto4"};
	this.rtwnameHashMap["<S8>/Goto5"] = {sid: "BLDCmotorControl_R2017b:2687:578"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:578"] = {rtwname: "<S8>/Goto5"};
	this.rtwnameHashMap["<S8>/Goto7"] = {sid: "BLDCmotorControl_R2017b:2687:1473"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1473"] = {rtwname: "<S8>/Goto7"};
	this.rtwnameHashMap["<S8>/Goto8"] = {sid: "BLDCmotorControl_R2017b:2687:536"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:536"] = {rtwname: "<S8>/Goto8"};
	this.rtwnameHashMap["<S8>/Goto9"] = {sid: "BLDCmotorControl_R2017b:2687:538"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:538"] = {rtwname: "<S8>/Goto9"};
	this.rtwnameHashMap["<S8>/Logical Operator2"] = {sid: "BLDCmotorControl_R2017b:2687:1668"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1668"] = {rtwname: "<S8>/Logical Operator2"};
	this.rtwnameHashMap["<S8>/Math Function"] = {sid: "BLDCmotorControl_R2017b:2687:623"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:623"] = {rtwname: "<S8>/Math Function"};
	this.rtwnameHashMap["<S8>/Mux"] = {sid: "BLDCmotorControl_R2017b:2687:258"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:258"] = {rtwname: "<S8>/Mux"};
	this.rtwnameHashMap["<S8>/Product2"] = {sid: "BLDCmotorControl_R2017b:2687:545"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:545"] = {rtwname: "<S8>/Product2"};
	this.rtwnameHashMap["<S8>/Product6"] = {sid: "BLDCmotorControl_R2017b:2687:1474"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1474"] = {rtwname: "<S8>/Product6"};
	this.rtwnameHashMap["<S8>/Relational Operator4"] = {sid: "BLDCmotorControl_R2017b:2687:1670"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1670"] = {rtwname: "<S8>/Relational Operator4"};
	this.rtwnameHashMap["<S8>/Relational Operator7"] = {sid: "BLDCmotorControl_R2017b:2687:1475"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1475"] = {rtwname: "<S8>/Relational Operator7"};
	this.rtwnameHashMap["<S8>/Scope"] = {sid: "BLDCmotorControl_R2017b:2687:262"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:262"] = {rtwname: "<S8>/Scope"};
	this.rtwnameHashMap["<S8>/Sum1"] = {sid: "BLDCmotorControl_R2017b:2687:1476"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1476"] = {rtwname: "<S8>/Sum1"};
	this.rtwnameHashMap["<S8>/Sum2"] = {sid: "BLDCmotorControl_R2017b:2687:1477"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1477"] = {rtwname: "<S8>/Sum2"};
	this.rtwnameHashMap["<S8>/Sum3"] = {sid: "BLDCmotorControl_R2017b:2687:546"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:546"] = {rtwname: "<S8>/Sum3"};
	this.rtwnameHashMap["<S8>/Switch3"] = {sid: "BLDCmotorControl_R2017b:2687:1478"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1478"] = {rtwname: "<S8>/Switch3"};
	this.rtwnameHashMap["<S8>/Switch_PhaAdv"] = {sid: "BLDCmotorControl_R2017b:2687:514"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:514"] = {rtwname: "<S8>/Switch_PhaAdv"};
	this.rtwnameHashMap["<S8>/a_elecAngle1"] = {sid: "BLDCmotorControl_R2017b:2687:1479"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1479"] = {rtwname: "<S8>/a_elecAngle1"};
	this.rtwnameHashMap["<S8>/a_elecPeriod1"] = {sid: "BLDCmotorControl_R2017b:2687:512"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:512"] = {rtwname: "<S8>/a_elecPeriod1"};
	this.rtwnameHashMap["<S8>/a_elecPeriod2"] = {sid: "BLDCmotorControl_R2017b:2687:547"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:547"] = {rtwname: "<S8>/a_elecPeriod2"};
	this.rtwnameHashMap["<S8>/a_phaAdv_M2"] = {sid: "BLDCmotorControl_R2017b:2687:521"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:521"] = {rtwname: "<S8>/a_phaAdv_M2"};
	this.rtwnameHashMap["<S8>/n_motPhaAdvEna"] = {sid: "BLDCmotorControl_R2017b:2687:1671"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1671"] = {rtwname: "<S8>/n_motPhaAdvEna"};
	this.rtwnameHashMap["<S8>/r_phaAdvDC_XA"] = {sid: "BLDCmotorControl_R2017b:2687:522"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:522"] = {rtwname: "<S8>/r_phaAdvDC_XA"};
	this.rtwnameHashMap["<S8>/a_elecAngleAdv"] = {sid: "BLDCmotorControl_R2017b:2687:278"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:278"] = {rtwname: "<S8>/a_elecAngleAdv"};
	this.rtwnameHashMap["<S8>/a_elecAngle"] = {sid: "BLDCmotorControl_R2017b:2687:279"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:279"] = {rtwname: "<S8>/a_elecAngle"};
	this.rtwnameHashMap["<S9>/z_ctrlTypSel"] = {sid: "BLDCmotorControl_R2017b:2687:283"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:283"] = {rtwname: "<S9>/z_ctrlTypSel"};
	this.rtwnameHashMap["<S9>/a_elecAngleAdv"] = {sid: "BLDCmotorControl_R2017b:2687:284"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:284"] = {rtwname: "<S9>/a_elecAngleAdv"};
	this.rtwnameHashMap["<S9>/F03_01_Pure_Trapezoidal_Method"] = {sid: "BLDCmotorControl_R2017b:2687:285"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:285"] = {rtwname: "<S9>/F03_01_Pure_Trapezoidal_Method"};
	this.rtwnameHashMap["<S9>/F03_02_Sinusoidal_Method"] = {sid: "BLDCmotorControl_R2017b:2687:305"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:305"] = {rtwname: "<S9>/F03_02_Sinusoidal_Method"};
	this.rtwnameHashMap["<S9>/F03_03_Sinusoidal3rd_Method"] = {sid: "BLDCmotorControl_R2017b:2687:295"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:295"] = {rtwname: "<S9>/F03_03_Sinusoidal3rd_Method"};
	this.rtwnameHashMap["<S9>/From"] = {sid: "BLDCmotorControl_R2017b:2687:315"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:315"] = {rtwname: "<S9>/From"};
	this.rtwnameHashMap["<S9>/From10"] = {sid: "BLDCmotorControl_R2017b:2687:316"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:316"] = {rtwname: "<S9>/From10"};
	this.rtwnameHashMap["<S9>/From13"] = {sid: "BLDCmotorControl_R2017b:2687:317"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:317"] = {rtwname: "<S9>/From13"};
	this.rtwnameHashMap["<S9>/From14"] = {sid: "BLDCmotorControl_R2017b:2687:318"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:318"] = {rtwname: "<S9>/From14"};
	this.rtwnameHashMap["<S9>/From15"] = {sid: "BLDCmotorControl_R2017b:2687:319"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:319"] = {rtwname: "<S9>/From15"};
	this.rtwnameHashMap["<S9>/From16"] = {sid: "BLDCmotorControl_R2017b:2687:320"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:320"] = {rtwname: "<S9>/From16"};
	this.rtwnameHashMap["<S9>/From17"] = {sid: "BLDCmotorControl_R2017b:2687:321"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:321"] = {rtwname: "<S9>/From17"};
	this.rtwnameHashMap["<S9>/From18"] = {sid: "BLDCmotorControl_R2017b:2687:322"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:322"] = {rtwname: "<S9>/From18"};
	this.rtwnameHashMap["<S9>/From19"] = {sid: "BLDCmotorControl_R2017b:2687:323"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:323"] = {rtwname: "<S9>/From19"};
	this.rtwnameHashMap["<S9>/From20"] = {sid: "BLDCmotorControl_R2017b:2687:324"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:324"] = {rtwname: "<S9>/From20"};
	this.rtwnameHashMap["<S9>/From4"] = {sid: "BLDCmotorControl_R2017b:2687:325"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:325"] = {rtwname: "<S9>/From4"};
	this.rtwnameHashMap["<S9>/From5"] = {sid: "BLDCmotorControl_R2017b:2687:326"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:326"] = {rtwname: "<S9>/From5"};
	this.rtwnameHashMap["<S9>/From6"] = {sid: "BLDCmotorControl_R2017b:2687:327"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:327"] = {rtwname: "<S9>/From6"};
	this.rtwnameHashMap["<S9>/From7"] = {sid: "BLDCmotorControl_R2017b:2687:328"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:328"] = {rtwname: "<S9>/From7"};
	this.rtwnameHashMap["<S9>/From8"] = {sid: "BLDCmotorControl_R2017b:2687:329"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:329"] = {rtwname: "<S9>/From8"};
	this.rtwnameHashMap["<S9>/From9"] = {sid: "BLDCmotorControl_R2017b:2687:330"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:330"] = {rtwname: "<S9>/From9"};
	this.rtwnameHashMap["<S9>/Goto"] = {sid: "BLDCmotorControl_R2017b:2687:331"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:331"] = {rtwname: "<S9>/Goto"};
	this.rtwnameHashMap["<S9>/Goto1"] = {sid: "BLDCmotorControl_R2017b:2687:332"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:332"] = {rtwname: "<S9>/Goto1"};
	this.rtwnameHashMap["<S9>/Goto10"] = {sid: "BLDCmotorControl_R2017b:2687:333"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:333"] = {rtwname: "<S9>/Goto10"};
	this.rtwnameHashMap["<S9>/Goto11"] = {sid: "BLDCmotorControl_R2017b:2687:334"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:334"] = {rtwname: "<S9>/Goto11"};
	this.rtwnameHashMap["<S9>/Goto12"] = {sid: "BLDCmotorControl_R2017b:2687:335"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:335"] = {rtwname: "<S9>/Goto12"};
	this.rtwnameHashMap["<S9>/Goto14"] = {sid: "BLDCmotorControl_R2017b:2687:336"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:336"] = {rtwname: "<S9>/Goto14"};
	this.rtwnameHashMap["<S9>/Goto2"] = {sid: "BLDCmotorControl_R2017b:2687:337"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:337"] = {rtwname: "<S9>/Goto2"};
	this.rtwnameHashMap["<S9>/Goto3"] = {sid: "BLDCmotorControl_R2017b:2687:338"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:338"] = {rtwname: "<S9>/Goto3"};
	this.rtwnameHashMap["<S9>/Goto4"] = {sid: "BLDCmotorControl_R2017b:2687:339"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:339"] = {rtwname: "<S9>/Goto4"};
	this.rtwnameHashMap["<S9>/Goto5"] = {sid: "BLDCmotorControl_R2017b:2687:340"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:340"] = {rtwname: "<S9>/Goto5"};
	this.rtwnameHashMap["<S9>/Goto6"] = {sid: "BLDCmotorControl_R2017b:2687:341"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:341"] = {rtwname: "<S9>/Goto6"};
	this.rtwnameHashMap["<S9>/Goto7"] = {sid: "BLDCmotorControl_R2017b:2687:342"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:342"] = {rtwname: "<S9>/Goto7"};
	this.rtwnameHashMap["<S9>/Goto8"] = {sid: "BLDCmotorControl_R2017b:2687:343"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:343"] = {rtwname: "<S9>/Goto8"};
	this.rtwnameHashMap["<S9>/Goto9"] = {sid: "BLDCmotorControl_R2017b:2687:344"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:344"] = {rtwname: "<S9>/Goto9"};
	this.rtwnameHashMap["<S9>/Merge"] = {sid: "BLDCmotorControl_R2017b:2687:345"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:345"] = {rtwname: "<S9>/Merge"};
	this.rtwnameHashMap["<S9>/Merge1"] = {sid: "BLDCmotorControl_R2017b:2687:346"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:346"] = {rtwname: "<S9>/Merge1"};
	this.rtwnameHashMap["<S9>/Merge2"] = {sid: "BLDCmotorControl_R2017b:2687:347"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:347"] = {rtwname: "<S9>/Merge2"};
	this.rtwnameHashMap["<S9>/Switch Case"] = {sid: "BLDCmotorControl_R2017b:2687:348"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:348"] = {rtwname: "<S9>/Switch Case"};
	this.rtwnameHashMap["<S9>/signal_log1"] = {sid: "BLDCmotorControl_R2017b:2687:349"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:349"] = {rtwname: "<S9>/signal_log1"};
	this.rtwnameHashMap["<S9>/signal_log2"] = {sid: "BLDCmotorControl_R2017b:2687:352"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:352"] = {rtwname: "<S9>/signal_log2"};
	this.rtwnameHashMap["<S9>/signal_log6"] = {sid: "BLDCmotorControl_R2017b:2687:355"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:355"] = {rtwname: "<S9>/signal_log6"};
	this.rtwnameHashMap["<S9>/r_phaA"] = {sid: "BLDCmotorControl_R2017b:2687:358"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:358"] = {rtwname: "<S9>/r_phaA"};
	this.rtwnameHashMap["<S9>/r_phaB"] = {sid: "BLDCmotorControl_R2017b:2687:359"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:359"] = {rtwname: "<S9>/r_phaB"};
	this.rtwnameHashMap["<S9>/r_phaC "] = {sid: "BLDCmotorControl_R2017b:2687:360"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:360"] = {rtwname: "<S9>/r_phaC "};
	this.rtwnameHashMap["<S10>/r_DC"] = {sid: "BLDCmotorControl_R2017b:2687:362"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:362"] = {rtwname: "<S10>/r_DC"};
	this.rtwnameHashMap["<S10>/r_phaA"] = {sid: "BLDCmotorControl_R2017b:2687:364"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:364"] = {rtwname: "<S10>/r_phaA"};
	this.rtwnameHashMap["<S10>/r_phaB"] = {sid: "BLDCmotorControl_R2017b:2687:365"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:365"] = {rtwname: "<S10>/r_phaB"};
	this.rtwnameHashMap["<S10>/r_phaC"] = {sid: "BLDCmotorControl_R2017b:2687:366"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:366"] = {rtwname: "<S10>/r_phaC"};
	this.rtwnameHashMap["<S10>/z_pos"] = {sid: "BLDCmotorControl_R2017b:2687:367"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:367"] = {rtwname: "<S10>/z_pos"};
	this.rtwnameHashMap["<S10>/b_advCtrlEna"] = {sid: "BLDCmotorControl_R2017b:2687:1385"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1385"] = {rtwname: "<S10>/b_advCtrlEna"};
	this.rtwnameHashMap["<S10>/Constant1"] = {sid: "BLDCmotorControl_R2017b:2687:370"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:370"] = {rtwname: "<S10>/Constant1"};
	this.rtwnameHashMap["<S10>/Demux"] = {sid: "BLDCmotorControl_R2017b:2687:372"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:372"] = {rtwname: "<S10>/Demux"};
	this.rtwnameHashMap["<S10>/Divide1"] = {sid: "BLDCmotorControl_R2017b:2687:373"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:373"] = {rtwname: "<S10>/Divide1"};
	this.rtwnameHashMap["<S10>/Divide2"] = {sid: "BLDCmotorControl_R2017b:2687:374"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:374"] = {rtwname: "<S10>/Divide2"};
	this.rtwnameHashMap["<S10>/Divide4"] = {sid: "BLDCmotorControl_R2017b:2687:375"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:375"] = {rtwname: "<S10>/Divide4"};
	this.rtwnameHashMap["<S10>/From"] = {sid: "BLDCmotorControl_R2017b:2687:1389"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1389"] = {rtwname: "<S10>/From"};
	this.rtwnameHashMap["<S10>/From1"] = {sid: "BLDCmotorControl_R2017b:2687:376"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:376"] = {rtwname: "<S10>/From1"};
	this.rtwnameHashMap["<S10>/From10"] = {sid: "BLDCmotorControl_R2017b:2687:377"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:377"] = {rtwname: "<S10>/From10"};
	this.rtwnameHashMap["<S10>/From2"] = {sid: "BLDCmotorControl_R2017b:2687:378"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:378"] = {rtwname: "<S10>/From2"};
	this.rtwnameHashMap["<S10>/From27"] = {sid: "BLDCmotorControl_R2017b:2687:379"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:379"] = {rtwname: "<S10>/From27"};
	this.rtwnameHashMap["<S10>/From39"] = {sid: "BLDCmotorControl_R2017b:2687:380"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:380"] = {rtwname: "<S10>/From39"};
	this.rtwnameHashMap["<S10>/From40"] = {sid: "BLDCmotorControl_R2017b:2687:381"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:381"] = {rtwname: "<S10>/From40"};
	this.rtwnameHashMap["<S10>/From41"] = {sid: "BLDCmotorControl_R2017b:2687:382"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:382"] = {rtwname: "<S10>/From41"};
	this.rtwnameHashMap["<S10>/From8"] = {sid: "BLDCmotorControl_R2017b:2687:385"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:385"] = {rtwname: "<S10>/From8"};
	this.rtwnameHashMap["<S10>/From9"] = {sid: "BLDCmotorControl_R2017b:2687:386"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:386"] = {rtwname: "<S10>/From9"};
	this.rtwnameHashMap["<S10>/Goto"] = {sid: "BLDCmotorControl_R2017b:2687:387"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:387"] = {rtwname: "<S10>/Goto"};
	this.rtwnameHashMap["<S10>/Goto1"] = {sid: "BLDCmotorControl_R2017b:2687:388"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:388"] = {rtwname: "<S10>/Goto1"};
	this.rtwnameHashMap["<S10>/Goto10"] = {sid: "BLDCmotorControl_R2017b:2687:1386"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1386"] = {rtwname: "<S10>/Goto10"};
	this.rtwnameHashMap["<S10>/Goto2"] = {sid: "BLDCmotorControl_R2017b:2687:389"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:389"] = {rtwname: "<S10>/Goto2"};
	this.rtwnameHashMap["<S10>/Goto4"] = {sid: "BLDCmotorControl_R2017b:2687:391"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:391"] = {rtwname: "<S10>/Goto4"};
	this.rtwnameHashMap["<S10>/Goto6"] = {sid: "BLDCmotorControl_R2017b:2687:393"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:393"] = {rtwname: "<S10>/Goto6"};
	this.rtwnameHashMap["<S10>/Goto7"] = {sid: "BLDCmotorControl_R2017b:2687:394"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:394"] = {rtwname: "<S10>/Goto7"};
	this.rtwnameHashMap["<S10>/Goto8"] = {sid: "BLDCmotorControl_R2017b:2687:395"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:395"] = {rtwname: "<S10>/Goto8"};
	this.rtwnameHashMap["<S10>/Goto9"] = {sid: "BLDCmotorControl_R2017b:2687:396"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:396"] = {rtwname: "<S10>/Goto9"};
	this.rtwnameHashMap["<S10>/Mux2"] = {sid: "BLDCmotorControl_R2017b:2687:398"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:398"] = {rtwname: "<S10>/Mux2"};
	this.rtwnameHashMap["<S10>/Switch1"] = {sid: "BLDCmotorControl_R2017b:2687:401"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:401"] = {rtwname: "<S10>/Switch1"};
	this.rtwnameHashMap["<S10>/z_commutMap_M1"] = {sid: "BLDCmotorControl_R2017b:2687:411"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:411"] = {rtwname: "<S10>/z_commutMap_M1"};
	this.rtwnameHashMap["<S10>/DC_phaA"] = {sid: "BLDCmotorControl_R2017b:2687:412"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:412"] = {rtwname: "<S10>/DC_phaA"};
	this.rtwnameHashMap["<S10>/DC_phaB"] = {sid: "BLDCmotorControl_R2017b:2687:413"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:413"] = {rtwname: "<S10>/DC_phaB"};
	this.rtwnameHashMap["<S10>/DC_phaC "] = {sid: "BLDCmotorControl_R2017b:2687:414"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:414"] = {rtwname: "<S10>/DC_phaC "};
	this.rtwnameHashMap["<S11>/b_hallA"] = {sid: "BLDCmotorControl_R2017b:2687:27"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:27"] = {rtwname: "<S11>/b_hallA"};
	this.rtwnameHashMap["<S11>/b_hallB"] = {sid: "BLDCmotorControl_R2017b:2687:28"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:28"] = {rtwname: "<S11>/b_hallB"};
	this.rtwnameHashMap["<S11>/b_hallC"] = {sid: "BLDCmotorControl_R2017b:2687:29"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:29"] = {rtwname: "<S11>/b_hallC"};
	this.rtwnameHashMap["<S11>/Bitwise Operator"] = {sid: "BLDCmotorControl_R2017b:2687:1535"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1535"] = {rtwname: "<S11>/Bitwise Operator"};
	this.rtwnameHashMap["<S11>/UnitDelay"] = {sid: "BLDCmotorControl_R2017b:2687:31"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:31"] = {rtwname: "<S11>/UnitDelay"};
	this.rtwnameHashMap["<S11>/UnitDelay1"] = {sid: "BLDCmotorControl_R2017b:2687:32"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:32"] = {rtwname: "<S11>/UnitDelay1"};
	this.rtwnameHashMap["<S11>/UnitDelay2"] = {sid: "BLDCmotorControl_R2017b:2687:33"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:33"] = {rtwname: "<S11>/UnitDelay2"};
	this.rtwnameHashMap["<S11>/b_edge "] = {sid: "BLDCmotorControl_R2017b:2687:37"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:37"] = {rtwname: "<S11>/b_edge "};
	this.rtwnameHashMap["<S12>/b_hallA"] = {sid: "BLDCmotorControl_R2017b:2687:11"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:11"] = {rtwname: "<S12>/b_hallA"};
	this.rtwnameHashMap["<S12>/b_hallB"] = {sid: "BLDCmotorControl_R2017b:2687:12"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:12"] = {rtwname: "<S12>/b_hallB"};
	this.rtwnameHashMap["<S12>/b_hallC"] = {sid: "BLDCmotorControl_R2017b:2687:13"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:13"] = {rtwname: "<S12>/b_hallC"};
	this.rtwnameHashMap["<S12>/Selector"] = {sid: "BLDCmotorControl_R2017b:2687:14"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:14"] = {rtwname: "<S12>/Selector"};
	this.rtwnameHashMap["<S12>/Sum"] = {sid: "BLDCmotorControl_R2017b:2687:15"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:15"] = {rtwname: "<S12>/Sum"};
	this.rtwnameHashMap["<S12>/g_Ha"] = {sid: "BLDCmotorControl_R2017b:2687:17"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:17"] = {rtwname: "<S12>/g_Ha"};
	this.rtwnameHashMap["<S12>/g_Hb"] = {sid: "BLDCmotorControl_R2017b:2687:18"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:18"] = {rtwname: "<S12>/g_Hb"};
	this.rtwnameHashMap["<S12>/vec_hallToPos"] = {sid: "BLDCmotorControl_R2017b:2687:22"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:22"] = {rtwname: "<S12>/vec_hallToPos"};
	this.rtwnameHashMap["<S12>/z_pos "] = {sid: "BLDCmotorControl_R2017b:2687:23"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:23"] = {rtwname: "<S12>/z_pos "};
	this.rtwnameHashMap["<S13>/z_pos"] = {sid: "BLDCmotorControl_R2017b:2687:39"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:39"] = {rtwname: "<S13>/z_pos"};
	this.rtwnameHashMap["<S13>/Action Port"] = {sid: "BLDCmotorControl_R2017b:2687:1314"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1314"] = {rtwname: "<S13>/Action Port"};
	this.rtwnameHashMap["<S13>/Constant20"] = {sid: "BLDCmotorControl_R2017b:2687:42"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:42"] = {rtwname: "<S13>/Constant20"};
	this.rtwnameHashMap["<S13>/Constant23"] = {sid: "BLDCmotorControl_R2017b:2687:43"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:43"] = {rtwname: "<S13>/Constant23"};
	this.rtwnameHashMap["<S13>/Constant24"] = {sid: "BLDCmotorControl_R2017b:2687:44"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:44"] = {rtwname: "<S13>/Constant24"};
	this.rtwnameHashMap["<S13>/Constant8"] = {sid: "BLDCmotorControl_R2017b:2687:45"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:45"] = {rtwname: "<S13>/Constant8"};
	this.rtwnameHashMap["<S13>/Logical Operator3"] = {sid: "BLDCmotorControl_R2017b:2687:48"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:48"] = {rtwname: "<S13>/Logical Operator3"};
	this.rtwnameHashMap["<S13>/Relational Operator1"] = {sid: "BLDCmotorControl_R2017b:2687:49"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:49"] = {rtwname: "<S13>/Relational Operator1"};
	this.rtwnameHashMap["<S13>/Relational Operator6"] = {sid: "BLDCmotorControl_R2017b:2687:50"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:50"] = {rtwname: "<S13>/Relational Operator6"};
	this.rtwnameHashMap["<S13>/Sum2"] = {sid: "BLDCmotorControl_R2017b:2687:51"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:51"] = {rtwname: "<S13>/Sum2"};
	this.rtwnameHashMap["<S13>/Switch2"] = {sid: "BLDCmotorControl_R2017b:2687:52"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:52"] = {rtwname: "<S13>/Switch2"};
	this.rtwnameHashMap["<S13>/UnitDelay1"] = {sid: "BLDCmotorControl_R2017b:2687:1631"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1631"] = {rtwname: "<S13>/UnitDelay1"};
	this.rtwnameHashMap["<S13>/UnitDelay2"] = {sid: "BLDCmotorControl_R2017b:2687:1318"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1318"] = {rtwname: "<S13>/UnitDelay2"};
	this.rtwnameHashMap["<S13>/z_dir"] = {sid: "BLDCmotorControl_R2017b:2687:57"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:57"] = {rtwname: "<S13>/z_dir"};
	this.rtwnameHashMap["<S13>/z_dirPrev"] = {sid: "BLDCmotorControl_R2017b:2687:1632"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1632"] = {rtwname: "<S13>/z_dirPrev"};
	this.rtwnameHashMap["<S14>/r_DC"] = {sid: "BLDCmotorControl_R2017b:2687:1373"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1373"] = {rtwname: "<S14>/r_DC"};
	this.rtwnameHashMap["<S14>/r_DCabs"] = {sid: "BLDCmotorControl_R2017b:2687:1663"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1663"] = {rtwname: "<S14>/r_DCabs"};
	this.rtwnameHashMap["<S14>/z_ctrlTypSel"] = {sid: "BLDCmotorControl_R2017b:2687:1370"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1370"] = {rtwname: "<S14>/z_ctrlTypSel"};
	this.rtwnameHashMap["<S14>/b_edge"] = {sid: "BLDCmotorControl_R2017b:2687:60"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:60"] = {rtwname: "<S14>/b_edge"};
	this.rtwnameHashMap["<S14>/z_dir"] = {sid: "BLDCmotorControl_R2017b:2687:61"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:61"] = {rtwname: "<S14>/z_dir"};
	this.rtwnameHashMap["<S14>/z_dirPrev"] = {sid: "BLDCmotorControl_R2017b:2687:1629"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1629"] = {rtwname: "<S14>/z_dirPrev"};
	this.rtwnameHashMap["<S14>/Abs2"] = {sid: "BLDCmotorControl_R2017b:2687:1366"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1366"] = {rtwname: "<S14>/Abs2"};
	this.rtwnameHashMap["<S14>/CTRL_COMM"] = {sid: "BLDCmotorControl_R2017b:2687:1321"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1321"] = {rtwname: "<S14>/CTRL_COMM"};
	this.rtwnameHashMap["<S14>/Constant6"] = {sid: "BLDCmotorControl_R2017b:2687:64"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:64"] = {rtwname: "<S14>/Constant6"};
	this.rtwnameHashMap["<S14>/Counter_Hold_and_Error_Calculation"] = {sid: "BLDCmotorControl_R2017b:2687:1340"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1340"] = {rtwname: "<S14>/Counter_Hold_and_Error_Calculation"};
	this.rtwnameHashMap["<S14>/From"] = {sid: "BLDCmotorControl_R2017b:2687:80"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:80"] = {rtwname: "<S14>/From"};
	this.rtwnameHashMap["<S14>/From1"] = {sid: "BLDCmotorControl_R2017b:2687:81"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:81"] = {rtwname: "<S14>/From1"};
	this.rtwnameHashMap["<S14>/From10"] = {sid: "BLDCmotorControl_R2017b:2687:660"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:660"] = {rtwname: "<S14>/From10"};
	this.rtwnameHashMap["<S14>/From11"] = {sid: "BLDCmotorControl_R2017b:2687:83"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:83"] = {rtwname: "<S14>/From11"};
	this.rtwnameHashMap["<S14>/From12"] = {sid: "BLDCmotorControl_R2017b:2687:1486"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1486"] = {rtwname: "<S14>/From12"};
	this.rtwnameHashMap["<S14>/From13"] = {sid: "BLDCmotorControl_R2017b:2687:1523"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1523"] = {rtwname: "<S14>/From13"};
	this.rtwnameHashMap["<S14>/From14"] = {sid: "BLDCmotorControl_R2017b:2687:1641"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1641"] = {rtwname: "<S14>/From14"};
	this.rtwnameHashMap["<S14>/From15"] = {sid: "BLDCmotorControl_R2017b:2687:1642"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1642"] = {rtwname: "<S14>/From15"};
	this.rtwnameHashMap["<S14>/From16"] = {sid: "BLDCmotorControl_R2017b:2687:86"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:86"] = {rtwname: "<S14>/From16"};
	this.rtwnameHashMap["<S14>/From17"] = {sid: "BLDCmotorControl_R2017b:2687:1665"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1665"] = {rtwname: "<S14>/From17"};
	this.rtwnameHashMap["<S14>/From18"] = {sid: "BLDCmotorControl_R2017b:2687:1380"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1380"] = {rtwname: "<S14>/From18"};
	this.rtwnameHashMap["<S14>/From19"] = {sid: "BLDCmotorControl_R2017b:2687:1455"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1455"] = {rtwname: "<S14>/From19"};
	this.rtwnameHashMap["<S14>/From2"] = {sid: "BLDCmotorControl_R2017b:2687:1361"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1361"] = {rtwname: "<S14>/From2"};
	this.rtwnameHashMap["<S14>/From20"] = {sid: "BLDCmotorControl_R2017b:2687:1675"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1675"] = {rtwname: "<S14>/From20"};
	this.rtwnameHashMap["<S14>/From29"] = {sid: "BLDCmotorControl_R2017b:2687:1323"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1323"] = {rtwname: "<S14>/From29"};
	this.rtwnameHashMap["<S14>/From3"] = {sid: "BLDCmotorControl_R2017b:2687:1517"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1517"] = {rtwname: "<S14>/From3"};
	this.rtwnameHashMap["<S14>/From30"] = {sid: "BLDCmotorControl_R2017b:2687:1324"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1324"] = {rtwname: "<S14>/From30"};
	this.rtwnameHashMap["<S14>/From4"] = {sid: "BLDCmotorControl_R2017b:2687:92"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:92"] = {rtwname: "<S14>/From4"};
	this.rtwnameHashMap["<S14>/From42"] = {sid: "BLDCmotorControl_R2017b:2687:1397"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1397"] = {rtwname: "<S14>/From42"};
	this.rtwnameHashMap["<S14>/From5"] = {sid: "BLDCmotorControl_R2017b:2687:1485"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1485"] = {rtwname: "<S14>/From5"};
	this.rtwnameHashMap["<S14>/From6"] = {sid: "BLDCmotorControl_R2017b:2687:1521"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1521"] = {rtwname: "<S14>/From6"};
	this.rtwnameHashMap["<S14>/From7"] = {sid: "BLDCmotorControl_R2017b:2687:972"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:972"] = {rtwname: "<S14>/From7"};
	this.rtwnameHashMap["<S14>/From8"] = {sid: "BLDCmotorControl_R2017b:2687:1395"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1395"] = {rtwname: "<S14>/From8"};
	this.rtwnameHashMap["<S14>/From9"] = {sid: "BLDCmotorControl_R2017b:2687:1533"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1533"] = {rtwname: "<S14>/From9"};
	this.rtwnameHashMap["<S14>/Goto"] = {sid: "BLDCmotorControl_R2017b:2687:99"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:99"] = {rtwname: "<S14>/Goto"};
	this.rtwnameHashMap["<S14>/Goto1"] = {sid: "BLDCmotorControl_R2017b:2687:100"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:100"] = {rtwname: "<S14>/Goto1"};
	this.rtwnameHashMap["<S14>/Goto10"] = {sid: "BLDCmotorControl_R2017b:2687:1664"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1664"] = {rtwname: "<S14>/Goto10"};
	this.rtwnameHashMap["<S14>/Goto15"] = {sid: "BLDCmotorControl_R2017b:2687:1398"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1398"] = {rtwname: "<S14>/Goto15"};
	this.rtwnameHashMap["<S14>/Goto16"] = {sid: "BLDCmotorControl_R2017b:2687:1371"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1371"] = {rtwname: "<S14>/Goto16"};
	this.rtwnameHashMap["<S14>/Goto17"] = {sid: "BLDCmotorControl_R2017b:2687:1372"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1372"] = {rtwname: "<S14>/Goto17"};
	this.rtwnameHashMap["<S14>/Goto18"] = {sid: "BLDCmotorControl_R2017b:2687:1374"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1374"] = {rtwname: "<S14>/Goto18"};
	this.rtwnameHashMap["<S14>/Goto2"] = {sid: "BLDCmotorControl_R2017b:2687:1630"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1630"] = {rtwname: "<S14>/Goto2"};
	this.rtwnameHashMap["<S14>/Goto22"] = {sid: "BLDCmotorControl_R2017b:2687:106"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:106"] = {rtwname: "<S14>/Goto22"};
	this.rtwnameHashMap["<S14>/Goto3"] = {sid: "BLDCmotorControl_R2017b:2687:1674"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1674"] = {rtwname: "<S14>/Goto3"};
	this.rtwnameHashMap["<S14>/Goto5"] = {sid: "BLDCmotorControl_R2017b:2687:786"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:786"] = {rtwname: "<S14>/Goto5"};
	this.rtwnameHashMap["<S14>/Goto6"] = {sid: "BLDCmotorControl_R2017b:2687:1400"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1400"] = {rtwname: "<S14>/Goto6"};
	this.rtwnameHashMap["<S14>/Goto8"] = {sid: "BLDCmotorControl_R2017b:2687:108"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:108"] = {rtwname: "<S14>/Goto8"};
	this.rtwnameHashMap["<S14>/Goto9"] = {sid: "BLDCmotorControl_R2017b:2687:1362"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1362"] = {rtwname: "<S14>/Goto9"};
	this.rtwnameHashMap["<S14>/If1"] = {sid: "BLDCmotorControl_R2017b:2687:1339"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1339"] = {rtwname: "<S14>/If1"};
	this.rtwnameHashMap["<S14>/Logical Operator2"] = {sid: "BLDCmotorControl_R2017b:2687:1325"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1325"] = {rtwname: "<S14>/Logical Operator2"};
	this.rtwnameHashMap["<S14>/Motor_Speed_Calculation"] = {sid: "BLDCmotorControl_R2017b:2687:1401"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1401"] = {rtwname: "<S14>/Motor_Speed_Calculation"};
	this.rtwnameHashMap["<S14>/Mux1"] = {sid: "BLDCmotorControl_R2017b:2687:659"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:659"] = {rtwname: "<S14>/Mux1"};
	this.rtwnameHashMap["<S14>/Mux2"] = {sid: "BLDCmotorControl_R2017b:2687:842"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:842"] = {rtwname: "<S14>/Mux2"};
	this.rtwnameHashMap["<S14>/Relational Operator1"] = {sid: "BLDCmotorControl_R2017b:2687:1524"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1524"] = {rtwname: "<S14>/Relational Operator1"};
	this.rtwnameHashMap["<S14>/Relational Operator3"] = {sid: "BLDCmotorControl_R2017b:2687:1326"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1326"] = {rtwname: "<S14>/Relational Operator3"};
	this.rtwnameHashMap["<S14>/Relational Operator4"] = {sid: "BLDCmotorControl_R2017b:2687:1327"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1327"] = {rtwname: "<S14>/Relational Operator4"};
	this.rtwnameHashMap["<S14>/Scope2"] = {sid: "BLDCmotorControl_R2017b:2687:141"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:141"] = {rtwname: "<S14>/Scope2"};
	this.rtwnameHashMap["<S14>/Sign"] = {sid: "BLDCmotorControl_R2017b:2687:1525"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1525"] = {rtwname: "<S14>/Sign"};
	this.rtwnameHashMap["<S14>/Sign1"] = {sid: "BLDCmotorControl_R2017b:2687:1526"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1526"] = {rtwname: "<S14>/Sign1"};
	this.rtwnameHashMap["<S14>/Sum1"] = {sid: "BLDCmotorControl_R2017b:2687:142"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:142"] = {rtwname: "<S14>/Sum1"};
	this.rtwnameHashMap["<S14>/UnitDelay1"] = {sid: "BLDCmotorControl_R2017b:2687:1507"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1507"] = {rtwname: "<S14>/UnitDelay1"};
	this.rtwnameHashMap["<S14>/dz_counter"] = {sid: "BLDCmotorControl_R2017b:2687:1518"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1518"] = {rtwname: "<S14>/dz_counter"};
	this.rtwnameHashMap["<S14>/n_commDeacv"] = {sid: "BLDCmotorControl_R2017b:2687:1328"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1328"] = {rtwname: "<S14>/n_commDeacv"};
	this.rtwnameHashMap["<S14>/r_commDCDeacv"] = {sid: "BLDCmotorControl_R2017b:2687:1329"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1329"] = {rtwname: "<S14>/r_commDCDeacv"};
	this.rtwnameHashMap["<S14>/rst_DelayLim"] = {sid: "BLDCmotorControl_R2017b:2687:1651"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1651"] = {rtwname: "<S14>/rst_DelayLim"};
	this.rtwnameHashMap["<S14>/n_mot"] = {sid: "BLDCmotorControl_R2017b:2687:173"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:173"] = {rtwname: "<S14>/n_mot"};
	this.rtwnameHashMap["<S14>/n_motAbs"] = {sid: "BLDCmotorControl_R2017b:2687:1676"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1676"] = {rtwname: "<S14>/n_motAbs"};
	this.rtwnameHashMap["<S14>/b_advCtrlEna"] = {sid: "BLDCmotorControl_R2017b:2687:1381"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1381"] = {rtwname: "<S14>/b_advCtrlEna"};
	this.rtwnameHashMap["<S14>/z_counter"] = {sid: "BLDCmotorControl_R2017b:2687:1487"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1487"] = {rtwname: "<S14>/z_counter"};
	this.rtwnameHashMap["<S14>/z_counterRaw"] = {sid: "BLDCmotorControl_R2017b:2687:1488"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1488"] = {rtwname: "<S14>/z_counterRaw"};
	this.rtwnameHashMap["<S15>/z_counterRawPrev"] = {sid: "BLDCmotorControl_R2017b:2687:1341"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1341"] = {rtwname: "<S15>/z_counterRawPrev"};
	this.rtwnameHashMap["<S15>/Action Port"] = {sid: "BLDCmotorControl_R2017b:2687:1344"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1344"] = {rtwname: "<S15>/Action Port"};
	this.rtwnameHashMap["<S15>/Sum4"] = {sid: "BLDCmotorControl_R2017b:2687:1454"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1454"] = {rtwname: "<S15>/Sum4"};
	this.rtwnameHashMap["<S15>/z_counter2"] = {sid: "BLDCmotorControl_R2017b:2687:169"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:169"] = {rtwname: "<S15>/z_counter2"};
	this.rtwnameHashMap["<S15>/z_counter"] = {sid: "BLDCmotorControl_R2017b:2687:1358"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1358"] = {rtwname: "<S15>/z_counter"};
	this.rtwnameHashMap["<S15>/dz_counter"] = {sid: "BLDCmotorControl_R2017b:2687:1359"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1359"] = {rtwname: "<S15>/dz_counter"};
	this.rtwnameHashMap["<S16>/z_dir"] = {sid: "BLDCmotorControl_R2017b:2687:1431"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1431"] = {rtwname: "<S16>/z_dir"};
	this.rtwnameHashMap["<S16>/z_dirPrev"] = {sid: "BLDCmotorControl_R2017b:2687:1640"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1640"] = {rtwname: "<S16>/z_dirPrev"};
	this.rtwnameHashMap["<S16>/z_counter"] = {sid: "BLDCmotorControl_R2017b:2687:1430"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1430"] = {rtwname: "<S16>/z_counter"};
	this.rtwnameHashMap["<S16>/z_counterRaw"] = {sid: "BLDCmotorControl_R2017b:2687:1639"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1639"] = {rtwname: "<S16>/z_counterRaw"};
	this.rtwnameHashMap["<S16>/Abs5"] = {sid: "BLDCmotorControl_R2017b:2687:1672"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1672"] = {rtwname: "<S16>/Abs5"};
	this.rtwnameHashMap["<S16>/Constant1"] = {sid: "BLDCmotorControl_R2017b:2687:1637"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1637"] = {rtwname: "<S16>/Constant1"};
	this.rtwnameHashMap["<S16>/Constant2"] = {sid: "BLDCmotorControl_R2017b:2687:1433"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1433"] = {rtwname: "<S16>/Constant2"};
	this.rtwnameHashMap["<S16>/Constant3"] = {sid: "BLDCmotorControl_R2017b:2687:1434"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1434"] = {rtwname: "<S16>/Constant3"};
	this.rtwnameHashMap["<S16>/Divide1"] = {sid: "BLDCmotorControl_R2017b:2687:1435"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1435"] = {rtwname: "<S16>/Divide1"};
	this.rtwnameHashMap["<S16>/Divide2"] = {sid: "BLDCmotorControl_R2017b:2687:1436"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1436"] = {rtwname: "<S16>/Divide2"};
	this.rtwnameHashMap["<S16>/Divide3"] = {sid: "BLDCmotorControl_R2017b:2687:1437"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1437"] = {rtwname: "<S16>/Divide3"};
	this.rtwnameHashMap["<S16>/Divide4"] = {sid: "BLDCmotorControl_R2017b:2687:1438"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1438"] = {rtwname: "<S16>/Divide4"};
	this.rtwnameHashMap["<S16>/From1"] = {sid: "BLDCmotorControl_R2017b:2687:1439"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1439"] = {rtwname: "<S16>/From1"};
	this.rtwnameHashMap["<S16>/From14"] = {sid: "BLDCmotorControl_R2017b:2687:1623"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1623"] = {rtwname: "<S16>/From14"};
	this.rtwnameHashMap["<S16>/From15"] = {sid: "BLDCmotorControl_R2017b:2687:1635"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1635"] = {rtwname: "<S16>/From15"};
	this.rtwnameHashMap["<S16>/From17"] = {sid: "BLDCmotorControl_R2017b:2687:1636"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1636"] = {rtwname: "<S16>/From17"};
	this.rtwnameHashMap["<S16>/From42"] = {sid: "BLDCmotorControl_R2017b:2687:1645"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1645"] = {rtwname: "<S16>/From42"};
	this.rtwnameHashMap["<S16>/From8"] = {sid: "BLDCmotorControl_R2017b:2687:1646"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1646"] = {rtwname: "<S16>/From8"};
	this.rtwnameHashMap["<S16>/Goto"] = {sid: "BLDCmotorControl_R2017b:2687:1647"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1647"] = {rtwname: "<S16>/Goto"};
	this.rtwnameHashMap["<S16>/Goto1"] = {sid: "BLDCmotorControl_R2017b:2687:1648"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1648"] = {rtwname: "<S16>/Goto1"};
	this.rtwnameHashMap["<S16>/Goto2"] = {sid: "BLDCmotorControl_R2017b:2687:1649"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1649"] = {rtwname: "<S16>/Goto2"};
	this.rtwnameHashMap["<S16>/Goto22"] = {sid: "BLDCmotorControl_R2017b:2687:1440"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1440"] = {rtwname: "<S16>/Goto22"};
	this.rtwnameHashMap["<S16>/Goto3"] = {sid: "BLDCmotorControl_R2017b:2687:1650"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1650"] = {rtwname: "<S16>/Goto3"};
	this.rtwnameHashMap["<S16>/Logical Operator1"] = {sid: "BLDCmotorControl_R2017b:2687:1627"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1627"] = {rtwname: "<S16>/Logical Operator1"};
	this.rtwnameHashMap["<S16>/Relational Operator2"] = {sid: "BLDCmotorControl_R2017b:2687:1624"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1624"] = {rtwname: "<S16>/Relational Operator2"};
	this.rtwnameHashMap["<S16>/Relational Operator5"] = {sid: "BLDCmotorControl_R2017b:2687:1628"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1628"] = {rtwname: "<S16>/Relational Operator5"};
	this.rtwnameHashMap["<S16>/Sum1"] = {sid: "BLDCmotorControl_R2017b:2687:1443"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1443"] = {rtwname: "<S16>/Sum1"};
	this.rtwnameHashMap["<S16>/Sum2"] = {sid: "BLDCmotorControl_R2017b:2687:1444"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1444"] = {rtwname: "<S16>/Sum2"};
	this.rtwnameHashMap["<S16>/Switch1"] = {sid: "BLDCmotorControl_R2017b:2687:1638"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1638"] = {rtwname: "<S16>/Switch1"};
	this.rtwnameHashMap["<S16>/UnitDelay2"] = {sid: "BLDCmotorControl_R2017b:2687:1446"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1446"] = {rtwname: "<S16>/UnitDelay2"};
	this.rtwnameHashMap["<S16>/cf_spdCoef"] = {sid: "BLDCmotorControl_R2017b:2687:1447"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1447"] = {rtwname: "<S16>/cf_spdCoef"};
	this.rtwnameHashMap["<S16>/cf_speedFilt"] = {sid: "BLDCmotorControl_R2017b:2687:1448"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1448"] = {rtwname: "<S16>/cf_speedFilt"};
	this.rtwnameHashMap["<S16>/z_maxCntRst"] = {sid: "BLDCmotorControl_R2017b:2687:1625"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1625"] = {rtwname: "<S16>/z_maxCntRst"};
	this.rtwnameHashMap["<S16>/n_motRaw"] = {sid: "BLDCmotorControl_R2017b:2687:1450"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1450"] = {rtwname: "<S16>/n_motRaw"};
	this.rtwnameHashMap["<S16>/n_mot"] = {sid: "BLDCmotorControl_R2017b:2687:1451"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1451"] = {rtwname: "<S16>/n_mot"};
	this.rtwnameHashMap["<S16>/n_motAbs"] = {sid: "BLDCmotorControl_R2017b:2687:1673"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1673"] = {rtwname: "<S16>/n_motAbs"};
	this.rtwnameHashMap["<S17>/u"] = {sid: "BLDCmotorControl_R2017b:2687:1651:1614"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1651:1614"] = {rtwname: "<S17>/u"};
	this.rtwnameHashMap["<S17>/rst"] = {sid: "BLDCmotorControl_R2017b:2687:1651:1615"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1651:1615"] = {rtwname: "<S17>/rst"};
	this.rtwnameHashMap["<S17>/Constant1"] = {sid: "BLDCmotorControl_R2017b:2687:1651:1616"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1651:1616"] = {rtwname: "<S17>/Constant1"};
	this.rtwnameHashMap["<S17>/Constant23"] = {sid: "BLDCmotorControl_R2017b:2687:1651:1617"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1651:1617"] = {rtwname: "<S17>/Constant23"};
	this.rtwnameHashMap["<S17>/Relational Operator1"] = {sid: "BLDCmotorControl_R2017b:2687:1651:1618"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1651:1618"] = {rtwname: "<S17>/Relational Operator1"};
	this.rtwnameHashMap["<S17>/Switch1"] = {sid: "BLDCmotorControl_R2017b:2687:1651:1619"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1651:1619"] = {rtwname: "<S17>/Switch1"};
	this.rtwnameHashMap["<S17>/Switch2"] = {sid: "BLDCmotorControl_R2017b:2687:1651:1620"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1651:1620"] = {rtwname: "<S17>/Switch2"};
	this.rtwnameHashMap["<S17>/UnitDelay1"] = {sid: "BLDCmotorControl_R2017b:2687:1651:1621"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1651:1621"] = {rtwname: "<S17>/UnitDelay1"};
	this.rtwnameHashMap["<S17>/y"] = {sid: "BLDCmotorControl_R2017b:2687:1651:1622"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:1651:1622"] = {rtwname: "<S17>/y"};
	this.rtwnameHashMap["<S18>/a_elecAngleAdv"] = {sid: "BLDCmotorControl_R2017b:2687:286"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:286"] = {rtwname: "<S18>/a_elecAngleAdv"};
	this.rtwnameHashMap["<S18>/Action Port"] = {sid: "BLDCmotorControl_R2017b:2687:287"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:287"] = {rtwname: "<S18>/Action Port"};
	this.rtwnameHashMap["<S18>/a_trapElecAngle_XA"] = {sid: "BLDCmotorControl_R2017b:2687:288"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:288"] = {rtwname: "<S18>/a_trapElecAngle_XA"};
	this.rtwnameHashMap["<S18>/r_trapPhaA_M1"] = {sid: "BLDCmotorControl_R2017b:2687:289"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:289"] = {rtwname: "<S18>/r_trapPhaA_M1"};
	this.rtwnameHashMap["<S18>/r_trapPhaB_M1"] = {sid: "BLDCmotorControl_R2017b:2687:290"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:290"] = {rtwname: "<S18>/r_trapPhaB_M1"};
	this.rtwnameHashMap["<S18>/r_trapPhaC_M1"] = {sid: "BLDCmotorControl_R2017b:2687:291"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:291"] = {rtwname: "<S18>/r_trapPhaC_M1"};
	this.rtwnameHashMap["<S18>/r_phaA_Trap"] = {sid: "BLDCmotorControl_R2017b:2687:292"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:292"] = {rtwname: "<S18>/r_phaA_Trap"};
	this.rtwnameHashMap["<S18>/r_phaB_Trap"] = {sid: "BLDCmotorControl_R2017b:2687:293"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:293"] = {rtwname: "<S18>/r_phaB_Trap"};
	this.rtwnameHashMap["<S18>/r_phaC_Trap"] = {sid: "BLDCmotorControl_R2017b:2687:294"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:294"] = {rtwname: "<S18>/r_phaC_Trap"};
	this.rtwnameHashMap["<S19>/a_elecAngleAdv"] = {sid: "BLDCmotorControl_R2017b:2687:306"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:306"] = {rtwname: "<S19>/a_elecAngleAdv"};
	this.rtwnameHashMap["<S19>/Action Port"] = {sid: "BLDCmotorControl_R2017b:2687:307"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:307"] = {rtwname: "<S19>/Action Port"};
	this.rtwnameHashMap["<S19>/a_sinElecAngle_XA"] = {sid: "BLDCmotorControl_R2017b:2687:308"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:308"] = {rtwname: "<S19>/a_sinElecAngle_XA"};
	this.rtwnameHashMap["<S19>/r_sinPhaA_M1"] = {sid: "BLDCmotorControl_R2017b:2687:309"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:309"] = {rtwname: "<S19>/r_sinPhaA_M1"};
	this.rtwnameHashMap["<S19>/r_sinPhaB_M1"] = {sid: "BLDCmotorControl_R2017b:2687:310"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:310"] = {rtwname: "<S19>/r_sinPhaB_M1"};
	this.rtwnameHashMap["<S19>/r_sinPhaC_M1"] = {sid: "BLDCmotorControl_R2017b:2687:311"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:311"] = {rtwname: "<S19>/r_sinPhaC_M1"};
	this.rtwnameHashMap["<S19>/r_phaA_Sin"] = {sid: "BLDCmotorControl_R2017b:2687:312"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:312"] = {rtwname: "<S19>/r_phaA_Sin"};
	this.rtwnameHashMap["<S19>/r_phaB_Sin"] = {sid: "BLDCmotorControl_R2017b:2687:313"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:313"] = {rtwname: "<S19>/r_phaB_Sin"};
	this.rtwnameHashMap["<S19>/r_phaC_Sin"] = {sid: "BLDCmotorControl_R2017b:2687:314"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:314"] = {rtwname: "<S19>/r_phaC_Sin"};
	this.rtwnameHashMap["<S20>/a_elecAngleAdv"] = {sid: "BLDCmotorControl_R2017b:2687:296"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:296"] = {rtwname: "<S20>/a_elecAngleAdv"};
	this.rtwnameHashMap["<S20>/Action Port"] = {sid: "BLDCmotorControl_R2017b:2687:297"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:297"] = {rtwname: "<S20>/Action Port"};
	this.rtwnameHashMap["<S20>/a_sinElecAngle_XA"] = {sid: "BLDCmotorControl_R2017b:2687:298"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:298"] = {rtwname: "<S20>/a_sinElecAngle_XA"};
	this.rtwnameHashMap["<S20>/r_sin3PhaA_M1"] = {sid: "BLDCmotorControl_R2017b:2687:299"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:299"] = {rtwname: "<S20>/r_sin3PhaA_M1"};
	this.rtwnameHashMap["<S20>/r_sin3PhaB_M1"] = {sid: "BLDCmotorControl_R2017b:2687:300"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:300"] = {rtwname: "<S20>/r_sin3PhaB_M1"};
	this.rtwnameHashMap["<S20>/r_sin3PhaC_M1"] = {sid: "BLDCmotorControl_R2017b:2687:301"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:301"] = {rtwname: "<S20>/r_sin3PhaC_M1"};
	this.rtwnameHashMap["<S20>/r_phaA_Sin3"] = {sid: "BLDCmotorControl_R2017b:2687:302"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:302"] = {rtwname: "<S20>/r_phaA_Sin3"};
	this.rtwnameHashMap["<S20>/r_phaB_Sin3"] = {sid: "BLDCmotorControl_R2017b:2687:303"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:303"] = {rtwname: "<S20>/r_phaB_Sin3"};
	this.rtwnameHashMap["<S20>/r_phaC_Sin3"] = {sid: "BLDCmotorControl_R2017b:2687:304"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:304"] = {rtwname: "<S20>/r_phaC_Sin3"};
	this.rtwnameHashMap["<S21>/r_phaB"] = {sid: "BLDCmotorControl_R2017b:2687:350"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:350"] = {rtwname: "<S21>/r_phaB"};
	this.rtwnameHashMap["<S21>/Terminator_1"] = {sid: "BLDCmotorControl_R2017b:2687:351"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:351"] = {rtwname: "<S21>/Terminator_1"};
	this.rtwnameHashMap["<S22>/r_phaC"] = {sid: "BLDCmotorControl_R2017b:2687:353"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:353"] = {rtwname: "<S22>/r_phaC"};
	this.rtwnameHashMap["<S22>/Terminator_1"] = {sid: "BLDCmotorControl_R2017b:2687:354"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:354"] = {rtwname: "<S22>/Terminator_1"};
	this.rtwnameHashMap["<S23>/r_phaA"] = {sid: "BLDCmotorControl_R2017b:2687:356"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:356"] = {rtwname: "<S23>/r_phaA"};
	this.rtwnameHashMap["<S23>/Terminator_1"] = {sid: "BLDCmotorControl_R2017b:2687:357"};
	this.sidHashMap["BLDCmotorControl_R2017b:2687:357"] = {rtwname: "<S23>/Terminator_1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
