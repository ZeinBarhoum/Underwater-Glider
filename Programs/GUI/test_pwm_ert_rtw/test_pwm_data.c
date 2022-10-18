/*
 * File: test_pwm_data.c
 *
 * Code generated for Simulink model 'test_pwm'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Jun  3 13:57:14 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test_pwm.h"
#include "test_pwm_private.h"

/* Block parameters (default storage) */
P_test_pwm_T test_pwm_P = {
  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S2>/Constant'
   */
  -0.5,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S1>/Constant'
   */
  2.0E+7,

  /* Expression: 250
   * Referenced by: '<Root>/Constant'
   */
  250.0,

  /* Expression: 1000
   * Referenced by: '<Root>/Saturation'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.0002,

  /* Expression: 0
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 31
   * Referenced by: '<Root>/Step'
   */
  31.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Step'
   */
  1.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
