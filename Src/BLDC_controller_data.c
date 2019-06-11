/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BLDC_controller_data.c
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

P rtP = {
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
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
