/*
 * File: test.c
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
#include "test_dt.h"

/* Block signals (default storage) */
B_test_T test_B;

/* Block states (default storage) */
DW_test_T test_DW;

/* Real-time model */
static RT_MODEL_test_T test_M_;
RT_MODEL_test_T *const test_M = &test_M_;

/* Forward declaration for local functions */
static void test_quaternionBase_rotmat(real_T q_a, real_T q_b, real_T q_c,
  real_T q_d, real_T r[9]);
static real_T test_rt_remd_snf(real_T u0, real_T u1);
static void test_sind(real_T *x);
static void test_tand(real_T *x);
static void test_cosd(real_T *x);
static void test_SystemCore_setup(beagleboneblue_bbblueMPU9250__T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void test_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(test_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  test_M->Timing.RateInteraction.TID0_1 = (test_M->Timing.TaskCounters.TID[1] ==
    0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (test_M->Timing.TaskCounters.TID[1])++;
  if ((test_M->Timing.TaskCounters.TID[1]) > 499) {/* Sample time: [0.1s, 0.0s] */
    test_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * System initialize for atomic system:
 *    synthesized block
 *    synthesized block
 */
void test_I2CMasterWrite_Init(DW_I2CMasterWrite_test_T *localDW)
{
  MW_I2C_Mode_Type ModeType;
  uint32_T i2cname;
  beagleboneblue_bbblueI2CMaste_T *obj;

  /* Start for MATLABSystem: '<S10>/I2C Master Write' */
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj.isInitialized = 0;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  obj = &localDW->obj;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  ModeType = MW_I2C_MASTER;
  i2cname = 1;
  obj->MW_I2C_HANDLE = MW_I2C_Open(i2cname, ModeType);
  localDW->obj.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(localDW->obj.MW_I2C_HANDLE, localDW->obj.BusSpeed);
  localDW->obj.isSetupComplete = true;
}

/*
 * Output and update for atomic system:
 *    synthesized block
 *    synthesized block
 */
void test_I2CMasterWrite(real_T rtu_0, DW_I2CMasterWrite_test_T *localDW)
{
  real_T b_x;
  int32_T i;
  uint8_T b_SwappedDataBytes[9];
  uint8_T SwappedDataBytes[8];
  uint8_T xtmp;

  /* MATLABSystem: '<S10>/I2C Master Write' */
  memcpy((void *)&SwappedDataBytes[0], (void *)&rtu_0, (uint32_T)((size_t)8 *
          sizeof(uint8_T)));
  xtmp = SwappedDataBytes[0];
  SwappedDataBytes[0] = SwappedDataBytes[7];
  SwappedDataBytes[7] = xtmp;
  xtmp = SwappedDataBytes[1];
  SwappedDataBytes[1] = SwappedDataBytes[6];
  SwappedDataBytes[6] = xtmp;
  xtmp = SwappedDataBytes[2];
  SwappedDataBytes[2] = SwappedDataBytes[5];
  SwappedDataBytes[5] = xtmp;
  xtmp = SwappedDataBytes[3];
  SwappedDataBytes[3] = SwappedDataBytes[4];
  SwappedDataBytes[4] = xtmp;
  memcpy((void *)&b_x, (void *)&SwappedDataBytes[0], (uint32_T)((size_t)1 *
          sizeof(real_T)));
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_x, (uint32_T)((size_t)8 *
          sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 107U;
  for (i = 0; i < 8; i++) {
    b_SwappedDataBytes[i + 1] = SwappedDataBytes[i];
  }

  MW_I2C_MasterWrite(localDW->obj.MW_I2C_HANDLE, 105U, &b_SwappedDataBytes[0],
                     9U, false, false);

  /* End of MATLABSystem: '<S10>/I2C Master Write' */
}

/*
 * Termination for atomic system:
 *    synthesized block
 *    synthesized block
 */
void test_I2CMasterWrite_Term(DW_I2CMasterWrite_test_T *localDW)
{
  /* Terminate for MATLABSystem: '<S10>/I2C Master Write' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      MW_I2C_Close(localDW->obj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S10>/I2C Master Write' */
}

/*
 * Output and update for atomic system:
 *    '<S24>/MATLAB Function'
 *    '<S25>/MATLAB Function'
 */
void test_MATLABFunction(const real_T rtu_u[3], real_T rty_y[3])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;
  absxk = fabs(rtu_u[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = fabs(rtu_u[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(rtu_u[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  y = scale * sqrt(y);
  rty_y[0] = rtu_u[0] / y;
  rty_y[1] = rtu_u[1] / y;
  rty_y[2] = rtu_u[2] / y;
}

/* Function for MATLAB Function: '<S20>/MATLAB Function2' */
static void test_quaternionBase_rotmat(real_T q_a, real_T q_b, real_T q_c,
  real_T q_d, real_T r[9])
{
  test_B.n = sqrt(((q_a * q_a + q_b * q_b) + q_c * q_c) + q_d * q_d);
  q_a /= test_B.n;
  q_b /= test_B.n;
  q_c /= test_B.n;
  q_d /= test_B.n;
  test_B.n = q_a * q_b * 2.0;
  test_B.ac2 = q_a * q_c * 2.0;
  test_B.ad2 = q_a * q_d * 2.0;
  test_B.bc2 = q_b * q_c * 2.0;
  test_B.bd2 = q_b * q_d * 2.0;
  test_B.cd2 = q_c * q_d * 2.0;
  test_B.aasq = q_a * q_a * 2.0 - 1.0;
  r[0] = q_b * q_b * 2.0 + test_B.aasq;
  r[3] = test_B.bc2 + test_B.ad2;
  r[6] = test_B.bd2 - test_B.ac2;
  r[1] = test_B.bc2 - test_B.ad2;
  r[4] = q_c * q_c * 2.0 + test_B.aasq;
  r[7] = test_B.cd2 + test_B.n;
  r[2] = test_B.bd2 + test_B.ac2;
  r[5] = test_B.cd2 - test_B.n;
  r[8] = q_d * q_d * 2.0 + test_B.aasq;
}

static real_T test_rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      test_B.u1 = ceil(u1);
    } else {
      test_B.u1 = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != test_B.u1)) {
      test_B.u1 = fabs(u0 / u1);
      if (!(fabs(test_B.u1 - floor(test_B.u1 + 0.5)) > DBL_EPSILON * test_B.u1))
      {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S19>/MATLAB Function' */
static void test_sind(real_T *x)
{
  int8_T n;
  if (rtIsInf(*x) || rtIsNaN(*x)) {
    *x = (rtNaN);
  } else {
    test_B.c_x = test_rt_remd_snf(*x, 360.0);
    test_B.absx_c = fabs(test_B.c_x);
    if (test_B.absx_c > 180.0) {
      if (test_B.c_x > 0.0) {
        test_B.c_x -= 360.0;
      } else {
        test_B.c_x += 360.0;
      }

      test_B.absx_c = fabs(test_B.c_x);
    }

    if (test_B.absx_c <= 45.0) {
      test_B.c_x *= 0.017453292519943295;
      n = 0;
    } else if (test_B.absx_c <= 135.0) {
      if (test_B.c_x > 0.0) {
        test_B.c_x = (test_B.c_x - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        test_B.c_x = (test_B.c_x + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (test_B.c_x > 0.0) {
      test_B.c_x = (test_B.c_x - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      test_B.c_x = (test_B.c_x + 180.0) * 0.017453292519943295;
      n = -2;
    }

    switch (n) {
     case 0:
      *x = sin(test_B.c_x);
      break;

     case 1:
      *x = cos(test_B.c_x);
      break;

     case -1:
      *x = -cos(test_B.c_x);
      break;

     default:
      *x = -sin(test_B.c_x);
      break;
    }
  }
}

/* Function for MATLAB Function: '<S19>/MATLAB Function' */
static void test_tand(real_T *x)
{
  int8_T n;
  if (rtIsInf(*x) || rtIsNaN(*x)) {
    *x = (rtNaN);
  } else {
    test_B.b_x_f = test_rt_remd_snf(*x, 360.0);
    test_B.absx_g = fabs(test_B.b_x_f);
    if (test_B.absx_g > 180.0) {
      if (test_B.b_x_f > 0.0) {
        test_B.b_x_f -= 360.0;
      } else {
        test_B.b_x_f += 360.0;
      }

      test_B.absx_g = fabs(test_B.b_x_f);
    }

    if (test_B.absx_g <= 45.0) {
      test_B.b_x_f *= 0.017453292519943295;
      n = 0;
    } else if (test_B.absx_g <= 135.0) {
      if (test_B.b_x_f > 0.0) {
        test_B.b_x_f = (test_B.b_x_f - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        test_B.b_x_f = (test_B.b_x_f + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (test_B.b_x_f > 0.0) {
      test_B.b_x_f = (test_B.b_x_f - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      test_B.b_x_f = (test_B.b_x_f + 180.0) * 0.017453292519943295;
      n = -2;
    }

    *x = tan(test_B.b_x_f);
    if ((n == 1) || (n == -1)) {
      test_B.b_x_f = 1.0 / *x;
      *x = -(1.0 / *x);
      if (rtIsInf(*x) && (n == 1)) {
        *x = test_B.b_x_f;
      }
    }
  }
}

/* Function for MATLAB Function: '<S19>/MATLAB Function' */
static void test_cosd(real_T *x)
{
  int8_T n;
  if (rtIsInf(*x) || rtIsNaN(*x)) {
    *x = (rtNaN);
  } else {
    test_B.b_x = test_rt_remd_snf(*x, 360.0);
    test_B.absx = fabs(test_B.b_x);
    if (test_B.absx > 180.0) {
      if (test_B.b_x > 0.0) {
        test_B.b_x -= 360.0;
      } else {
        test_B.b_x += 360.0;
      }

      test_B.absx = fabs(test_B.b_x);
    }

    if (test_B.absx <= 45.0) {
      test_B.b_x *= 0.017453292519943295;
      n = 0;
    } else if (test_B.absx <= 135.0) {
      if (test_B.b_x > 0.0) {
        test_B.b_x = (test_B.b_x - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        test_B.b_x = (test_B.b_x + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (test_B.b_x > 0.0) {
      test_B.b_x = (test_B.b_x - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      test_B.b_x = (test_B.b_x + 180.0) * 0.017453292519943295;
      n = -2;
    }

    switch (n) {
     case 0:
      *x = cos(test_B.b_x);
      break;

     case 1:
      *x = -sin(test_B.b_x);
      break;

     case -1:
      *x = sin(test_B.b_x);
      break;

     default:
      *x = -cos(test_B.b_x);
      break;
    }
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

static void test_SystemCore_setup(beagleboneblue_bbblueMPU9250__T *obj)
{
  uint8_T SwappedDataBytes[2];
  uint8_T b_SwappedDataBytes[2];
  uint8_T SwappedDataBytes_0;
  uint8_T regSet;
  uint8_T status;
  boolean_T exitg1;
  obj->isInitialized = 1;
  test_B.ModeType_m = MW_I2C_MASTER;
  test_B.i2cname_c = 2;
  obj->i2cObjmpu.MW_I2C_HANDLE = MW_I2C_Open(test_B.i2cname_c, test_B.ModeType_m);
  obj->i2cObjmpu.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cObjmpu.MW_I2C_HANDLE, obj->i2cObjmpu.BusSpeed);
  test_B.ModeType_m = MW_I2C_MASTER;
  test_B.i2cname_c = 2;
  obj->i2cObjak8963.MW_I2C_HANDLE = MW_I2C_Open(test_B.i2cname_c,
    test_B.ModeType_m);
  obj->i2cObjak8963.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cObjak8963.MW_I2C_HANDLE, obj->i2cObjak8963.BusSpeed);
  regSet = 128U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (uint32_T)((size_t)1 *
          sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 107U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &SwappedDataBytes[0],
                     2U, false, false);
  regSet = 0U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (uint32_T)((size_t)1 *
          sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 107U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &SwappedDataBytes[0],
                     2U, false, false);
  MW_usleep(MAX_uint16_T);
  status = 117U;
  memcpy((void *)&SwappedDataBytes_0, (void *)&status, (uint32_T)((size_t)1 *
          sizeof(uint8_T)));
  status = MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U,
    &SwappedDataBytes_0, 1U, true, false);
  if (0 == status) {
    MW_I2C_MasterRead(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &status, 1U, false,
                      true);
    memcpy((void *)&regSet, (void *)&status, (uint32_T)((size_t)1 * sizeof
            (uint8_T)));
  } else {
    regSet = 0U;
  }

  obj->MPUConnect = (regSet == 113);
  if (obj->MPUConnect) {
    regSet = 0U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (uint32_T)((size_t)1
            * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 25U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &SwappedDataBytes[0],
                       2U, false, false);
    regSet = 3U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (uint32_T)((size_t)1
            * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 29U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &SwappedDataBytes[0],
                       2U, false, false);
    status = 28U;
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U,
      &SwappedDataBytes_0, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &status, 1U, false,
                        true);
      memcpy((void *)&regSet, (void *)&status, (uint32_T)((size_t)1 * sizeof
              (uint8_T)));
    } else {
      regSet = 0U;
    }

    regSet = (uint8_T)(regSet & 231);
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (uint32_T)((size_t)1
            * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 28U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &SwappedDataBytes[0],
                       2U, false, false);
    status = 27U;
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U,
      &SwappedDataBytes_0, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &status, 1U, false,
                        true);
      memcpy((void *)&regSet, (void *)&status, (uint32_T)((size_t)1 * sizeof
              (uint8_T)));
    } else {
      regSet = 0U;
    }

    regSet = (uint8_T)(regSet & 228);
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (uint32_T)((size_t)1
            * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 27U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &SwappedDataBytes[0],
                       2U, false, false);
    status = 26U;
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U,
      &SwappedDataBytes_0, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &status, 1U, false,
                        true);
      memcpy((void *)&regSet, (void *)&status, (uint32_T)((size_t)1 * sizeof
              (uint8_T)));
    } else {
      regSet = 0U;
    }

    regSet = (uint8_T)((regSet & 248) | 3);
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (uint32_T)((size_t)1
            * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 26U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &SwappedDataBytes[0],
                       2U, false, false);
    regSet = 0U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (uint32_T)((size_t)1
            * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 106U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &SwappedDataBytes[0],
                       2U, false, false);
    MW_usleep(3000);
    regSet = 130U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (uint32_T)((size_t)1
            * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 55U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &SwappedDataBytes[0],
                       2U, false, false);
    status = 0U;
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(obj->i2cObjak8963.MW_I2C_HANDLE, 12U,
      &SwappedDataBytes_0, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(obj->i2cObjak8963.MW_I2C_HANDLE, 12U, &status, 1U, false,
                        true);
      memcpy((void *)&regSet, (void *)&status, (uint32_T)((size_t)1 * sizeof
              (uint8_T)));
    } else {
      regSet = 0U;
    }

    obj->AK8963Connect = (regSet == 72);
    test_B.temp[0] = 0U;
    test_B.temp[1] = 0U;
    test_B.temp[2] = 0U;
    if (obj->AK8963Connect) {
      regSet = 0U;
      memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (uint32_T)((size_t)
              1 * sizeof(uint8_T)));
      b_SwappedDataBytes[0] = 10U;
      memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
             (uint32_T)((size_t)2 * sizeof(uint8_T)));
      MW_I2C_MasterWrite(obj->i2cObjak8963.MW_I2C_HANDLE, 12U,
                         &SwappedDataBytes[0], 2U, false, false);
      MW_usleep(1000);
      regSet = 15U;
      memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (uint32_T)((size_t)
              1 * sizeof(uint8_T)));
      b_SwappedDataBytes[0] = 10U;
      memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
             (uint32_T)((size_t)2 * sizeof(uint8_T)));
      MW_I2C_MasterWrite(obj->i2cObjak8963.MW_I2C_HANDLE, 12U,
                         &SwappedDataBytes[0], 2U, false, false);
      MW_usleep(1000);
      status = 16U;
      memcpy((void *)&SwappedDataBytes_0, (void *)&status, (uint32_T)((size_t)1 *
              sizeof(uint8_T)));
      status = MW_I2C_MasterWrite(obj->i2cObjak8963.MW_I2C_HANDLE, 12U,
        &SwappedDataBytes_0, 1U, true, false);
      if (0 == status) {
        MW_I2C_MasterRead(obj->i2cObjak8963.MW_I2C_HANDLE, 12U,
                          &test_B.output_raw_l[0], 3U, false, true);
        memcpy((void *)&test_B.temp[0], (void *)&test_B.output_raw_l[0],
               (uint32_T)((size_t)3 * sizeof(uint8_T)));
      } else {
        test_B.temp[0] = 0U;
        test_B.temp[1] = 0U;
        test_B.temp[2] = 0U;
      }

      regSet = 0U;
      memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (uint32_T)((size_t)
              1 * sizeof(uint8_T)));
      b_SwappedDataBytes[0] = 10U;
      memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
             (uint32_T)((size_t)2 * sizeof(uint8_T)));
      MW_I2C_MasterWrite(obj->i2cObjak8963.MW_I2C_HANDLE, 12U,
                         &SwappedDataBytes[0], 2U, false, false);
      MW_usleep(100);
      regSet = 22U;
      memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (uint32_T)((size_t)
              1 * sizeof(uint8_T)));
      b_SwappedDataBytes[0] = 10U;
      memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
             (uint32_T)((size_t)2 * sizeof(uint8_T)));
      MW_I2C_MasterWrite(obj->i2cObjak8963.MW_I2C_HANDLE, 12U,
                         &SwappedDataBytes[0], 2U, false, false);
      MW_usleep(100);
    }

    test_B.x_tmp[0] = test_B.temp[0];
    test_B.x_tmp[1] = test_B.temp[1];
    test_B.x_tmp[2] = test_B.temp[2];
    test_B.idx = 0;
    test_B.b_ii = 1;
    exitg1 = false;
    while ((!exitg1) && (test_B.b_ii - 1 < 3)) {
      if (test_B.x_tmp[test_B.b_ii - 1] == 0) {
        test_B.idx++;
        test_B.ii_data[test_B.idx - 1] = test_B.b_ii;
        if (test_B.idx >= 3) {
          exitg1 = true;
        } else {
          test_B.b_ii++;
        }
      } else {
        test_B.b_ii++;
      }
    }

    if (1 > test_B.idx) {
      test_B.idx = 0;
    }

    for (test_B.b_ii = 0; test_B.b_ii < test_B.idx; test_B.b_ii++) {
      test_B.ii_data_n = test_B.ii_data[test_B.b_ii];
      test_B.i_data[test_B.b_ii] = test_B.ii_data_n;
      test_B.ii_data[test_B.b_ii] = test_B.ii_data_n;
    }

    if (test_B.idx == 0) {
      test_B.y_p = 0.0;
    } else {
      test_B.y_p = test_B.i_data[0];
      for (test_B.b_ii = 2; test_B.b_ii <= test_B.idx; test_B.b_ii++) {
        test_B.y_p += (real_T)test_B.i_data[test_B.b_ii - 1];
      }
    }

    if (test_B.y_p != 6.0) {
      obj->AK8963SensitivityAdj[0] = ((real_T)test_B.temp[0] - 128.0) / 256.0 +
        1.0;
      obj->AK8963SensitivityAdj[1] = ((real_T)test_B.temp[1] - 128.0) / 256.0 +
        1.0;
      obj->AK8963SensitivityAdj[2] = ((real_T)test_B.temp[2] - 128.0) / 256.0 +
        1.0;
    }
  }

  obj->TunablePropsChanged = false;
}

/* Model step function for TID0 */
void test_step0(void)                  /* Sample time: [0.0002s, 0.0s] */
{
  real_T rtb_Step;
  real_T rtb_Step_0;
  real_T tmp;
  boolean_T rtb_Compare;

  {                                    /* Sample time: [0.0002s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<Root>/Rate Transition' */
  if (test_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition: '<Root>/Rate Transition' */
    test_B.RateTransition = test_DW.RateTransition_Buffer0;
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Pitch_desired'
   */
  rtb_Step = test_P.Pitch_desired_Value - test_B.RateTransition;

  /* DeadZone: '<Root>/Dead Zone' */
  if (rtb_Step > test_P.DeadZone_End) {
    rtb_Step -= test_P.DeadZone_End;
  } else if (rtb_Step >= test_P.DeadZone_Start) {
    rtb_Step = 0.0;
  } else {
    rtb_Step -= test_P.DeadZone_Start;
  }

  /* End of DeadZone: '<Root>/Dead Zone' */

  /* Gain: '<Root>/Gain' */
  rtb_Step *= test_P.Gain_Gain_k;

  /* Signum: '<Root>/Sign' */
  if (rtb_Step < 0.0) {
    rtb_Step_0 = -1.0;
  } else if (rtb_Step > 0.0) {
    rtb_Step_0 = 1.0;
  } else if (rtb_Step == 0.0) {
    rtb_Step_0 = 0.0;
  } else {
    rtb_Step_0 = (rtNaN);
  }

  /* End of Signum: '<Root>/Sign' */

  /* MATLABSystem: '<Root>/Digital Write' incorporates:
   *  Constant: '<S2>/Constant'
   *  RelationalOperator: '<S2>/Compare'
   */
  MW_digitalIO_write(test_DW.obj_ma.MW_DIGITALIO_HANDLE, rtb_Step_0 >=
                     test_P.CompareToConstant1_const);

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   *  Delay: '<Root>/Delay'
   */
  rtb_Compare = (test_DW.Delay_DSTATE >= test_P.CompareToConstant_const);

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   */
  if (rtb_Compare && (test_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
    test_DW.DiscreteTimeIntegrator_DSTATE = test_P.DiscreteTimeIntegrator_IC_a;
  }

  test_DW.Delay_DSTATE = test_DW.DiscreteTimeIntegrator_DSTATE;

  /* End of DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */

  /* Abs: '<Root>/Abs' */
  rtb_Step = fabs(rtb_Step);

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Step > test_P.Saturation_UpperSat) {
    rtb_Step = test_P.Saturation_UpperSat;
  } else {
    if (rtb_Step < test_P.Saturation_LowerSat) {
      rtb_Step = test_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* MATLAB Function: '<Root>/MATLAB Function' */
  if (rtb_Step < 260.0) {
    rtb_Step_0 = 0.95;
  } else if (rtb_Step < 550.0) {
    rtb_Step_0 = 0.7;
  } else if (rtb_Step < 650.0) {
    rtb_Step_0 = 0.6;
  } else {
    rtb_Step_0 = 0.4;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* Step: '<Root>/Step' */
  if (test_M->Timing.taskTime0 < test_P.Step_Time) {
    tmp = test_P.Step_Y0;
  } else {
    tmp = test_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Product: '<Root>/Product'
   *  RelationalOperator: '<Root>/Relational Operator'
   *  Rounding: '<Root>/Rounding Function'
   *  Sum: '<Root>/Sum1'
   */
  tmp = floor((real_T)(test_DW.Delay_DSTATE - floor(test_DW.Delay_DSTATE) >=
                       rtb_Step_0) * tmp);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  /* MATLABSystem: '<Root>/Digital Write1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  MW_digitalIO_write(test_DW.obj_l.MW_DIGITALIO_HANDLE, (tmp < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp) != 0);

  /* Constant: '<Root>/Mass_desired' */
  test_B.Mass_desired = test_P.Mass_desired_Value;

  /* Constant: '<Root>/Time_desired' */
  test_B.Time_desired = test_P.Time_desired_Value;

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  test_DW.DiscreteTimeIntegrator_DSTATE +=
    test_P.DiscreteTimeIntegrator_gainva_p * rtb_Step;
  test_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)rtb_Compare;

  /* Matfile logging */
  rt_UpdateTXYLogVars(test_M->rtwLogInfo, (&test_M->Timing.taskTime0));

  /* External mode */
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, (real_T)test_M->Timing.taskTime0);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0002s, 0.0s] */
    if ((rtmGetTFinal(test_M)!=-1) &&
        !((rtmGetTFinal(test_M)-test_M->Timing.taskTime0) >
          test_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(test_M, "Simulation finished");
    }

    if (rtmGetStopRequested(test_M)) {
      rtmSetErrorStatus(test_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  test_M->Timing.taskTime0 =
    ((time_T)(++test_M->Timing.clockTick0)) * test_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void test_step1(void)                  /* Sample time: [0.1s, 0.0s] */
{
  beagleboneblue_bbblueMPU9250__T *obj;
  int32_T R_tmp;
  int16_T rtb_Sum3;
  int8_T output;
  int8_T output_0;
  uint8_T SwappedDataBytes;
  uint8_T status;
  uint8_T xtmp;
  boolean_T y[3];
  boolean_T exitg1;
  boolean_T guard1 = false;
  boolean_T nanPageIdx;

  /* Reset subsysRan breadcrumbs */
  srClearBC(test_DW.IfActionSubsystem2_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(test_DW.IfActionSubsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(test_DW.IfActionSubsystem3_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(test_DW.Intialization_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(test_DW.Running_SubsysRanBC);

  /* DigitalClock: '<S4>/Digital Clock' */
  test_B.DigitalClock = ((test_M->Timing.clockTick1) * 0.1);

  /* MATLABSystem: '<S36>/I2C Master Read' */
  if (test_DW.obj_f.SampleTime != test_P.I2CMasterRead_SampleTime_e) {
    test_DW.obj_f.SampleTime = test_P.I2CMasterRead_SampleTime_e;
  }

  status = 67U;
  status = MW_I2C_MasterWrite(test_DW.obj_f.MW_I2C_HANDLE, 105U, &status, 1U,
    true, false);
  if (0 == status) {
    MW_I2C_MasterRead(test_DW.obj_f.MW_I2C_HANDLE, 105U, &status, 1U, false,
                      true);
    memcpy((void *)&output, (void *)&status, (uint32_T)((size_t)1 * sizeof
            (int8_T)));
  } else {
    output = 0;
  }

  /* MATLABSystem: '<S36>/I2C Master Read1' */
  if (test_DW.obj_m.SampleTime != test_P.I2CMasterRead1_SampleTime_c) {
    test_DW.obj_m.SampleTime = test_P.I2CMasterRead1_SampleTime_c;
  }

  status = 68U;
  status = MW_I2C_MasterWrite(test_DW.obj_m.MW_I2C_HANDLE, 105U, &status, 1U,
    true, false);
  if (0 == status) {
    MW_I2C_MasterRead(test_DW.obj_m.MW_I2C_HANDLE, 105U, &status, 1U, false,
                      true);
    memcpy((void *)&output_0, (void *)&status, (uint32_T)((size_t)1 * sizeof
            (int8_T)));
  } else {
    output_0 = 0;
  }

  /* Sum: '<S36>/Sum' incorporates:
   *  Gain: '<S36>/Gain'
   *  MATLABSystem: '<S36>/I2C Master Read'
   *  MATLABSystem: '<S36>/I2C Master Read1'
   *  Sum: '<S35>/Sum3'
   */
  rtb_Sum3 = (int16_T)((((test_P.Gain_Gain_g * output) << 2) + output_0) >> 2);

  /* Switch: '<S36>/Switch' incorporates:
   *  Constant: '<S36>/Constant'
   *  Constant: '<S36>/Constant1'
   *  Sum: '<S35>/Sum3'
   */
  if (rtb_Sum3 >= test_P.Switch_Threshold) {
    test_B.Gain2_k = test_P.Constant_Value_d;
  } else {
    test_B.Gain2_k = test_P.Constant1_Value_n;
  }

  /* End of Switch: '<S36>/Switch' */

  /* Gain: '<S36>/Gain2' incorporates:
   *  Sum: '<S35>/Sum3'
   *  Sum: '<S36>/Sum1'
   */
  test_B.Gain2 = ((real_T)rtb_Sum3 * 4.0 - test_B.Gain2_k) * test_P.Gain2_Gain_m;

  /* MATLABSystem: '<S36>/I2C Master Read4' */
  if (test_DW.obj_pp.SampleTime != test_P.I2CMasterRead4_SampleTime_h) {
    test_DW.obj_pp.SampleTime = test_P.I2CMasterRead4_SampleTime_h;
  }

  status = 71U;
  status = MW_I2C_MasterWrite(test_DW.obj_pp.MW_I2C_HANDLE, 105U, &status, 1U,
    true, false);
  if (0 == status) {
    MW_I2C_MasterRead(test_DW.obj_pp.MW_I2C_HANDLE, 105U, &status, 1U, false,
                      true);
    memcpy((void *)&output, (void *)&status, (uint32_T)((size_t)1 * sizeof
            (int8_T)));
  } else {
    output = 0;
  }

  /* MATLABSystem: '<S36>/I2C Master Read5' */
  if (test_DW.obj_p.SampleTime != test_P.I2CMasterRead5_SampleTime_h) {
    test_DW.obj_p.SampleTime = test_P.I2CMasterRead5_SampleTime_h;
  }

  status = 72U;
  status = MW_I2C_MasterWrite(test_DW.obj_p.MW_I2C_HANDLE, 105U, &status, 1U,
    true, false);
  if (0 == status) {
    MW_I2C_MasterRead(test_DW.obj_p.MW_I2C_HANDLE, 105U, &status, 1U, false,
                      true);
    memcpy((void *)&output_0, (void *)&status, (uint32_T)((size_t)1 * sizeof
            (int8_T)));
  } else {
    output_0 = 0;
  }

  /* Sum: '<S36>/Sum6' incorporates:
   *  Gain: '<S36>/Gain4'
   *  MATLABSystem: '<S36>/I2C Master Read4'
   *  MATLABSystem: '<S36>/I2C Master Read5'
   *  Sum: '<S35>/Sum3'
   */
  rtb_Sum3 = (int16_T)((((test_P.Gain4_Gain * output) << 2) + output_0) >> 2);

  /* Switch: '<S36>/Switch2' incorporates:
   *  Constant: '<S36>/Constant6'
   *  Constant: '<S36>/Constant7'
   *  Sum: '<S35>/Sum3'
   */
  if (rtb_Sum3 >= test_P.Switch2_Threshold) {
    test_B.Gain2_k = test_P.Constant6_Value_a;
  } else {
    test_B.Gain2_k = test_P.Constant7_Value_i;
  }

  /* End of Switch: '<S36>/Switch2' */

  /* Gain: '<S36>/Gain5' incorporates:
   *  Sum: '<S35>/Sum3'
   *  Sum: '<S36>/Sum7'
   */
  test_B.Gain5 = ((real_T)rtb_Sum3 * 4.0 - test_B.Gain2_k) * test_P.Gain5_Gain;

  /* MATLABSystem: '<S36>/I2C Master Read2' */
  if (test_DW.obj_k.SampleTime != test_P.I2CMasterRead2_SampleTime_i) {
    test_DW.obj_k.SampleTime = test_P.I2CMasterRead2_SampleTime_i;
  }

  status = 69U;
  status = MW_I2C_MasterWrite(test_DW.obj_k.MW_I2C_HANDLE, 105U, &status, 1U,
    true, false);
  if (0 == status) {
    MW_I2C_MasterRead(test_DW.obj_k.MW_I2C_HANDLE, 105U, &status, 1U, false,
                      true);
    memcpy((void *)&output, (void *)&status, (uint32_T)((size_t)1 * sizeof
            (int8_T)));
  } else {
    output = 0;
  }

  /* MATLABSystem: '<S36>/I2C Master Read3' */
  if (test_DW.obj_g.SampleTime != test_P.I2CMasterRead3_SampleTime_m) {
    test_DW.obj_g.SampleTime = test_P.I2CMasterRead3_SampleTime_m;
  }

  status = 70U;
  status = MW_I2C_MasterWrite(test_DW.obj_g.MW_I2C_HANDLE, 105U, &status, 1U,
    true, false);
  if (0 == status) {
    MW_I2C_MasterRead(test_DW.obj_g.MW_I2C_HANDLE, 105U, &status, 1U, false,
                      true);
    memcpy((void *)&output_0, (void *)&status, (uint32_T)((size_t)1 * sizeof
            (int8_T)));
  } else {
    output_0 = 0;
  }

  /* Sum: '<S36>/Sum3' incorporates:
   *  Gain: '<S36>/Gain1'
   *  MATLABSystem: '<S36>/I2C Master Read2'
   *  MATLABSystem: '<S36>/I2C Master Read3'
   *  Sum: '<S35>/Sum3'
   */
  rtb_Sum3 = (int16_T)((((test_P.Gain1_Gain_c * output) << 2) + output_0) >> 2);

  /* Switch: '<S36>/Switch1' incorporates:
   *  Constant: '<S36>/Constant3'
   *  Constant: '<S36>/Constant4'
   *  Sum: '<S35>/Sum3'
   */
  if (rtb_Sum3 >= test_P.Switch1_Threshold) {
    test_B.Gain2_k = test_P.Constant3_Value_a;
  } else {
    test_B.Gain2_k = test_P.Constant4_Value_f;
  }

  /* End of Switch: '<S36>/Switch1' */

  /* Gain: '<S36>/Gain3' incorporates:
   *  Sum: '<S35>/Sum3'
   *  Sum: '<S36>/Sum4'
   */
  test_B.Gain3 = ((real_T)rtb_Sum3 * 4.0 - test_B.Gain2_k) * test_P.Gain3_Gain;

  /* MATLABSystem: '<S35>/I2C Master Read' */
  if (test_DW.obj_c.SampleTime != test_P.I2CMasterRead_SampleTime) {
    test_DW.obj_c.SampleTime = test_P.I2CMasterRead_SampleTime;
  }

  status = 59U;
  status = MW_I2C_MasterWrite(test_DW.obj_c.MW_I2C_HANDLE, 105U, &status, 1U,
    true, false);
  if (0 == status) {
    MW_I2C_MasterRead(test_DW.obj_c.MW_I2C_HANDLE, 105U, &status, 1U, false,
                      true);
    memcpy((void *)&output, (void *)&status, (uint32_T)((size_t)1 * sizeof
            (int8_T)));
  } else {
    output = 0;
  }

  /* MATLABSystem: '<S35>/I2C Master Read1' */
  if (test_DW.obj_pu.SampleTime != test_P.I2CMasterRead1_SampleTime) {
    test_DW.obj_pu.SampleTime = test_P.I2CMasterRead1_SampleTime;
  }

  status = 60U;
  status = MW_I2C_MasterWrite(test_DW.obj_pu.MW_I2C_HANDLE, 105U, &status, 1U,
    true, false);
  if (0 == status) {
    MW_I2C_MasterRead(test_DW.obj_pu.MW_I2C_HANDLE, 105U, &status, 1U, false,
                      true);
    memcpy((void *)&output_0, (void *)&status, (uint32_T)((size_t)1 * sizeof
            (int8_T)));
  } else {
    output_0 = 0;
  }

  /* Sum: '<S35>/Sum' incorporates:
   *  Gain: '<S35>/Gain'
   *  MATLABSystem: '<S35>/I2C Master Read'
   *  MATLABSystem: '<S35>/I2C Master Read1'
   *  Sum: '<S35>/Sum3'
   */
  rtb_Sum3 = (int16_T)((((test_P.Gain_Gain_f * output) << 2) + output_0) >> 2);

  /* Switch: '<S35>/Switch' incorporates:
   *  Constant: '<S35>/Constant'
   *  Constant: '<S35>/Constant1'
   *  Sum: '<S35>/Sum3'
   */
  if (rtb_Sum3 >= test_P.Switch_Threshold_j) {
    test_B.Gain2_k = test_P.Constant_Value_a;
  } else {
    test_B.Gain2_k = test_P.Constant1_Value_a;
  }

  /* End of Switch: '<S35>/Switch' */

  /* Gain: '<S35>/Gain2' incorporates:
   *  Sum: '<S35>/Sum1'
   *  Sum: '<S35>/Sum3'
   */
  test_B.Gain2_b = ((real_T)rtb_Sum3 * 4.0 - test_B.Gain2_k) *
    test_P.Gain2_Gain_o;

  /* MATLABSystem: '<S35>/I2C Master Read4' */
  if (test_DW.obj_d.SampleTime != test_P.I2CMasterRead4_SampleTime) {
    test_DW.obj_d.SampleTime = test_P.I2CMasterRead4_SampleTime;
  }

  status = 63U;
  status = MW_I2C_MasterWrite(test_DW.obj_d.MW_I2C_HANDLE, 105U, &status, 1U,
    true, false);
  if (0 == status) {
    MW_I2C_MasterRead(test_DW.obj_d.MW_I2C_HANDLE, 105U, &status, 1U, false,
                      true);
    memcpy((void *)&output, (void *)&status, (uint32_T)((size_t)1 * sizeof
            (int8_T)));
  } else {
    output = 0;
  }

  /* MATLABSystem: '<S35>/I2C Master Read5' */
  if (test_DW.obj_my.SampleTime != test_P.I2CMasterRead5_SampleTime) {
    test_DW.obj_my.SampleTime = test_P.I2CMasterRead5_SampleTime;
  }

  status = 64U;
  status = MW_I2C_MasterWrite(test_DW.obj_my.MW_I2C_HANDLE, 105U, &status, 1U,
    true, false);
  if (0 == status) {
    MW_I2C_MasterRead(test_DW.obj_my.MW_I2C_HANDLE, 105U, &status, 1U, false,
                      true);
    memcpy((void *)&output_0, (void *)&status, (uint32_T)((size_t)1 * sizeof
            (int8_T)));
  } else {
    output_0 = 0;
  }

  /* Sum: '<S35>/Sum6' incorporates:
   *  Gain: '<S35>/Gain4'
   *  MATLABSystem: '<S35>/I2C Master Read4'
   *  MATLABSystem: '<S35>/I2C Master Read5'
   *  Sum: '<S35>/Sum3'
   */
  rtb_Sum3 = (int16_T)((((test_P.Gain4_Gain_d * output) << 2) + output_0) >> 2);

  /* Switch: '<S35>/Switch2' incorporates:
   *  Constant: '<S35>/Constant6'
   *  Constant: '<S35>/Constant7'
   *  Sum: '<S35>/Sum3'
   */
  if (rtb_Sum3 >= test_P.Switch2_Threshold_k) {
    test_B.Gain2_k = test_P.Constant6_Value;
  } else {
    test_B.Gain2_k = test_P.Constant7_Value;
  }

  /* End of Switch: '<S35>/Switch2' */

  /* Gain: '<S35>/Gain5' incorporates:
   *  Sum: '<S35>/Sum3'
   *  Sum: '<S35>/Sum7'
   */
  test_B.Gain5_h = ((real_T)rtb_Sum3 * 4.0 - test_B.Gain2_k) *
    test_P.Gain5_Gain_d;

  /* MATLABSystem: '<S35>/I2C Master Read2' */
  if (test_DW.obj_du.SampleTime != test_P.I2CMasterRead2_SampleTime) {
    test_DW.obj_du.SampleTime = test_P.I2CMasterRead2_SampleTime;
  }

  status = 61U;
  status = MW_I2C_MasterWrite(test_DW.obj_du.MW_I2C_HANDLE, 105U, &status, 1U,
    true, false);
  if (0 == status) {
    MW_I2C_MasterRead(test_DW.obj_du.MW_I2C_HANDLE, 105U, &status, 1U, false,
                      true);
    memcpy((void *)&output, (void *)&status, (uint32_T)((size_t)1 * sizeof
            (int8_T)));
  } else {
    output = 0;
  }

  /* MATLABSystem: '<S35>/I2C Master Read3' */
  if (test_DW.obj_pl.SampleTime != test_P.I2CMasterRead3_SampleTime) {
    test_DW.obj_pl.SampleTime = test_P.I2CMasterRead3_SampleTime;
  }

  status = 62U;
  status = MW_I2C_MasterWrite(test_DW.obj_pl.MW_I2C_HANDLE, 105U, &status, 1U,
    true, false);
  if (0 == status) {
    MW_I2C_MasterRead(test_DW.obj_pl.MW_I2C_HANDLE, 105U, &status, 1U, false,
                      true);
    memcpy((void *)&output_0, (void *)&status, (uint32_T)((size_t)1 * sizeof
            (int8_T)));
  } else {
    output_0 = 0;
  }

  /* Sum: '<S35>/Sum3' incorporates:
   *  Gain: '<S35>/Gain1'
   *  MATLABSystem: '<S35>/I2C Master Read2'
   *  MATLABSystem: '<S35>/I2C Master Read3'
   */
  rtb_Sum3 = (int16_T)((((test_P.Gain1_Gain_i * output) << 2) + output_0) >> 2);

  /* Switch: '<S35>/Switch1' incorporates:
   *  Constant: '<S35>/Constant3'
   *  Constant: '<S35>/Constant4'
   *  Sum: '<S35>/Sum3'
   */
  if (rtb_Sum3 >= test_P.Switch1_Threshold_j) {
    test_B.Gain2_k = test_P.Constant3_Value;
  } else {
    test_B.Gain2_k = test_P.Constant4_Value;
  }

  /* End of Switch: '<S35>/Switch1' */

  /* Gain: '<S35>/Gain3' incorporates:
   *  Sum: '<S35>/Sum3'
   *  Sum: '<S35>/Sum4'
   */
  test_B.Gain3_c = ((real_T)rtb_Sum3 * 4.0 - test_B.Gain2_k) *
    test_P.Gain3_Gain_k;

  /* MATLABSystem: '<S8>/MPU9250' */
  if (test_DW.obj.SampleTime != test_P.MPU9250_SampleTime) {
    test_DW.obj.SampleTime = test_P.MPU9250_SampleTime;
  }

  obj = &test_DW.obj;
  if (test_DW.obj.TunablePropsChanged) {
    test_DW.obj.TunablePropsChanged = false;
  }

  status = 59U;
  memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
          sizeof(uint8_T)));
  status = MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U,
    &SwappedDataBytes, 1U, true, false);
  if (0 == status) {
    MW_I2C_MasterRead(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &test_B.output_raw_m[0],
                      6U, false, true);
    memcpy((void *)&test_B.b_RegisterValue_g[0], (void *)&test_B.output_raw_m[0],
           (uint32_T)((size_t)6 * sizeof(uint8_T)));
  } else {
    for (test_B.i_p = 0; test_B.i_p < 6; test_B.i_p++) {
      test_B.b_RegisterValue_g[test_B.i_p] = 0U;
    }
  }

  test_B.AccelData[0] = (int16_T)(test_B.b_RegisterValue_g[0] << 8) |
    test_B.b_RegisterValue_g[1];
  test_B.AccelData[1] = (int16_T)(test_B.b_RegisterValue_g[2] << 8) |
    test_B.b_RegisterValue_g[3];
  test_B.AccelData[2] = (int16_T)(test_B.b_RegisterValue_g[4] << 8) |
    test_B.b_RegisterValue_g[5];
  test_B.AccelData[0] = test_B.AccelData[0] * 9.80665 / 16384.0;
  test_B.AccelData[1] = test_B.AccelData[1] * 9.80665 / 16384.0;
  test_B.invpa = test_B.AccelData[2] * 9.80665 / 16384.0;
  test_B.AccelData[2] = test_B.invpa;
  status = 67U;
  memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
          sizeof(uint8_T)));
  status = MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U,
    &SwappedDataBytes, 1U, true, false);
  if (0 == status) {
    MW_I2C_MasterRead(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &test_B.output_raw_m[0],
                      6U, false, true);
    memcpy((void *)&test_B.b_RegisterValue_g[0], (void *)&test_B.output_raw_m[0],
           (uint32_T)((size_t)6 * sizeof(uint8_T)));
  } else {
    for (test_B.i_p = 0; test_B.i_p < 6; test_B.i_p++) {
      test_B.b_RegisterValue_g[test_B.i_p] = 0U;
    }
  }

  test_B.GyroData[0] = (int16_T)(test_B.b_RegisterValue_g[0] << 8) |
    test_B.b_RegisterValue_g[1];
  test_B.GyroData[1] = (int16_T)(test_B.b_RegisterValue_g[2] << 8) |
    test_B.b_RegisterValue_g[3];
  test_B.GyroData[2] = (int16_T)(test_B.b_RegisterValue_g[4] << 8) |
    test_B.b_RegisterValue_g[5];
  test_B.GyroData[0] *= 0.00762939453125;
  test_B.GyroData[1] *= 0.00762939453125;
  test_B.GyroData_b = test_B.GyroData[2] * 0.00762939453125;
  test_B.GyroData[2] = test_B.GyroData_b;
  status = 2U;
  memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
          sizeof(uint8_T)));
  status = MW_I2C_MasterWrite(obj->i2cObjak8963.MW_I2C_HANDLE, 12U,
    &SwappedDataBytes, 1U, true, false);
  if (0 == status) {
    MW_I2C_MasterRead(obj->i2cObjak8963.MW_I2C_HANDLE, 12U, &status, 1U, false,
                      true);
    memcpy((void *)&xtmp, (void *)&status, (uint32_T)((size_t)1 * sizeof(uint8_T)));
  } else {
    xtmp = 0U;
  }

  guard1 = false;
  if ((xtmp & 1U) != 0U) {
    status = 3U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(obj->i2cObjak8963.MW_I2C_HANDLE, 12U,
      &SwappedDataBytes, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(obj->i2cObjak8963.MW_I2C_HANDLE, 12U,
                        &test_B.output_raw[0], 7U, false, true);
      memcpy((void *)&test_B.b_RegisterValue[0], (void *)&test_B.output_raw[0],
             (uint32_T)((size_t)7 * sizeof(uint8_T)));
    } else {
      for (test_B.i_p = 0; test_B.i_p < 7; test_B.i_p++) {
        test_B.b_RegisterValue[test_B.i_p] = 0U;
      }
    }

    if ((test_B.b_RegisterValue[6] & 8) != 8) {
      test_B.MagData[0] = (real_T)((int16_T)(test_B.b_RegisterValue[1] << 8) |
        test_B.b_RegisterValue[0]) * test_DW.obj.AK8963SensitivityAdj[0];
      test_B.MagData[1] = (real_T)((int16_T)(test_B.b_RegisterValue[3] << 8) |
        test_B.b_RegisterValue[2]) * test_DW.obj.AK8963SensitivityAdj[1];
      test_B.scale = (real_T)((int16_T)(test_B.b_RegisterValue[5] << 8) |
        test_B.b_RegisterValue[4]) * test_DW.obj.AK8963SensitivityAdj[2];
      test_DW.obj.AK8963Data[0] = test_B.MagData[0] * 0.14993894993894993;
      test_DW.obj.AK8963Data[1] = test_B.MagData[1] * 0.14993894993894993;
      test_DW.obj.AK8963Data[2] = test_B.scale * 0.14993894993894993;
      test_B.MagData[0] = test_DW.obj.AK8963Data[0];
      test_B.MagData[1] = test_DW.obj.AK8963Data[1];
      test_B.MagData[2] = test_DW.obj.AK8963Data[2];
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    test_B.MagData[0] = test_DW.obj.AK8963Data[0];
    test_B.MagData[1] = test_DW.obj.AK8963Data[1];
    test_B.MagData[2] = test_DW.obj.AK8963Data[2];
  }

  /* Sum: '<S8>/Subtract' incorporates:
   *  Constant: '<S8>/Constant'
   *  MATLABSystem: '<S8>/MPU9250'
   */
  test_B.MagData[0] -= test_P.Constant_Value_j[0];
  test_B.MagData[1] -= test_P.Constant_Value_j[1];
  test_B.scale = test_B.MagData[2] - test_P.Constant_Value_j[2];
  test_B.MagData[2] = test_B.scale;

  /* Gain: '<S8>/Gain2' */
  test_B.Gain2_k = test_P.Gain2_Gain_f * test_B.scale;

  /* Gain: '<S8>/Gain1' */
  test_B.Gain1_k = test_P.Gain1_Gain_e * test_B.MagData[1];

  /* Gain: '<S8>/Gain' */
  test_B.Gain_c = test_P.Gain_Gain_i * test_B.MagData[0];

  /* If: '<S4>/If' incorporates:
   *  MATLAB Function: '<S15>/MATLAB Function'
   *  MATLAB Function: '<S16>/MATLAB Function'
   *  SignalConversion generated from: '<S18>/ SFunction '
   *  Sum: '<S26>/Add'
   */
  if (test_B.DigitalClock < 31.0) {
    /* Outputs for IfAction SubSystem: '<S4>/Intialization' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* If: '<S5>/If' incorporates:
     *  Constant: '<S10>/Constant'
     *  Constant: '<S9>/Constant'
     */
    if (test_B.DigitalClock < 0.2) {
      /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S10>/Action Port'
       */
      test_I2CMasterWrite(test_P.Constant_Value, &test_DW.I2CMasterWrite);

      /* End of Outputs for SubSystem: '<S5>/If Action Subsystem2' */

      /* Update for IfAction SubSystem: '<S5>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S10>/Action Port'
       */
      /* Update for If: '<S5>/If' incorporates:
       *  Constant: '<S10>/Constant'
       */
      srUpdateBC(test_DW.IfActionSubsystem2_SubsysRanBC);

      /* End of Update for SubSystem: '<S5>/If Action Subsystem2' */
    } else if (test_B.DigitalClock <= 1.0) {
      /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S9>/Action Port'
       */
      test_I2CMasterWrite(test_P.Constant_Value_c, &test_DW.I2CMasterWrite_p);

      /* MATLABSystem: '<S9>/I2C Master Write1' incorporates:
       *  Constant: '<S9>/Constant'
       *  Constant: '<S9>/Constant1'
       */
      memcpy((void *)&test_B.SwappedDataBytes[0], (void *)
             &test_P.Constant1_Value, (uint32_T)((size_t)8 * sizeof(uint8_T)));
      xtmp = test_B.SwappedDataBytes[0];
      test_B.SwappedDataBytes[0] = test_B.SwappedDataBytes[7];
      test_B.SwappedDataBytes[7] = xtmp;
      xtmp = test_B.SwappedDataBytes[1];
      test_B.SwappedDataBytes[1] = test_B.SwappedDataBytes[6];
      test_B.SwappedDataBytes[6] = xtmp;
      xtmp = test_B.SwappedDataBytes[2];
      test_B.SwappedDataBytes[2] = test_B.SwappedDataBytes[5];
      test_B.SwappedDataBytes[5] = xtmp;
      xtmp = test_B.SwappedDataBytes[3];
      test_B.SwappedDataBytes[3] = test_B.SwappedDataBytes[4];
      test_B.SwappedDataBytes[4] = xtmp;
      memcpy((void *)&test_B.Gain2, (void *)&test_B.SwappedDataBytes[0],
             (uint32_T)((size_t)1 * sizeof(real_T)));
      memcpy((void *)&test_B.SwappedDataBytes[0], (void *)&test_B.Gain2,
             (uint32_T)((size_t)8 * sizeof(uint8_T)));
      test_B.b_SwappedDataBytes[0] = 26U;
      for (test_B.xpageoffset = 0; test_B.xpageoffset < 8; test_B.xpageoffset++)
      {
        test_B.b_SwappedDataBytes[test_B.xpageoffset + 1] =
          test_B.SwappedDataBytes[test_B.xpageoffset];
      }

      MW_I2C_MasterWrite(test_DW.obj_km.MW_I2C_HANDLE, 105U,
                         &test_B.b_SwappedDataBytes[0], 9U, false, false);

      /* End of MATLABSystem: '<S9>/I2C Master Write1' */
      /* End of Outputs for SubSystem: '<S5>/If Action Subsystem1' */

      /* Update for IfAction SubSystem: '<S5>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S9>/Action Port'
       */
      /* Update for If: '<S5>/If' */
      srUpdateBC(test_DW.IfActionSubsystem1_SubsysRanBC);

      /* End of Update for SubSystem: '<S5>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S11>/Action Port'
       */
      /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
      test_B.DiscreteTimeIntegrator = test_DW.DiscreteTimeIntegrator_DSTATE_b;

      /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
      test_B.DiscreteTimeIntegrator1 = test_DW.DiscreteTimeIntegrator1_DSTATE;

      /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator2' */
      test_B.DiscreteTimeIntegrator2 = test_DW.DiscreteTimeIntegrator2_DSTATE;

      /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator3' */
      test_B.DiscreteTimeIntegrator3 = test_DW.DiscreteTimeIntegrator3_DSTATE;

      /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator4' */
      test_B.DiscreteTimeIntegrator4 = test_DW.DiscreteTimeIntegrator4_DSTATE;

      /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator5' */
      test_B.DiscreteTimeIntegrator5 = test_DW.DiscreteTimeIntegrator5_DSTATE;

      /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator10' */
      test_B.DiscreteTimeIntegrator10 = test_DW.DiscreteTimeIntegrator10_DSTATE;

      /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator11' */
      test_B.DiscreteTimeIntegrator11 = test_DW.DiscreteTimeIntegrator11_DSTATE;

      /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator12' */
      test_B.DiscreteTimeIntegrator12 = test_DW.DiscreteTimeIntegrator12_DSTATE;

      /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator13' */
      test_B.DiscreteTimeIntegrator13 = test_DW.DiscreteTimeIntegrator13_DSTATE;

      /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator14' */
      test_B.DiscreteTimeIntegrator14 = test_DW.DiscreteTimeIntegrator14_DSTATE;

      /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator6' */
      test_B.DiscreteTimeIntegrator6 = test_DW.DiscreteTimeIntegrator6_DSTATE;

      /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator7' */
      test_B.DiscreteTimeIntegrator7 = test_DW.DiscreteTimeIntegrator7_DSTATE;

      /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator8' */
      test_B.DiscreteTimeIntegrator8 = test_DW.DiscreteTimeIntegrator8_DSTATE;

      /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator9' */
      test_B.DiscreteTimeIntegrator9 = test_DW.DiscreteTimeIntegrator9_DSTATE;

      /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
      test_DW.DiscreteTimeIntegrator_DSTATE_b +=
        test_P.DiscreteTimeIntegrator_gainval * test_B.Gain3;

      /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
      test_DW.DiscreteTimeIntegrator1_DSTATE +=
        test_P.DiscreteTimeIntegrator1_gainval * test_B.Gain5;

      /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator2' */
      test_DW.DiscreteTimeIntegrator2_DSTATE +=
        test_P.DiscreteTimeIntegrator2_gainval * test_B.Gain2;

      /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator3' */
      test_DW.DiscreteTimeIntegrator3_DSTATE +=
        test_P.DiscreteTimeIntegrator3_gainval * test_B.Gain3_c;

      /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator4' */
      test_DW.DiscreteTimeIntegrator4_DSTATE +=
        test_P.DiscreteTimeIntegrator4_gainval * test_B.Gain5_h;

      /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator5' */
      test_DW.DiscreteTimeIntegrator5_DSTATE +=
        test_P.DiscreteTimeIntegrator5_gainval * test_B.Gain2_b;

      /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator10' incorporates:
       *  MATLABSystem: '<S8>/MPU9250'
       */
      test_DW.DiscreteTimeIntegrator10_DSTATE +=
        test_P.DiscreteTimeIntegrator10_gainva * test_B.GyroData[1];

      /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator11' */
      test_DW.DiscreteTimeIntegrator11_DSTATE +=
        test_P.DiscreteTimeIntegrator11_gainva * test_B.GyroData_b;

      /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator12' */
      test_DW.DiscreteTimeIntegrator12_DSTATE +=
        test_P.DiscreteTimeIntegrator12_gainva * test_B.Gain_c;

      /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator13' */
      test_DW.DiscreteTimeIntegrator13_DSTATE +=
        test_P.DiscreteTimeIntegrator13_gainva * test_B.Gain1_k;

      /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator14' */
      test_DW.DiscreteTimeIntegrator14_DSTATE +=
        test_P.DiscreteTimeIntegrator14_gainva * test_B.Gain2_k;

      /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator6' incorporates:
       *  MATLABSystem: '<S8>/MPU9250'
       */
      test_DW.DiscreteTimeIntegrator6_DSTATE +=
        test_P.DiscreteTimeIntegrator6_gainval * test_B.AccelData[0];

      /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator7' incorporates:
       *  MATLABSystem: '<S8>/MPU9250'
       */
      test_DW.DiscreteTimeIntegrator7_DSTATE +=
        test_P.DiscreteTimeIntegrator7_gainval * test_B.AccelData[1];

      /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator8' */
      test_DW.DiscreteTimeIntegrator8_DSTATE +=
        test_P.DiscreteTimeIntegrator8_gainval * test_B.invpa;

      /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator9' incorporates:
       *  MATLABSystem: '<S8>/MPU9250'
       */
      test_DW.DiscreteTimeIntegrator9_DSTATE +=
        test_P.DiscreteTimeIntegrator9_gainval * test_B.GyroData[0];

      /* End of Outputs for SubSystem: '<S5>/If Action Subsystem3' */

      /* Update for IfAction SubSystem: '<S5>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S11>/Action Port'
       */
      /* Update for If: '<S5>/If' */
      srUpdateBC(test_DW.IfActionSubsystem3_SubsysRanBC);

      /* End of Update for SubSystem: '<S5>/If Action Subsystem3' */
    }

    /* End of If: '<S5>/If' */

    /* Gain: '<S5>/Gain' */
    test_B.Gain[0] = test_P.Gain_Gain * test_B.DiscreteTimeIntegrator3;
    test_B.Gain[1] = test_P.Gain_Gain * test_B.DiscreteTimeIntegrator4;
    test_B.Gain[2] = test_P.Gain_Gain * test_B.DiscreteTimeIntegrator5;
    test_B.Gain[3] = test_P.Gain_Gain * test_B.DiscreteTimeIntegrator;
    test_B.Gain[4] = test_P.Gain_Gain * test_B.DiscreteTimeIntegrator1;
    test_B.Gain[5] = test_P.Gain_Gain * test_B.DiscreteTimeIntegrator2;

    /* Gain: '<S5>/Gain1' */
    test_B.Gain1[0] = test_P.Gain1_Gain * test_B.DiscreteTimeIntegrator6;
    test_B.Gain1[1] = test_P.Gain1_Gain * test_B.DiscreteTimeIntegrator7;
    test_B.Gain1[2] = test_P.Gain1_Gain * test_B.DiscreteTimeIntegrator8;
    test_B.Gain1[3] = test_P.Gain1_Gain * test_B.DiscreteTimeIntegrator9;
    test_B.Gain1[4] = test_P.Gain1_Gain * test_B.DiscreteTimeIntegrator10;
    test_B.Gain1[5] = test_P.Gain1_Gain * test_B.DiscreteTimeIntegrator11;
    test_B.Gain1[6] = test_P.Gain1_Gain * test_B.DiscreteTimeIntegrator12;
    test_B.Gain1[7] = test_P.Gain1_Gain * test_B.DiscreteTimeIntegrator13;
    test_B.Gain1[8] = test_P.Gain1_Gain * test_B.DiscreteTimeIntegrator14;

    /* End of Outputs for SubSystem: '<S4>/Intialization' */

    /* Update for IfAction SubSystem: '<S4>/Intialization' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Update for If: '<S4>/If' */
    srUpdateBC(test_DW.Intialization_SubsysRanBC);

    /* End of Update for SubSystem: '<S4>/Intialization' */
  } else {
    /* Outputs for IfAction SubSystem: '<S4>/Running' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Gain: '<S23>/Gain' incorporates:
     *  MATLABSystem: '<S8>/MPU9250'
     *  Sum: '<S23>/Add'
     */
    test_B.Gain_f[0] = (test_B.Gain3_c + test_B.AccelData[0]) *
      test_P.Gain_Gain_l;
    test_B.Gain_f[1] = (test_B.Gain5_h + test_B.AccelData[1]) *
      test_P.Gain_Gain_l;
    test_B.Gain_f[2] = (test_B.Gain2_b + test_B.invpa) * test_P.Gain_Gain_l;

    /* MATLAB Function: '<S24>/MATLAB Function' */
    test_MATLABFunction(test_B.Gain_f, test_B.MagData);

    /* MATLAB Function: '<S24>/MATLAB Function1' incorporates:
     *  SignalConversion generated from: '<S29>/ SFunction '
     */
    test_B.scale = 3.3121686421112381E-170;
    test_B.Gain5_h = fabs(test_B.Gain_c);
    if (test_B.Gain5_h > 3.3121686421112381E-170) {
      test_B.invpa = 1.0;
      test_B.scale = test_B.Gain5_h;
    } else {
      test_B.Gain3_c = test_B.Gain5_h / 3.3121686421112381E-170;
      test_B.invpa = test_B.Gain3_c * test_B.Gain3_c;
    }

    test_B.Gain5_h = fabs(test_B.Gain1_k);
    if (test_B.Gain5_h > test_B.scale) {
      test_B.Gain3_c = test_B.scale / test_B.Gain5_h;
      test_B.invpa = test_B.invpa * test_B.Gain3_c * test_B.Gain3_c + 1.0;
      test_B.scale = test_B.Gain5_h;
    } else {
      test_B.Gain3_c = test_B.Gain5_h / test_B.scale;
      test_B.invpa += test_B.Gain3_c * test_B.Gain3_c;
    }

    test_B.Gain5_h = fabs(test_B.Gain2_k);
    if (test_B.Gain5_h > test_B.scale) {
      test_B.Gain3_c = test_B.scale / test_B.Gain5_h;
      test_B.invpa = test_B.invpa * test_B.Gain3_c * test_B.Gain3_c + 1.0;
      test_B.scale = test_B.Gain5_h;
    } else {
      test_B.Gain3_c = test_B.Gain5_h / test_B.scale;
      test_B.invpa += test_B.Gain3_c * test_B.Gain3_c;
    }

    test_B.invpa = test_B.scale * sqrt(test_B.invpa);

    /* SignalConversion generated from: '<S30>/ SFunction ' incorporates:
     *  MATLAB Function: '<S24>/MATLAB Function1'
     *  MATLAB Function: '<S24>/MATLAB Function2'
     *  SignalConversion generated from: '<S29>/ SFunction '
     */
    test_B.TmpSignalConversionAtSFun_h[3] = test_B.Gain_c / test_B.invpa;
    test_B.TmpSignalConversionAtSFun_h[4] = test_B.Gain1_k / test_B.invpa;
    test_B.TmpSignalConversionAtSFun_h[5] = test_B.Gain2_k / test_B.invpa;

    /* MATLAB Function: '<S24>/MATLAB Function2' incorporates:
     *  SignalConversion generated from: '<S30>/ SFunction '
     */
    test_B.scale = test_B.MagData[1] * -test_B.TmpSignalConversionAtSFun_h[5] -
      test_B.MagData[2] * test_B.TmpSignalConversionAtSFun_h[3];
    test_B.Gain5_h = test_B.MagData[2] * test_B.TmpSignalConversionAtSFun_h[4] -
      test_B.MagData[0] * -test_B.TmpSignalConversionAtSFun_h[5];
    test_B.Gain3_c = test_B.MagData[0] * test_B.TmpSignalConversionAtSFun_h[3] -
      test_B.MagData[1] * test_B.TmpSignalConversionAtSFun_h[4];
    test_B.R[6] = test_B.MagData[0];
    test_B.R[3] = test_B.scale;
    test_B.R[7] = test_B.MagData[1];
    test_B.R[4] = test_B.Gain5_h;
    test_B.R[8] = test_B.MagData[2];
    test_B.R[5] = test_B.Gain3_c;
    test_B.R[0] = test_B.Gain5_h * test_B.MagData[2] - test_B.Gain3_c *
      test_B.MagData[1];
    test_B.R[1] = test_B.Gain3_c * test_B.MagData[0] - test_B.scale *
      test_B.MagData[2];
    test_B.R[2] = test_B.scale * test_B.MagData[1] - test_B.Gain5_h *
      test_B.MagData[0];
    for (test_B.xpageoffset = 0; test_B.xpageoffset < 9; test_B.xpageoffset++) {
      test_B.scale = test_B.R[test_B.xpageoffset];
      test_B.r[test_B.xpageoffset] = test_B.scale * test_B.scale;
    }

    for (test_B.i_p = 0; test_B.i_p < 3; test_B.i_p++) {
      test_B.xpageoffset = test_B.i_p * 3;
      test_B.MagData[test_B.i_p] = sqrt(test_B.r[test_B.xpageoffset + 2] +
        (test_B.r[test_B.xpageoffset + 1] + test_B.r[test_B.xpageoffset]));
    }

    memcpy(&test_B.r[0], &test_B.R[0], 9U * sizeof(real_T));
    for (test_B.i_p = 0; test_B.i_p < 3; test_B.i_p++) {
      test_B.scale = test_B.MagData[test_B.i_p];
      test_B.R[3 * test_B.i_p] = test_B.r[3 * test_B.i_p] / test_B.scale;
      R_tmp = 3 * test_B.i_p + 1;
      test_B.R[R_tmp] = test_B.r[R_tmp] / test_B.scale;
      R_tmp = 3 * test_B.i_p + 2;
      test_B.R[R_tmp] = test_B.r[R_tmp] / test_B.scale;
    }

    for (test_B.xpageoffset = 0; test_B.xpageoffset < 9; test_B.xpageoffset++) {
      test_B.b_b[test_B.xpageoffset] = rtIsNaN(test_B.R[test_B.xpageoffset]);
    }

    y[0] = false;
    y[1] = false;
    y[2] = false;
    test_B.i_p = 1;
    exitg1 = false;
    while ((!exitg1) && (test_B.i_p <= 3)) {
      if (!test_B.b_b[test_B.i_p - 1]) {
        test_B.i_p++;
      } else {
        y[0] = true;
        exitg1 = true;
      }
    }

    test_B.i_p = 4;
    exitg1 = false;
    while ((!exitg1) && (test_B.i_p <= 6)) {
      if (!test_B.b_b[test_B.i_p - 1]) {
        test_B.i_p++;
      } else {
        y[1] = true;
        exitg1 = true;
      }
    }

    test_B.i_p = 7;
    exitg1 = false;
    while ((!exitg1) && (test_B.i_p <= 9)) {
      if (!test_B.b_b[test_B.i_p - 1]) {
        test_B.i_p++;
      } else {
        y[2] = true;
        exitg1 = true;
      }
    }

    nanPageIdx = false;
    test_B.i_p = 0;
    exitg1 = false;
    while ((!exitg1) && (test_B.i_p < 3)) {
      if (!y[test_B.i_p]) {
        test_B.i_p++;
      } else {
        nanPageIdx = true;
        exitg1 = true;
      }
    }

    if (nanPageIdx) {
      memset(&test_B.R[0], 0, 9U * sizeof(real_T));
      test_B.R[0] = 1.0;
      test_B.R[4] = 1.0;
      test_B.R[8] = 1.0;
    }

    test_B.scale = (test_B.R[0] + test_B.R[4]) + test_B.R[8];
    test_B.psquared[0] = (test_B.scale * 2.0 + 1.0) - test_B.scale;
    test_B.psquared[1] = (2.0 * test_B.R[0] + 1.0) - test_B.scale;
    test_B.psquared[2] = (2.0 * test_B.R[4] + 1.0) - test_B.scale;
    test_B.psquared[3] = (2.0 * test_B.R[8] + 1.0) - test_B.scale;
    if (!rtIsNaN(test_B.psquared[0])) {
      test_B.i_p = 1;
    } else {
      test_B.i_p = 0;
      test_B.xpageoffset = 2;
      exitg1 = false;
      while ((!exitg1) && (test_B.xpageoffset < 5)) {
        if (!rtIsNaN(test_B.psquared[test_B.xpageoffset - 1])) {
          test_B.i_p = test_B.xpageoffset;
          exitg1 = true;
        } else {
          test_B.xpageoffset++;
        }
      }
    }

    if (test_B.i_p == 0) {
      test_B.scale = test_B.psquared[0];
      test_B.i_p = 1;
    } else {
      test_B.scale = test_B.psquared[test_B.i_p - 1];
      test_B.xpageoffset = test_B.i_p;
      while (test_B.xpageoffset + 1 < 5) {
        if (test_B.scale < test_B.psquared[test_B.xpageoffset]) {
          test_B.scale = test_B.psquared[test_B.xpageoffset];
          test_B.i_p = test_B.xpageoffset + 1;
        }

        test_B.xpageoffset++;
      }
    }

    switch (test_B.i_p) {
     case 1:
      test_B.Gain5_h = sqrt(test_B.scale);
      test_B.Gain_c = 0.5 * test_B.Gain5_h;
      test_B.invpa = 0.5 / test_B.Gain5_h;
      test_B.Gain1_k = (test_B.R[7] - test_B.R[5]) * test_B.invpa;
      test_B.Gain2_k = (test_B.R[2] - test_B.R[6]) * test_B.invpa;
      test_B.Gain2_b = (test_B.R[3] - test_B.R[1]) * test_B.invpa;
      break;

     case 2:
      test_B.scale = sqrt(test_B.scale);
      test_B.Gain1_k = 0.5 * test_B.scale;
      test_B.invpa = 0.5 / test_B.scale;
      test_B.Gain_c = (test_B.R[7] - test_B.R[5]) * test_B.invpa;
      test_B.Gain2_k = (test_B.R[3] + test_B.R[1]) * test_B.invpa;
      test_B.Gain2_b = (test_B.R[2] + test_B.R[6]) * test_B.invpa;
      break;

     case 3:
      test_B.scale = sqrt(test_B.scale);
      test_B.Gain2_k = 0.5 * test_B.scale;
      test_B.invpa = 0.5 / test_B.scale;
      test_B.Gain_c = (test_B.R[2] - test_B.R[6]) * test_B.invpa;
      test_B.Gain1_k = (test_B.R[3] + test_B.R[1]) * test_B.invpa;
      test_B.Gain2_b = (test_B.R[7] + test_B.R[5]) * test_B.invpa;
      break;

     default:
      test_B.scale = sqrt(test_B.scale);
      test_B.Gain2_b = 0.5 * test_B.scale;
      test_B.Gain3_c = 0.5 / test_B.scale;
      test_B.Gain_c = (test_B.R[3] - test_B.R[1]) * test_B.Gain3_c;
      test_B.Gain1_k = (test_B.R[2] + test_B.R[6]) * test_B.Gain3_c;
      test_B.Gain2_k = (test_B.R[7] + test_B.R[5]) * test_B.Gain3_c;
      break;
    }

    if (test_B.Gain_c < 0.0) {
      test_B.Gain_c = -test_B.Gain_c;
      test_B.Gain1_k = -test_B.Gain1_k;
      test_B.Gain2_k = -test_B.Gain2_k;
      test_B.Gain2_b = -test_B.Gain2_b;
    }

    /* Sum: '<S26>/Add' */
    test_B.scale = test_B.Gain[0] + test_B.Gain1[0];

    /* Gain: '<S26>/Gain' */
    test_B.MagData[0] = test_P.Gain_Gain_d * test_B.scale;
    test_B.Gain_f[0] = test_B.scale;

    /* Sum: '<S26>/Add' */
    test_B.scale = test_B.Gain[1] + test_B.Gain1[1];

    /* Gain: '<S26>/Gain' */
    test_B.MagData[1] = test_P.Gain_Gain_d * test_B.scale;
    test_B.Gain_f[1] = test_B.scale;

    /* Sum: '<S26>/Add' */
    test_B.scale = test_B.Gain[2] + test_B.Gain1[2];

    /* Gain: '<S26>/Gain' */
    test_B.MagData[2] = test_P.Gain_Gain_d * test_B.scale;
    test_B.Gain_f[2] = test_B.scale;

    /* MATLAB Function: '<S25>/MATLAB Function' incorporates:
     *  Sum: '<S26>/Add'
     */
    test_MATLABFunction(test_B.MagData, test_B.Gain_f);

    /* MATLAB Function: '<S25>/MATLAB Function1' */
    test_B.scale = 3.3121686421112381E-170;
    test_B.Gain5_h = fabs(test_B.Gain1[6]);
    if (test_B.Gain5_h > 3.3121686421112381E-170) {
      test_B.invpa = 1.0;
      test_B.scale = test_B.Gain5_h;
    } else {
      test_B.Gain3_c = test_B.Gain5_h / 3.3121686421112381E-170;
      test_B.invpa = test_B.Gain3_c * test_B.Gain3_c;
    }

    /* SignalConversion generated from: '<S33>/ SFunction ' incorporates:
     *  MATLAB Function: '<S25>/MATLAB Function2'
     */
    test_B.TmpSignalConversionAtSFun_h[0] = test_B.Gain_f[0];

    /* MATLAB Function: '<S25>/MATLAB Function1' */
    test_B.Gain5_h = fabs(test_B.Gain1[7]);
    if (test_B.Gain5_h > test_B.scale) {
      test_B.Gain3_c = test_B.scale / test_B.Gain5_h;
      test_B.invpa = test_B.invpa * test_B.Gain3_c * test_B.Gain3_c + 1.0;
      test_B.scale = test_B.Gain5_h;
    } else {
      test_B.Gain3_c = test_B.Gain5_h / test_B.scale;
      test_B.invpa += test_B.Gain3_c * test_B.Gain3_c;
    }

    /* SignalConversion generated from: '<S33>/ SFunction ' incorporates:
     *  MATLAB Function: '<S25>/MATLAB Function2'
     */
    test_B.TmpSignalConversionAtSFun_h[1] = test_B.Gain_f[1];

    /* MATLAB Function: '<S25>/MATLAB Function1' */
    test_B.Gain5_h = fabs(test_B.Gain1[8]);
    if (test_B.Gain5_h > test_B.scale) {
      test_B.Gain3_c = test_B.scale / test_B.Gain5_h;
      test_B.invpa = test_B.invpa * test_B.Gain3_c * test_B.Gain3_c + 1.0;
      test_B.scale = test_B.Gain5_h;
    } else {
      test_B.Gain3_c = test_B.Gain5_h / test_B.scale;
      test_B.invpa += test_B.Gain3_c * test_B.Gain3_c;
    }

    /* SignalConversion generated from: '<S33>/ SFunction ' incorporates:
     *  MATLAB Function: '<S25>/MATLAB Function2'
     */
    test_B.TmpSignalConversionAtSFun_h[2] = test_B.Gain_f[2];

    /* MATLAB Function: '<S25>/MATLAB Function1' */
    test_B.invpa = test_B.scale * sqrt(test_B.invpa);

    /* SignalConversion generated from: '<S33>/ SFunction ' incorporates:
     *  MATLAB Function: '<S25>/MATLAB Function1'
     *  MATLAB Function: '<S25>/MATLAB Function2'
     */
    test_B.TmpSignalConversionAtSFun_h[3] = test_B.Gain1[6] / test_B.invpa;
    test_B.TmpSignalConversionAtSFun_h[4] = test_B.Gain1[7] / test_B.invpa;
    test_B.TmpSignalConversionAtSFun_h[5] = test_B.Gain1[8] / test_B.invpa;

    /* MATLAB Function: '<S25>/MATLAB Function2' incorporates:
     *  SignalConversion generated from: '<S33>/ SFunction '
     */
    test_B.scale = test_B.Gain_f[1] * -test_B.TmpSignalConversionAtSFun_h[5] -
      test_B.Gain_f[2] * test_B.TmpSignalConversionAtSFun_h[3];
    test_B.Gain5_h = test_B.Gain_f[2] * test_B.TmpSignalConversionAtSFun_h[4] -
      test_B.Gain_f[0] * -test_B.TmpSignalConversionAtSFun_h[5];
    test_B.Gain3_c = test_B.Gain_f[0] * test_B.TmpSignalConversionAtSFun_h[3] -
      test_B.Gain_f[1] * test_B.TmpSignalConversionAtSFun_h[4];
    test_B.R[6] = test_B.Gain_f[0];
    test_B.R[3] = test_B.scale;
    test_B.R[7] = test_B.Gain_f[1];
    test_B.R[4] = test_B.Gain5_h;
    test_B.R[8] = test_B.Gain_f[2];
    test_B.R[5] = test_B.Gain3_c;
    test_B.R[0] = test_B.Gain5_h * test_B.Gain_f[2] - test_B.Gain3_c *
      test_B.Gain_f[1];
    test_B.R[1] = test_B.Gain3_c * test_B.Gain_f[0] - test_B.scale *
      test_B.Gain_f[2];
    test_B.R[2] = test_B.scale * test_B.Gain_f[1] - test_B.Gain5_h *
      test_B.Gain_f[0];
    for (test_B.xpageoffset = 0; test_B.xpageoffset < 9; test_B.xpageoffset++) {
      test_B.scale = test_B.R[test_B.xpageoffset];
      test_B.r[test_B.xpageoffset] = test_B.scale * test_B.scale;
    }

    for (test_B.i_p = 0; test_B.i_p < 3; test_B.i_p++) {
      test_B.xpageoffset = test_B.i_p * 3;
      test_B.MagData[test_B.i_p] = sqrt(test_B.r[test_B.xpageoffset + 2] +
        (test_B.r[test_B.xpageoffset + 1] + test_B.r[test_B.xpageoffset]));
    }

    memcpy(&test_B.r[0], &test_B.R[0], 9U * sizeof(real_T));
    for (test_B.i_p = 0; test_B.i_p < 3; test_B.i_p++) {
      test_B.scale = test_B.MagData[test_B.i_p];
      test_B.R[3 * test_B.i_p] = test_B.r[3 * test_B.i_p] / test_B.scale;
      R_tmp = 3 * test_B.i_p + 1;
      test_B.R[R_tmp] = test_B.r[R_tmp] / test_B.scale;
      R_tmp = 3 * test_B.i_p + 2;
      test_B.R[R_tmp] = test_B.r[R_tmp] / test_B.scale;
    }

    for (test_B.xpageoffset = 0; test_B.xpageoffset < 9; test_B.xpageoffset++) {
      test_B.b_b[test_B.xpageoffset] = rtIsNaN(test_B.R[test_B.xpageoffset]);
    }

    y[0] = false;
    y[1] = false;
    y[2] = false;
    test_B.i_p = 1;
    exitg1 = false;
    while ((!exitg1) && (test_B.i_p <= 3)) {
      if (!test_B.b_b[test_B.i_p - 1]) {
        test_B.i_p++;
      } else {
        y[0] = true;
        exitg1 = true;
      }
    }

    test_B.i_p = 4;
    exitg1 = false;
    while ((!exitg1) && (test_B.i_p <= 6)) {
      if (!test_B.b_b[test_B.i_p - 1]) {
        test_B.i_p++;
      } else {
        y[1] = true;
        exitg1 = true;
      }
    }

    test_B.i_p = 7;
    exitg1 = false;
    while ((!exitg1) && (test_B.i_p <= 9)) {
      if (!test_B.b_b[test_B.i_p - 1]) {
        test_B.i_p++;
      } else {
        y[2] = true;
        exitg1 = true;
      }
    }

    nanPageIdx = false;
    test_B.i_p = 0;
    exitg1 = false;
    while ((!exitg1) && (test_B.i_p < 3)) {
      if (!y[test_B.i_p]) {
        test_B.i_p++;
      } else {
        nanPageIdx = true;
        exitg1 = true;
      }
    }

    if (nanPageIdx) {
      memset(&test_B.R[0], 0, 9U * sizeof(real_T));
      test_B.R[0] = 1.0;
      test_B.R[4] = 1.0;
      test_B.R[8] = 1.0;
    }

    test_B.scale = (test_B.R[0] + test_B.R[4]) + test_B.R[8];
    test_B.psquared[0] = (test_B.scale * 2.0 + 1.0) - test_B.scale;
    test_B.psquared[1] = (2.0 * test_B.R[0] + 1.0) - test_B.scale;
    test_B.psquared[2] = (2.0 * test_B.R[4] + 1.0) - test_B.scale;
    test_B.psquared[3] = (2.0 * test_B.R[8] + 1.0) - test_B.scale;
    if (!rtIsNaN(test_B.psquared[0])) {
      test_B.i_p = 1;
    } else {
      test_B.i_p = 0;
      test_B.xpageoffset = 2;
      exitg1 = false;
      while ((!exitg1) && (test_B.xpageoffset < 5)) {
        if (!rtIsNaN(test_B.psquared[test_B.xpageoffset - 1])) {
          test_B.i_p = test_B.xpageoffset;
          exitg1 = true;
        } else {
          test_B.xpageoffset++;
        }
      }
    }

    if (test_B.i_p == 0) {
      test_B.scale = test_B.psquared[0];
      test_B.i_p = 1;
    } else {
      test_B.scale = test_B.psquared[test_B.i_p - 1];
      test_B.xpageoffset = test_B.i_p;
      while (test_B.xpageoffset + 1 < 5) {
        if (test_B.scale < test_B.psquared[test_B.xpageoffset]) {
          test_B.scale = test_B.psquared[test_B.xpageoffset];
          test_B.i_p = test_B.xpageoffset + 1;
        }

        test_B.xpageoffset++;
      }
    }

    switch (test_B.i_p) {
     case 1:
      test_B.Gain5_h = sqrt(test_B.scale);
      test_B.scale = 0.5 * test_B.Gain5_h;
      test_B.invpa = 0.5 / test_B.Gain5_h;
      test_B.Gain5_h = (test_B.R[7] - test_B.R[5]) * test_B.invpa;
      test_B.Gain3_c = (test_B.R[2] - test_B.R[6]) * test_B.invpa;
      test_B.invpa *= test_B.R[3] - test_B.R[1];
      break;

     case 2:
      test_B.scale = sqrt(test_B.scale);
      test_B.Gain5_h = 0.5 * test_B.scale;
      test_B.invpa = 0.5 / test_B.scale;
      test_B.scale = (test_B.R[7] - test_B.R[5]) * test_B.invpa;
      test_B.Gain3_c = (test_B.R[3] + test_B.R[1]) * test_B.invpa;
      test_B.invpa *= test_B.R[2] + test_B.R[6];
      break;

     case 3:
      test_B.scale = sqrt(test_B.scale);
      test_B.Gain3_c = 0.5 * test_B.scale;
      test_B.invpa = 0.5 / test_B.scale;
      test_B.scale = (test_B.R[2] - test_B.R[6]) * test_B.invpa;
      test_B.Gain5_h = (test_B.R[3] + test_B.R[1]) * test_B.invpa;
      test_B.invpa *= test_B.R[7] + test_B.R[5];
      break;

     default:
      test_B.scale = sqrt(test_B.scale);
      test_B.invpa = 0.5 * test_B.scale;
      test_B.Gain3_c = 0.5 / test_B.scale;
      test_B.scale = (test_B.R[3] - test_B.R[1]) * test_B.Gain3_c;
      test_B.Gain5_h = (test_B.R[2] + test_B.R[6]) * test_B.Gain3_c;
      test_B.Gain3_c *= test_B.R[7] + test_B.R[5];
      break;
    }

    if (test_B.scale < 0.0) {
      test_B.scale = -test_B.scale;
      test_B.Gain5_h = -test_B.Gain5_h;
      test_B.Gain3_c = -test_B.Gain3_c;
      test_B.invpa = -test_B.invpa;
    }

    /* MATLAB Function: '<S20>/MATLAB Function2' incorporates:
     *  MATLAB Function: '<S24>/MATLAB Function2'
     *  MATLAB Function: '<S25>/MATLAB Function2'
     */
    test_quaternionBase_rotmat(test_B.scale, test_B.Gain5_h, test_B.Gain3_c,
      test_B.invpa, test_B.r);
    test_quaternionBase_rotmat(test_B.Gain_c, test_B.Gain1_k, test_B.Gain2_k,
      test_B.Gain2_b, test_B.dv);
    for (test_B.i_p = 0; test_B.i_p < 3; test_B.i_p++) {
      for (test_B.xpageoffset = 0; test_B.xpageoffset < 3; test_B.xpageoffset++)
      {
        R_tmp = test_B.i_p + 3 * test_B.xpageoffset;
        test_B.R[R_tmp] = 0.0;
        test_B.R[R_tmp] += test_B.r[test_B.i_p] * test_B.dv[test_B.xpageoffset];
        test_B.R[R_tmp] += test_B.r[test_B.i_p + 3] *
          test_B.dv[test_B.xpageoffset + 3];
        test_B.R[R_tmp] += test_B.r[test_B.i_p + 6] *
          test_B.dv[test_B.xpageoffset + 6];
      }

      /* SignalConversion generated from: '<S22>/ SFunction ' incorporates:
       *  MATLAB Function: '<S19>/MATLAB Function'
       *  MATLABSystem: '<S8>/MPU9250'
       *  SignalConversion generated from: '<S18>/ SFunction '
       *  Sum: '<S14>/Subtract'
       */
      test_B.TmpSignalConversionAtSFun_h[test_B.i_p] =
        test_B.GyroData[test_B.i_p] - test_B.Gain1[test_B.i_p + 3];
    }

    test_B.Gain2_k = asin(-test_B.R[2]);

    /* SignalConversion generated from: '<S22>/ SFunction ' incorporates:
     *  Delay: '<S19>/Delay'
     *  Delay: '<S19>/Delay1'
     *  MATLAB Function: '<S19>/MATLAB Function'
     *  SignalConversion generated from: '<S18>/ SFunction '
     */
    test_B.TmpSignalConversionAtSFun_h[3] = test_DW.Delay_DSTATE_g;
    test_B.TmpSignalConversionAtSFun_h[4] = test_DW.Delay1_DSTATE;

    /* MATLAB Function: '<S19>/MATLAB Function' incorporates:
     *  Delay: '<S19>/Delay'
     *  Delay: '<S19>/Delay1'
     *  Delay: '<S19>/Delay2'
     *  SignalConversion generated from: '<S18>/ SFunction '
     *  SignalConversion generated from: '<S22>/ SFunction '
     */
    test_B.GyroData[0] = test_DW.Delay_DSTATE_g;
    test_B.GyroData[1] = test_DW.Delay1_DSTATE;
    test_B.GyroData[2] = test_DW.Delay2_DSTATE;
    test_B.Gain1_k = test_B.TmpSignalConversionAtSFun_h[3];
    test_sind(&test_B.Gain1_k);
    test_B.Gain_c = test_B.TmpSignalConversionAtSFun_h[4];
    test_tand(&test_B.Gain_c);
    test_B.Gain2_b = test_B.TmpSignalConversionAtSFun_h[3];
    test_cosd(&test_B.Gain2_b);
    test_B.scale = test_B.TmpSignalConversionAtSFun_h[4];
    test_tand(&test_B.scale);
    test_B.dv1[4] = test_B.TmpSignalConversionAtSFun_h[3];
    test_cosd(&test_B.dv1[4]);
    test_B.Gain5_h = test_B.TmpSignalConversionAtSFun_h[3];
    test_sind(&test_B.Gain5_h);
    test_B.Gain3_c = test_B.TmpSignalConversionAtSFun_h[3];
    test_sind(&test_B.Gain3_c);
    test_B.invpa = test_B.TmpSignalConversionAtSFun_h[4];
    test_cosd(&test_B.invpa);
    test_B.GyroData_b = test_B.TmpSignalConversionAtSFun_h[3];
    test_cosd(&test_B.GyroData_b);
    test_B.k = test_B.TmpSignalConversionAtSFun_h[4];
    test_cosd(&test_B.k);
    test_B.dv1[0] = 1.0;
    test_B.dv1[3] = test_B.Gain1_k * test_B.Gain_c;
    test_B.dv1[6] = test_B.Gain2_b * test_B.scale;
    test_B.dv1[1] = 0.0;
    test_B.dv1[7] = -test_B.Gain5_h;
    test_B.dv1[2] = 0.0;
    test_B.dv1[5] = test_B.Gain3_c / test_B.invpa;
    test_B.dv1[8] = test_B.GyroData_b / test_B.k;
    test_B.Gain1_k = test_B.TmpSignalConversionAtSFun_h[0];
    test_B.Gain_c = test_B.TmpSignalConversionAtSFun_h[1];
    test_B.Gain2_b = test_B.TmpSignalConversionAtSFun_h[2];
    for (test_B.xpageoffset = 0; test_B.xpageoffset < 3; test_B.xpageoffset++) {
      test_B.MagData[test_B.xpageoffset] = (test_B.dv1[test_B.xpageoffset + 6] *
        test_B.Gain2_b + (test_B.dv1[test_B.xpageoffset + 3] * test_B.Gain_c +
                          test_B.dv1[test_B.xpageoffset] * test_B.Gain1_k)) *
        0.1 + test_B.GyroData[test_B.xpageoffset];
    }

    /* SignalConversion generated from: '<S34>/ SFunction ' incorporates:
     *  Delay: '<S21>/Delay'
     *  Delay: '<S21>/Delay1'
     *  Delay: '<S21>/Delay2'
     *  MATLAB Function: '<S21>/MATLAB Function'
     *  Sum: '<S14>/Subtract1'
     */
    test_B.TmpSignalConversionAtSFun_h[0] = test_B.Gain3 - test_B.Gain[3];
    test_B.TmpSignalConversionAtSFun_h[1] = test_B.Gain5 - test_B.Gain[4];
    test_B.TmpSignalConversionAtSFun_h[2] = test_B.Gain2 - test_B.Gain[5];
    test_B.TmpSignalConversionAtSFun_h[3] = test_DW.Delay_DSTATE_l;
    test_B.TmpSignalConversionAtSFun_h[4] = test_DW.Delay1_DSTATE_k;
    test_B.TmpSignalConversionAtSFun_h[5] = test_DW.Delay2_DSTATE_c;

    /* MATLAB Function: '<S21>/MATLAB Function' */
    test_B.GyroData[0] = test_B.TmpSignalConversionAtSFun_h[3];
    test_B.GyroData[1] = test_B.TmpSignalConversionAtSFun_h[4];
    test_B.GyroData[2] = test_B.TmpSignalConversionAtSFun_h[5];
    test_B.Gain1_k = test_B.TmpSignalConversionAtSFun_h[3];
    test_sind(&test_B.Gain1_k);
    test_B.Gain_c = test_B.TmpSignalConversionAtSFun_h[4];
    test_tand(&test_B.Gain_c);
    test_B.Gain2_b = test_B.TmpSignalConversionAtSFun_h[3];
    test_cosd(&test_B.Gain2_b);
    test_B.scale = test_B.TmpSignalConversionAtSFun_h[4];
    test_tand(&test_B.scale);
    test_B.dv2[4] = test_B.TmpSignalConversionAtSFun_h[3];
    test_cosd(&test_B.dv2[4]);
    test_B.Gain5_h = test_B.TmpSignalConversionAtSFun_h[3];
    test_sind(&test_B.Gain5_h);
    test_B.Gain3_c = test_B.TmpSignalConversionAtSFun_h[3];
    test_sind(&test_B.Gain3_c);
    test_B.invpa = test_B.TmpSignalConversionAtSFun_h[4];
    test_cosd(&test_B.invpa);
    test_B.GyroData_b = test_B.TmpSignalConversionAtSFun_h[3];
    test_cosd(&test_B.GyroData_b);
    test_B.k = test_B.TmpSignalConversionAtSFun_h[4];
    test_cosd(&test_B.k);

    /* MATLAB Function: '<S20>/MATLAB Function2' incorporates:
     *  Gain: '<S13>/Gain'
     */
    test_B.Gain2 = cos(test_B.Gain2_k);
    test_B.Gain_f[0] = rt_atan2d_snf(test_B.R[5] / test_B.Gain2, test_B.R[8] /
      test_B.Gain2) * 180.0 / 3.1415926535897931 * test_P.Gain_Gain_n;
    test_B.Gain_f[1] = test_B.Gain2_k * 180.0 / 3.1415926535897931 *
      test_P.Gain_Gain_n;
    test_B.Gain_f[2] = rt_atan2d_snf(test_B.R[1] / test_B.Gain2, test_B.R[0] /
      test_B.Gain2) * 180.0 / 3.1415926535897931 * test_P.Gain_Gain_n;

    /* MATLAB Function: '<S21>/MATLAB Function' */
    test_B.dv2[0] = 1.0;
    test_B.dv2[3] = test_B.Gain1_k * test_B.Gain_c;
    test_B.dv2[6] = test_B.Gain2_b * test_B.scale;
    test_B.dv2[1] = 0.0;
    test_B.dv2[7] = -test_B.Gain5_h;
    test_B.dv2[2] = 0.0;
    test_B.dv2[5] = test_B.Gain3_c / test_B.invpa;
    test_B.dv2[8] = test_B.GyroData_b / test_B.k;
    test_B.Gain1_k = test_B.TmpSignalConversionAtSFun_h[0];
    test_B.Gain_c = test_B.TmpSignalConversionAtSFun_h[1];
    test_B.Gain2_b = test_B.TmpSignalConversionAtSFun_h[2];
    for (test_B.i_p = 0; test_B.i_p < 3; test_B.i_p++) {
      /* Sum: '<S13>/Sum' incorporates:
       *  Gain: '<S13>/Gain1'
       *  Gain: '<S13>/Gain2'
       */
      test_B.Sum[test_B.i_p] = ((test_B.dv2[test_B.i_p + 6] * test_B.Gain2_b +
        (test_B.dv2[test_B.i_p + 3] * test_B.Gain_c + test_B.dv2[test_B.i_p] *
         test_B.Gain1_k)) * 0.1 + test_B.GyroData[test_B.i_p]) *
        test_P.Gain2_Gain + (test_P.Gain1_Gain_o * test_B.MagData[test_B.i_p] +
        test_B.Gain_f[test_B.i_p]);

      /* SignalConversion generated from: '<S17>/ SFunction ' incorporates:
       *  MATLAB Function: '<S15>/MATLAB Function'
       */
      test_B.TmpSignalConversionAtSFun_h[test_B.i_p] = test_B.Sum[test_B.i_p];
      test_B.TmpSignalConversionAtSFun_h[test_B.i_p + 3] =
        test_B.Gain1[test_B.i_p];
    }

    test_B.MagData[0] = 0.017453292519943295 *
      test_B.TmpSignalConversionAtSFun_h[2] / 2.0;
    test_B.MagData[1] = 0.017453292519943295 *
      test_B.TmpSignalConversionAtSFun_h[1] / 2.0;

    /* MATLAB Function: '<S15>/MATLAB Function' */
    test_B.scale = 0.017453292519943295 * test_B.TmpSignalConversionAtSFun_h[0] /
      2.0;
    test_B.Gain2 = sin(test_B.scale);
    test_B.Gain5 = cos(test_B.scale);
    test_B.Gain3 = sin(test_B.MagData[0]);
    test_B.Gain2_b = sin(test_B.MagData[1]);
    test_B.scale = cos(test_B.MagData[0]);
    test_B.Gain5_h = cos(test_B.MagData[1]);
    test_B.Gain_c = test_B.scale * test_B.Gain5_h * test_B.Gain5 + test_B.Gain3 *
      test_B.Gain2_b * test_B.Gain2;
    test_B.Gain1_k = cos(test_B.MagData[0]) * cos(test_B.MagData[1]) *
      test_B.Gain2 - test_B.Gain5 * test_B.Gain3 * test_B.Gain2_b;
    test_B.Gain2_k = test_B.scale * test_B.Gain5 * test_B.Gain2_b +
      test_B.Gain5_h * test_B.Gain3 * test_B.Gain2;
    test_B.Gain2_b = test_B.Gain5_h * test_B.Gain5 * test_B.Gain3 - test_B.scale
      * test_B.Gain2_b * test_B.Gain2;
    test_B.scale = sqrt(((test_B.Gain_c * test_B.Gain_c + test_B.Gain1_k *
                          test_B.Gain1_k) + test_B.Gain2_k * test_B.Gain2_k) +
                        test_B.Gain2_b * test_B.Gain2_b);
    test_B.Gain2 = test_B.Gain_c / test_B.scale;
    test_B.Gain5 = test_B.Gain1_k / test_B.scale;
    test_B.Gain3 = test_B.Gain2_k / test_B.scale;
    test_B.Gain2_k = test_B.Gain2_b / test_B.scale;
    test_B.Gain1_k = test_B.Gain2 * test_B.Gain5 * 2.0;
    test_B.Gain_c = test_B.Gain2 * test_B.Gain3 * 2.0;
    test_B.Gain2_b = test_B.Gain2 * test_B.Gain2_k * 2.0;
    test_B.scale = test_B.Gain5 * test_B.Gain3 * 2.0;
    test_B.Gain5_h = test_B.Gain5 * test_B.Gain2_k * 2.0;
    test_B.Gain3_c = test_B.Gain3 * test_B.Gain2_k * 2.0;
    test_B.Gain2 = test_B.Gain2 * test_B.Gain2 * 2.0 - 1.0;
    test_B.R[0] = test_B.Gain5 * test_B.Gain5 * 2.0 + test_B.Gain2;
    test_B.R[3] = test_B.scale + test_B.Gain2_b;
    test_B.R[6] = test_B.Gain5_h - test_B.Gain_c;
    test_B.R[1] = test_B.scale - test_B.Gain2_b;
    test_B.R[4] = test_B.Gain3 * test_B.Gain3 * 2.0 + test_B.Gain2;
    test_B.R[7] = test_B.Gain3_c + test_B.Gain1_k;
    test_B.R[2] = test_B.Gain5_h + test_B.Gain_c;
    test_B.R[5] = test_B.Gain3_c - test_B.Gain1_k;
    test_B.R[8] = test_B.Gain2_k * test_B.Gain2_k * 2.0 + test_B.Gain2;
    for (test_B.i_p = 0; test_B.i_p < 3; test_B.i_p++) {
      test_B.xpageoffset = ((int8_T)(test_B.i_p + 1) - 1) * 3;
      test_B.r[(int8_T)(test_B.i_p + 1) - 1] = test_B.R[test_B.xpageoffset];
      test_B.r[(int8_T)(test_B.i_p + 1) + 2] = test_B.R[test_B.xpageoffset + 1];
      test_B.r[(int8_T)(test_B.i_p + 1) + 5] = test_B.R[test_B.xpageoffset + 2];
    }

    test_B.Gain2 = test_B.TmpSignalConversionAtSFun_h[3];
    test_B.Gain5 = test_B.TmpSignalConversionAtSFun_h[4];
    test_B.Gain3 = test_B.TmpSignalConversionAtSFun_h[5];
    for (test_B.xpageoffset = 0; test_B.xpageoffset < 3; test_B.xpageoffset++) {
      /* SignalConversion generated from: '<S18>/ SFunction ' incorporates:
       *  MATLAB Function: '<S16>/MATLAB Function'
       *  MATLABSystem: '<S8>/MPU9250'
       *  Sum: '<S12>/Sum1'
       */
      test_B.TmpSignalConversionAtSFun_h[test_B.xpageoffset] =
        test_B.AccelData[test_B.xpageoffset] - (test_B.r[3 * test_B.xpageoffset
        + 2] * test_B.Gain3 + (test_B.r[3 * test_B.xpageoffset + 1] *
        test_B.Gain5 + test_B.r[3 * test_B.xpageoffset] * test_B.Gain2));
      test_B.TmpSignalConversionAtSFun_h[test_B.xpageoffset + 3] =
        test_B.Sum[test_B.xpageoffset];
    }

    test_B.MagData[0] = 0.017453292519943295 *
      test_B.TmpSignalConversionAtSFun_h[5] / 2.0;
    test_B.MagData[1] = 0.017453292519943295 *
      test_B.TmpSignalConversionAtSFun_h[4] / 2.0;

    /* MATLAB Function: '<S16>/MATLAB Function' incorporates:
     *  SignalConversion generated from: '<S18>/ SFunction '
     */
    test_B.scale = 0.017453292519943295 * test_B.TmpSignalConversionAtSFun_h[3] /
      2.0;
    test_B.Gain2 = sin(test_B.scale);
    test_B.Gain5 = cos(test_B.scale);
    test_B.Gain3 = sin(test_B.MagData[0]);
    test_B.Gain2_b = sin(test_B.MagData[1]);
    test_B.scale = cos(test_B.MagData[0]);
    test_B.Gain5_h = cos(test_B.MagData[1]);
    test_B.Gain_c = test_B.scale * test_B.Gain5_h * test_B.Gain5 + test_B.Gain3 *
      test_B.Gain2_b * test_B.Gain2;
    test_B.Gain1_k = cos(test_B.MagData[0]) * cos(test_B.MagData[1]) *
      test_B.Gain2 - test_B.Gain5 * test_B.Gain3 * test_B.Gain2_b;
    test_B.Gain2_k = test_B.scale * test_B.Gain5 * test_B.Gain2_b +
      test_B.Gain5_h * test_B.Gain3 * test_B.Gain2;
    test_B.Gain2_b = test_B.Gain5_h * test_B.Gain5 * test_B.Gain3 - test_B.scale
      * test_B.Gain2_b * test_B.Gain2;
    test_B.scale = sqrt(((test_B.Gain_c * test_B.Gain_c + test_B.Gain1_k *
                          test_B.Gain1_k) + test_B.Gain2_k * test_B.Gain2_k) +
                        test_B.Gain2_b * test_B.Gain2_b);
    test_B.Gain2 = test_B.Gain_c / test_B.scale;
    test_B.Gain5 = test_B.Gain1_k / test_B.scale;
    test_B.Gain3 = test_B.Gain2_k / test_B.scale;
    test_B.Gain2_k = test_B.Gain2_b / test_B.scale;
    test_B.Gain1_k = test_B.Gain2 * test_B.Gain5 * 2.0;
    test_B.Gain_c = test_B.Gain2 * test_B.Gain3 * 2.0;
    test_B.Gain2_b = test_B.Gain2 * test_B.Gain2_k * 2.0;
    test_B.scale = test_B.Gain5 * test_B.Gain3 * 2.0;
    test_B.Gain5_h = test_B.Gain5 * test_B.Gain2_k * 2.0;
    test_B.Gain3_c = test_B.Gain3 * test_B.Gain2_k * 2.0;
    test_B.Gain2 = test_B.Gain2 * test_B.Gain2 * 2.0 - 1.0;
    test_B.R[0] = test_B.Gain5 * test_B.Gain5 * 2.0 + test_B.Gain2;
    test_B.R[3] = test_B.scale + test_B.Gain2_b;
    test_B.R[6] = test_B.Gain5_h - test_B.Gain_c;
    test_B.R[1] = test_B.scale - test_B.Gain2_b;
    test_B.R[4] = test_B.Gain3 * test_B.Gain3 * 2.0 + test_B.Gain2;
    test_B.R[7] = test_B.Gain3_c + test_B.Gain1_k;
    test_B.R[2] = test_B.Gain5_h + test_B.Gain_c;
    test_B.R[5] = test_B.Gain3_c - test_B.Gain1_k;
    test_B.R[8] = test_B.Gain2_k * test_B.Gain2_k * 2.0 + test_B.Gain2;
    for (test_B.i_p = 0; test_B.i_p < 3; test_B.i_p++) {
      test_B.xpageoffset = ((int8_T)(test_B.i_p + 1) - 1) * 3;
      test_B.r[(int8_T)(test_B.i_p + 1) - 1] = test_B.R[test_B.xpageoffset];
      test_B.r[(int8_T)(test_B.i_p + 1) + 2] = test_B.R[test_B.xpageoffset + 1];
      test_B.r[(int8_T)(test_B.i_p + 1) + 5] = test_B.R[test_B.xpageoffset + 2];
    }

    test_B.Gain1_k = test_B.TmpSignalConversionAtSFun_h[0];
    test_B.Gain_c = test_B.TmpSignalConversionAtSFun_h[1];
    test_B.Gain2_b = test_B.TmpSignalConversionAtSFun_h[2];
    for (test_B.xpageoffset = 0; test_B.xpageoffset < 3; test_B.xpageoffset++) {
      test_B.y[test_B.xpageoffset] = 0.0;
      test_B.y[test_B.xpageoffset] += test_B.r[test_B.xpageoffset] *
        test_B.Gain1_k;
      test_B.y[test_B.xpageoffset] += test_B.r[test_B.xpageoffset + 3] *
        test_B.Gain_c;
      test_B.y[test_B.xpageoffset] += test_B.r[test_B.xpageoffset + 6] *
        test_B.Gain2_b;
    }

    /* Update for Delay: '<S19>/Delay' */
    test_DW.Delay_DSTATE_g = test_B.Sum[0];

    /* Update for Delay: '<S19>/Delay1' */
    test_DW.Delay1_DSTATE = test_B.Sum[1];

    /* Update for Delay: '<S19>/Delay2' */
    test_DW.Delay2_DSTATE = test_B.Sum[2];

    /* Update for Delay: '<S21>/Delay' */
    test_DW.Delay_DSTATE_l = test_B.Sum[0];

    /* Update for Delay: '<S21>/Delay1' */
    test_DW.Delay1_DSTATE_k = test_B.Sum[1];

    /* Update for Delay: '<S21>/Delay2' */
    test_DW.Delay2_DSTATE_c = test_B.Sum[2];

    /* End of Outputs for SubSystem: '<S4>/Running' */

    /* Update for IfAction SubSystem: '<S4>/Running' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Update for If: '<S4>/If' */
    srUpdateBC(test_DW.Running_SubsysRanBC);

    /* End of Update for SubSystem: '<S4>/Running' */
  }

  /* End of If: '<S4>/If' */
  /* RateTransition: '<Root>/Rate Transition' */
  test_DW.RateTransition_Buffer0 = test_B.Sum[0];
  rtExtModeUpload(1, (real_T)((test_M->Timing.clockTick1) * 0.1));

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  test_M->Timing.clockTick1++;
}

/* Model step wrapper function for compatibility with a static main program */
void test_step(int_T tid)
{
  switch (tid) {
   case 0 :
    test_step0();
    break;

   case 1 :
    test_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void test_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(test_M, 2000.0);
  test_M->Timing.stepSize0 = 0.0002;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    test_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(test_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(test_M->rtwLogInfo, (NULL));
    rtliSetLogT(test_M->rtwLogInfo, "tout");
    rtliSetLogX(test_M->rtwLogInfo, "");
    rtliSetLogXFinal(test_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(test_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(test_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(test_M->rtwLogInfo, 0);
    rtliSetLogDecimation(test_M->rtwLogInfo, 1);
    rtliSetLogY(test_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(test_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(test_M->rtwLogInfo, (NULL));
  }

  /* External mode info */
  test_M->Sizes.checksums[0] = (2118232500U);
  test_M->Sizes.checksums[1] = (1677254575U);
  test_M->Sizes.checksums[2] = (2372940222U);
  test_M->Sizes.checksums[3] = (1776357827U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[48];
    test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)&test_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[5] = (sysRanDType *)&test_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[6] = (sysRanDType *)&test_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[7] = (sysRanDType *)&test_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[8] = (sysRanDType *)&test_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[9] = (sysRanDType *)&test_DW.IfActionSubsystem3_SubsysRanBC;
    systemRan[10] = (sysRanDType *)&test_DW.Intialization_SubsysRanBC;
    systemRan[11] = (sysRanDType *)&test_DW.Running_SubsysRanBC;
    systemRan[12] = (sysRanDType *)&test_DW.Running_SubsysRanBC;
    systemRan[13] = (sysRanDType *)&test_DW.Running_SubsysRanBC;
    systemRan[14] = (sysRanDType *)&test_DW.Running_SubsysRanBC;
    systemRan[15] = (sysRanDType *)&test_DW.Running_SubsysRanBC;
    systemRan[16] = (sysRanDType *)&test_DW.Running_SubsysRanBC;
    systemRan[17] = (sysRanDType *)&test_DW.Running_SubsysRanBC;
    systemRan[18] = (sysRanDType *)&test_DW.Running_SubsysRanBC;
    systemRan[19] = (sysRanDType *)&test_DW.Running_SubsysRanBC;
    systemRan[20] = (sysRanDType *)&test_DW.Running_SubsysRanBC;
    systemRan[21] = (sysRanDType *)&test_DW.Running_SubsysRanBC;
    systemRan[22] = (sysRanDType *)&test_DW.Running_SubsysRanBC;
    systemRan[23] = &rtAlwaysEnabled;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = &rtAlwaysEnabled;
    systemRan[26] = &rtAlwaysEnabled;
    systemRan[27] = &rtAlwaysEnabled;
    systemRan[28] = &rtAlwaysEnabled;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = &rtAlwaysEnabled;
    systemRan[31] = &rtAlwaysEnabled;
    systemRan[32] = &rtAlwaysEnabled;
    systemRan[33] = &rtAlwaysEnabled;
    systemRan[34] = &rtAlwaysEnabled;
    systemRan[35] = &rtAlwaysEnabled;
    systemRan[36] = &rtAlwaysEnabled;
    systemRan[37] = &rtAlwaysEnabled;
    systemRan[38] = &rtAlwaysEnabled;
    systemRan[39] = &rtAlwaysEnabled;
    systemRan[40] = &rtAlwaysEnabled;
    systemRan[41] = &rtAlwaysEnabled;
    systemRan[42] = &rtAlwaysEnabled;
    systemRan[43] = &rtAlwaysEnabled;
    systemRan[44] = &rtAlwaysEnabled;
    systemRan[45] = &rtAlwaysEnabled;
    systemRan[46] = &rtAlwaysEnabled;
    systemRan[47] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(test_M->extModeInfo,
      &test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(test_M->extModeInfo, test_M->Sizes.checksums);
    rteiSetTPtr(test_M->extModeInfo, rtmGetTPtr(test_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    test_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(test_M->rtwLogInfo, 0.0, rtmGetTFinal(test_M),
    test_M->Timing.stepSize0, (&rtmGetErrorStatus(test_M)));

  {
    beagleboneblue_bbblueDigitalW_T *obj;
    beagleboneblue_bbblueI2CMas_j_T *obj_0;
    beagleboneblue_bbblueI2CMaste_T *obj_2;
    beagleboneblue_bbblueMPU9250__T *obj_1;

    /* Start for RateTransition: '<Root>/Rate Transition' */
    test_B.RateTransition = test_P.RateTransition_InitialCondition;

    /* InitializeConditions for RateTransition: '<Root>/Rate Transition' */
    test_DW.RateTransition_Buffer0 = test_P.RateTransition_InitialCondition;

    /* InitializeConditions for Delay: '<Root>/Delay' */
    test_DW.Delay_DSTATE = test_P.Delay_InitialCondition_p;

    /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
    test_DW.DiscreteTimeIntegrator_DSTATE = test_P.DiscreteTimeIntegrator_IC_a;
    test_DW.DiscreteTimeIntegrator_PrevRese = 2;

    /* SystemInitialize for IfAction SubSystem: '<S4>/Intialization' */
    /* SystemInitialize for IfAction SubSystem: '<S5>/If Action Subsystem1' */
    /* Constant: '<S9>/Constant' */
    test_I2CMasterWrite_Init(&test_DW.I2CMasterWrite_p);

    /* Start for MATLABSystem: '<S9>/I2C Master Write1' */
    test_DW.obj_km.matlabCodegenIsDeleted = true;
    test_DW.obj_km.DefaultMaximumBusSpeedInHz = 400000.0;
    test_DW.obj_km.isInitialized = 0;
    test_DW.obj_km.matlabCodegenIsDeleted = false;
    obj_2 = &test_DW.obj_km;
    test_DW.obj_km.isSetupComplete = false;
    test_DW.obj_km.isInitialized = 1;
    test_B.ModeType = MW_I2C_MASTER;
    test_B.i2cname = 1;
    obj_2->MW_I2C_HANDLE = MW_I2C_Open(test_B.i2cname, test_B.ModeType);
    test_DW.obj_km.BusSpeed = 100000U;
    MW_I2C_SetBusSpeed(test_DW.obj_km.MW_I2C_HANDLE, test_DW.obj_km.BusSpeed);
    test_DW.obj_km.isSetupComplete = true;

    /* End of SystemInitialize for SubSystem: '<S5>/If Action Subsystem1' */

    /* SystemInitialize for IfAction SubSystem: '<S5>/If Action Subsystem2' */
    /* Constant: '<S10>/Constant' */
    test_I2CMasterWrite_Init(&test_DW.I2CMasterWrite);

    /* End of SystemInitialize for SubSystem: '<S5>/If Action Subsystem2' */

    /* SystemInitialize for IfAction SubSystem: '<S5>/If Action Subsystem3' */
    /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
    test_DW.DiscreteTimeIntegrator_DSTATE_b = test_P.DiscreteTimeIntegrator_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
    test_DW.DiscreteTimeIntegrator1_DSTATE = test_P.DiscreteTimeIntegrator1_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator2' */
    test_DW.DiscreteTimeIntegrator2_DSTATE = test_P.DiscreteTimeIntegrator2_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator3' */
    test_DW.DiscreteTimeIntegrator3_DSTATE = test_P.DiscreteTimeIntegrator3_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator4' */
    test_DW.DiscreteTimeIntegrator4_DSTATE = test_P.DiscreteTimeIntegrator4_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator5' */
    test_DW.DiscreteTimeIntegrator5_DSTATE = test_P.DiscreteTimeIntegrator5_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator10' */
    test_DW.DiscreteTimeIntegrator10_DSTATE = test_P.DiscreteTimeIntegrator10_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator11' */
    test_DW.DiscreteTimeIntegrator11_DSTATE = test_P.DiscreteTimeIntegrator11_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator12' */
    test_DW.DiscreteTimeIntegrator12_DSTATE = test_P.DiscreteTimeIntegrator12_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator13' */
    test_DW.DiscreteTimeIntegrator13_DSTATE = test_P.DiscreteTimeIntegrator13_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator14' */
    test_DW.DiscreteTimeIntegrator14_DSTATE = test_P.DiscreteTimeIntegrator14_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator6' */
    test_DW.DiscreteTimeIntegrator6_DSTATE = test_P.DiscreteTimeIntegrator6_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator7' */
    test_DW.DiscreteTimeIntegrator7_DSTATE = test_P.DiscreteTimeIntegrator7_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator8' */
    test_DW.DiscreteTimeIntegrator8_DSTATE = test_P.DiscreteTimeIntegrator8_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator9' */
    test_DW.DiscreteTimeIntegrator9_DSTATE = test_P.DiscreteTimeIntegrator9_IC;

    /* SystemInitialize for DiscreteIntegrator: '<S11>/Discrete-Time Integrator3' incorporates:
     *  Outport: '<S11>/Out1'
     */
    test_B.DiscreteTimeIntegrator3 = test_P.Out1_Y0;

    /* SystemInitialize for DiscreteIntegrator: '<S11>/Discrete-Time Integrator4' incorporates:
     *  Outport: '<S11>/Out1'
     */
    test_B.DiscreteTimeIntegrator4 = test_P.Out1_Y0;

    /* SystemInitialize for DiscreteIntegrator: '<S11>/Discrete-Time Integrator5' incorporates:
     *  Outport: '<S11>/Out1'
     */
    test_B.DiscreteTimeIntegrator5 = test_P.Out1_Y0;

    /* SystemInitialize for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' incorporates:
     *  Outport: '<S11>/Out1'
     */
    test_B.DiscreteTimeIntegrator = test_P.Out1_Y0;

    /* SystemInitialize for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' incorporates:
     *  Outport: '<S11>/Out1'
     */
    test_B.DiscreteTimeIntegrator1 = test_P.Out1_Y0;

    /* SystemInitialize for DiscreteIntegrator: '<S11>/Discrete-Time Integrator2' incorporates:
     *  Outport: '<S11>/Out1'
     */
    test_B.DiscreteTimeIntegrator2 = test_P.Out1_Y0;

    /* SystemInitialize for DiscreteIntegrator: '<S11>/Discrete-Time Integrator6' incorporates:
     *  Outport: '<S11>/Out2'
     */
    test_B.DiscreteTimeIntegrator6 = test_P.Out2_Y0;

    /* SystemInitialize for DiscreteIntegrator: '<S11>/Discrete-Time Integrator7' incorporates:
     *  Outport: '<S11>/Out2'
     */
    test_B.DiscreteTimeIntegrator7 = test_P.Out2_Y0;

    /* SystemInitialize for DiscreteIntegrator: '<S11>/Discrete-Time Integrator8' incorporates:
     *  Outport: '<S11>/Out2'
     */
    test_B.DiscreteTimeIntegrator8 = test_P.Out2_Y0;

    /* SystemInitialize for DiscreteIntegrator: '<S11>/Discrete-Time Integrator9' incorporates:
     *  Outport: '<S11>/Out2'
     */
    test_B.DiscreteTimeIntegrator9 = test_P.Out2_Y0;

    /* SystemInitialize for DiscreteIntegrator: '<S11>/Discrete-Time Integrator10' incorporates:
     *  Outport: '<S11>/Out2'
     */
    test_B.DiscreteTimeIntegrator10 = test_P.Out2_Y0;

    /* SystemInitialize for DiscreteIntegrator: '<S11>/Discrete-Time Integrator11' incorporates:
     *  Outport: '<S11>/Out2'
     */
    test_B.DiscreteTimeIntegrator11 = test_P.Out2_Y0;

    /* SystemInitialize for DiscreteIntegrator: '<S11>/Discrete-Time Integrator12' incorporates:
     *  Outport: '<S11>/Out2'
     */
    test_B.DiscreteTimeIntegrator12 = test_P.Out2_Y0;

    /* SystemInitialize for DiscreteIntegrator: '<S11>/Discrete-Time Integrator13' incorporates:
     *  Outport: '<S11>/Out2'
     */
    test_B.DiscreteTimeIntegrator13 = test_P.Out2_Y0;

    /* SystemInitialize for DiscreteIntegrator: '<S11>/Discrete-Time Integrator14' incorporates:
     *  Outport: '<S11>/Out2'
     */
    test_B.DiscreteTimeIntegrator14 = test_P.Out2_Y0;

    /* End of SystemInitialize for SubSystem: '<S5>/If Action Subsystem3' */
    for (test_B.i = 0; test_B.i < 6; test_B.i++) {
      /* SystemInitialize for Gain: '<S5>/Gain' incorporates:
       *  Outport: '<S5>/MPU6050 Bias'
       */
      test_B.Gain[test_B.i] = test_P.MPU6050Bias_Y0;
    }

    for (test_B.i = 0; test_B.i < 9; test_B.i++) {
      /* SystemInitialize for Gain: '<S5>/Gain1' incorporates:
       *  Outport: '<S5>/MPU9250 Bias'
       */
      test_B.Gain1[test_B.i] = test_P.MPU9250Bias_Y0;
    }

    /* End of SystemInitialize for SubSystem: '<S4>/Intialization' */

    /* SystemInitialize for IfAction SubSystem: '<S4>/Running' */
    /* InitializeConditions for Delay: '<S19>/Delay' */
    test_DW.Delay_DSTATE_g = test_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S19>/Delay1' */
    test_DW.Delay1_DSTATE = test_P.Delay1_InitialCondition;

    /* InitializeConditions for Delay: '<S19>/Delay2' */
    test_DW.Delay2_DSTATE = test_P.Delay2_InitialCondition;

    /* InitializeConditions for Delay: '<S21>/Delay' */
    test_DW.Delay_DSTATE_l = test_P.Delay_InitialCondition_f;

    /* InitializeConditions for Delay: '<S21>/Delay1' */
    test_DW.Delay1_DSTATE_k = test_P.Delay1_InitialCondition_p;

    /* InitializeConditions for Delay: '<S21>/Delay2' */
    test_DW.Delay2_DSTATE_c = test_P.Delay2_InitialCondition_l;

    /* SystemInitialize for Sum: '<S13>/Sum' incorporates:
     *  Outport: '<S6>/Euler Angles'
     */
    test_B.Sum[0] = test_P.EulerAngles_Y0;

    /* SystemInitialize for Outport: '<S6>/Accel//I' */
    test_B.y[0] = test_P.AccelI_Y0;

    /* SystemInitialize for Sum: '<S13>/Sum' incorporates:
     *  Outport: '<S6>/Euler Angles'
     */
    test_B.Sum[1] = test_P.EulerAngles_Y0;

    /* SystemInitialize for Outport: '<S6>/Accel//I' */
    test_B.y[1] = test_P.AccelI_Y0;

    /* SystemInitialize for Sum: '<S13>/Sum' incorporates:
     *  Outport: '<S6>/Euler Angles'
     */
    test_B.Sum[2] = test_P.EulerAngles_Y0;

    /* SystemInitialize for Outport: '<S6>/Accel//I' */
    test_B.y[2] = test_P.AccelI_Y0;

    /* End of SystemInitialize for SubSystem: '<S4>/Running' */

    /* Start for MATLABSystem: '<Root>/Digital Write' */
    test_DW.obj_ma.matlabCodegenIsDeleted = true;
    test_DW.obj_ma.isInitialized = 0;
    test_DW.obj_ma.matlabCodegenIsDeleted = false;
    obj = &test_DW.obj_ma;
    test_DW.obj_ma.isSetupComplete = false;
    test_DW.obj_ma.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(97, 1);
    test_DW.obj_ma.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write1' */
    test_DW.obj_l.matlabCodegenIsDeleted = true;
    test_DW.obj_l.isInitialized = 0;
    test_DW.obj_l.matlabCodegenIsDeleted = false;
    obj = &test_DW.obj_l;
    test_DW.obj_l.isSetupComplete = false;
    test_DW.obj_l.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(98, 1);
    test_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S36>/I2C Master Read' */
    test_DW.obj_f.matlabCodegenIsDeleted = true;
    test_DW.obj_f.DefaultMaximumBusSpeedInHz = 400000.0;
    test_DW.obj_f.isInitialized = 0;
    test_DW.obj_f.SampleTime = -1.0;
    test_DW.obj_f.matlabCodegenIsDeleted = false;
    test_DW.obj_f.SampleTime = test_P.I2CMasterRead_SampleTime_e;
    obj_0 = &test_DW.obj_f;
    test_DW.obj_f.isSetupComplete = false;
    test_DW.obj_f.isInitialized = 1;
    test_B.ModeType = MW_I2C_MASTER;
    test_B.i2cname = 1;
    obj_0->MW_I2C_HANDLE = MW_I2C_Open(test_B.i2cname, test_B.ModeType);
    test_DW.obj_f.BusSpeed = 100000U;
    MW_I2C_SetBusSpeed(test_DW.obj_f.MW_I2C_HANDLE, test_DW.obj_f.BusSpeed);
    test_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S36>/I2C Master Read1' */
    test_DW.obj_m.matlabCodegenIsDeleted = true;
    test_DW.obj_m.DefaultMaximumBusSpeedInHz = 400000.0;
    test_DW.obj_m.isInitialized = 0;
    test_DW.obj_m.SampleTime = -1.0;
    test_DW.obj_m.matlabCodegenIsDeleted = false;
    test_DW.obj_m.SampleTime = test_P.I2CMasterRead1_SampleTime_c;
    obj_0 = &test_DW.obj_m;
    test_DW.obj_m.isSetupComplete = false;
    test_DW.obj_m.isInitialized = 1;
    test_B.ModeType = MW_I2C_MASTER;
    test_B.i2cname = 1;
    obj_0->MW_I2C_HANDLE = MW_I2C_Open(test_B.i2cname, test_B.ModeType);
    test_DW.obj_m.BusSpeed = 100000U;
    MW_I2C_SetBusSpeed(test_DW.obj_m.MW_I2C_HANDLE, test_DW.obj_m.BusSpeed);
    test_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S36>/I2C Master Read4' */
    test_DW.obj_pp.matlabCodegenIsDeleted = true;
    test_DW.obj_pp.DefaultMaximumBusSpeedInHz = 400000.0;
    test_DW.obj_pp.isInitialized = 0;
    test_DW.obj_pp.SampleTime = -1.0;
    test_DW.obj_pp.matlabCodegenIsDeleted = false;
    test_DW.obj_pp.SampleTime = test_P.I2CMasterRead4_SampleTime_h;
    obj_0 = &test_DW.obj_pp;
    test_DW.obj_pp.isSetupComplete = false;
    test_DW.obj_pp.isInitialized = 1;
    test_B.ModeType = MW_I2C_MASTER;
    test_B.i2cname = 1;
    obj_0->MW_I2C_HANDLE = MW_I2C_Open(test_B.i2cname, test_B.ModeType);
    test_DW.obj_pp.BusSpeed = 100000U;
    MW_I2C_SetBusSpeed(test_DW.obj_pp.MW_I2C_HANDLE, test_DW.obj_pp.BusSpeed);
    test_DW.obj_pp.isSetupComplete = true;

    /* Start for MATLABSystem: '<S36>/I2C Master Read5' */
    test_DW.obj_p.matlabCodegenIsDeleted = true;
    test_DW.obj_p.DefaultMaximumBusSpeedInHz = 400000.0;
    test_DW.obj_p.isInitialized = 0;
    test_DW.obj_p.SampleTime = -1.0;
    test_DW.obj_p.matlabCodegenIsDeleted = false;
    test_DW.obj_p.SampleTime = test_P.I2CMasterRead5_SampleTime_h;
    obj_0 = &test_DW.obj_p;
    test_DW.obj_p.isSetupComplete = false;
    test_DW.obj_p.isInitialized = 1;
    test_B.ModeType = MW_I2C_MASTER;
    test_B.i2cname = 1;
    obj_0->MW_I2C_HANDLE = MW_I2C_Open(test_B.i2cname, test_B.ModeType);
    test_DW.obj_p.BusSpeed = 100000U;
    MW_I2C_SetBusSpeed(test_DW.obj_p.MW_I2C_HANDLE, test_DW.obj_p.BusSpeed);
    test_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S36>/I2C Master Read2' */
    test_DW.obj_k.matlabCodegenIsDeleted = true;
    test_DW.obj_k.DefaultMaximumBusSpeedInHz = 400000.0;
    test_DW.obj_k.isInitialized = 0;
    test_DW.obj_k.SampleTime = -1.0;
    test_DW.obj_k.matlabCodegenIsDeleted = false;
    test_DW.obj_k.SampleTime = test_P.I2CMasterRead2_SampleTime_i;
    obj_0 = &test_DW.obj_k;
    test_DW.obj_k.isSetupComplete = false;
    test_DW.obj_k.isInitialized = 1;
    test_B.ModeType = MW_I2C_MASTER;
    test_B.i2cname = 1;
    obj_0->MW_I2C_HANDLE = MW_I2C_Open(test_B.i2cname, test_B.ModeType);
    test_DW.obj_k.BusSpeed = 100000U;
    MW_I2C_SetBusSpeed(test_DW.obj_k.MW_I2C_HANDLE, test_DW.obj_k.BusSpeed);
    test_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S36>/I2C Master Read3' */
    test_DW.obj_g.matlabCodegenIsDeleted = true;
    test_DW.obj_g.DefaultMaximumBusSpeedInHz = 400000.0;
    test_DW.obj_g.isInitialized = 0;
    test_DW.obj_g.SampleTime = -1.0;
    test_DW.obj_g.matlabCodegenIsDeleted = false;
    test_DW.obj_g.SampleTime = test_P.I2CMasterRead3_SampleTime_m;
    obj_0 = &test_DW.obj_g;
    test_DW.obj_g.isSetupComplete = false;
    test_DW.obj_g.isInitialized = 1;
    test_B.ModeType = MW_I2C_MASTER;
    test_B.i2cname = 1;
    obj_0->MW_I2C_HANDLE = MW_I2C_Open(test_B.i2cname, test_B.ModeType);
    test_DW.obj_g.BusSpeed = 100000U;
    MW_I2C_SetBusSpeed(test_DW.obj_g.MW_I2C_HANDLE, test_DW.obj_g.BusSpeed);
    test_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S35>/I2C Master Read' */
    test_DW.obj_c.matlabCodegenIsDeleted = true;
    test_DW.obj_c.DefaultMaximumBusSpeedInHz = 400000.0;
    test_DW.obj_c.isInitialized = 0;
    test_DW.obj_c.SampleTime = -1.0;
    test_DW.obj_c.matlabCodegenIsDeleted = false;
    test_DW.obj_c.SampleTime = test_P.I2CMasterRead_SampleTime;
    obj_0 = &test_DW.obj_c;
    test_DW.obj_c.isSetupComplete = false;
    test_DW.obj_c.isInitialized = 1;
    test_B.ModeType = MW_I2C_MASTER;
    test_B.i2cname = 1;
    obj_0->MW_I2C_HANDLE = MW_I2C_Open(test_B.i2cname, test_B.ModeType);
    test_DW.obj_c.BusSpeed = 100000U;
    MW_I2C_SetBusSpeed(test_DW.obj_c.MW_I2C_HANDLE, test_DW.obj_c.BusSpeed);
    test_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S35>/I2C Master Read1' */
    test_DW.obj_pu.matlabCodegenIsDeleted = true;
    test_DW.obj_pu.DefaultMaximumBusSpeedInHz = 400000.0;
    test_DW.obj_pu.isInitialized = 0;
    test_DW.obj_pu.SampleTime = -1.0;
    test_DW.obj_pu.matlabCodegenIsDeleted = false;
    test_DW.obj_pu.SampleTime = test_P.I2CMasterRead1_SampleTime;
    obj_0 = &test_DW.obj_pu;
    test_DW.obj_pu.isSetupComplete = false;
    test_DW.obj_pu.isInitialized = 1;
    test_B.ModeType = MW_I2C_MASTER;
    test_B.i2cname = 1;
    obj_0->MW_I2C_HANDLE = MW_I2C_Open(test_B.i2cname, test_B.ModeType);
    test_DW.obj_pu.BusSpeed = 100000U;
    MW_I2C_SetBusSpeed(test_DW.obj_pu.MW_I2C_HANDLE, test_DW.obj_pu.BusSpeed);
    test_DW.obj_pu.isSetupComplete = true;

    /* Start for MATLABSystem: '<S35>/I2C Master Read4' */
    test_DW.obj_d.matlabCodegenIsDeleted = true;
    test_DW.obj_d.DefaultMaximumBusSpeedInHz = 400000.0;
    test_DW.obj_d.isInitialized = 0;
    test_DW.obj_d.SampleTime = -1.0;
    test_DW.obj_d.matlabCodegenIsDeleted = false;
    test_DW.obj_d.SampleTime = test_P.I2CMasterRead4_SampleTime;
    obj_0 = &test_DW.obj_d;
    test_DW.obj_d.isSetupComplete = false;
    test_DW.obj_d.isInitialized = 1;
    test_B.ModeType = MW_I2C_MASTER;
    test_B.i2cname = 1;
    obj_0->MW_I2C_HANDLE = MW_I2C_Open(test_B.i2cname, test_B.ModeType);
    test_DW.obj_d.BusSpeed = 100000U;
    MW_I2C_SetBusSpeed(test_DW.obj_d.MW_I2C_HANDLE, test_DW.obj_d.BusSpeed);
    test_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S35>/I2C Master Read5' */
    test_DW.obj_my.matlabCodegenIsDeleted = true;
    test_DW.obj_my.DefaultMaximumBusSpeedInHz = 400000.0;
    test_DW.obj_my.isInitialized = 0;
    test_DW.obj_my.SampleTime = -1.0;
    test_DW.obj_my.matlabCodegenIsDeleted = false;
    test_DW.obj_my.SampleTime = test_P.I2CMasterRead5_SampleTime;
    obj_0 = &test_DW.obj_my;
    test_DW.obj_my.isSetupComplete = false;
    test_DW.obj_my.isInitialized = 1;
    test_B.ModeType = MW_I2C_MASTER;
    test_B.i2cname = 1;
    obj_0->MW_I2C_HANDLE = MW_I2C_Open(test_B.i2cname, test_B.ModeType);
    test_DW.obj_my.BusSpeed = 100000U;
    MW_I2C_SetBusSpeed(test_DW.obj_my.MW_I2C_HANDLE, test_DW.obj_my.BusSpeed);
    test_DW.obj_my.isSetupComplete = true;

    /* Start for MATLABSystem: '<S35>/I2C Master Read2' */
    test_DW.obj_du.matlabCodegenIsDeleted = true;
    test_DW.obj_du.DefaultMaximumBusSpeedInHz = 400000.0;
    test_DW.obj_du.isInitialized = 0;
    test_DW.obj_du.SampleTime = -1.0;
    test_DW.obj_du.matlabCodegenIsDeleted = false;
    test_DW.obj_du.SampleTime = test_P.I2CMasterRead2_SampleTime;
    obj_0 = &test_DW.obj_du;
    test_DW.obj_du.isSetupComplete = false;
    test_DW.obj_du.isInitialized = 1;
    test_B.ModeType = MW_I2C_MASTER;
    test_B.i2cname = 1;
    obj_0->MW_I2C_HANDLE = MW_I2C_Open(test_B.i2cname, test_B.ModeType);
    test_DW.obj_du.BusSpeed = 100000U;
    MW_I2C_SetBusSpeed(test_DW.obj_du.MW_I2C_HANDLE, test_DW.obj_du.BusSpeed);
    test_DW.obj_du.isSetupComplete = true;

    /* Start for MATLABSystem: '<S35>/I2C Master Read3' */
    test_DW.obj_pl.matlabCodegenIsDeleted = true;
    test_DW.obj_pl.DefaultMaximumBusSpeedInHz = 400000.0;
    test_DW.obj_pl.isInitialized = 0;
    test_DW.obj_pl.SampleTime = -1.0;
    test_DW.obj_pl.matlabCodegenIsDeleted = false;
    test_DW.obj_pl.SampleTime = test_P.I2CMasterRead3_SampleTime;
    obj_0 = &test_DW.obj_pl;
    test_DW.obj_pl.isSetupComplete = false;
    test_DW.obj_pl.isInitialized = 1;
    test_B.ModeType = MW_I2C_MASTER;
    test_B.i2cname = 1;
    obj_0->MW_I2C_HANDLE = MW_I2C_Open(test_B.i2cname, test_B.ModeType);
    test_DW.obj_pl.BusSpeed = 100000U;
    MW_I2C_SetBusSpeed(test_DW.obj_pl.MW_I2C_HANDLE, test_DW.obj_pl.BusSpeed);
    test_DW.obj_pl.isSetupComplete = true;

    /* Start for MATLABSystem: '<S8>/MPU9250' */
    test_DW.obj.i2cObjmpu.matlabCodegenIsDeleted = true;
    test_DW.obj.i2cObjak8963.matlabCodegenIsDeleted = true;
    test_DW.obj.matlabCodegenIsDeleted = true;
    obj_1 = &test_DW.obj;
    test_DW.obj.AK8963SensitivityAdj[0] = 0.0;
    test_DW.obj.AK8963SensitivityAdj[1] = 0.0;
    test_DW.obj.AK8963SensitivityAdj[2] = 0.0;
    test_DW.obj.AK8963Data[0] = 0.0;
    test_DW.obj.AK8963Data[1] = 0.0;
    test_DW.obj.AK8963Data[2] = 0.0;
    test_DW.obj.isInitialized = 0;
    test_DW.obj.SampleTime = -1.0;
    obj_1->i2cObjmpu.DefaultMaximumBusSpeedInHz = 400000.0;
    obj_1->i2cObjmpu.matlabCodegenIsDeleted = false;
    obj_1->i2cObjak8963.DefaultMaximumBusSpeedInHz = 400000.0;
    obj_1->i2cObjak8963.matlabCodegenIsDeleted = false;
    test_DW.obj.matlabCodegenIsDeleted = false;
    test_DW.obj.SampleTime = test_P.MPU9250_SampleTime;
    test_SystemCore_setup(&test_DW.obj);
  }
}

/* Model terminate function */
void test_terminate(void)
{
  j_beagleboneblue_bbblueI2CMas_T *obj_0;
  k_beagleboneblue_bbblueI2CMas_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  if (!test_DW.obj_ma.matlabCodegenIsDeleted) {
    test_DW.obj_ma.matlabCodegenIsDeleted = true;
    if ((test_DW.obj_ma.isInitialized == 1) && test_DW.obj_ma.isSetupComplete) {
      MW_digitalIO_close(test_DW.obj_ma.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  if (!test_DW.obj_l.matlabCodegenIsDeleted) {
    test_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((test_DW.obj_l.isInitialized == 1) && test_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(test_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S36>/I2C Master Read' */
  if (!test_DW.obj_f.matlabCodegenIsDeleted) {
    test_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((test_DW.obj_f.isInitialized == 1) && test_DW.obj_f.isSetupComplete) {
      MW_I2C_Close(test_DW.obj_f.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S36>/I2C Master Read' */

  /* Terminate for MATLABSystem: '<S36>/I2C Master Read1' */
  if (!test_DW.obj_m.matlabCodegenIsDeleted) {
    test_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((test_DW.obj_m.isInitialized == 1) && test_DW.obj_m.isSetupComplete) {
      MW_I2C_Close(test_DW.obj_m.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S36>/I2C Master Read1' */

  /* Terminate for MATLABSystem: '<S36>/I2C Master Read4' */
  if (!test_DW.obj_pp.matlabCodegenIsDeleted) {
    test_DW.obj_pp.matlabCodegenIsDeleted = true;
    if ((test_DW.obj_pp.isInitialized == 1) && test_DW.obj_pp.isSetupComplete) {
      MW_I2C_Close(test_DW.obj_pp.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S36>/I2C Master Read4' */

  /* Terminate for MATLABSystem: '<S36>/I2C Master Read5' */
  if (!test_DW.obj_p.matlabCodegenIsDeleted) {
    test_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((test_DW.obj_p.isInitialized == 1) && test_DW.obj_p.isSetupComplete) {
      MW_I2C_Close(test_DW.obj_p.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S36>/I2C Master Read5' */

  /* Terminate for MATLABSystem: '<S36>/I2C Master Read2' */
  if (!test_DW.obj_k.matlabCodegenIsDeleted) {
    test_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((test_DW.obj_k.isInitialized == 1) && test_DW.obj_k.isSetupComplete) {
      MW_I2C_Close(test_DW.obj_k.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S36>/I2C Master Read2' */

  /* Terminate for MATLABSystem: '<S36>/I2C Master Read3' */
  if (!test_DW.obj_g.matlabCodegenIsDeleted) {
    test_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((test_DW.obj_g.isInitialized == 1) && test_DW.obj_g.isSetupComplete) {
      MW_I2C_Close(test_DW.obj_g.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S36>/I2C Master Read3' */

  /* Terminate for MATLABSystem: '<S35>/I2C Master Read' */
  if (!test_DW.obj_c.matlabCodegenIsDeleted) {
    test_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((test_DW.obj_c.isInitialized == 1) && test_DW.obj_c.isSetupComplete) {
      MW_I2C_Close(test_DW.obj_c.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/I2C Master Read' */

  /* Terminate for MATLABSystem: '<S35>/I2C Master Read1' */
  if (!test_DW.obj_pu.matlabCodegenIsDeleted) {
    test_DW.obj_pu.matlabCodegenIsDeleted = true;
    if ((test_DW.obj_pu.isInitialized == 1) && test_DW.obj_pu.isSetupComplete) {
      MW_I2C_Close(test_DW.obj_pu.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/I2C Master Read1' */

  /* Terminate for MATLABSystem: '<S35>/I2C Master Read4' */
  if (!test_DW.obj_d.matlabCodegenIsDeleted) {
    test_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((test_DW.obj_d.isInitialized == 1) && test_DW.obj_d.isSetupComplete) {
      MW_I2C_Close(test_DW.obj_d.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/I2C Master Read4' */

  /* Terminate for MATLABSystem: '<S35>/I2C Master Read5' */
  if (!test_DW.obj_my.matlabCodegenIsDeleted) {
    test_DW.obj_my.matlabCodegenIsDeleted = true;
    if ((test_DW.obj_my.isInitialized == 1) && test_DW.obj_my.isSetupComplete) {
      MW_I2C_Close(test_DW.obj_my.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/I2C Master Read5' */

  /* Terminate for MATLABSystem: '<S35>/I2C Master Read2' */
  if (!test_DW.obj_du.matlabCodegenIsDeleted) {
    test_DW.obj_du.matlabCodegenIsDeleted = true;
    if ((test_DW.obj_du.isInitialized == 1) && test_DW.obj_du.isSetupComplete) {
      MW_I2C_Close(test_DW.obj_du.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/I2C Master Read2' */

  /* Terminate for MATLABSystem: '<S35>/I2C Master Read3' */
  if (!test_DW.obj_pl.matlabCodegenIsDeleted) {
    test_DW.obj_pl.matlabCodegenIsDeleted = true;
    if ((test_DW.obj_pl.isInitialized == 1) && test_DW.obj_pl.isSetupComplete) {
      MW_I2C_Close(test_DW.obj_pl.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/I2C Master Read3' */

  /* Terminate for MATLABSystem: '<S8>/MPU9250' */
  if (!test_DW.obj.matlabCodegenIsDeleted) {
    test_DW.obj.matlabCodegenIsDeleted = true;
  }

  obj = &test_DW.obj.i2cObjak8963;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  obj_0 = &test_DW.obj.i2cObjmpu;
  if (!obj_0->matlabCodegenIsDeleted) {
    obj_0->matlabCodegenIsDeleted = true;
    if (obj_0->isInitialized == 1) {
      obj_0->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S8>/MPU9250' */

  /* Terminate for IfAction SubSystem: '<S4>/Intialization' */
  /* Terminate for IfAction SubSystem: '<S5>/If Action Subsystem2' */
  test_I2CMasterWrite_Term(&test_DW.I2CMasterWrite);

  /* End of Terminate for SubSystem: '<S5>/If Action Subsystem2' */

  /* Terminate for IfAction SubSystem: '<S5>/If Action Subsystem1' */
  test_I2CMasterWrite_Term(&test_DW.I2CMasterWrite_p);

  /* Terminate for MATLABSystem: '<S9>/I2C Master Write1' */
  if (!test_DW.obj_km.matlabCodegenIsDeleted) {
    test_DW.obj_km.matlabCodegenIsDeleted = true;
    if ((test_DW.obj_km.isInitialized == 1) && test_DW.obj_km.isSetupComplete) {
      MW_I2C_Close(test_DW.obj_km.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/I2C Master Write1' */
  /* End of Terminate for SubSystem: '<S5>/If Action Subsystem1' */
  /* End of Terminate for SubSystem: '<S4>/Intialization' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
