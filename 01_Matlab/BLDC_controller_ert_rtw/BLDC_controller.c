/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BLDC_controller.c
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

#include "BLDC_controller.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if 0

/* Skip this size verification because of preprocessor limitation */
#if ( ULLONG_MAX != (0xFFFFFFFFFFFFFFFFULL) ) || ( LLONG_MAX != (0x7FFFFFFFFFFFFFFFLL) )
#error Code was generated for compiler with different sized ulong_long/long_long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif
#endif

/* Block signals and states (auto storage) */
DW rtDW;

/* Previous zero-crossings (trigger) states */
PrevZCX rtPrevZCX;

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;
static uint8_T plook_u8s32u32n31_evenc_s(int32_T u, int32_T bp0, uint32_T
  bpSpace, uint32_T maxIndex, uint32_T *fraction);
static int16_T intrp1d_s16s32s32u8u32n31l_s(uint8_T bpIndex, uint32_T frac,
  const int16_T table[]);
static int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator);
static void F01_03_Direction_Detection(boolean_T rtu_Enable, uint8_T rtu_z_pos,
  uint8_T rtu_z_posPrev, int8_T *rty_z_dir, int8_T *rty_z_dirPrev,
  DW_F01_03_Direction_Detection *localDW);
static void Edge_counter_Reset(DW_Edge_counter *localDW);
static void Edge_counter_Disable(uint8_T *rty_cnt, DW_Edge_counter *localDW);
static void Edge_counter(boolean_T rtu_Enable, boolean_T rtu_b_edge, int8_T
  rtu_z_dir, int8_T rtu_z_dirPrev, uint8_T *rty_cnt, DW_Edge_counter *localDW);
static void Motor_Speed_Calculation(boolean_T rtu_Trigger, int16_T rtu_z_counter,
  int8_T rtu_z_dir, int32_T *rty_n_mot, DW_Motor_Speed_Calculation *localDW,
  ZCE_Motor_Speed_Calculation *localZCE);
static void F03_01_Pure_Trapezoidal_Method(int32_T rtu_a_elecAngleAdv, int16_T
  *rty_r_phaA_Trap, int16_T *rty_r_phaB_Trap, int16_T *rty_r_phaC_Trap);
static void F03_02_Sinusoidal_Method(int32_T rtu_a_elecAngleAdv, int16_T
  *rty_r_phaA_Sin, int16_T *rty_r_phaB_Sin, int16_T *rty_r_phaC_Sin);
static void F03_02_Sinusoidal3rd_Method(int32_T rtu_a_elecAngleAdv, int16_T
  *rty_r_phaA_Sin3, int16_T *rty_r_phaB_Sin3, int16_T *rty_r_phaC_Sin3);
static void F02_Electrical_Angle_Ca_Disable(int32_T *rty_a_elecAngleAdv, int32_T
  *rty_a_elecAngle);
static void F02_Electrical_Angle_Calculatio(int32_T rtu_r_DC, uint8_T rtu_z_pos,
  int8_T rtu_z_dir, int16_T rtu_z_counter, int16_T rtu_z_counterRaw, int32_T
  *rty_a_elecAngleAdv, int32_T *rty_a_elecAngle);
static void falling_edge2(void);
static void rising_edge(void);
static void falling_edge2_b(void);
static void rising_edge_f(void);
static uint8_T plook_u8s32u32n31_evenc_s(int32_T u, int32_T bp0, uint32_T
  bpSpace, uint32_T maxIndex, uint32_T *fraction)
{
  uint8_T bpIndex;
  uint32_T uAdjust;
  uint32_T fbpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'even'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u <= bp0) {
    bpIndex = 0U;
    *fraction = 0U;
  } else {
    uAdjust = (uint32_T)u - bp0;
    fbpIndex = uAdjust / bpSpace;
    if (fbpIndex < maxIndex) {
      bpIndex = (uint8_T)fbpIndex;
      *fraction = (uint32_T)(((uint64_T)(uAdjust - bpIndex * bpSpace) << 31) /
        bpSpace);
    } else {
      bpIndex = (uint8_T)(maxIndex - 1U);
      *fraction = 2147483648U;
    }
  }

  return bpIndex;
}

static int16_T intrp1d_s16s32s32u8u32n31l_s(uint8_T bpIndex, uint32_T frac,
  const int16_T table[])
{
  uint32_T offset_0d;

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  offset_0d = bpIndex;
  return (int16_T)((int16_T)(((int64_T)(table[offset_0d + 1U] - table[offset_0d])
    * frac) >> 31) + table[offset_0d]);
}

static int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

/*
 * Output and update for enable system:
 *    '<S12>/F01_03_Direction_Detection'
 *    '<S50>/F01_03_Direction_Detection'
 */
static void F01_03_Direction_Detection(boolean_T rtu_Enable, uint8_T rtu_z_pos,
  uint8_T rtu_z_posPrev, int8_T *rty_z_dir, int8_T *rty_z_dirPrev,
  DW_F01_03_Direction_Detection *localDW)
{
  int8_T rtb_Sum2;

  /* Outputs for Enabled SubSystem: '<S12>/F01_03_Direction_Detection' incorporates:
   *  EnablePort: '<S22>/Enable'
   */
  if (rtu_Enable) {
    /* UnitDelay: '<S22>/UnitDelay1' */
    *rty_z_dirPrev = localDW->UnitDelay1_DSTATE;

    /* Sum: '<S22>/Sum2' incorporates:
     *  DataTypeConversion: '<S22>/Data Type Conversion1'
     *  DataTypeConversion: '<S22>/Data Type Conversion10'
     */
    rtb_Sum2 = (int8_T)((int8_T)rtu_z_pos - (int8_T)rtu_z_posPrev);

    /* Switch: '<S22>/Switch2' incorporates:
     *  Constant: '<S22>/Constant20'
     *  Constant: '<S22>/Constant23'
     *  Constant: '<S22>/Constant24'
     *  Constant: '<S22>/Constant8'
     *  Logic: '<S22>/Logical Operator3'
     *  RelationalOperator: '<S22>/Relational Operator1'
     *  RelationalOperator: '<S22>/Relational Operator6'
     */
    if ((rtb_Sum2 == 1) || (rtb_Sum2 == -5)) {
      *rty_z_dir = 1;
    } else {
      *rty_z_dir = -1;
    }

    /* End of Switch: '<S22>/Switch2' */

    /* Update for UnitDelay: '<S22>/UnitDelay1' */
    localDW->UnitDelay1_DSTATE = *rty_z_dir;
  }

  /* End of Outputs for SubSystem: '<S12>/F01_03_Direction_Detection' */
}

/*
 * System reset for enable system:
 *    '<S23>/Edge_counter'
 *    '<S61>/Edge_counter'
 */
static void Edge_counter_Reset(DW_Edge_counter *localDW)
{
  /* InitializeConditions for UnitDelay: '<S37>/UnitDelay1' */
  localDW->UnitDelay1_DSTATE = 0U;
}

/*
 * Disable for enable system:
 *    '<S23>/Edge_counter'
 *    '<S61>/Edge_counter'
 */
static void Edge_counter_Disable(uint8_T *rty_cnt, DW_Edge_counter *localDW)
{
  /* Outputs for Enabled SubSystem: '<S23>/Edge_counter' incorporates:
   *  EnablePort: '<S27>/Enable'
   */
  /* Disable for Outport: '<S27>/cnt' */
  *rty_cnt = 0U;

  /* End of Outputs for SubSystem: '<S23>/Edge_counter' */
  localDW->Edge_counter_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S23>/Edge_counter'
 *    '<S61>/Edge_counter'
 */
static void Edge_counter(boolean_T rtu_Enable, boolean_T rtu_b_edge, int8_T
  rtu_z_dir, int8_T rtu_z_dirPrev, uint8_T *rty_cnt, DW_Edge_counter *localDW)
{
  boolean_T rtb_RelationalOperator1_i;
  uint8_T rtb_RelationalOperator1_m1;

  /* Outputs for Enabled SubSystem: '<S23>/Edge_counter' incorporates:
   *  EnablePort: '<S27>/Enable'
   */
  if (rtu_Enable) {
    if (!localDW->Edge_counter_MODE) {
      Edge_counter_Reset(localDW);
      localDW->Edge_counter_MODE = true;
    }

    /* RelationalOperator: '<S27>/Relational Operator1' */
    rtb_RelationalOperator1_i = (rtu_z_dir == rtu_z_dirPrev);

    /* Switch: '<S37>/Switch1' incorporates:
     *  Constant: '<S37>/Constant23'
     *  Logic: '<S27>/Logical Operator2'
     *  UnitDelay: '<S37>/UnitDelay1'
     */
    if (!rtb_RelationalOperator1_i) {
      rtb_RelationalOperator1_m1 = 0U;
    } else {
      rtb_RelationalOperator1_m1 = localDW->UnitDelay1_DSTATE;
    }

    /* End of Switch: '<S37>/Switch1' */

    /* Sum: '<S27>/Sum2' incorporates:
     *  Logic: '<S27>/Logical Operator1'
     */
    *rty_cnt = (uint8_T)((uint32_T)(rtu_b_edge && rtb_RelationalOperator1_i) +
                         rtb_RelationalOperator1_m1);

    /* Update for UnitDelay: '<S37>/UnitDelay1' */
    localDW->UnitDelay1_DSTATE = *rty_cnt;
  } else {
    if (localDW->Edge_counter_MODE) {
      Edge_counter_Disable(rty_cnt, localDW);
    }
  }

  /* End of Outputs for SubSystem: '<S23>/Edge_counter' */
}

/*
 * Output and update for trigger system:
 *    '<S23>/Motor_Speed_Calculation'
 *    '<S61>/Motor_Speed_Calculation'
 */
static void Motor_Speed_Calculation(boolean_T rtu_Trigger, int16_T rtu_z_counter,
  int8_T rtu_z_dir, int32_T *rty_n_mot, DW_Motor_Speed_Calculation *localDW,
  ZCE_Motor_Speed_Calculation *localZCE)
{
  int32_T rtb_Sum2;

  /* Outputs for Triggered SubSystem: '<S23>/Motor_Speed_Calculation' incorporates:
   *  TriggerPort: '<S28>/Trigger'
   */
  if (rtu_Trigger && (localZCE->Motor_Speed_Calculation_Trig_ZC != POS_ZCSIG)) {
    /* Switch: '<S28>/Switch' incorporates:
     *  Constant: '<S28>/Constant1'
     *  Constant: '<S28>/cf_spdCoef'
     *  Constant: '<S28>/z_maxCntRst'
     *  Product: '<S28>/Divide4'
     *  RelationalOperator: '<S28>/Relational Operator1'
     */
    if (rtu_z_counter >= rtP.z_maxCntRst) {
      rtb_Sum2 = 0;
    } else {
      rtb_Sum2 = rtP.cf_speedCoef / rtu_z_counter;
    }

    /* End of Switch: '<S28>/Switch' */

    /* Product: '<S28>/Product2' */
    rtb_Sum2 *= rtu_z_dir;

    /* Product: '<S28>/Divide1' incorporates:
     *  Constant: '<S28>/Constant2'
     *  Sum: '<S28>/Sum2'
     *  UnitDelay: '<S28>/UnitDelay1'
     *  UnitDelay: '<S28>/UnitDelay5'
     */
    *rty_n_mot = ((localDW->UnitDelay5_DSTATE + localDW->UnitDelay1_DSTATE) +
                  rtb_Sum2) / 3;

    /* Update for UnitDelay: '<S28>/UnitDelay5' incorporates:
     *  UnitDelay: '<S28>/UnitDelay1'
     */
    localDW->UnitDelay5_DSTATE = localDW->UnitDelay1_DSTATE;

    /* Update for UnitDelay: '<S28>/UnitDelay1' */
    localDW->UnitDelay1_DSTATE = rtb_Sum2;
  }

  localZCE->Motor_Speed_Calculation_Trig_ZC = rtu_Trigger;

  /* End of Outputs for SubSystem: '<S23>/Motor_Speed_Calculation' */
}

/* Output and update for atomic system: '<S23>/falling_edge2' */
static void falling_edge2(void)
{
  /* Logic: '<S30>/Logical Operator' incorporates:
   *  Logic: '<S30>/Logical Operator1'
   *  UnitDelay: '<S30>/UnitDelay'
   */
  rtDW.LogicalOperator = ((!rtDW.Logic[0]) && rtDW.UnitDelay_DSTATE_b);

  /* Update for UnitDelay: '<S30>/UnitDelay' */
  rtDW.UnitDelay_DSTATE_b = rtDW.Logic[0];
}

/* Output and update for atomic system: '<S23>/rising_edge' */
static void rising_edge(void)
{
  /* Logic: '<S31>/Logical Operator' incorporates:
   *  Logic: '<S31>/Logical Operator1'
   *  UnitDelay: '<S31>/UnitDelay'
   */
  rtDW.LogicalOperator_h = (rtDW.LogicalOperator5 && (!rtDW.UnitDelay_DSTATE_l));

  /* Update for UnitDelay: '<S31>/UnitDelay' */
  rtDW.UnitDelay_DSTATE_l = rtDW.LogicalOperator5;
}

/*
 * Output and update for action system:
 *    '<S14>/F03_01_Pure_Trapezoidal_Method'
 *    '<S52>/F03_01_Pure_Trapezoidal_Method'
 */
static void F03_01_Pure_Trapezoidal_Method(int32_T rtu_a_elecAngleAdv, int16_T
  *rty_r_phaA_Trap, int16_T *rty_r_phaB_Trap, int16_T *rty_r_phaC_Trap)
{
  uint8_T rtb_a_trapElecAngle_XA_o1;
  uint32_T rtb_a_trapElecAngle_XA_o2;

  /* PreLookup: '<S41>/a_trapElecAngle_XA' */
  rtb_a_trapElecAngle_XA_o1 = plook_u8s32u32n31_evenc_s(rtu_a_elecAngleAdv, 0,
    60U, 6U, &rtb_a_trapElecAngle_XA_o2);

  /* Interpolation_n-D: '<S41>/r_trapPhaA_M1' */
  *rty_r_phaA_Trap = intrp1d_s16s32s32u8u32n31l_s(rtb_a_trapElecAngle_XA_o1,
    rtb_a_trapElecAngle_XA_o2, rtConstP.pooled9);

  /* Interpolation_n-D: '<S41>/r_trapPhaB_M1' */
  *rty_r_phaB_Trap = intrp1d_s16s32s32u8u32n31l_s(rtb_a_trapElecAngle_XA_o1,
    rtb_a_trapElecAngle_XA_o2, rtConstP.pooled10);

  /* Interpolation_n-D: '<S41>/r_trapPhaC_M1' */
  *rty_r_phaC_Trap = intrp1d_s16s32s32u8u32n31l_s(rtb_a_trapElecAngle_XA_o1,
    rtb_a_trapElecAngle_XA_o2, rtConstP.pooled11);
}

/*
 * Output and update for action system:
 *    '<S14>/F03_02_Sinusoidal_Method'
 *    '<S52>/F03_02_Sinusoidal_Method'
 */
static void F03_02_Sinusoidal_Method(int32_T rtu_a_elecAngleAdv, int16_T
  *rty_r_phaA_Sin, int16_T *rty_r_phaB_Sin, int16_T *rty_r_phaC_Sin)
{
  uint8_T rtb_a_sinElecAngle_XA_o1;
  uint32_T rtb_a_sinElecAngle_XA_o2;

  /* PreLookup: '<S43>/a_sinElecAngle_XA' */
  rtb_a_sinElecAngle_XA_o1 = plook_u8s32u32n31_evenc_s(rtu_a_elecAngleAdv, 0,
    10U, 36U, &rtb_a_sinElecAngle_XA_o2);

  /* Interpolation_n-D: '<S43>/r_sinPhaA_M1' */
  *rty_r_phaA_Sin = intrp1d_s16s32s32u8u32n31l_s(rtb_a_sinElecAngle_XA_o1,
    rtb_a_sinElecAngle_XA_o2, rtConstP.pooled12);

  /* Interpolation_n-D: '<S43>/r_sinPhaB_M1' */
  *rty_r_phaB_Sin = intrp1d_s16s32s32u8u32n31l_s(rtb_a_sinElecAngle_XA_o1,
    rtb_a_sinElecAngle_XA_o2, rtConstP.pooled13);

  /* Interpolation_n-D: '<S43>/r_sinPhaC_M1' */
  *rty_r_phaC_Sin = intrp1d_s16s32s32u8u32n31l_s(rtb_a_sinElecAngle_XA_o1,
    rtb_a_sinElecAngle_XA_o2, rtConstP.pooled14);
}

/*
 * Output and update for action system:
 *    '<S14>/F03_02_Sinusoidal3rd_Method'
 *    '<S52>/F03_02_Sinusoidal3rd_Method'
 */
static void F03_02_Sinusoidal3rd_Method(int32_T rtu_a_elecAngleAdv, int16_T
  *rty_r_phaA_Sin3, int16_T *rty_r_phaB_Sin3, int16_T *rty_r_phaC_Sin3)
{
  uint8_T rtb_a_sinElecAngle_XA_o1;
  uint32_T rtb_a_sinElecAngle_XA_o2;

  /* PreLookup: '<S42>/a_sinElecAngle_XA' */
  rtb_a_sinElecAngle_XA_o1 = plook_u8s32u32n31_evenc_s(rtu_a_elecAngleAdv, 0,
    10U, 36U, &rtb_a_sinElecAngle_XA_o2);

  /* Interpolation_n-D: '<S42>/r_sin3PhaA_M1' */
  *rty_r_phaA_Sin3 = intrp1d_s16s32s32u8u32n31l_s(rtb_a_sinElecAngle_XA_o1,
    rtb_a_sinElecAngle_XA_o2, rtConstP.pooled15);

  /* Interpolation_n-D: '<S42>/r_sin3PhaB_M1' */
  *rty_r_phaB_Sin3 = intrp1d_s16s32s32u8u32n31l_s(rtb_a_sinElecAngle_XA_o1,
    rtb_a_sinElecAngle_XA_o2, rtConstP.pooled16);

  /* Interpolation_n-D: '<S42>/r_sin3PhaC_M1' */
  *rty_r_phaC_Sin3 = intrp1d_s16s32s32u8u32n31l_s(rtb_a_sinElecAngle_XA_o1,
    rtb_a_sinElecAngle_XA_o2, rtConstP.pooled17);
}

/*
 * Disable for action system:
 *    '<S2>/F02_Electrical_Angle_Calculation'
 *    '<S3>/F02_Electrical_Angle_Calculation'
 */
static void F02_Electrical_Angle_Ca_Disable(int32_T *rty_a_elecAngleAdv, int32_T
  *rty_a_elecAngle)
{
  /* Disable for Outport: '<S13>/a_elecAngleAdv' */
  *rty_a_elecAngleAdv = 0;

  /* Disable for Outport: '<S13>/a_elecAngle' */
  *rty_a_elecAngle = 0;
}

/*
 * Output and update for action system:
 *    '<S2>/F02_Electrical_Angle_Calculation'
 *    '<S3>/F02_Electrical_Angle_Calculation'
 */
static void F02_Electrical_Angle_Calculatio(int32_T rtu_r_DC, uint8_T rtu_z_pos,
  int8_T rtu_z_dir, int16_T rtu_z_counter, int16_T rtu_z_counterRaw, int32_T
  *rty_a_elecAngleAdv, int32_T *rty_a_elecAngle)
{
  uint8_T rtb_Switch3;
  int16_T rtb_a_phaAdv_M2;
  uint32_T rtb_r_phaAdvDC_XA_o2;
  int32_T rtu_r_DC_0;

  /* Switch: '<S13>/Switch3' incorporates:
   *  Constant: '<S13>/Constant16'
   *  RelationalOperator: '<S13>/Relational Operator7'
   *  Sum: '<S13>/Sum1'
   */
  if (rtu_z_dir == 1) {
    rtb_Switch3 = rtu_z_pos;
  } else {
    rtb_Switch3 = (uint8_T)(rtu_z_pos + 1U);
  }

  /* End of Switch: '<S13>/Switch3' */

  /* Sum: '<S13>/Sum2' incorporates:
   *  Constant: '<S13>/a_elecAngle1'
   *  Product: '<S13>/Divide4'
   *  Product: '<S13>/Divide5'
   *  Product: '<S13>/Product6'
   */
  *rty_a_elecAngle = 60 * rtu_z_counterRaw / rtu_z_counter * rtu_z_dir +
    rtb_Switch3 * 60;

  /* Switch: '<S13>/Switch_PhaAdv' incorporates:
   *  Constant: '<S13>/a_elecPeriod1'
   *  Math: '<S13>/Math Function'
   */
  if (rtP.b_phaAdvEna) {
    /* Abs: '<S13>/Abs2' */
    if (rtu_r_DC < 0) {
      rtu_r_DC_0 = -rtu_r_DC;
    } else {
      rtu_r_DC_0 = rtu_r_DC;
    }

    /* End of Abs: '<S13>/Abs2' */

    /* PreLookup: '<S13>/r_phaAdvDC_XA' */
    rtb_Switch3 = plook_u8s32u32n31_evenc_s(rtu_r_DC_0, rtP.r_phaAdvDC_XA[0],
      (uint32_T)rtP.r_phaAdvDC_XA[1] - rtP.r_phaAdvDC_XA[0], 10U,
      &rtb_r_phaAdvDC_XA_o2);

    /* Interpolation_n-D: '<S13>/a_phaAdv_M2' */
    rtb_a_phaAdv_M2 = intrp1d_s16s32s32u8u32n31l_s(rtb_Switch3,
      rtb_r_phaAdvDC_XA_o2, rtP.a_phaAdv_M1);

    /* Sum: '<S13>/Sum3' incorporates:
     *  Product: '<S13>/Product2'
     */
    rtu_r_DC_0 = rtu_z_dir * rtb_a_phaAdv_M2 + *rty_a_elecAngle;
    *rty_a_elecAngleAdv = rtu_r_DC_0 - div_nde_s32_floor(rtu_r_DC_0, 360) * 360;
  } else {
    *rty_a_elecAngleAdv = *rty_a_elecAngle;
  }

  /* End of Switch: '<S13>/Switch_PhaAdv' */
}

/* Output and update for atomic system: '<S61>/falling_edge2' */
static void falling_edge2_b(void)
{
  /* Logic: '<S68>/Logical Operator' incorporates:
   *  Logic: '<S68>/Logical Operator1'
   *  UnitDelay: '<S68>/UnitDelay'
   */
  rtDW.LogicalOperator_h = ((!rtDW.Logic_j[0]) && rtDW.UnitDelay_DSTATE_i);

  /* Update for UnitDelay: '<S68>/UnitDelay' */
  rtDW.UnitDelay_DSTATE_i = rtDW.Logic_j[0];
}

/* Output and update for atomic system: '<S61>/rising_edge' */
static void rising_edge_f(void)
{
  /* Logic: '<S69>/Logical Operator' incorporates:
   *  Logic: '<S69>/Logical Operator1'
   *  UnitDelay: '<S69>/UnitDelay'
   */
  rtDW.LogicalOperator_h = (rtDW.LogicalOperator5 && (!rtDW.UnitDelay_DSTATE_k));

  /* Update for UnitDelay: '<S69>/UnitDelay' */
  rtDW.UnitDelay_DSTATE_k = rtDW.LogicalOperator5;
}

/* Model step function */
void BLDC_controller_step(void)
{
  uint8_T rtb_Sum;
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_LogicalOperator3;
  int32_T rtb_Abs1;
  int8_T rtPrevAction;
  int8_T rtAction;
  uint8_T rtb_Sum_a;
  int16_T rtb_Switch;
  int16_T rtb_Switch_b;
  int16_T rtb_Sum1;
  int16_T rtb_Sum1_c;
  int32_T rtb_Switch1_idx_0;
  int32_T rtb_Switch1_idx_1;
  uint8_T tmp;

  /* Outputs for Atomic SubSystem: '<Root>/BLDC_controller' */
  /* Sum: '<S21>/Sum' incorporates:
   *  Gain: '<S21>/g_Ha'
   *  Gain: '<S21>/g_Hb'
   *  Inport: '<Root>/b_hallALeft '
   *  Inport: '<Root>/b_hallBLeft'
   *  Inport: '<Root>/b_hallCLeft'
   */
  rtb_Sum = (uint8_T)((uint32_T)(uint8_T)((uint32_T)(uint8_T)(rtU.b_hallALeft <<
    2) + (uint8_T)(rtU.b_hallBLeft << 1)) + rtU.b_hallCLeft);

  /* Logic: '<S20>/Logical Operator' incorporates:
   *  Inport: '<Root>/b_hallALeft '
   *  Inport: '<Root>/b_hallBLeft'
   *  Inport: '<Root>/b_hallCLeft'
   *  UnitDelay: '<S20>/UnitDelay'
   *  UnitDelay: '<S20>/UnitDelay1'
   *  UnitDelay: '<S20>/UnitDelay2'
   */
  rtb_LogicalOperator = (boolean_T)((rtU.b_hallALeft != 0) ^ (rtU.b_hallBLeft !=
    0) ^ (rtU.b_hallCLeft != 0) ^ (rtDW.UnitDelay_DSTATE != 0) ^
    (rtDW.UnitDelay1_DSTATE_p != 0)) ^ (rtDW.UnitDelay2_DSTATE != 0);

  /* Outputs for Enabled SubSystem: '<S12>/F01_03_Direction_Detection' */

  /* Selector: '<S21>/Selector' incorporates:
   *  Constant: '<S21>/vec_hallToPos'
   *  UnitDelay: '<S21>/UnitDelay1'
   */
  F01_03_Direction_Detection(rtb_LogicalOperator, rtConstP.pooled26[rtb_Sum],
    rtDW.UnitDelay1_DSTATE_g, &rtDW.Switch2_e, &rtDW.UnitDelay1_k,
    &rtDW.F01_03_Direction_Detection_o);

  /* End of Outputs for SubSystem: '<S12>/F01_03_Direction_Detection' */

  /* Logic: '<S23>/Logical Operator3' incorporates:
   *  Constant: '<S23>/z_maxCntRst'
   *  RelationalOperator: '<S23>/Relational Operator1'
   *  UnitDelay: '<S23>/z_counterRawPrev'
   */
  rtb_LogicalOperator3 = (rtb_LogicalOperator || (rtDW.z_counterRawPrev_DSTATE >
    rtP.z_maxCntRst));

  /* Outputs for Enabled SubSystem: '<S23>/Edge_counter' */

  /* Logic: '<S23>/Logical Operator2' incorporates:
   *  UnitDelay: '<S23>/UnitDelay8'
   */
  Edge_counter(!rtDW.UnitDelay8_DSTATE, rtb_LogicalOperator, rtDW.Switch2_e,
               rtDW.UnitDelay1_k, &rtDW.Sum2_l, &rtDW.Edge_counter_f);

  /* End of Outputs for SubSystem: '<S23>/Edge_counter' */

  /* Logic: '<S23>/Logical Operator5' incorporates:
   *  Constant: '<S23>/z_maxCntRst2'
   *  RelationalOperator: '<S23>/Relational Operator3'
   *  RelationalOperator: '<S23>/Relational Operator6'
   *  UnitDelay: '<S23>/z_counterRawPrev'
   */
  rtDW.LogicalOperator5 = ((rtDW.Switch2_e != rtDW.UnitDelay1_k) ||
    (rtDW.z_counterRawPrev_DSTATE > rtP.z_maxCntRst));

  /* Outputs for Atomic SubSystem: '<S23>/rising_edge' */
  rising_edge();

  /* End of Outputs for SubSystem: '<S23>/rising_edge' */

  /* CombinatorialLogic: '<S29>/Logic' incorporates:
   *  Constant: '<S23>/z_nrEdgeSpdAcv'
   *  Memory: '<S29>/Memory'
   *  RelationalOperator: '<S23>/Relational Operator5'
   */
  rtb_Switch1_idx_0 = (int32_T)(((((uint32_T)(rtDW.Sum2_l >= rtP.z_nrEdgeSpdAcv)
    << 1) + rtDW.LogicalOperator_h) << 1) + rtDW.Memory_PreviousInput);
  rtDW.Logic[0U] = rtConstP.pooled30[(uint32_T)rtb_Switch1_idx_0];
  rtDW.Logic[1U] = rtConstP.pooled30[rtb_Switch1_idx_0 + 8U];

  /* Outputs for Atomic SubSystem: '<S23>/falling_edge2' */
  falling_edge2();

  /* End of Outputs for SubSystem: '<S23>/falling_edge2' */

  /* Switch: '<S23>/Switch' incorporates:
   *  Logic: '<S23>/Logical Operator1'
   *  Switch: '<S23>/Switch1'
   *  UnitDelay: '<S23>/z_counter2'
   *  UnitDelay: '<S23>/z_counterRawPrev'
   */
  if (rtb_LogicalOperator3 && rtDW.Logic[0]) {
    rtb_Switch = rtDW.z_counterRawPrev_DSTATE;
  } else if (rtDW.LogicalOperator) {
    /* Switch: '<S23>/Switch1' incorporates:
     *  Constant: '<S23>/z_maxCntRst1'
     */
    rtb_Switch = rtP.z_maxCntRst;
  } else {
    rtb_Switch = rtDW.z_counter2_DSTATE;
  }

  /* End of Switch: '<S23>/Switch' */

  /* Outputs for Triggered SubSystem: '<S23>/Motor_Speed_Calculation' */

  /* Outport: '<Root>/n_motLeft' */
  Motor_Speed_Calculation(rtb_LogicalOperator3, rtb_Switch, rtDW.Switch2_e,
    &rtY.n_motLeft, &rtDW.Motor_Speed_Calculation_m,
    &rtPrevZCX.Motor_Speed_Calculation_m);

  /* End of Outputs for SubSystem: '<S23>/Motor_Speed_Calculation' */

  /* Abs: '<S15>/Abs5' incorporates:
   *  Outport: '<Root>/n_motLeft'
   */
  if (rtY.n_motLeft < 0) {
    rtb_Abs1 = -rtY.n_motLeft;
  } else {
    rtb_Abs1 = rtY.n_motLeft;
  }

  /* End of Abs: '<S15>/Abs5' */

  /* Relay: '<S15>/Relay' */
  if (rtb_Abs1 >= rtP.n_commDeacvHi) {
    rtDW.Relay_Mode = true;
  } else {
    if (rtb_Abs1 <= rtP.n_commAcvLo) {
      rtDW.Relay_Mode = false;
    }
  }

  /* Switch: '<S32>/Switch1' incorporates:
   *  Constant: '<S32>/Constant23'
   *  UnitDelay: '<S32>/UnitDelay1'
   */
  if (rtb_LogicalOperator3) {
    rtb_Sum1_c = 0;
  } else {
    rtb_Sum1_c = rtDW.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S32>/Switch1' */

  /* Sum: '<S23>/Sum1' */
  rtb_Sum1 = (int16_T)(1 + rtb_Sum1_c);

  /* If: '<S2>/If1' incorporates:
   *  Constant: '<S12>/z_ctrlTypSel1'
   *  Constant: '<S21>/vec_hallToPos'
   *  Inport: '<Root>/r_DCLeft'
   *  Outport: '<Root>/a_elecAngleLeft'
   *  Selector: '<S21>/Selector'
   */
  rtPrevAction = rtDW.If1_ActiveSubsystem;
  rtAction = -1;
  if (rtP.z_ctrlTypSel != 0) {
    rtAction = 0;
  }

  rtDW.If1_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    F02_Electrical_Angle_Ca_Disable(&rtDW.Switch_PhaAdv_a, &rtY.a_elecAngleLeft);
  }

  if (rtAction == 0) {
    /* Outputs for IfAction SubSystem: '<S2>/F02_Electrical_Angle_Calculation' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    F02_Electrical_Angle_Calculatio(rtU.r_DCLeft, rtConstP.pooled26[rtb_Sum],
      rtDW.Switch2_e, rtb_Switch, rtb_Sum1, &rtDW.Switch_PhaAdv_a,
      &rtY.a_elecAngleLeft);

    /* End of Outputs for SubSystem: '<S2>/F02_Electrical_Angle_Calculation' */
  }

  /* End of If: '<S2>/If1' */

  /* SwitchCase: '<S14>/Switch Case' incorporates:
   *  Constant: '<S12>/z_ctrlTypSel1'
   */
  switch (rtP.z_ctrlTypSel) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S14>/F03_01_Pure_Trapezoidal_Method' incorporates:
     *  ActionPort: '<S41>/Action Port'
     */
    F03_01_Pure_Trapezoidal_Method(rtDW.Switch_PhaAdv_a, &rtDW.Merge,
      &rtDW.Merge1, &rtDW.Merge2);

    /* End of Outputs for SubSystem: '<S14>/F03_01_Pure_Trapezoidal_Method' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S14>/F03_02_Sinusoidal_Method' incorporates:
     *  ActionPort: '<S43>/Action Port'
     */
    F03_02_Sinusoidal_Method(rtDW.Switch_PhaAdv_a, &rtDW.Merge, &rtDW.Merge1,
      &rtDW.Merge2);

    /* End of Outputs for SubSystem: '<S14>/F03_02_Sinusoidal_Method' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S14>/F03_02_Sinusoidal3rd_Method' incorporates:
     *  ActionPort: '<S42>/Action Port'
     */
    F03_02_Sinusoidal3rd_Method(rtDW.Switch_PhaAdv_a, &rtDW.Merge, &rtDW.Merge1,
      &rtDW.Merge2);

    /* End of Outputs for SubSystem: '<S14>/F03_02_Sinusoidal3rd_Method' */
    break;
  }

  /* End of SwitchCase: '<S14>/Switch Case' */

  /* Abs: '<S15>/Abs1' incorporates:
   *  Inport: '<Root>/r_DCLeft'
   */
  if (rtU.r_DCLeft < 0) {
    rtb_Switch1_idx_0 = -rtU.r_DCLeft;
  } else {
    rtb_Switch1_idx_0 = rtU.r_DCLeft;
  }

  /* End of Abs: '<S15>/Abs1' */

  /* Switch: '<S15>/Switch1' incorporates:
   *  Constant: '<S12>/z_ctrlTypSel1'
   *  Constant: '<S15>/CTRL_COMM'
   *  Constant: '<S15>/r_commDCDeacv'
   *  Constant: '<S21>/vec_hallToPos'
   *  Inport: '<Root>/r_DCLeft'
   *  Logic: '<S15>/Logical Operator3'
   *  LookupNDDirect: '<S15>/z_commutMap_M1'
   *  Product: '<S15>/Divide2'
   *  Product: '<S15>/Divide4'
   *  RelationalOperator: '<S15>/Relational Operator1'
   *  RelationalOperator: '<S15>/Relational Operator2'
   *  Relay: '<S15>/Relay'
   *  Selector: '<S21>/Selector'
   *
   * About '<S15>/z_commutMap_M1':
   *  2-dimensional Direct Look-Up returning a Column
   */
  if (rtDW.Relay_Mode && (rtb_Switch1_idx_0 > rtP.r_commDCDeacv) &&
      (rtP.z_ctrlTypSel != 0)) {
    rtb_Switch1_idx_0 = rtU.r_DCLeft * rtDW.Merge;
    rtb_Switch1_idx_1 = rtU.r_DCLeft * rtDW.Merge1;
    rtb_Abs1 = rtU.r_DCLeft * rtDW.Merge2;
  } else {
    if (rtConstP.pooled26[rtb_Sum] < 5) {
      /* LookupNDDirect: '<S15>/z_commutMap_M1' incorporates:
       *  Constant: '<S21>/vec_hallToPos'
       *  Selector: '<S21>/Selector'
       *
       * About '<S15>/z_commutMap_M1':
       *  2-dimensional Direct Look-Up returning a Column
       */
      tmp = rtConstP.pooled26[rtb_Sum];
    } else {
      /* LookupNDDirect: '<S15>/z_commutMap_M1'
       *
       * About '<S15>/z_commutMap_M1':
       *  2-dimensional Direct Look-Up returning a Column
       */
      tmp = 5U;
    }

    /* LookupNDDirect: '<S15>/z_commutMap_M1'
     *
     * About '<S15>/z_commutMap_M1':
     *  2-dimensional Direct Look-Up returning a Column
     */
    rtb_Abs1 = tmp * 3;
    rtb_Switch1_idx_0 = rtU.r_DCLeft * rtConstP.pooled18[rtb_Abs1];
    rtb_Switch1_idx_1 = rtConstP.pooled18[1 + rtb_Abs1] * rtU.r_DCLeft;
    rtb_Abs1 = rtConstP.pooled18[2 + rtb_Abs1] * rtU.r_DCLeft;
  }

  /* End of Switch: '<S15>/Switch1' */

  /* Outport: '<Root>/DC_phaALeft' incorporates:
   *  Constant: '<S15>/Constant1'
   *  Product: '<S15>/Divide1'
   */
  rtY.DC_phaALeft = rtb_Switch1_idx_0 / 1000;

  /* Outport: '<Root>/DC_phaBLeft' incorporates:
   *  Constant: '<S15>/Constant1'
   *  Product: '<S15>/Divide1'
   */
  rtY.DC_phaBLeft = rtb_Switch1_idx_1 / 1000;

  /* Outport: '<Root>/DC_phaCLeft' incorporates:
   *  Constant: '<S15>/Constant1'
   *  Product: '<S15>/Divide1'
   */
  rtY.DC_phaCLeft = rtb_Abs1 / 1000;

  /* Sum: '<S59>/Sum' incorporates:
   *  Gain: '<S59>/g_Ha'
   *  Gain: '<S59>/g_Hb'
   *  Inport: '<Root>/b_hallARight'
   *  Inport: '<Root>/b_hallBRight'
   *  Inport: '<Root>/b_hallCRight'
   */
  rtb_Sum_a = (uint8_T)((uint32_T)(uint8_T)((uint32_T)(uint8_T)(rtU.b_hallARight
    << 2) + (uint8_T)(rtU.b_hallBRight << 1)) + rtU.b_hallCRight);

  /* Logic: '<S58>/Logical Operator' incorporates:
   *  Inport: '<Root>/b_hallARight'
   *  Inport: '<Root>/b_hallBRight'
   *  Inport: '<Root>/b_hallCRight'
   *  UnitDelay: '<S58>/UnitDelay'
   *  UnitDelay: '<S58>/UnitDelay1'
   *  UnitDelay: '<S58>/UnitDelay2'
   */
  rtb_LogicalOperator = (boolean_T)((rtU.b_hallARight != 0) ^ (rtU.b_hallBRight
    != 0) ^ (rtU.b_hallCRight != 0) ^ (rtDW.UnitDelay_DSTATE_j != 0) ^
    (rtDW.UnitDelay1_DSTATE_f != 0)) ^ (rtDW.UnitDelay2_DSTATE_b != 0);

  /* Outputs for Enabled SubSystem: '<S50>/F01_03_Direction_Detection' */

  /* Selector: '<S59>/Selector' incorporates:
   *  Constant: '<S59>/vec_hallToPos'
   *  UnitDelay: '<S59>/UnitDelay1'
   */
  F01_03_Direction_Detection(rtb_LogicalOperator, rtConstP.pooled26[rtb_Sum_a],
    rtDW.UnitDelay1_DSTATE_j, &rtDW.Switch2, &rtDW.UnitDelay1,
    &rtDW.F01_03_Direction_Detection_j);

  /* End of Outputs for SubSystem: '<S50>/F01_03_Direction_Detection' */

  /* Logic: '<S61>/Logical Operator3' incorporates:
   *  Constant: '<S61>/z_maxCntRst'
   *  RelationalOperator: '<S61>/Relational Operator1'
   *  UnitDelay: '<S61>/z_counterRawPrev'
   */
  rtb_LogicalOperator3 = (rtb_LogicalOperator || (rtDW.z_counterRawPrev_DSTATE_p
    > rtP.z_maxCntRst));

  /* Outputs for Enabled SubSystem: '<S61>/Edge_counter' */

  /* Logic: '<S61>/Logical Operator2' incorporates:
   *  UnitDelay: '<S61>/UnitDelay8'
   */
  Edge_counter(!rtDW.UnitDelay8_DSTATE_p, rtb_LogicalOperator, rtDW.Switch2,
               rtDW.UnitDelay1, &rtDW.Sum2_i, &rtDW.Edge_counter_l);

  /* End of Outputs for SubSystem: '<S61>/Edge_counter' */

  /* Logic: '<S61>/Logical Operator5' incorporates:
   *  Constant: '<S61>/z_maxCntRst2'
   *  RelationalOperator: '<S61>/Relational Operator3'
   *  RelationalOperator: '<S61>/Relational Operator6'
   *  UnitDelay: '<S61>/z_counterRawPrev'
   */
  rtDW.LogicalOperator5 = ((rtDW.Switch2 != rtDW.UnitDelay1) ||
    (rtDW.z_counterRawPrev_DSTATE_p > rtP.z_maxCntRst));

  /* Outputs for Atomic SubSystem: '<S61>/rising_edge' */
  rising_edge_f();

  /* End of Outputs for SubSystem: '<S61>/rising_edge' */

  /* CombinatorialLogic: '<S67>/Logic' incorporates:
   *  Constant: '<S61>/z_nrEdgeSpdAcv'
   *  Memory: '<S67>/Memory'
   *  RelationalOperator: '<S61>/Relational Operator5'
   */
  rtb_Switch1_idx_0 = (int32_T)(((((uint32_T)(rtDW.Sum2_i >= rtP.z_nrEdgeSpdAcv)
    << 1) + rtDW.LogicalOperator_h) << 1) + rtDW.Memory_PreviousInput_i);
  rtDW.Logic_j[0U] = rtConstP.pooled30[(uint32_T)rtb_Switch1_idx_0];
  rtDW.Logic_j[1U] = rtConstP.pooled30[rtb_Switch1_idx_0 + 8U];

  /* Outputs for Atomic SubSystem: '<S61>/falling_edge2' */
  falling_edge2_b();

  /* End of Outputs for SubSystem: '<S61>/falling_edge2' */

  /* Switch: '<S61>/Switch' incorporates:
   *  Logic: '<S61>/Logical Operator1'
   *  Switch: '<S61>/Switch1'
   *  UnitDelay: '<S61>/z_counter2'
   *  UnitDelay: '<S61>/z_counterRawPrev'
   */
  if (rtb_LogicalOperator3 && rtDW.Logic_j[0]) {
    rtb_Switch_b = rtDW.z_counterRawPrev_DSTATE_p;
  } else if (rtDW.LogicalOperator_h) {
    /* Switch: '<S61>/Switch1' incorporates:
     *  Constant: '<S61>/z_maxCntRst1'
     */
    rtb_Switch_b = rtP.z_maxCntRst;
  } else {
    rtb_Switch_b = rtDW.z_counter2_DSTATE_h;
  }

  /* End of Switch: '<S61>/Switch' */

  /* Outputs for Triggered SubSystem: '<S61>/Motor_Speed_Calculation' */

  /* Outport: '<Root>/n_motRight' */
  Motor_Speed_Calculation(rtb_LogicalOperator3, rtb_Switch_b, rtDW.Switch2,
    &rtY.n_motRight, &rtDW.Motor_Speed_Calculation_k,
    &rtPrevZCX.Motor_Speed_Calculation_k);

  /* End of Outputs for SubSystem: '<S61>/Motor_Speed_Calculation' */

  /* Abs: '<S53>/Abs5' incorporates:
   *  Outport: '<Root>/n_motRight'
   */
  if (rtY.n_motRight < 0) {
    rtb_Abs1 = -rtY.n_motRight;
  } else {
    rtb_Abs1 = rtY.n_motRight;
  }

  /* End of Abs: '<S53>/Abs5' */

  /* Relay: '<S53>/Relay' */
  if (rtb_Abs1 >= rtP.n_commDeacvHi) {
    rtDW.Relay_Mode_m = true;
  } else {
    if (rtb_Abs1 <= rtP.n_commAcvLo) {
      rtDW.Relay_Mode_m = false;
    }
  }

  /* Switch: '<S70>/Switch1' incorporates:
   *  Constant: '<S70>/Constant23'
   *  UnitDelay: '<S70>/UnitDelay1'
   */
  if (rtb_LogicalOperator3) {
    rtb_Sum1_c = 0;
  } else {
    rtb_Sum1_c = rtDW.UnitDelay1_DSTATE_k;
  }

  /* End of Switch: '<S70>/Switch1' */

  /* Sum: '<S61>/Sum1' */
  rtb_Sum1_c++;

  /* If: '<S3>/If1' incorporates:
   *  Constant: '<S50>/z_ctrlTypSel1'
   *  Constant: '<S59>/vec_hallToPos'
   *  Inport: '<Root>/r_DCRight'
   *  Outport: '<Root>/a_elecAngleRight'
   *  Selector: '<S59>/Selector'
   */
  rtPrevAction = rtDW.If1_ActiveSubsystem_j;
  rtAction = -1;
  if (rtP.z_ctrlTypSel != 0) {
    rtAction = 0;
  }

  rtDW.If1_ActiveSubsystem_j = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    F02_Electrical_Angle_Ca_Disable(&rtDW.Switch_PhaAdv, &rtY.a_elecAngleRight);
  }

  if (rtAction == 0) {
    /* Outputs for IfAction SubSystem: '<S3>/F02_Electrical_Angle_Calculation' incorporates:
     *  ActionPort: '<S51>/Action Port'
     */
    F02_Electrical_Angle_Calculatio(rtU.r_DCRight, rtConstP.pooled26[rtb_Sum_a],
      rtDW.Switch2, rtb_Switch_b, rtb_Sum1_c, &rtDW.Switch_PhaAdv,
      &rtY.a_elecAngleRight);

    /* End of Outputs for SubSystem: '<S3>/F02_Electrical_Angle_Calculation' */
  }

  /* End of If: '<S3>/If1' */

  /* SwitchCase: '<S52>/Switch Case' incorporates:
   *  Constant: '<S50>/z_ctrlTypSel1'
   */
  switch (rtP.z_ctrlTypSel) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S52>/F03_01_Pure_Trapezoidal_Method' incorporates:
     *  ActionPort: '<S79>/Action Port'
     */
    F03_01_Pure_Trapezoidal_Method(rtDW.Switch_PhaAdv, &rtDW.Merge_j,
      &rtDW.Merge1_m, &rtDW.Merge2_d);

    /* End of Outputs for SubSystem: '<S52>/F03_01_Pure_Trapezoidal_Method' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S52>/F03_02_Sinusoidal_Method' incorporates:
     *  ActionPort: '<S81>/Action Port'
     */
    F03_02_Sinusoidal_Method(rtDW.Switch_PhaAdv, &rtDW.Merge_j, &rtDW.Merge1_m,
      &rtDW.Merge2_d);

    /* End of Outputs for SubSystem: '<S52>/F03_02_Sinusoidal_Method' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S52>/F03_02_Sinusoidal3rd_Method' incorporates:
     *  ActionPort: '<S80>/Action Port'
     */
    F03_02_Sinusoidal3rd_Method(rtDW.Switch_PhaAdv, &rtDW.Merge_j,
      &rtDW.Merge1_m, &rtDW.Merge2_d);

    /* End of Outputs for SubSystem: '<S52>/F03_02_Sinusoidal3rd_Method' */
    break;
  }

  /* End of SwitchCase: '<S52>/Switch Case' */

  /* Abs: '<S53>/Abs1' incorporates:
   *  Inport: '<Root>/r_DCRight'
   */
  if (rtU.r_DCRight < 0) {
    rtb_Switch1_idx_0 = -rtU.r_DCRight;
  } else {
    rtb_Switch1_idx_0 = rtU.r_DCRight;
  }

  /* End of Abs: '<S53>/Abs1' */

  /* Switch: '<S53>/Switch1' incorporates:
   *  Constant: '<S50>/z_ctrlTypSel1'
   *  Constant: '<S53>/CTRL_COMM'
   *  Constant: '<S53>/r_commDCDeacv'
   *  Constant: '<S59>/vec_hallToPos'
   *  Inport: '<Root>/r_DCRight'
   *  Logic: '<S53>/Logical Operator3'
   *  LookupNDDirect: '<S53>/z_commutMap_M1'
   *  Product: '<S53>/Divide2'
   *  Product: '<S53>/Divide4'
   *  RelationalOperator: '<S53>/Relational Operator1'
   *  RelationalOperator: '<S53>/Relational Operator2'
   *  Relay: '<S53>/Relay'
   *  Selector: '<S59>/Selector'
   *
   * About '<S53>/z_commutMap_M1':
   *  2-dimensional Direct Look-Up returning a Column
   */
  if (rtDW.Relay_Mode_m && (rtb_Switch1_idx_0 > rtP.r_commDCDeacv) &&
      (rtP.z_ctrlTypSel != 0)) {
    rtb_Switch1_idx_0 = rtU.r_DCRight * rtDW.Merge_j;
    rtb_Switch1_idx_1 = rtU.r_DCRight * rtDW.Merge1_m;
    rtb_Abs1 = rtU.r_DCRight * rtDW.Merge2_d;
  } else {
    if (rtConstP.pooled26[rtb_Sum_a] < 5) {
      /* LookupNDDirect: '<S53>/z_commutMap_M1' incorporates:
       *  Constant: '<S59>/vec_hallToPos'
       *  Selector: '<S59>/Selector'
       *
       * About '<S53>/z_commutMap_M1':
       *  2-dimensional Direct Look-Up returning a Column
       */
      tmp = rtConstP.pooled26[rtb_Sum_a];
    } else {
      /* LookupNDDirect: '<S53>/z_commutMap_M1'
       *
       * About '<S53>/z_commutMap_M1':
       *  2-dimensional Direct Look-Up returning a Column
       */
      tmp = 5U;
    }

    /* LookupNDDirect: '<S53>/z_commutMap_M1'
     *
     * About '<S53>/z_commutMap_M1':
     *  2-dimensional Direct Look-Up returning a Column
     */
    rtb_Abs1 = tmp * 3;
    rtb_Switch1_idx_0 = rtU.r_DCRight * rtConstP.pooled18[rtb_Abs1];
    rtb_Switch1_idx_1 = rtConstP.pooled18[1 + rtb_Abs1] * rtU.r_DCRight;
    rtb_Abs1 = rtConstP.pooled18[2 + rtb_Abs1] * rtU.r_DCRight;
  }

  /* End of Switch: '<S53>/Switch1' */

  /* Outport: '<Root>/DC_phaARight' incorporates:
   *  Constant: '<S53>/Constant1'
   *  Product: '<S53>/Divide1'
   */
  rtY.DC_phaARight = rtb_Switch1_idx_0 / 1000;

  /* Outport: '<Root>/DC_phaBRight' incorporates:
   *  Constant: '<S53>/Constant1'
   *  Product: '<S53>/Divide1'
   */
  rtY.DC_phaBRight = rtb_Switch1_idx_1 / 1000;

  /* Update for UnitDelay: '<S20>/UnitDelay' incorporates:
   *  Inport: '<Root>/b_hallALeft '
   */
  rtDW.UnitDelay_DSTATE = rtU.b_hallALeft;

  /* Update for UnitDelay: '<S20>/UnitDelay1' incorporates:
   *  Inport: '<Root>/b_hallBLeft'
   */
  rtDW.UnitDelay1_DSTATE_p = rtU.b_hallBLeft;

  /* Update for UnitDelay: '<S20>/UnitDelay2' incorporates:
   *  Inport: '<Root>/b_hallCLeft'
   */
  rtDW.UnitDelay2_DSTATE = rtU.b_hallCLeft;

  /* Update for UnitDelay: '<S21>/UnitDelay1' incorporates:
   *  Constant: '<S21>/vec_hallToPos'
   *  Selector: '<S21>/Selector'
   */
  rtDW.UnitDelay1_DSTATE_g = rtConstP.pooled26[rtb_Sum];

  /* Update for UnitDelay: '<S23>/z_counterRawPrev' */
  rtDW.z_counterRawPrev_DSTATE = rtb_Sum1;

  /* Update for UnitDelay: '<S23>/UnitDelay8' */
  rtDW.UnitDelay8_DSTATE = rtDW.Logic[0];

  /* Update for Memory: '<S29>/Memory' */
  rtDW.Memory_PreviousInput = rtDW.Logic[0];

  /* Update for UnitDelay: '<S23>/z_counter2' */
  rtDW.z_counter2_DSTATE = rtb_Switch;

  /* Update for UnitDelay: '<S32>/UnitDelay1' */
  rtDW.UnitDelay1_DSTATE = rtb_Sum1;

  /* Update for UnitDelay: '<S58>/UnitDelay' incorporates:
   *  Inport: '<Root>/b_hallARight'
   */
  rtDW.UnitDelay_DSTATE_j = rtU.b_hallARight;

  /* Update for UnitDelay: '<S58>/UnitDelay1' incorporates:
   *  Inport: '<Root>/b_hallBRight'
   */
  rtDW.UnitDelay1_DSTATE_f = rtU.b_hallBRight;

  /* Update for UnitDelay: '<S58>/UnitDelay2' incorporates:
   *  Inport: '<Root>/b_hallCRight'
   */
  rtDW.UnitDelay2_DSTATE_b = rtU.b_hallCRight;

  /* Update for UnitDelay: '<S59>/UnitDelay1' incorporates:
   *  Constant: '<S59>/vec_hallToPos'
   *  Selector: '<S59>/Selector'
   */
  rtDW.UnitDelay1_DSTATE_j = rtConstP.pooled26[rtb_Sum_a];

  /* Update for UnitDelay: '<S61>/z_counterRawPrev' */
  rtDW.z_counterRawPrev_DSTATE_p = rtb_Sum1_c;

  /* Update for UnitDelay: '<S61>/UnitDelay8' */
  rtDW.UnitDelay8_DSTATE_p = rtDW.Logic_j[0];

  /* Update for Memory: '<S67>/Memory' */
  rtDW.Memory_PreviousInput_i = rtDW.Logic_j[0];

  /* Update for UnitDelay: '<S61>/z_counter2' */
  rtDW.z_counter2_DSTATE_h = rtb_Switch_b;

  /* Update for UnitDelay: '<S70>/UnitDelay1' */
  rtDW.UnitDelay1_DSTATE_k = rtb_Sum1_c;

  /* Outport: '<Root>/DC_phaCRight' incorporates:
   *  Constant: '<S53>/Constant1'
   *  Product: '<S53>/Divide1'
   */
  rtY.DC_phaCRight = rtb_Abs1 / 1000;

  /* End of Outputs for SubSystem: '<Root>/BLDC_controller' */
}

/* Model initialize function */
void BLDC_controller_initialize(void)
{
  /* Start for Atomic SubSystem: '<Root>/BLDC_controller' */
  /* Start for If: '<S2>/If1' */
  rtDW.If1_ActiveSubsystem = -1;

  /* Start for If: '<S3>/If1' */
  rtDW.If1_ActiveSubsystem_j = -1;

  /* End of Start for SubSystem: '<Root>/BLDC_controller' */
  rtPrevZCX.Motor_Speed_Calculation_k.Motor_Speed_Calculation_Trig_ZC =
    POS_ZCSIG;
  rtPrevZCX.Motor_Speed_Calculation_m.Motor_Speed_Calculation_Trig_ZC =
    POS_ZCSIG;

  /* SystemInitialize for Atomic SubSystem: '<Root>/BLDC_controller' */
  /* InitializeConditions for UnitDelay: '<S23>/z_counter2' */
  rtDW.z_counter2_DSTATE = rtP.z_maxCntRst;

  /* InitializeConditions for UnitDelay: '<S61>/z_counter2' */
  rtDW.z_counter2_DSTATE_h = rtP.z_maxCntRst;

  /* End of SystemInitialize for SubSystem: '<Root>/BLDC_controller' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
