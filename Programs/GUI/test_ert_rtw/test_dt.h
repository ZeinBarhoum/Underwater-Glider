/*
 * test_dt.h
 *
 * Code generation for model "test".
 *
 * Model version              : 1.75
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Thu Jun  3 14:01:37 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int8_T),
  sizeof(int16_T),
  sizeof(beagleboneblue_bbblueDigitalW_T),
  sizeof(beagleboneblue_bbblueI2CMaste_T),
  sizeof(beagleboneblue_bbblueI2CMas_j_T),
  sizeof(beagleboneblue_bbblueMPU9250__T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "int8_T",
  "int16_T",
  "beagleboneblue_bbblueDigitalW_T",
  "beagleboneblue_bbblueI2CMaste_T",
  "beagleboneblue_bbblueI2CMas_j_T",
  "beagleboneblue_bbblueMPU9250__T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&test_B.RateTransition), 0, 0, 40 }
  ,

  { (char_T *)(&test_DW.obj), 19, 0, 1 },

  { (char_T *)(&test_DW.obj_p), 18, 0, 12 },

  { (char_T *)(&test_DW.obj_km), 17, 0, 1 },

  { (char_T *)(&test_DW.obj_l), 16, 0, 2 },

  { (char_T *)(&test_DW.Delay_DSTATE), 0, 0, 24 },

  { (char_T *)(&test_DW.Scope_time2_PWORK.LoggedData), 11, 0, 5 },

  { (char_T *)(&test_DW.DiscreteTimeIntegrator_PrevRese), 2, 0, 6 },

  { (char_T *)(&test_DW.I2CMasterWrite_p.obj), 17, 0, 1 },

  { (char_T *)(&test_DW.I2CMasterWrite_p.objisempty), 8, 0, 1 },

  { (char_T *)(&test_DW.I2CMasterWrite.obj), 17, 0, 1 },

  { (char_T *)(&test_DW.I2CMasterWrite.objisempty), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  12U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&test_P.CompareToConstant1_const), 0, 0, 106 },

  { (char_T *)(&test_P.Switch_Threshold), 15, 0, 6 },

  { (char_T *)(&test_P.Gain_Gain_g), 14, 0, 6 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] test_dt.h */
