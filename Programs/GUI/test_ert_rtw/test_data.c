/*
 * File: test_data.c
 *
 * Code generated for Simulink model 'test'.
 *
 * Model version                  : 1.75
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Jun  3 14:01:37 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test.h"
#include "test_private.h"

/* Block parameters (default storage) */
P_test_T test_P = {
  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S2>/Constant'
   */
  -0.5,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S1>/Constant'
   */
  2.0E+7,

  /* Expression: 80
   * Referenced by: '<S10>/Constant'
   */
  80.0,

  /* Expression: 0
   * Referenced by: '<S9>/Constant'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<S9>/Constant1'
   */
  3.0,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S11>/Out1'
   */
  0.0,

  /* Computed Parameter: Out2_Y0
   * Referenced by: '<S11>/Out2'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S11>/Discrete-Time Integrator'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S11>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainval
   * Referenced by: '<S11>/Discrete-Time Integrator1'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S11>/Discrete-Time Integrator1'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator2_gainval
   * Referenced by: '<S11>/Discrete-Time Integrator2'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S11>/Discrete-Time Integrator2'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator3_gainval
   * Referenced by: '<S11>/Discrete-Time Integrator3'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S11>/Discrete-Time Integrator3'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator4_gainval
   * Referenced by: '<S11>/Discrete-Time Integrator4'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S11>/Discrete-Time Integrator4'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator5_gainval
   * Referenced by: '<S11>/Discrete-Time Integrator5'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S11>/Discrete-Time Integrator5'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator10_gainva
   * Referenced by: '<S11>/Discrete-Time Integrator10'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S11>/Discrete-Time Integrator10'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator11_gainva
   * Referenced by: '<S11>/Discrete-Time Integrator11'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S11>/Discrete-Time Integrator11'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator12_gainva
   * Referenced by: '<S11>/Discrete-Time Integrator12'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S11>/Discrete-Time Integrator12'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator13_gainva
   * Referenced by: '<S11>/Discrete-Time Integrator13'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S11>/Discrete-Time Integrator13'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator14_gainva
   * Referenced by: '<S11>/Discrete-Time Integrator14'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S11>/Discrete-Time Integrator14'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator6_gainval
   * Referenced by: '<S11>/Discrete-Time Integrator6'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S11>/Discrete-Time Integrator6'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator7_gainval
   * Referenced by: '<S11>/Discrete-Time Integrator7'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S11>/Discrete-Time Integrator7'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator8_gainval
   * Referenced by: '<S11>/Discrete-Time Integrator8'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S11>/Discrete-Time Integrator8'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator9_gainval
   * Referenced by: '<S11>/Discrete-Time Integrator9'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S11>/Discrete-Time Integrator9'
   */
  0.0,

  /* Computed Parameter: MPU6050Bias_Y0
   * Referenced by: '<S5>/MPU6050 Bias'
   */
  0.0,

  /* Computed Parameter: MPU9250Bias_Y0
   * Referenced by: '<S5>/MPU9250 Bias'
   */
  0.0,

  /* Expression: 1/30
   * Referenced by: '<S5>/Gain'
   */
  0.033333333333333333,

  /* Expression: 1/30
   * Referenced by: '<S5>/Gain1'
   */
  0.033333333333333333,

  /* Computed Parameter: EulerAngles_Y0
   * Referenced by: '<S6>/Euler Angles'
   */
  0.0,

  /* Computed Parameter: AccelI_Y0
   * Referenced by: '<S6>/Accel//I'
   */
  0.0,

  /* Expression: 1/2
   * Referenced by: '<S23>/Gain'
   */
  0.5,

  /* Expression: 1/2
   * Referenced by: '<S26>/Gain'
   */
  0.5,

  /* Expression: 0.1
   * Referenced by: '<S13>/Gain'
   */
  0.1,

  /* Expression: 0.0
   * Referenced by: '<S19>/Delay'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S19>/Delay1'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S19>/Delay2'
   */
  0.0,

  /* Expression: 0.9
   * Referenced by: '<S13>/Gain1'
   */
  0.9,

  /* Expression: 0.0
   * Referenced by: '<S21>/Delay'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S21>/Delay1'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S21>/Delay2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S13>/Gain2'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S35>/I2C Master Read'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<S35>/I2C Master Read1'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<S35>/I2C Master Read2'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<S35>/I2C Master Read3'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<S35>/I2C Master Read4'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<S35>/I2C Master Read5'
   */
  0.1,

  /* Expression: 65536
   * Referenced by: '<S35>/Constant3'
   */
  65536.0,

  /* Expression: 0
   * Referenced by: '<S35>/Constant4'
   */
  0.0,

  /* Expression: 65536
   * Referenced by: '<S35>/Constant6'
   */
  65536.0,

  /* Expression: 0
   * Referenced by: '<S35>/Constant7'
   */
  0.0,

  /* Expression: 65536
   * Referenced by: '<S35>/Constant'
   */
  65536.0,

  /* Expression: 0
   * Referenced by: '<S35>/Constant1'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S36>/I2C Master Read'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<S36>/I2C Master Read1'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<S36>/I2C Master Read2'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<S36>/I2C Master Read3'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<S36>/I2C Master Read4'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<S36>/I2C Master Read5'
   */
  0.1,

  /* Expression: 65536
   * Referenced by: '<S36>/Constant3'
   */
  65536.0,

  /* Expression: 0
   * Referenced by: '<S36>/Constant4'
   */
  0.0,

  /* Expression: 65536
   * Referenced by: '<S36>/Constant6'
   */
  65536.0,

  /* Expression: 0
   * Referenced by: '<S36>/Constant7'
   */
  0.0,

  /* Expression: 65536
   * Referenced by: '<S36>/Constant'
   */
  65536.0,

  /* Expression: 0
   * Referenced by: '<S36>/Constant1'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S8>/MPU9250'
   */
  0.1,

  /* Expression: 28.3746
   * Referenced by: '<Root>/Pitch_desired'
   */
  28.3746,

  /* Expression: 0
   * Referenced by: '<Root>/Rate Transition'
   */
  0.0,

  /* Expression: -5
   * Referenced by: '<Root>/Dead Zone'
   */
  -5.0,

  /* Expression: 5
   * Referenced by: '<Root>/Dead Zone'
   */
  5.0,

  /* Expression: 15
   * Referenced by: '<Root>/Gain'
   */
  15.0,

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_p
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.0002,

  /* Expression: 0
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<Root>/Saturation'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation'
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
  1.0,

  /* Expression: 0.21905
   * Referenced by: '<Root>/Mass_desired'
   */
  0.21905,

  /* Expression: 30
   * Referenced by: '<Root>/Time_desired'
   */
  30.0,

  /* Expression: 250/32768
   * Referenced by: '<S36>/Gain2'
   */
  0.00762939453125,

  /* Expression: 250/32768
   * Referenced by: '<S36>/Gain5'
   */
  0.00762939453125,

  /* Expression: 250/32768
   * Referenced by: '<S36>/Gain3'
   */
  0.00762939453125,

  /* Expression: 9.81*2/32768
   * Referenced by: '<S35>/Gain2'
   */
  0.0005987548828125,

  /* Expression: 9.81*2/32768
   * Referenced by: '<S35>/Gain5'
   */
  0.0005987548828125,

  /* Expression: 9.81*2/32768
   * Referenced by: '<S35>/Gain3'
   */
  0.0005987548828125,

  /* Expression: [22.73,70.49,-38.6495]
   * Referenced by: '<S8>/Constant'
   */
  { 22.73, 70.49, -38.6495 },

  /* Expression: 1/45.3705
   * Referenced by: '<S8>/Gain2'
   */
  0.022040753352949603,

  /* Expression: 1/45.01
   * Referenced by: '<S8>/Gain1'
   */
  0.022217285047767165,

  /* Expression: 1/44.45
   * Referenced by: '<S8>/Gain'
   */
  0.022497187851518559,

  /* Computed Parameter: Switch_Threshold
   * Referenced by: '<S36>/Switch'
   */
  8192,

  /* Computed Parameter: Switch2_Threshold
   * Referenced by: '<S36>/Switch2'
   */
  8192,

  /* Computed Parameter: Switch1_Threshold
   * Referenced by: '<S36>/Switch1'
   */
  8192,

  /* Computed Parameter: Switch_Threshold_j
   * Referenced by: '<S35>/Switch'
   */
  8192,

  /* Computed Parameter: Switch2_Threshold_k
   * Referenced by: '<S35>/Switch2'
   */
  8192,

  /* Computed Parameter: Switch1_Threshold_j
   * Referenced by: '<S35>/Switch1'
   */
  8192,

  /* Computed Parameter: Gain_Gain_g
   * Referenced by: '<S36>/Gain'
   */
  64,

  /* Computed Parameter: Gain4_Gain
   * Referenced by: '<S36>/Gain4'
   */
  64,

  /* Computed Parameter: Gain1_Gain_c
   * Referenced by: '<S36>/Gain1'
   */
  64,

  /* Computed Parameter: Gain_Gain_f
   * Referenced by: '<S35>/Gain'
   */
  64,

  /* Computed Parameter: Gain4_Gain_d
   * Referenced by: '<S35>/Gain4'
   */
  64,

  /* Computed Parameter: Gain1_Gain_i
   * Referenced by: '<S35>/Gain1'
   */
  64
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
