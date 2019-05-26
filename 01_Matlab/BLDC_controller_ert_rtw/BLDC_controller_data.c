/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BLDC_controller_data.c
 *
 * Code generated for Simulink model 'BLDC_controller'.
 *
 * Model version                  : 1.800
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Sat May 25 21:42:39 2019
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

/* Block parameters (auto storage) */
P rtP = {
  /* Variable: cf_spdCoef
   * Referenced by:
   *   '<S29>/cf_spdCoef'
   *   '<S69>/cf_spdCoef'
   */
  66667,

  /* Variable: n_commAcvLo
   * Referenced by:
   *   '<S15>/Relay'
   *   '<S55>/Relay'
   */
  100,

  /* Variable: n_commDeacvHi
   * Referenced by:
   *   '<S15>/Relay'
   *   '<S55>/Relay'
   */
  180,

  /* Variable: n_thresSpdDeacv
   * Referenced by:
   *   '<S23>/n_thresSpdDeacv'
   *   '<S63>/n_thresSpdDeacv'
   */
  5,

  /* Variable: r_commDCDeacv
   * Referenced by:
   *   '<S15>/r_commDCDeacv'
   *   '<S55>/r_commDCDeacv'
   */
  70,

  /* Variable: r_phaAdvDC_XA
   * Referenced by:
   *   '<S13>/r_phaAdvDC_XA'
   *   '<S53>/r_phaAdvDC_XA'
   */
  { 0, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 },

  /* Variable: a_phaAdv_M1
   * Referenced by:
   *   '<S13>/a_phaAdv_M2'
   *   '<S53>/a_phaAdv_M2'
   */
  { 0, 0, 7, 2, 2, 2, 4, 5, 9, 16, 25 },

  /* Variable: z_maxCntRst
   * Referenced by:
   *   '<S23>/z_maxCntRst'
   *   '<S63>/z_maxCntRst'
   *   '<S29>/z_maxCntRst'
   *   '<S69>/z_maxCntRst'
   */
  2000,

  /* Variable: z_ctrlTypSel
   * Referenced by:
   *   '<S12>/z_ctrlTypSel1'
   *   '<S52>/z_ctrlTypSel1'
   */
  3U,

  /* Variable: z_nrEdgeSpdAcv
   * Referenced by:
   *   '<S23>/z_nrEdgeSpdAcv'
   *   '<S63>/z_nrEdgeSpdAcv'
   */
  5U,

  /* Variable: b_phaAdvEna
   * Referenced by:
   *   '<S13>/a_elecPeriod1'
   *   '<S53>/a_elecPeriod1'
   */
  1
};

/* Constant parameters (auto storage) */
const ConstP rtConstP = {
  /* Pooled Parameter (Expression: r_trapPhaA_M1)
   * Referenced by:
   *   '<S43>/r_trapPhaA_M1'
   *   '<S83>/r_trapPhaA_M1'
   */
  { 1000, 1000, 1000, -1000, -1000, -1000, 1000 },

  /* Pooled Parameter (Expression: r_trapPhaB_M1)
   * Referenced by:
   *   '<S43>/r_trapPhaB_M1'
   *   '<S83>/r_trapPhaB_M1'
   */
  { -1000, -1000, 1000, 1000, 1000, -1000, -1000 },

  /* Pooled Parameter (Expression: r_trapPhaC_M1)
   * Referenced by:
   *   '<S43>/r_trapPhaC_M1'
   *   '<S83>/r_trapPhaC_M1'
   */
  { 1000, -1000, -1000, -1000, 1000, 1000, 1000 },

  /* Pooled Parameter (Expression: r_sinPhaA_M1)
   * Referenced by:
   *   '<S45>/r_sinPhaA_M1'
   *   '<S85>/r_sinPhaA_M1'
   */
  { 500, 643, 766, 866, 940, 985, 1000, 985, 940, 866, 766, 643, 500, 342, 174,
    0, -174, -342, -500, -643, -766, -866, -940, -985, -1000, -985, -940, -866,
    -766, -643, -500, -342, -174, 0, 174, 342, 500 },

  /* Pooled Parameter (Expression: r_sinPhaB_M1)
   * Referenced by:
   *   '<S45>/r_sinPhaB_M1'
   *   '<S85>/r_sinPhaB_M1'
   */
  { -1000, -985, -940, -866, -766, -643, -500, -342, -174, 0, 174, 342, 500, 643,
    766, 866, 940, 985, 1000, 985, 940, 866, 766, 643, 500, 342, 174, 0, -174,
    -342, -500, -643, -766, -866, -940, -985, -1000 },

  /* Pooled Parameter (Expression: r_sinPhaC_M1)
   * Referenced by:
   *   '<S45>/r_sinPhaC_M1'
   *   '<S85>/r_sinPhaC_M1'
   */
  { 500, 342, 174, 0, -174, -342, -500, -643, -766, -866, -940, -985, -1000,
    -985, -940, -866, -766, -643, -500, -342, -174, 0, 174, 342, 500, 643, 766,
    866, 940, 985, 1000, 985, 940, 866, 766, 643, 500 },

  /* Pooled Parameter (Expression: r_sin3PhaA_M1)
   * Referenced by:
   *   '<S44>/r_sin3PhaA_M1'
   *   '<S84>/r_sin3PhaA_M1'
   */
  { 795, 930, 991, 996, 971, 942, 930, 942, 971, 996, 991, 930, 795, 584, 310, 0,
    -310, -584, -795, -930, -991, -996, -971, -942, -930, -942, -971, -996, -991,
    -930, -795, -584, -310, 0, 310, 584, 795 },

  /* Pooled Parameter (Expression: r_sin3PhaB_M1)
   * Referenced by:
   *   '<S44>/r_sin3PhaB_M1'
   *   '<S84>/r_sin3PhaB_M1'
   */
  { -930, -942, -971, -996, -991, -930, -795, -584, -310, 0, 310, 584, 795, 930,
    991, 996, 971, 942, 930, 942, 971, 996, 991, 930, 795, 584, 310, 0, -310,
    -584, -795, -930, -991, -996, -971, -942, -930 },

  /* Pooled Parameter (Expression: r_sin3PhaC_M1)
   * Referenced by:
   *   '<S44>/r_sin3PhaC_M1'
   *   '<S84>/r_sin3PhaC_M1'
   */
  { 795, 584, 310, 0, -310, -584, -795, -930, -991, -996, -971, -942, -930, -942,
    -971, -996, -991, -930, -795, -584, -310, 0, 310, 584, 795, 930, 991, 996,
    971, 942, 930, 942, 971, 996, 991, 930, 795 },

  /* Pooled Parameter (Expression: z_commutMap_M1)
   * Referenced by:
   *   '<S15>/z_commutMap_M1'
   *   '<S55>/z_commutMap_M1'
   */
  { 1000, -1000, 0, 1000, 0, -1000, 0, 1000, -1000, -1000, 1000, 0, -1000, 0,
    1000, 0, -1000, 1000 },

  /* Pooled Parameter (Expression: vec_hallToPos)
   * Referenced by:
   *   '<S21>/vec_hallToPos'
   *   '<S61>/vec_hallToPos'
   */
  { 0U, 5U, 3U, 4U, 1U, 0U, 2U, 0U },

  /* Pooled Parameter (Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0])
   * Referenced by:
   *   '<S30>/Logic'
   *   '<S70>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
