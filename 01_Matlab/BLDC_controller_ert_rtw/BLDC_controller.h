/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BLDC_controller.h
 *
 * Code generated for Simulink model 'BLDC_controller'.
 *
 * Model version                  : 1.817
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue May 28 19:55:33 2019
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
#include "zero_crossing_types.h"
#ifndef BLDC_controller_COMMON_INCLUDES_
# define BLDC_controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* BLDC_controller_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */

/* Block signals and states (auto storage) for system '<S12>/F01_03_Direction_Detection' */
typedef struct {
  int8_T UnitDelay1_DSTATE;            /* '<S22>/UnitDelay1' */
} DW_F01_03_Direction_Detection;

/* Block signals and states (auto storage) for system '<S23>/Edge_counter' */
typedef struct {
  uint8_T UnitDelay1_DSTATE;           /* '<S37>/UnitDelay1' */
  boolean_T Edge_counter_MODE;         /* '<S23>/Edge_counter' */
} DW_Edge_counter;

/* Block signals and states (auto storage) for system '<S23>/Motor_Speed_Calculation' */
typedef struct {
  int32_T UnitDelay5_DSTATE;           /* '<S28>/UnitDelay5' */
  int32_T UnitDelay1_DSTATE;           /* '<S28>/UnitDelay1' */
} DW_Motor_Speed_Calculation;

/* Zero-crossing (trigger) state for system '<S23>/Motor_Speed_Calculation' */
typedef struct {
  ZCSigState Motor_Speed_Calculation_Trig_ZC;/* '<S23>/Motor_Speed_Calculation' */
} ZCE_Motor_Speed_Calculation;

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  DW_Motor_Speed_Calculation Motor_Speed_Calculation_k;/* '<S61>/Motor_Speed_Calculation' */
  DW_Edge_counter Edge_counter_l;      /* '<S61>/Edge_counter' */
  DW_F01_03_Direction_Detection F01_03_Direction_Detection_j;/* '<S50>/F01_03_Direction_Detection' */
  DW_Motor_Speed_Calculation Motor_Speed_Calculation_m;/* '<S23>/Motor_Speed_Calculation' */
  DW_Edge_counter Edge_counter_f;      /* '<S23>/Edge_counter' */
  DW_F01_03_Direction_Detection F01_03_Direction_Detection_o;/* '<S12>/F01_03_Direction_Detection' */
  int32_T Switch_PhaAdv;               /* '<S51>/Switch_PhaAdv' */
  int32_T Switch_PhaAdv_a;             /* '<S13>/Switch_PhaAdv' */
  int16_T Merge;                       /* '<S14>/Merge' */
  int16_T Merge1;                      /* '<S14>/Merge1' */
  int16_T Merge2;                      /* '<S14>/Merge2' */
  int16_T Merge_j;                     /* '<S52>/Merge' */
  int16_T Merge1_m;                    /* '<S52>/Merge1' */
  int16_T Merge2_d;                    /* '<S52>/Merge2' */
  int16_T z_counterRawPrev_DSTATE;     /* '<S23>/z_counterRawPrev' */
  int16_T z_counter2_DSTATE;           /* '<S23>/z_counter2' */
  int16_T UnitDelay1_DSTATE;           /* '<S32>/UnitDelay1' */
  int16_T z_counterRawPrev_DSTATE_p;   /* '<S61>/z_counterRawPrev' */
  int16_T z_counter2_DSTATE_h;         /* '<S61>/z_counter2' */
  int16_T UnitDelay1_DSTATE_k;         /* '<S70>/UnitDelay1' */
  int8_T UnitDelay1;                   /* '<S60>/UnitDelay1' */
  int8_T Switch2;                      /* '<S60>/Switch2' */
  int8_T UnitDelay1_k;                 /* '<S22>/UnitDelay1' */
  int8_T Switch2_e;                    /* '<S22>/Switch2' */
  int8_T If1_ActiveSubsystem;          /* '<S2>/If1' */
  int8_T If1_ActiveSubsystem_j;        /* '<S3>/If1' */
  uint8_T Sum2_i;                      /* '<S65>/Sum2' */
  uint8_T Sum2_l;                      /* '<S27>/Sum2' */
  uint8_T UnitDelay_DSTATE;            /* '<S20>/UnitDelay' */
  uint8_T UnitDelay1_DSTATE_p;         /* '<S20>/UnitDelay1' */
  uint8_T UnitDelay2_DSTATE;           /* '<S20>/UnitDelay2' */
  uint8_T UnitDelay1_DSTATE_g;         /* '<S21>/UnitDelay1' */
  uint8_T UnitDelay_DSTATE_j;          /* '<S58>/UnitDelay' */
  uint8_T UnitDelay1_DSTATE_f;         /* '<S58>/UnitDelay1' */
  uint8_T UnitDelay2_DSTATE_b;         /* '<S58>/UnitDelay2' */
  uint8_T UnitDelay1_DSTATE_j;         /* '<S59>/UnitDelay1' */
  boolean_T Logic[2];                  /* '<S29>/Logic' */
  boolean_T Logic_j[2];                /* '<S67>/Logic' */
  boolean_T LogicalOperator;           /* '<S30>/Logical Operator' */
  boolean_T LogicalOperator5;          /* '<S61>/Logical Operator5' */
  boolean_T LogicalOperator_h;         /* '<S68>/Logical Operator' */
  boolean_T UnitDelay8_DSTATE;         /* '<S23>/UnitDelay8' */
  boolean_T UnitDelay8_DSTATE_p;       /* '<S61>/UnitDelay8' */
  boolean_T UnitDelay_DSTATE_k;        /* '<S69>/UnitDelay' */
  boolean_T UnitDelay_DSTATE_i;        /* '<S68>/UnitDelay' */
  boolean_T UnitDelay_DSTATE_l;        /* '<S31>/UnitDelay' */
  boolean_T UnitDelay_DSTATE_b;        /* '<S30>/UnitDelay' */
  boolean_T Memory_PreviousInput;      /* '<S29>/Memory' */
  boolean_T Relay_Mode;                /* '<S15>/Relay' */
  boolean_T Memory_PreviousInput_i;    /* '<S67>/Memory' */
  boolean_T Relay_Mode_m;              /* '<S53>/Relay' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCE_Motor_Speed_Calculation Motor_Speed_Calculation_k;/* '<S61>/Motor_Speed_Calculation' */
  ZCE_Motor_Speed_Calculation Motor_Speed_Calculation_m;/* '<S23>/Motor_Speed_Calculation' */
} PrevZCX;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: r_trapPhaA_M1)
   * Referenced by:
   *   '<S41>/r_trapPhaA_M1'
   *   '<S79>/r_trapPhaA_M1'
   */
  int16_T pooled9[7];

  /* Pooled Parameter (Expression: r_trapPhaB_M1)
   * Referenced by:
   *   '<S41>/r_trapPhaB_M1'
   *   '<S79>/r_trapPhaB_M1'
   */
  int16_T pooled10[7];

  /* Pooled Parameter (Expression: r_trapPhaC_M1)
   * Referenced by:
   *   '<S41>/r_trapPhaC_M1'
   *   '<S79>/r_trapPhaC_M1'
   */
  int16_T pooled11[7];

  /* Pooled Parameter (Expression: r_sinPhaA_M1)
   * Referenced by:
   *   '<S43>/r_sinPhaA_M1'
   *   '<S81>/r_sinPhaA_M1'
   */
  int16_T pooled12[37];

  /* Pooled Parameter (Expression: r_sinPhaB_M1)
   * Referenced by:
   *   '<S43>/r_sinPhaB_M1'
   *   '<S81>/r_sinPhaB_M1'
   */
  int16_T pooled13[37];

  /* Pooled Parameter (Expression: r_sinPhaC_M1)
   * Referenced by:
   *   '<S43>/r_sinPhaC_M1'
   *   '<S81>/r_sinPhaC_M1'
   */
  int16_T pooled14[37];

  /* Pooled Parameter (Expression: r_sin3PhaA_M1)
   * Referenced by:
   *   '<S42>/r_sin3PhaA_M1'
   *   '<S80>/r_sin3PhaA_M1'
   */
  int16_T pooled15[37];

  /* Pooled Parameter (Expression: r_sin3PhaB_M1)
   * Referenced by:
   *   '<S42>/r_sin3PhaB_M1'
   *   '<S80>/r_sin3PhaB_M1'
   */
  int16_T pooled16[37];

  /* Pooled Parameter (Expression: r_sin3PhaC_M1)
   * Referenced by:
   *   '<S42>/r_sin3PhaC_M1'
   *   '<S80>/r_sin3PhaC_M1'
   */
  int16_T pooled17[37];

  /* Pooled Parameter (Expression: z_commutMap_M1)
   * Referenced by:
   *   '<S15>/z_commutMap_M1'
   *   '<S53>/z_commutMap_M1'
   */
  int16_T pooled18[18];

  /* Pooled Parameter (Expression: vec_hallToPos)
   * Referenced by:
   *   '<S21>/vec_hallToPos'
   *   '<S59>/vec_hallToPos'
   */
  uint8_T pooled26[8];

  /* Pooled Parameter (Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0])
   * Referenced by:
   *   '<S29>/Logic'
   *   '<S67>/Logic'
   */
  boolean_T pooled30[16];
} ConstP;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  uint8_T b_hallALeft;                 /* '<Root>/b_hallALeft ' */
  uint8_T b_hallBLeft;                 /* '<Root>/b_hallBLeft' */
  uint8_T b_hallCLeft;                 /* '<Root>/b_hallCLeft' */
  int32_T r_DCLeft;                    /* '<Root>/r_DCLeft' */
  uint8_T b_hallARight;                /* '<Root>/b_hallARight' */
  uint8_T b_hallBRight;                /* '<Root>/b_hallBRight' */
  uint8_T b_hallCRight;                /* '<Root>/b_hallCRight' */
  int32_T r_DCRight;                   /* '<Root>/r_DCRight' */
} ExtU;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  int32_T DC_phaALeft;                 /* '<Root>/DC_phaALeft' */
  int32_T DC_phaBLeft;                 /* '<Root>/DC_phaBLeft' */
  int32_T DC_phaCLeft;                 /* '<Root>/DC_phaCLeft' */
  int32_T n_motLeft;                   /* '<Root>/n_motLeft' */
  int32_T a_elecAngleLeft;             /* '<Root>/a_elecAngleLeft' */
  int32_T DC_phaARight;                /* '<Root>/DC_phaARight' */
  int32_T DC_phaBRight;                /* '<Root>/DC_phaBRight' */
  int32_T DC_phaCRight;                /* '<Root>/DC_phaCRight' */
  int32_T n_motRight;                  /* '<Root>/n_motRight' */
  int32_T a_elecAngleRight;            /* '<Root>/a_elecAngleRight' */
} ExtY;

/* Parameters (auto storage) */
struct P_ {
  int32_T cf_speedCoef;                /* Variable: cf_speedCoef
                                        * Referenced by:
                                        *   '<S28>/cf_spdCoef'
                                        *   '<S66>/cf_spdCoef'
                                        */
  int32_T n_commAcvLo;                 /* Variable: n_commAcvLo
                                        * Referenced by:
                                        *   '<S15>/Relay'
                                        *   '<S53>/Relay'
                                        */
  int32_T n_commDeacvHi;               /* Variable: n_commDeacvHi
                                        * Referenced by:
                                        *   '<S15>/Relay'
                                        *   '<S53>/Relay'
                                        */
  int32_T r_commDCDeacv;               /* Variable: r_commDCDeacv
                                        * Referenced by:
                                        *   '<S15>/r_commDCDeacv'
                                        *   '<S53>/r_commDCDeacv'
                                        */
  int32_T r_phaAdvDC_XA[11];           /* Variable: r_phaAdvDC_XA
                                        * Referenced by:
                                        *   '<S13>/r_phaAdvDC_XA'
                                        *   '<S51>/r_phaAdvDC_XA'
                                        */
  int16_T a_phaAdv_M1[11];             /* Variable: a_phaAdv_M1
                                        * Referenced by:
                                        *   '<S13>/a_phaAdv_M2'
                                        *   '<S51>/a_phaAdv_M2'
                                        */
  int16_T z_maxCntRst;                 /* Variable: z_maxCntRst
                                        * Referenced by:
                                        *   '<S23>/z_maxCntRst'
                                        *   '<S23>/z_maxCntRst1'
                                        *   '<S23>/z_maxCntRst2'
                                        *   '<S23>/z_counter2'
                                        *   '<S61>/z_maxCntRst'
                                        *   '<S61>/z_maxCntRst1'
                                        *   '<S61>/z_maxCntRst2'
                                        *   '<S61>/z_counter2'
                                        *   '<S28>/z_maxCntRst'
                                        *   '<S66>/z_maxCntRst'
                                        */
  uint8_T z_ctrlTypSel;                /* Variable: z_ctrlTypSel
                                        * Referenced by:
                                        *   '<S12>/z_ctrlTypSel1'
                                        *   '<S50>/z_ctrlTypSel1'
                                        */
  uint8_T z_nrEdgeSpdAcv;              /* Variable: z_nrEdgeSpdAcv
                                        * Referenced by:
                                        *   '<S23>/z_nrEdgeSpdAcv'
                                        *   '<S61>/z_nrEdgeSpdAcv'
                                        */
  boolean_T b_phaAdvEna;               /* Variable: b_phaAdvEna
                                        * Referenced by:
                                        *   '<S13>/a_elecPeriod1'
                                        *   '<S51>/a_elecPeriod1'
                                        */
};

/* Parameters (auto storage) */
typedef struct P_ P;

/* Block parameters (auto storage) */
extern P rtP;

/* Block signals and states (auto storage) */
extern DW rtDW;

/* External inputs (root inport signals with auto storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY rtY;

/* Constant parameters (auto storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void BLDC_controller_initialize(void);
extern void BLDC_controller_step(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S23>/Scope2' : Unused code path elimination
 * Block '<S13>/Scope' : Unused code path elimination
 * Block '<S61>/Scope2' : Unused code path elimination
 * Block '<S51>/Scope' : Unused code path elimination
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
 * '<S2>'   : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left'
 * '<S3>'   : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right'
 * '<S4>'   : 'BLDCmotorControl_R2017b/BLDC_controller/signal_log1'
 * '<S5>'   : 'BLDCmotorControl_R2017b/BLDC_controller/signal_log2'
 * '<S6>'   : 'BLDCmotorControl_R2017b/BLDC_controller/signal_log3'
 * '<S7>'   : 'BLDCmotorControl_R2017b/BLDC_controller/signal_log4'
 * '<S8>'   : 'BLDCmotorControl_R2017b/BLDC_controller/signal_log5'
 * '<S9>'   : 'BLDCmotorControl_R2017b/BLDC_controller/signal_log6'
 * '<S10>'  : 'BLDCmotorControl_R2017b/BLDC_controller/signal_log7'
 * '<S11>'  : 'BLDCmotorControl_R2017b/BLDC_controller/signal_log8'
 * '<S12>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F01_Preliminary_Calculations'
 * '<S13>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F02_Electrical_Angle_Calculation'
 * '<S14>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F03_Control_Method_Selection'
 * '<S15>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F04_Control_Type_Management'
 * '<S16>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/signal_log1'
 * '<S17>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/signal_log2'
 * '<S18>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/signal_log3'
 * '<S19>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/signal_log6'
 * '<S20>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F01_Preliminary_Calculations/F01_01_Edge_Detector'
 * '<S21>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F01_Preliminary_Calculations/F01_02_Position_Calculation'
 * '<S22>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F01_Preliminary_Calculations/F01_03_Direction_Detection'
 * '<S23>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F01_Preliminary_Calculations/F01_04_Speed_Calculation'
 * '<S24>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F01_Preliminary_Calculations/F01_01_Edge_Detector/signal_log6'
 * '<S25>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F01_Preliminary_Calculations/F01_02_Position_Calculation/signal_log6'
 * '<S26>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F01_Preliminary_Calculations/F01_03_Direction_Detection/signal_log6'
 * '<S27>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F01_Preliminary_Calculations/F01_04_Speed_Calculation/Edge_counter'
 * '<S28>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F01_Preliminary_Calculations/F01_04_Speed_Calculation/Motor_Speed_Calculation'
 * '<S29>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F01_Preliminary_Calculations/F01_04_Speed_Calculation/S-R Flip-Flop'
 * '<S30>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F01_Preliminary_Calculations/F01_04_Speed_Calculation/falling_edge2'
 * '<S31>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F01_Preliminary_Calculations/F01_04_Speed_Calculation/rising_edge'
 * '<S32>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F01_Preliminary_Calculations/F01_04_Speed_Calculation/rst_Delay'
 * '<S33>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F01_Preliminary_Calculations/F01_04_Speed_Calculation/signal_log1'
 * '<S34>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F01_Preliminary_Calculations/F01_04_Speed_Calculation/signal_log3'
 * '<S35>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F01_Preliminary_Calculations/F01_04_Speed_Calculation/signal_log4'
 * '<S36>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F01_Preliminary_Calculations/F01_04_Speed_Calculation/signal_log5'
 * '<S37>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F01_Preliminary_Calculations/F01_04_Speed_Calculation/Edge_counter/rst_Delay'
 * '<S38>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F02_Electrical_Angle_Calculation/signal_log1'
 * '<S39>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F02_Electrical_Angle_Calculation/signal_log2'
 * '<S40>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F02_Electrical_Angle_Calculation/signal_log6'
 * '<S41>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F03_Control_Method_Selection/F03_01_Pure_Trapezoidal_Method'
 * '<S42>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F03_Control_Method_Selection/F03_02_Sinusoidal3rd_Method'
 * '<S43>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F03_Control_Method_Selection/F03_02_Sinusoidal_Method'
 * '<S44>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F03_Control_Method_Selection/signal_log1'
 * '<S45>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F03_Control_Method_Selection/signal_log2'
 * '<S46>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F03_Control_Method_Selection/signal_log6'
 * '<S47>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F04_Control_Type_Management/signal_log1'
 * '<S48>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F04_Control_Type_Management/signal_log2'
 * '<S49>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Left/F04_Control_Type_Management/signal_log6'
 * '<S50>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F01_Preliminary_Calculations'
 * '<S51>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F02_Electrical_Angle_Calculation'
 * '<S52>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F03_Control_Method_Selection'
 * '<S53>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F04_Control_Type_Management'
 * '<S54>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/signal_log1'
 * '<S55>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/signal_log2'
 * '<S56>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/signal_log3'
 * '<S57>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/signal_log6'
 * '<S58>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F01_Preliminary_Calculations/F01_01_Edge_Detector'
 * '<S59>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F01_Preliminary_Calculations/F01_02_Position_Calculation'
 * '<S60>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F01_Preliminary_Calculations/F01_03_Direction_Detection'
 * '<S61>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F01_Preliminary_Calculations/F01_04_Speed_Calculation'
 * '<S62>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F01_Preliminary_Calculations/F01_01_Edge_Detector/signal_log6'
 * '<S63>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F01_Preliminary_Calculations/F01_02_Position_Calculation/signal_log6'
 * '<S64>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F01_Preliminary_Calculations/F01_03_Direction_Detection/signal_log6'
 * '<S65>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F01_Preliminary_Calculations/F01_04_Speed_Calculation/Edge_counter'
 * '<S66>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F01_Preliminary_Calculations/F01_04_Speed_Calculation/Motor_Speed_Calculation'
 * '<S67>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F01_Preliminary_Calculations/F01_04_Speed_Calculation/S-R Flip-Flop'
 * '<S68>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F01_Preliminary_Calculations/F01_04_Speed_Calculation/falling_edge2'
 * '<S69>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F01_Preliminary_Calculations/F01_04_Speed_Calculation/rising_edge'
 * '<S70>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F01_Preliminary_Calculations/F01_04_Speed_Calculation/rst_Delay'
 * '<S71>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F01_Preliminary_Calculations/F01_04_Speed_Calculation/signal_log1'
 * '<S72>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F01_Preliminary_Calculations/F01_04_Speed_Calculation/signal_log3'
 * '<S73>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F01_Preliminary_Calculations/F01_04_Speed_Calculation/signal_log4'
 * '<S74>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F01_Preliminary_Calculations/F01_04_Speed_Calculation/signal_log5'
 * '<S75>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F01_Preliminary_Calculations/F01_04_Speed_Calculation/Edge_counter/rst_Delay'
 * '<S76>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F02_Electrical_Angle_Calculation/signal_log1'
 * '<S77>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F02_Electrical_Angle_Calculation/signal_log2'
 * '<S78>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F02_Electrical_Angle_Calculation/signal_log6'
 * '<S79>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F03_Control_Method_Selection/F03_01_Pure_Trapezoidal_Method'
 * '<S80>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F03_Control_Method_Selection/F03_02_Sinusoidal3rd_Method'
 * '<S81>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F03_Control_Method_Selection/F03_02_Sinusoidal_Method'
 * '<S82>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F03_Control_Method_Selection/signal_log1'
 * '<S83>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F03_Control_Method_Selection/signal_log2'
 * '<S84>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F03_Control_Method_Selection/signal_log6'
 * '<S85>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F04_Control_Type_Management/signal_log1'
 * '<S86>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F04_Control_Type_Management/signal_log2'
 * '<S87>'  : 'BLDCmotorControl_R2017b/BLDC_controller/BLDC_controller_Right/F04_Control_Type_Management/signal_log6'
 */
#endif                                 /* RTW_HEADER_BLDC_controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
