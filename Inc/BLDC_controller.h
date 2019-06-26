/*
 *
 * File: BLDC_controller.h
 *
 * Code generated for Simulink model 'BLDC_controller'.
 *
 * Model version                  : 1.883
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun 11 21:14:57 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_BLDC_controller_h_
#define RTW_HEADER_BLDC_controller_h_
#include "rtwtypes.h"
#ifndef BLDC_controller_COMMON_INCLUDES_
# define BLDC_controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* BLDC_controller_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  int32_T Switch_PhaAdv;               /* '<S8>/Switch_PhaAdv' */
  int32_T UnitDelay2_DSTATE;           /* '<S16>/UnitDelay2' */
  int16_T Merge;                       /* '<S9>/Merge' */
  int16_T Merge1;                      /* '<S9>/Merge1' */
  int16_T Merge2;                      /* '<S9>/Merge2' */
  int16_T z_counterRawPrev;            /* '<S15>/z_counterRawPrev' */
  int16_T Sum4;                        /* '<S15>/Sum4' */
  int16_T UnitDelay1_DSTATE;           /* '<S17>/UnitDelay1' */
  int16_T UnitDelay1_DSTATE_c;         /* '<S14>/UnitDelay1' */
  int16_T z_counter2_DSTATE;           /* '<S15>/z_counter2' */
  int8_T UnitDelay1;                   /* '<S13>/UnitDelay1' */
  int8_T Switch2;                      /* '<S13>/Switch2' */
  int8_T UnitDelay2_DSTATE_i;          /* '<S13>/UnitDelay2' */
  int8_T If1_ActiveSubsystem;          /* '<S2>/If1' */
  uint8_T UnitDelay_DSTATE;            /* '<S11>/UnitDelay' */
  uint8_T UnitDelay1_DSTATE_i;         /* '<S11>/UnitDelay1' */
  uint8_T UnitDelay2_DSTATE_h;         /* '<S11>/UnitDelay2' */
  boolean_T n_commDeacv_Mode;          /* '<S14>/n_commDeacv' */
  boolean_T dz_counter_Mode;           /* '<S14>/dz_counter' */
} DW;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: r_trapPhaA_M1_Table
   * Referenced by: '<S18>/r_trapPhaA_M1'
   */
  int16_T r_trapPhaA_M1_Table[7];

  /* Computed Parameter: r_trapPhaB_M1_Table
   * Referenced by: '<S18>/r_trapPhaB_M1'
   */
  int16_T r_trapPhaB_M1_Table[7];

  /* Computed Parameter: r_trapPhaC_M1_Table
   * Referenced by: '<S18>/r_trapPhaC_M1'
   */
  int16_T r_trapPhaC_M1_Table[7];

  /* Computed Parameter: r_sinPhaA_M1_Table
   * Referenced by: '<S19>/r_sinPhaA_M1'
   */
  int16_T r_sinPhaA_M1_Table[37];

  /* Computed Parameter: r_sinPhaB_M1_Table
   * Referenced by: '<S19>/r_sinPhaB_M1'
   */
  int16_T r_sinPhaB_M1_Table[37];

  /* Computed Parameter: r_sinPhaC_M1_Table
   * Referenced by: '<S19>/r_sinPhaC_M1'
   */
  int16_T r_sinPhaC_M1_Table[37];

  /* Computed Parameter: r_sin3PhaA_M1_Table
   * Referenced by: '<S20>/r_sin3PhaA_M1'
   */
  int16_T r_sin3PhaA_M1_Table[37];

  /* Computed Parameter: r_sin3PhaB_M1_Table
   * Referenced by: '<S20>/r_sin3PhaB_M1'
   */
  int16_T r_sin3PhaB_M1_Table[37];

  /* Computed Parameter: r_sin3PhaC_M1_Table
   * Referenced by: '<S20>/r_sin3PhaC_M1'
   */
  int16_T r_sin3PhaC_M1_Table[37];

  /* Computed Parameter: z_commutMap_M1_table
   * Referenced by: '<S10>/z_commutMap_M1'
   */
  int16_T z_commutMap_M1_table[18];

  /* Computed Parameter: vec_hallToPos_Value
   * Referenced by: '<S12>/vec_hallToPos'
   */
  int8_T vec_hallToPos_Value[8];
} ConstP;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  uint8_T b_hallA;                     /* '<Root>/b_hallA ' */
  uint8_T b_hallB;                     /* '<Root>/b_hallB' */
  uint8_T b_hallC;                     /* '<Root>/b_hallC' */
  int32_T r_DC;                        /* '<Root>/r_DC' */
} ExtU;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  int32_T DC_phaA;                     /* '<Root>/DC_phaA' */
  int32_T DC_phaB;                     /* '<Root>/DC_phaB' */
  int32_T DC_phaC;                     /* '<Root>/DC_phaC' */
  int32_T n_mot;                       /* '<Root>/n_mot' */
  int32_T a_elecAngle;                 /* '<Root>/a_elecAngle' */
} ExtY;

/* Parameters (auto storage) */
struct P_ {
  int32_T cf_speedCoef;                /* Variable: cf_speedCoef
                                        * Referenced by: '<S16>/cf_spdCoef'
                                        */
  int32_T cf_speedFilt;                /* Variable: cf_speedFilt
                                        * Referenced by: '<S16>/cf_speedFilt'
                                        */
  int32_T n_commAcvLo;                 /* Variable: n_commAcvLo
                                        * Referenced by: '<S14>/n_commDeacv'
                                        */
  int32_T n_commDeacvHi;               /* Variable: n_commDeacvHi
                                        * Referenced by: '<S14>/n_commDeacv'
                                        */
  int32_T n_motPhaAdvEna;              /* Variable: n_motPhaAdvEna
                                        * Referenced by: '<S8>/n_motPhaAdvEna'
                                        */
  int32_T r_commDCDeacv;               /* Variable: r_commDCDeacv
                                        * Referenced by: '<S14>/r_commDCDeacv'
                                        */
  int32_T r_phaAdvDC_XA[11];           /* Variable: r_phaAdvDC_XA
                                        * Referenced by: '<S8>/r_phaAdvDC_XA'
                                        */
  int16_T a_phaAdv_M1[11];             /* Variable: a_phaAdv_M1
                                        * Referenced by: '<S8>/a_phaAdv_M2'
                                        */
  int16_T dz_counterHi;                /* Variable: dz_counterHi
                                        * Referenced by: '<S14>/dz_counter'
                                        */
  int16_T dz_counterLo;                /* Variable: dz_counterLo
                                        * Referenced by: '<S14>/dz_counter'
                                        */
  int16_T z_maxCntRst;                 /* Variable: z_maxCntRst
                                        * Referenced by:
                                        *   '<S15>/z_counter'
                                        *   '<S15>/z_counter2'
                                        *   '<S16>/z_maxCntRst'
                                        *   '<S17>/Constant1'
                                        *   '<S17>/UnitDelay1'
                                        */
  uint8_T z_ctrlTypSel;                /* Variable: z_ctrlTypSel
                                        * Referenced by: '<S7>/z_ctrlTypSel1'
                                        */
  boolean_T b_phaAdvEna;               /* Variable: b_phaAdvEna
                                        * Referenced by: '<S8>/a_elecPeriod1'
                                        */
};

/* Parameters (auto storage) */
typedef struct P_ P;

/* Real-time Model Data Structure */
struct tag_RTM {
  P *defaultParam;
  ExtU *inputs;
  ExtY *outputs;
  DW *dwork;
};

/* Constant parameters (auto storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void BLDC_controller_initialize(RT_MODEL *const rtM);
extern void BLDC_controller_step(RT_MODEL *const rtM);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S14>/Scope2' : Unused code path elimination
 * Block '<S8>/Scope' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('BLDCmotorControl_R2017b/BLDC_controller')    - opens subsystem BLDCmotorControl_R2017b/BLDC_controller
 * hilite_system('BLDCmotorControl_R2017b/BLDC_controller/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'BLDCmotorControl_R2017b'
 * '<S1>'   : 'BLDCmotorControl_R2017b/BLDC_controller'
 * '<S2>'   : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller'
 * '<S3>'   : 'BLDCmotorControl_R2017b/BLDC_controller/signal_log1'
 * '<S4>'   : 'BLDCmotorControl_R2017b/BLDC_controller/signal_log2'
 * '<S5>'   : 'BLDCmotorControl_R2017b/BLDC_controller/signal_log3'
 * '<S6>'   : 'BLDCmotorControl_R2017b/BLDC_controller/signal_log6'
 * '<S7>'   : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller/F01_Preliminary_Calculations'
 * '<S8>'   : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller/F02_Electrical_Angle_Calculation'
 * '<S9>'   : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller/F03_Control_Method_Selection'
 * '<S10>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller/F04_Control_Type_Management'
 * '<S11>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller/F01_Preliminary_Calculations/F01_01_Edge_Detector'
 * '<S12>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller/F01_Preliminary_Calculations/F01_02_Position_Calculation'
 * '<S13>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller/F01_Preliminary_Calculations/F01_03_Direction_Detection'
 * '<S14>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller/F01_Preliminary_Calculations/F01_04_Speed_Calculation'
 * '<S15>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller/F01_Preliminary_Calculations/F01_04_Speed_Calculation/Counter_Hold_and_Error_Calculation'
 * '<S16>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller/F01_Preliminary_Calculations/F01_04_Speed_Calculation/Motor_Speed_Calculation'
 * '<S17>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller/F01_Preliminary_Calculations/F01_04_Speed_Calculation/rst_DelayLim'
 * '<S18>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller/F03_Control_Method_Selection/F03_01_Pure_Trapezoidal_Method'
 * '<S19>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller/F03_Control_Method_Selection/F03_02_Sinusoidal_Method'
 * '<S20>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller/F03_Control_Method_Selection/F03_03_Sinusoidal3rd_Method'
 * '<S21>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller/F03_Control_Method_Selection/signal_log1'
 * '<S22>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller/F03_Control_Method_Selection/signal_log2'
 * '<S23>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller/F03_Control_Method_Selection/signal_log6'
 */
#endif                                 /* RTW_HEADER_BLDC_controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
