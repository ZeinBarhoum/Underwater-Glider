/*
 * File: test_types.h
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

#ifndef RTW_HEADER_test_types_h_
#define RTW_HEADER_test_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"

/* Model Code Variants */

/* Custom Type definition for MATLABSystem: '<S10>/I2C Master Write' */
#include "MW_SVD.h"
#include "MW_I2C.h"
#ifndef struct_tag_PfJfPjTlv5xn2muIac7clC
#define struct_tag_PfJfPjTlv5xn2muIac7clC

struct tag_PfJfPjTlv5xn2muIac7clC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /*struct_tag_PfJfPjTlv5xn2muIac7clC*/

#ifndef typedef_beagleboneblue_bbblueI2CMaste_T
#define typedef_beagleboneblue_bbblueI2CMaste_T

typedef struct tag_PfJfPjTlv5xn2muIac7clC beagleboneblue_bbblueI2CMaste_T;

#endif                               /*typedef_beagleboneblue_bbblueI2CMaste_T*/

#ifndef struct_tag_171cozH0LfHg3YiuM1mAZD
#define struct_tag_171cozH0LfHg3YiuM1mAZD

struct tag_171cozH0LfHg3YiuM1mAZD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
};

#endif                                 /*struct_tag_171cozH0LfHg3YiuM1mAZD*/

#ifndef typedef_beagleboneblue_bbblueDigitalW_T
#define typedef_beagleboneblue_bbblueDigitalW_T

typedef struct tag_171cozH0LfHg3YiuM1mAZD beagleboneblue_bbblueDigitalW_T;

#endif                               /*typedef_beagleboneblue_bbblueDigitalW_T*/

#ifndef struct_tag_LSlpPjGQLckXEulsNSkYVG
#define struct_tag_LSlpPjGQLckXEulsNSkYVG

struct tag_LSlpPjGQLckXEulsNSkYVG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
  MW_Handle_Type MW_I2C_HANDLE;
  real_T SampleTime;
};

#endif                                 /*struct_tag_LSlpPjGQLckXEulsNSkYVG*/

#ifndef typedef_beagleboneblue_bbblueI2CMas_j_T
#define typedef_beagleboneblue_bbblueI2CMas_j_T

typedef struct tag_LSlpPjGQLckXEulsNSkYVG beagleboneblue_bbblueI2CMas_j_T;

#endif                               /*typedef_beagleboneblue_bbblueI2CMas_j_T*/

#ifndef struct_tag_wp3yTd5GcaknegGRkGBYYE
#define struct_tag_wp3yTd5GcaknegGRkGBYYE

struct tag_wp3yTd5GcaknegGRkGBYYE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /*struct_tag_wp3yTd5GcaknegGRkGBYYE*/

#ifndef typedef_j_beagleboneblue_bbblueI2CMas_T
#define typedef_j_beagleboneblue_bbblueI2CMas_T

typedef struct tag_wp3yTd5GcaknegGRkGBYYE j_beagleboneblue_bbblueI2CMas_T;

#endif                               /*typedef_j_beagleboneblue_bbblueI2CMas_T*/

#ifndef struct_tag_3Ds1yFMaUW7xxaYclfWoT
#define struct_tag_3Ds1yFMaUW7xxaYclfWoT

struct tag_3Ds1yFMaUW7xxaYclfWoT
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /*struct_tag_3Ds1yFMaUW7xxaYclfWoT*/

#ifndef typedef_k_beagleboneblue_bbblueI2CMas_T
#define typedef_k_beagleboneblue_bbblueI2CMas_T

typedef struct tag_3Ds1yFMaUW7xxaYclfWoT k_beagleboneblue_bbblueI2CMas_T;

#endif                               /*typedef_k_beagleboneblue_bbblueI2CMas_T*/

#ifndef struct_tag_FQe18RdefTmVQcyBKwML0E
#define struct_tag_FQe18RdefTmVQcyBKwML0E

struct tag_FQe18RdefTmVQcyBKwML0E
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  real_T SampleTime;
  j_beagleboneblue_bbblueI2CMas_T i2cObjmpu;
  k_beagleboneblue_bbblueI2CMas_T i2cObjak8963;
  real_T AK8963SensitivityAdj[3];
  real_T AK8963Data[3];
  boolean_T MPUConnect;
  boolean_T AK8963Connect;
};

#endif                                 /*struct_tag_FQe18RdefTmVQcyBKwML0E*/

#ifndef typedef_beagleboneblue_bbblueMPU9250__T
#define typedef_beagleboneblue_bbblueMPU9250__T

typedef struct tag_FQe18RdefTmVQcyBKwML0E beagleboneblue_bbblueMPU9250__T;

#endif                               /*typedef_beagleboneblue_bbblueMPU9250__T*/

/* Parameters (default storage) */
typedef struct P_test_T_ P_test_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_test_T RT_MODEL_test_T;

#endif                                 /* RTW_HEADER_test_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
