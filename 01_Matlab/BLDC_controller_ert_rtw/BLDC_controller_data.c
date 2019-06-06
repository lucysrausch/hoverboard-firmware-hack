/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BLDC_controller_data.c
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

/* Constant parameters (auto storage) */
const ConstP rtConstP = {
  /* Computed Parameter: r_trapPhaA_M1_Table
   * Referenced by: '<S18>/r_trapPhaA_M1'
   */
  { 1000, 1000, 1000, -1000, -1000, -1000, 1000 },

  /* Computed Parameter: r_trapPhaB_M1_Table
   * Referenced by: '<S18>/r_trapPhaB_M1'
   */
  { -1000, -1000, 1000, 1000, 1000, -1000, -1000 },

  /* Computed Parameter: r_trapPhaC_M1_Table
   * Referenced by: '<S18>/r_trapPhaC_M1'
   */
  { 1000, -1000, -1000, -1000, 1000, 1000, 1000 },

  /* Computed Parameter: r_sinPhaA_M1_Table
   * Referenced by: '<S19>/r_sinPhaA_M1'
   */
  { 500, 643, 766, 866, 940, 985, 1000, 985, 940, 866, 766, 643, 500, 342, 174,
    0, -174, -342, -500, -643, -766, -866, -940, -985, -1000, -985, -940, -866,
    -766, -643, -500, -342, -174, 0, 174, 342, 500 },

  /* Computed Parameter: r_sinPhaB_M1_Table
   * Referenced by: '<S19>/r_sinPhaB_M1'
   */
  { -1000, -985, -940, -866, -766, -643, -500, -342, -174, 0, 174, 342, 500, 643,
    766, 866, 940, 985, 1000, 985, 940, 866, 766, 643, 500, 342, 174, 0, -174,
    -342, -500, -643, -766, -866, -940, -985, -1000 },

  /* Computed Parameter: r_sinPhaC_M1_Table
   * Referenced by: '<S19>/r_sinPhaC_M1'
   */
  { 500, 342, 174, 0, -174, -342, -500, -643, -766, -866, -940, -985, -1000,
    -985, -940, -866, -766, -643, -500, -342, -174, 0, 174, 342, 500, 643, 766,
    866, 940, 985, 1000, 985, 940, 866, 766, 643, 500 },

  /* Computed Parameter: r_sin3PhaA_M1_Table
   * Referenced by: '<S20>/r_sin3PhaA_M1'
   */
  { 813, 945, 1000, 996, 962, 926, 912, 926, 962, 996, 1000, 945, 813, 599, 319,
    0, -319, -599, -813, -945, -1000, -996, -962, -926, -912, -926, -962, -996,
    -1000, -945, -813, -599, -319, 0, 319, 599, 813 },

  /* Computed Parameter: r_sin3PhaB_M1_Table
   * Referenced by: '<S20>/r_sin3PhaB_M1'
   */
  { -912, -926, -962, -996, -1000, -945, -813, -599, -319, 0, 319, 599, 813, 945,
    1000, 996, 962, 926, 912, 926, 962, 996, 1000, 945, 813, 599, 319, 0, -319,
    -599, -813, -945, -1000, -996, -962, -926, -912 },

  /* Computed Parameter: r_sin3PhaC_M1_Table
   * Referenced by: '<S20>/r_sin3PhaC_M1'
   */
  { 813, 599, 319, 0, -319, -599, -813, -945, -1000, -996, -962, -926, -912,
    -926, -962, -996, -1000, -945, -813, -599, -319, 0, 319, 599, 813, 945, 1000,
    996, 962, 926, 912, 926, 962, 996, 1000, 945, 813 },

  /* Computed Parameter: z_commutMap_M1_table
   * Referenced by: '<S10>/z_commutMap_M1'
   */
  { 1000, -1000, 0, 1000, 0, -1000, 0, 1000, -1000, -1000, 1000, 0, -1000, 0,
    1000, 0, -1000, 1000 },

  /* Computed Parameter: vec_hallToPos_Value
   * Referenced by: '<S12>/vec_hallToPos'
   */
  { 0, 5, 3, 4, 1, 0, 2, 0 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
