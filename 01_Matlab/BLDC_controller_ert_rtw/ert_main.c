/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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

#include <stddef.h>
#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include "BLDC_controller.h"           /* Model's header file */
#include "rtwtypes.h"

static RT_MODEL rtM_;
static RT_MODEL *const rtMPtr = &rtM_; /* Real-time model */
static P rtP = {
  /* Variable: cf_speedCoef
   * Referenced by: '<S16>/cf_spdCoef'
   */
  11111,

  /* Variable: cf_speedFilt
   * Referenced by: '<S16>/cf_speedFilt'
   */
  10,

  /* Variable: n_commAcvLo
   * Referenced by: '<S14>/n_commDeacv'
   */
  15,

  /* Variable: n_commDeacvHi
   * Referenced by: '<S14>/n_commDeacv'
   */
  30,

  /* Variable: n_motPhaAdvEna
   * Referenced by: '<S8>/n_motPhaAdvEna'
   */
  400,

  /* Variable: r_commDCDeacv
   * Referenced by: '<S14>/r_commDCDeacv'
   */
  70,

  /* Variable: r_phaAdvDC_XA
   * Referenced by: '<S8>/r_phaAdvDC_XA'
   */
  { 0, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 },

  /* Variable: a_phaAdv_M1
   * Referenced by: '<S8>/a_phaAdv_M2'
   */
  { 0, 0, 0, 0, 0, 2, 3, 5, 9, 16, 25 },

  /* Variable: dz_counterHi
   * Referenced by: '<S14>/dz_counter'
   */
  50,

  /* Variable: dz_counterLo
   * Referenced by: '<S14>/dz_counter'
   */
  20,

  /* Variable: z_maxCntRst
   * Referenced by:
   *   '<S15>/z_counter'
   *   '<S15>/z_counter2'
   *   '<S16>/z_maxCntRst'
   *   '<S17>/Constant1'
   *   '<S17>/UnitDelay1'
   */
  1500,

  /* Variable: z_ctrlTypSel
   * Referenced by: '<S7>/z_ctrlTypSel1'
   */
  3U,

  /* Variable: b_phaAdvEna
   * Referenced by: '<S8>/a_elecPeriod1'
   */
  1
};                                     /* Modifiable parameters */

static DW rtDW;                        /* Observable states */
static ExtU rtU;                       /* External inputs */
static ExtY rtY;                       /* External outputs */

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void rt_OneStep(RT_MODEL *const rtM);
void rt_OneStep(RT_MODEL *const rtM)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  BLDC_controller_step(rtM);

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*
 * The example "main" function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific.  This example
 * illustrates how you do this relative to initializing the model.
 */
int_T main(int_T argc, const char *argv[])
{
  RT_MODEL *const rtM = rtMPtr;

  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Pack model data into RTM */
  rtM->defaultParam = &rtP;
  rtM->dwork = &rtDW;
  rtM->inputs = &rtU;
  rtM->outputs = &rtY;

  /* Initialize model */
  BLDC_controller_initialize(rtM);

  /* Attach rt_OneStep to a timer or interrupt service routine with
   * period 6.0E-5 seconds (the model's base sample time) here.  The
   * call syntax for rt_OneStep is
   *
   *  rt_OneStep(rtM);
   */
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (1) {
    /*  Perform other application tasks here */
  }

  /* The option 'Remove error status field in real-time model data structure'
   * is selected, therefore the following code does not need to execute.
   */
#if 0

  /* Disable rt_OneStep() here */
#endif

  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
