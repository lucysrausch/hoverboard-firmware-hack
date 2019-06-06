/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BLDC_controller.c
 *
 * Code generated for Simulink model 'BLDC_controller'.
 *
 * Model version                  : 1.879
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Thu Jun  6 22:50:24 2019
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

uint8_T plook_u8s32u32n31_evenc_s(int32_T u, int32_T bp0, uint32_T bpSpace,
  uint32_T maxIndex, uint32_T *fraction);
int16_T intrp1d_s16s32s32u8u32n31l_s(uint8_T bpIndex, uint32_T frac, const
  int16_T table[]);
int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator);
uint8_T plook_u8s32u32n31_evenc_s(int32_T u, int32_T bp0, uint32_T bpSpace,
  uint32_T maxIndex, uint32_T *fraction)
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

int16_T intrp1d_s16s32s32u8u32n31l_s(uint8_T bpIndex, uint32_T frac, const
  int16_T table[])
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

int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

/* Model step function */
void BLDC_controller_step(RT_MODEL *const rtM)
{
  P *rtP = ((P *) rtM->defaultParam);
  DW *rtDW = ((DW *) rtM->dwork);
  ExtU *rtU = (ExtU *) rtM->inputs;
  ExtY *rtY = (ExtY *) rtM->outputs;
  uint8_T rtb_Sum;
  int32_T rtb_Abs1;
  uint8_T rtb_BitwiseOperator;
  int32_T rtb_Sum2;
  int16_T rtb_Abs2;
  int16_T rtb_Sum1_a;
  int32_T rtb_Abs5;
  int8_T rtAction;
  int8_T rtb_Sum2_h;
  uint32_T rtb_r_phaAdvDC_XA_o2;
  int32_T rtb_Switch1_idx_1;

  /* Outputs for Atomic SubSystem: '<Root>/BLDC_controller' */
  /* Sum: '<S12>/Sum' incorporates:
   *  Gain: '<S12>/g_Ha'
   *  Gain: '<S12>/g_Hb'
   *  Inport: '<Root>/b_hallA '
   *  Inport: '<Root>/b_hallB'
   *  Inport: '<Root>/b_hallC'
   */
  rtb_Sum = (uint8_T)((uint32_T)(uint8_T)((uint32_T)(uint8_T)(rtU->b_hallA << 2)
    + (uint8_T)(rtU->b_hallB << 1)) + rtU->b_hallC);

  /* Abs: '<S2>/Abs1' incorporates:
   *  Inport: '<Root>/r_DC'
   */
  if (rtU->r_DC < 0) {
    rtb_Abs1 = -rtU->r_DC;
  } else {
    rtb_Abs1 = rtU->r_DC;
  }

  /* End of Abs: '<S2>/Abs1' */

  /* S-Function (sfix_bitop): '<S11>/Bitwise Operator' incorporates:
   *  Inport: '<Root>/b_hallA '
   *  Inport: '<Root>/b_hallB'
   *  Inport: '<Root>/b_hallC'
   *  UnitDelay: '<S11>/UnitDelay'
   *  UnitDelay: '<S11>/UnitDelay1'
   *  UnitDelay: '<S11>/UnitDelay2'
   */
  rtb_BitwiseOperator = (uint8_T)(rtU->b_hallA ^ rtU->b_hallB ^ rtU->b_hallC ^
    rtDW->UnitDelay_DSTATE ^ rtDW->UnitDelay1_DSTATE_i ^
    rtDW->UnitDelay2_DSTATE_h);

  /* If: '<S14>/If1' incorporates:
   *  Constant: '<S14>/Constant6'
   *  Constant: '<S17>/Constant1'
   *  Constant: '<S17>/Constant23'
   *  If: '<S7>/If2'
   *  Inport: '<S15>/z_counterRawPrev'
   *  RelationalOperator: '<S17>/Relational Operator1'
   *  Sum: '<S14>/Sum1'
   *  Switch: '<S17>/Switch1'
   *  Switch: '<S17>/Switch2'
   *  UnitDelay: '<S14>/UnitDelay1'
   *  UnitDelay: '<S17>/UnitDelay1'
   */
  if (rtb_BitwiseOperator != 0) {
    /* Outputs for IfAction SubSystem: '<S7>/F01_03_Direction_Detection' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    /* UnitDelay: '<S13>/UnitDelay1' */
    rtDW->UnitDelay1 = rtDW->Switch2;

    /* Sum: '<S13>/Sum2' incorporates:
     *  Constant: '<S12>/vec_hallToPos'
     *  Selector: '<S12>/Selector'
     *  UnitDelay: '<S13>/UnitDelay2'
     */
    rtb_Sum2_h = (int8_T)(rtConstP.vec_hallToPos_Value[rtb_Sum] -
                          rtDW->UnitDelay2_DSTATE_i);

    /* Switch: '<S13>/Switch2' incorporates:
     *  Constant: '<S13>/Constant20'
     *  Constant: '<S13>/Constant23'
     *  Constant: '<S13>/Constant24'
     *  Constant: '<S13>/Constant8'
     *  Logic: '<S13>/Logical Operator3'
     *  RelationalOperator: '<S13>/Relational Operator1'
     *  RelationalOperator: '<S13>/Relational Operator6'
     */
    if ((rtb_Sum2_h == 1) || (rtb_Sum2_h == -5)) {
      rtDW->Switch2 = 1;
    } else {
      rtDW->Switch2 = -1;
    }

    /* End of Switch: '<S13>/Switch2' */

    /* Update for UnitDelay: '<S13>/UnitDelay2' incorporates:
     *  Constant: '<S12>/vec_hallToPos'
     *  Selector: '<S12>/Selector'
     */
    rtDW->UnitDelay2_DSTATE_i = rtConstP.vec_hallToPos_Value[rtb_Sum];

    /* End of Outputs for SubSystem: '<S7>/F01_03_Direction_Detection' */
    rtb_Abs2 = 1;

    /* Outputs for IfAction SubSystem: '<S14>/Counter_Hold_and_Error_Calculation' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    rtDW->z_counterRawPrev = rtDW->UnitDelay1_DSTATE_c;

    /* Sum: '<S15>/Sum4' incorporates:
     *  Constant: '<S14>/Constant6'
     *  Constant: '<S17>/Constant23'
     *  Inport: '<S15>/z_counterRawPrev'
     *  Sum: '<S14>/Sum1'
     *  UnitDelay: '<S14>/UnitDelay1'
     *  UnitDelay: '<S15>/z_counter2'
     */
    rtDW->Sum4 = (int16_T)(rtDW->z_counterRawPrev - rtDW->z_counter2_DSTATE);

    /* Update for UnitDelay: '<S15>/z_counter2' */
    rtDW->z_counter2_DSTATE = rtDW->z_counterRawPrev;

    /* End of Outputs for SubSystem: '<S14>/Counter_Hold_and_Error_Calculation' */
  } else {
    if (rtDW->UnitDelay1_DSTATE < 1500) {
      /* Switch: '<S17>/Switch2' incorporates:
       *  UnitDelay: '<S17>/UnitDelay1'
       */
      rtb_Abs2 = rtDW->UnitDelay1_DSTATE;
    } else {
      /* Switch: '<S17>/Switch2' incorporates:
       *  Constant: '<S17>/Constant1'
       */
      rtb_Abs2 = 1500;
    }

    rtb_Abs2++;
  }

  /* End of If: '<S14>/If1' */

  /* Sum: '<S14>/Sum1' */
  rtb_Sum1_a = rtb_Abs2;

  /* Switch: '<S16>/Switch1' incorporates:
   *  Constant: '<S16>/Constant1'
   *  Constant: '<S16>/cf_spdCoef'
   *  Constant: '<S16>/z_maxCntRst'
   *  Logic: '<S16>/Logical Operator1'
   *  Product: '<S16>/Divide4'
   *  RelationalOperator: '<S16>/Relational Operator2'
   *  RelationalOperator: '<S16>/Relational Operator5'
   *  Sum: '<S14>/Sum1'
   */
  if ((rtb_Abs2 > 1500) || (rtDW->Switch2 != rtDW->UnitDelay1)) {
    rtb_Sum2 = 0;
  } else {
    rtb_Sum2 = rtP->cf_speedCoef * rtDW->Switch2 / rtDW->z_counterRawPrev;
  }

  /* End of Switch: '<S16>/Switch1' */

  /* Product: '<S16>/Divide2' incorporates:
   *  Constant: '<S16>/Constant2'
   *  Constant: '<S16>/Constant3'
   *  Constant: '<S16>/cf_speedFilt'
   *  Product: '<S16>/Divide1'
   *  Product: '<S16>/Divide3'
   *  Sum: '<S16>/Sum1'
   *  Sum: '<S16>/Sum2'
   *  UnitDelay: '<S16>/UnitDelay2'
   */
  rtb_Sum2 = ((100 - rtP->cf_speedFilt) * rtDW->UnitDelay2_DSTATE + rtb_Sum2 *
              rtP->cf_speedFilt) / 100;

  /* Abs: '<S14>/Abs5' */
  if (rtb_Sum2 < 0) {
    rtb_Abs5 = -rtb_Sum2;
  } else {
    rtb_Abs5 = rtb_Sum2;
  }

  /* End of Abs: '<S14>/Abs5' */

  /* Relay: '<S14>/n_commDeacv' */
  if (rtb_Abs5 >= rtP->n_commDeacvHi) {
    rtDW->n_commDeacv_Mode = true;
  } else {
    if (rtb_Abs5 <= rtP->n_commAcvLo) {
      rtDW->n_commDeacv_Mode = false;
    }
  }

  /* Abs: '<S14>/Abs2' */
  if (rtDW->Sum4 < 0) {
    rtb_Abs2 = (int16_T)-rtDW->Sum4;
  } else {
    rtb_Abs2 = rtDW->Sum4;
  }

  /* End of Abs: '<S14>/Abs2' */

  /* Relay: '<S14>/dz_counter' */
  if (rtb_Abs2 >= rtP->dz_counterHi) {
    rtDW->dz_counter_Mode = true;
  } else {
    if (rtb_Abs2 <= rtP->dz_counterLo) {
      rtDW->dz_counter_Mode = false;
    }
  }

  /* If: '<S2>/If1' incorporates:
   *  Constant: '<S7>/z_ctrlTypSel1'
   */
  rtb_Sum2_h = rtDW->If1_ActiveSubsystem;
  rtAction = -1;
  if (rtP->z_ctrlTypSel != 0) {
    rtAction = 0;
  }

  rtDW->If1_ActiveSubsystem = rtAction;
  if ((rtb_Sum2_h != rtAction) && (rtb_Sum2_h == 0)) {
    /* Disable for Outport: '<S8>/a_elecAngleAdv' */
    rtDW->Switch_PhaAdv = 0;

    /* Disable for Outport: '<Root>/a_elecAngle' incorporates:
     *  Outport: '<S8>/a_elecAngle'
     */
    rtY->a_elecAngle = 0;
  }

  if (rtAction == 0) {
    /* Outputs for IfAction SubSystem: '<S2>/F02_Electrical_Angle_Calculation' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Switch: '<S8>/Switch3' incorporates:
     *  Constant: '<S12>/vec_hallToPos'
     *  Constant: '<S8>/Constant16'
     *  Gain: '<S12>/g_Ha'
     *  Gain: '<S12>/g_Hb'
     *  Inport: '<Root>/b_hallA '
     *  Inport: '<Root>/b_hallB'
     *  Inport: '<Root>/b_hallC'
     *  RelationalOperator: '<S8>/Relational Operator7'
     *  Selector: '<S12>/Selector'
     *  Sum: '<S12>/Sum'
     *  Sum: '<S8>/Sum1'
     */
    if (rtDW->Switch2 == 1) {
      rtb_Sum2_h = rtConstP.vec_hallToPos_Value[rtb_Sum];
    } else {
      rtb_Sum2_h = (int8_T)(rtConstP.vec_hallToPos_Value[(uint8_T)((uint32_T)
        (uint8_T)((uint32_T)(uint8_T)(rtU->b_hallA << 2) + (uint8_T)
                  (rtU->b_hallB << 1)) + rtU->b_hallC)] + 1);
    }

    /* End of Switch: '<S8>/Switch3' */

    /* Outport: '<Root>/a_elecAngle' incorporates:
     *  Constant: '<S8>/a_elecAngle1'
     *  Product: '<S8>/Divide4'
     *  Product: '<S8>/Divide5'
     *  Product: '<S8>/Product6'
     *  Sum: '<S8>/Sum2'
     */
    rtY->a_elecAngle = 60 * rtb_Sum1_a / rtDW->z_counterRawPrev * rtDW->Switch2
      + rtb_Sum2_h * 60;

    /* Switch: '<S8>/Switch_PhaAdv' incorporates:
     *  Constant: '<S8>/a_elecPeriod1'
     *  Outport: '<Root>/a_elecAngle'
     */
    if (rtP->b_phaAdvEna) {
      /* PreLookup: '<S8>/r_phaAdvDC_XA' */
      rtb_BitwiseOperator = plook_u8s32u32n31_evenc_s(rtb_Abs1,
        rtP->r_phaAdvDC_XA[0], (uint32_T)rtP->r_phaAdvDC_XA[1] -
        rtP->r_phaAdvDC_XA[0], 10U, &rtb_r_phaAdvDC_XA_o2);

      /* Interpolation_n-D: '<S8>/a_phaAdv_M2' */
      rtb_Abs2 = intrp1d_s16s32s32u8u32n31l_s(rtb_BitwiseOperator,
        rtb_r_phaAdvDC_XA_o2, rtP->a_phaAdv_M1);

      /* Sum: '<S8>/Sum3' incorporates:
       *  Outport: '<Root>/a_elecAngle'
       *  Product: '<S8>/Product2'
       */
      rtb_Abs5 = (int16_T)(rtb_Abs2 * rtDW->Switch2) + rtY->a_elecAngle;

      /* Math: '<S8>/Math Function' */
      rtDW->Switch_PhaAdv = rtb_Abs5 - div_nde_s32_floor(rtb_Abs5, 360) * 360;
    } else {
      rtDW->Switch_PhaAdv = rtY->a_elecAngle;
    }

    /* End of Switch: '<S8>/Switch_PhaAdv' */
    /* End of Outputs for SubSystem: '<S2>/F02_Electrical_Angle_Calculation' */
  }

  /* End of If: '<S2>/If1' */

  /* SwitchCase: '<S9>/Switch Case' incorporates:
   *  Constant: '<S7>/z_ctrlTypSel1'
   */
  switch (rtP->z_ctrlTypSel) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S9>/F03_01_Pure_Trapezoidal_Method' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    /* PreLookup: '<S18>/a_trapElecAngle_XA' */
    rtb_BitwiseOperator = plook_u8s32u32n31_evenc_s(rtDW->Switch_PhaAdv, 0, 60U,
      6U, &rtb_r_phaAdvDC_XA_o2);

    /* Interpolation_n-D: '<S18>/r_trapPhaA_M1' */
    rtDW->Merge = intrp1d_s16s32s32u8u32n31l_s(rtb_BitwiseOperator,
      rtb_r_phaAdvDC_XA_o2, rtConstP.r_trapPhaA_M1_Table);

    /* Interpolation_n-D: '<S18>/r_trapPhaB_M1' */
    rtDW->Merge1 = intrp1d_s16s32s32u8u32n31l_s(rtb_BitwiseOperator,
      rtb_r_phaAdvDC_XA_o2, rtConstP.r_trapPhaB_M1_Table);

    /* Interpolation_n-D: '<S18>/r_trapPhaC_M1' */
    rtDW->Merge2 = intrp1d_s16s32s32u8u32n31l_s(rtb_BitwiseOperator,
      rtb_r_phaAdvDC_XA_o2, rtConstP.r_trapPhaC_M1_Table);

    /* End of Outputs for SubSystem: '<S9>/F03_01_Pure_Trapezoidal_Method' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S9>/F03_02_Sinusoidal_Method' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    /* PreLookup: '<S19>/a_sinElecAngle_XA' */
    rtb_BitwiseOperator = plook_u8s32u32n31_evenc_s(rtDW->Switch_PhaAdv, 0, 10U,
      36U, &rtb_r_phaAdvDC_XA_o2);

    /* Interpolation_n-D: '<S19>/r_sinPhaA_M1' */
    rtDW->Merge = intrp1d_s16s32s32u8u32n31l_s(rtb_BitwiseOperator,
      rtb_r_phaAdvDC_XA_o2, rtConstP.r_sinPhaA_M1_Table);

    /* Interpolation_n-D: '<S19>/r_sinPhaB_M1' */
    rtDW->Merge1 = intrp1d_s16s32s32u8u32n31l_s(rtb_BitwiseOperator,
      rtb_r_phaAdvDC_XA_o2, rtConstP.r_sinPhaB_M1_Table);

    /* Interpolation_n-D: '<S19>/r_sinPhaC_M1' */
    rtDW->Merge2 = intrp1d_s16s32s32u8u32n31l_s(rtb_BitwiseOperator,
      rtb_r_phaAdvDC_XA_o2, rtConstP.r_sinPhaC_M1_Table);

    /* End of Outputs for SubSystem: '<S9>/F03_02_Sinusoidal_Method' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S9>/F03_03_Sinusoidal3rd_Method' incorporates:
     *  ActionPort: '<S20>/Action Port'
     */
    /* PreLookup: '<S20>/a_sinElecAngle_XA' */
    rtb_BitwiseOperator = plook_u8s32u32n31_evenc_s(rtDW->Switch_PhaAdv, 0, 10U,
      36U, &rtb_r_phaAdvDC_XA_o2);

    /* Interpolation_n-D: '<S20>/r_sin3PhaA_M1' */
    rtDW->Merge = intrp1d_s16s32s32u8u32n31l_s(rtb_BitwiseOperator,
      rtb_r_phaAdvDC_XA_o2, rtConstP.r_sin3PhaA_M1_Table);

    /* Interpolation_n-D: '<S20>/r_sin3PhaB_M1' */
    rtDW->Merge1 = intrp1d_s16s32s32u8u32n31l_s(rtb_BitwiseOperator,
      rtb_r_phaAdvDC_XA_o2, rtConstP.r_sin3PhaB_M1_Table);

    /* Interpolation_n-D: '<S20>/r_sin3PhaC_M1' */
    rtDW->Merge2 = intrp1d_s16s32s32u8u32n31l_s(rtb_BitwiseOperator,
      rtb_r_phaAdvDC_XA_o2, rtConstP.r_sin3PhaC_M1_Table);

    /* End of Outputs for SubSystem: '<S9>/F03_03_Sinusoidal3rd_Method' */
    break;
  }

  /* End of SwitchCase: '<S9>/Switch Case' */

  /* Signum: '<S14>/Sign' */
  if (rtDW->Switch2 < 0) {
    rtb_Sum2_h = -1;
  } else {
    rtb_Sum2_h = (int8_T)(rtDW->Switch2 > 0);
  }

  /* End of Signum: '<S14>/Sign' */

  /* Signum: '<S14>/Sign1' incorporates:
   *  Inport: '<Root>/r_DC'
   */
  if (rtU->r_DC < 0) {
    rtb_Abs5 = -1;
  } else {
    rtb_Abs5 = (rtU->r_DC > 0);
  }

  /* End of Signum: '<S14>/Sign1' */

  /* Switch: '<S10>/Switch1' incorporates:
   *  Constant: '<S12>/vec_hallToPos'
   *  Constant: '<S14>/CTRL_COMM'
   *  Constant: '<S14>/r_commDCDeacv'
   *  Constant: '<S7>/z_ctrlTypSel1'
   *  Inport: '<Root>/r_DC'
   *  Logic: '<S14>/Logical Operator2'
   *  LookupNDDirect: '<S10>/z_commutMap_M1'
   *  Product: '<S10>/Divide2'
   *  Product: '<S10>/Divide4'
   *  RelationalOperator: '<S14>/Relational Operator1'
   *  RelationalOperator: '<S14>/Relational Operator3'
   *  RelationalOperator: '<S14>/Relational Operator4'
   *  Relay: '<S14>/dz_counter'
   *  Relay: '<S14>/n_commDeacv'
   *  Selector: '<S12>/Selector'
   *
   * About '<S10>/z_commutMap_M1':
   *  2-dimensional Direct Look-Up returning a Column
   */
  if ((rtP->z_ctrlTypSel != 0) && (rtb_Abs1 > rtP->r_commDCDeacv) && (rtb_Sum2_h
       == rtb_Abs5) && rtDW->n_commDeacv_Mode && (!rtDW->dz_counter_Mode)) {
    rtb_Abs5 = rtU->r_DC * rtDW->Merge;
    rtb_Switch1_idx_1 = rtU->r_DC * rtDW->Merge1;
    rtb_Abs1 = rtU->r_DC * rtDW->Merge2;
  } else {
    if (rtConstP.vec_hallToPos_Value[rtb_Sum] > 5) {
      /* LookupNDDirect: '<S10>/z_commutMap_M1'
       *
       * About '<S10>/z_commutMap_M1':
       *  2-dimensional Direct Look-Up returning a Column
       */
      rtb_Sum2_h = 5;
    } else if (rtConstP.vec_hallToPos_Value[rtb_Sum] < 0) {
      /* LookupNDDirect: '<S10>/z_commutMap_M1'
       *
       * About '<S10>/z_commutMap_M1':
       *  2-dimensional Direct Look-Up returning a Column
       */
      rtb_Sum2_h = 0;
    } else {
      /* LookupNDDirect: '<S10>/z_commutMap_M1' incorporates:
       *  Constant: '<S12>/vec_hallToPos'
       *  Selector: '<S12>/Selector'
       *
       * About '<S10>/z_commutMap_M1':
       *  2-dimensional Direct Look-Up returning a Column
       */
      rtb_Sum2_h = rtConstP.vec_hallToPos_Value[rtb_Sum];
    }

    /* LookupNDDirect: '<S10>/z_commutMap_M1' incorporates:
     *  Constant: '<S12>/vec_hallToPos'
     *  Selector: '<S12>/Selector'
     *
     * About '<S10>/z_commutMap_M1':
     *  2-dimensional Direct Look-Up returning a Column
     */
    rtb_Abs1 = rtb_Sum2_h * 3;
    rtb_Abs5 = rtU->r_DC * rtConstP.z_commutMap_M1_table[rtb_Abs1];
    rtb_Switch1_idx_1 = rtConstP.z_commutMap_M1_table[1 + rtb_Abs1] * rtU->r_DC;
    rtb_Abs1 = rtConstP.z_commutMap_M1_table[2 + rtb_Abs1] * rtU->r_DC;
  }

  /* End of Switch: '<S10>/Switch1' */

  /* Outport: '<Root>/DC_phaA' incorporates:
   *  Constant: '<S10>/Constant1'
   *  Product: '<S10>/Divide1'
   */
  rtY->DC_phaA = rtb_Abs5 / 1000;

  /* Outport: '<Root>/DC_phaB' incorporates:
   *  Constant: '<S10>/Constant1'
   *  Product: '<S10>/Divide1'
   */
  rtY->DC_phaB = rtb_Switch1_idx_1 / 1000;

  /* Update for UnitDelay: '<S11>/UnitDelay' incorporates:
   *  Inport: '<Root>/b_hallA '
   */
  rtDW->UnitDelay_DSTATE = rtU->b_hallA;

  /* Update for UnitDelay: '<S11>/UnitDelay1' incorporates:
   *  Inport: '<Root>/b_hallB'
   */
  rtDW->UnitDelay1_DSTATE_i = rtU->b_hallB;

  /* Update for UnitDelay: '<S11>/UnitDelay2' incorporates:
   *  Inport: '<Root>/b_hallC'
   */
  rtDW->UnitDelay2_DSTATE_h = rtU->b_hallC;

  /* Update for UnitDelay: '<S17>/UnitDelay1' */
  rtDW->UnitDelay1_DSTATE = rtb_Sum1_a;

  /* Update for UnitDelay: '<S14>/UnitDelay1' */
  rtDW->UnitDelay1_DSTATE_c = rtb_Sum1_a;

  /* Update for UnitDelay: '<S16>/UnitDelay2' */
  rtDW->UnitDelay2_DSTATE = rtb_Sum2;

  /* Outport: '<Root>/DC_phaC' incorporates:
   *  Constant: '<S10>/Constant1'
   *  Product: '<S10>/Divide1'
   */
  rtY->DC_phaC = rtb_Abs1 / 1000;

  /* End of Outputs for SubSystem: '<Root>/BLDC_controller' */

  /* Outport: '<Root>/n_mot' */
  rtY->n_mot = rtb_Sum2;
}

/* Model initialize function */
void BLDC_controller_initialize(RT_MODEL *const rtM)
{
  DW *rtDW = ((DW *) rtM->dwork);

  /* Start for Atomic SubSystem: '<Root>/BLDC_controller' */
  /* Start for If: '<S2>/If1' */
  rtDW->If1_ActiveSubsystem = -1;

  /* End of Start for SubSystem: '<Root>/BLDC_controller' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/BLDC_controller' */
  /* InitializeConditions for UnitDelay: '<S17>/UnitDelay1' */
  rtDW->UnitDelay1_DSTATE = 1500;

  /* SystemInitialize for IfAction SubSystem: '<S14>/Counter_Hold_and_Error_Calculation' */
  /* InitializeConditions for UnitDelay: '<S15>/z_counter2' */
  rtDW->z_counter2_DSTATE = 1500;

  /* SystemInitialize for Outport: '<S15>/z_counter' */
  rtDW->z_counterRawPrev = 1500;

  /* End of SystemInitialize for SubSystem: '<S14>/Counter_Hold_and_Error_Calculation' */
  /* End of SystemInitialize for SubSystem: '<Root>/BLDC_controller' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
