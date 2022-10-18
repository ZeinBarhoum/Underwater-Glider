/*
 * File: test_pwm.c
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
#include "test_pwm_dt.h"

/* Block states (default storage) */
DW_test_pwm_T test_pwm_DW;

/* Real-time model */
static RT_MODEL_test_pwm_T test_pwm_M_;
RT_MODEL_test_pwm_T *const test_pwm_M = &test_pwm_M_;

/* Model step function */
void test_pwm_step(void)
{
  real_T rtb_Saturation;
  real_T rtb_Saturation_0;
  real_T tmp;
  boolean_T rtb_Compare;

  /* Signum: '<Root>/Sign' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (test_pwm_P.Constant_Value < 0.0) {
    tmp = -1.0;
  } else if (test_pwm_P.Constant_Value > 0.0) {
    tmp = 1.0;
  } else if (test_pwm_P.Constant_Value == 0.0) {
    tmp = 0.0;
  } else {
    tmp = (rtNaN);
  }

  /* End of Signum: '<Root>/Sign' */

  /* MATLABSystem: '<Root>/Digital Write' incorporates:
   *  Constant: '<S2>/Constant'
   *  RelationalOperator: '<S2>/Compare'
   */
  MW_digitalIO_write(test_pwm_DW.obj_i.MW_DIGITALIO_HANDLE, tmp >=
                     test_pwm_P.CompareToConstant1_const);

  /* Abs: '<Root>/Abs' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_Saturation = fabs(test_pwm_P.Constant_Value);

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Saturation > test_pwm_P.Saturation_UpperSat) {
    rtb_Saturation = test_pwm_P.Saturation_UpperSat;
  } else {
    if (rtb_Saturation < test_pwm_P.Saturation_LowerSat) {
      rtb_Saturation = test_pwm_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   *  Delay: '<Root>/Delay'
   */
  rtb_Compare = (test_pwm_DW.Delay_DSTATE >= test_pwm_P.CompareToConstant_const);

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   */
  if (rtb_Compare && (test_pwm_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
    test_pwm_DW.DiscreteTimeIntegrator_DSTATE =
      test_pwm_P.DiscreteTimeIntegrator_IC;
  }

  test_pwm_DW.Delay_DSTATE = test_pwm_DW.DiscreteTimeIntegrator_DSTATE;

  /* End of DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */

  /* MATLAB Function: '<Root>/MATLAB Function' */
  if (rtb_Saturation < 260.0) {
    rtb_Saturation_0 = 0.95;
  } else if (rtb_Saturation < 550.0) {
    rtb_Saturation_0 = 0.7;
  } else if (rtb_Saturation < 650.0) {
    rtb_Saturation_0 = 0.6;
  } else {
    rtb_Saturation_0 = 0.4;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* Step: '<Root>/Step' */
  if (test_pwm_M->Timing.taskTime0 < test_pwm_P.Step_Time) {
    tmp = test_pwm_P.Step_Y0;
  } else {
    tmp = test_pwm_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Product: '<Root>/Product'
   *  RelationalOperator: '<Root>/Relational Operator'
   *  Rounding: '<Root>/Rounding Function'
   *  Sum: '<Root>/Sum1'
   */
  tmp = floor((real_T)(test_pwm_DW.Delay_DSTATE - floor(test_pwm_DW.Delay_DSTATE)
                       >= rtb_Saturation_0) * tmp);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  /* MATLABSystem: '<Root>/Digital Write1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  MW_digitalIO_write(test_pwm_DW.obj.MW_DIGITALIO_HANDLE, (tmp < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp) != 0);

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  test_pwm_DW.DiscreteTimeIntegrator_DSTATE +=
    test_pwm_P.DiscreteTimeIntegrator_gainval * rtb_Saturation;
  test_pwm_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)rtb_Compare;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.0002s, 0.0s] */
    rtExtModeUpload(0, (real_T)test_pwm_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0002s, 0.0s] */
    if ((rtmGetTFinal(test_pwm_M)!=-1) &&
        !((rtmGetTFinal(test_pwm_M)-test_pwm_M->Timing.taskTime0) >
          test_pwm_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(test_pwm_M, "Simulation finished");
    }

    if (rtmGetStopRequested(test_pwm_M)) {
      rtmSetErrorStatus(test_pwm_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  test_pwm_M->Timing.taskTime0 =
    ((time_T)(++test_pwm_M->Timing.clockTick0)) * test_pwm_M->Timing.stepSize0;
}

/* Model initialize function */
void test_pwm_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(test_pwm_M, 2000.0);
  test_pwm_M->Timing.stepSize0 = 0.0002;

  /* External mode info */
  test_pwm_M->Sizes.checksums[0] = (3361238182U);
  test_pwm_M->Sizes.checksums[1] = (3009219132U);
  test_pwm_M->Sizes.checksums[2] = (2401397713U);
  test_pwm_M->Sizes.checksums[3] = (1646843003U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    test_pwm_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(test_pwm_M->extModeInfo,
      &test_pwm_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(test_pwm_M->extModeInfo, test_pwm_M->Sizes.checksums);
    rteiSetTPtr(test_pwm_M->extModeInfo, rtmGetTPtr(test_pwm_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    test_pwm_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    beagleboneblue_bbblueDigitalW_T *obj;

    /* InitializeConditions for Delay: '<Root>/Delay' */
    test_pwm_DW.Delay_DSTATE = test_pwm_P.Delay_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
    test_pwm_DW.DiscreteTimeIntegrator_DSTATE =
      test_pwm_P.DiscreteTimeIntegrator_IC;
    test_pwm_DW.DiscreteTimeIntegrator_PrevRese = 2;

    /* Start for MATLABSystem: '<Root>/Digital Write' */
    test_pwm_DW.obj_i.matlabCodegenIsDeleted = true;
    test_pwm_DW.obj_i.isInitialized = 0;
    test_pwm_DW.obj_i.matlabCodegenIsDeleted = false;
    obj = &test_pwm_DW.obj_i;
    test_pwm_DW.obj_i.isSetupComplete = false;
    test_pwm_DW.obj_i.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(97, 1);
    test_pwm_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write1' */
    test_pwm_DW.obj.matlabCodegenIsDeleted = true;
    test_pwm_DW.obj.isInitialized = 0;
    test_pwm_DW.obj.matlabCodegenIsDeleted = false;
    obj = &test_pwm_DW.obj;
    test_pwm_DW.obj.isSetupComplete = false;
    test_pwm_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(98, 1);
    test_pwm_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void test_pwm_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  if (!test_pwm_DW.obj_i.matlabCodegenIsDeleted) {
    test_pwm_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((test_pwm_DW.obj_i.isInitialized == 1) &&
        test_pwm_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(test_pwm_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  if (!test_pwm_DW.obj.matlabCodegenIsDeleted) {
    test_pwm_DW.obj.matlabCodegenIsDeleted = true;
    if ((test_pwm_DW.obj.isInitialized == 1) && test_pwm_DW.obj.isSetupComplete)
    {
      MW_digitalIO_close(test_pwm_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
