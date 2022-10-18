/*
 * File: test.h
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

#ifndef RTW_HEADER_test_h_
#define RTW_HEADER_test_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef test_COMMON_INCLUDES_
#define test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_digitalIO.h"
#include "MW_I2C.h"
#include "MW_MPU9250.h"
#endif                                 /* test_COMMON_INCLUDES_ */

#include "test_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block states (default storage) for system '<S10>/I2C Master Write' */
typedef struct {
  beagleboneblue_bbblueI2CMaste_T obj; /* '<S10>/I2C Master Write' */
  boolean_T objisempty;                /* '<S10>/I2C Master Write' */
} DW_I2CMasterWrite_test_T;

/* Block signals (default storage) */
typedef struct {
  real_T R[9];
  real_T r[9];
  real_T dv[9];
  real_T dv1[9];
  real_T dv2[9];
  real_T TmpSignalConversionAtSFun_h[6];/* '<S16>/MATLAB Function' */
  real_T psquared[4];
  real_T AccelData[3];
  real_T GyroData[3];
  real_T MagData[3];
  real_T Gain_f[3];                    /* '<S23>/Gain' */
  int32_T i_data[3];
  int32_T ii_data[3];
  boolean_T b_b[9];
  uint8_T b_SwappedDataBytes[9];
  uint8_T SwappedDataBytes[8];
  MW_I2C_Mode_Type ModeType;
  uint32_T i2cname;
  MW_I2C_Mode_Type ModeType_m;
  uint32_T i2cname_c;
  real_T RateTransition;               /* '<Root>/Rate Transition' */
  real_T Mass_desired;                 /* '<Root>/Mass_desired' */
  real_T Time_desired;                 /* '<Root>/Time_desired' */
  real_T DigitalClock;                 /* '<S4>/Digital Clock' */
  real_T Sum[3];                       /* '<S13>/Sum' */
  real_T y[3];                         /* '<S16>/MATLAB Function' */
  real_T Gain[6];                      /* '<S5>/Gain' */
  real_T Gain1[9];                     /* '<S5>/Gain1' */
  real_T DiscreteTimeIntegrator;       /* '<S11>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1;      /* '<S11>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator2;      /* '<S11>/Discrete-Time Integrator2' */
  real_T DiscreteTimeIntegrator3;      /* '<S11>/Discrete-Time Integrator3' */
  real_T DiscreteTimeIntegrator4;      /* '<S11>/Discrete-Time Integrator4' */
  real_T DiscreteTimeIntegrator5;      /* '<S11>/Discrete-Time Integrator5' */
  real_T DiscreteTimeIntegrator10;     /* '<S11>/Discrete-Time Integrator10' */
  real_T DiscreteTimeIntegrator11;     /* '<S11>/Discrete-Time Integrator11' */
  real_T DiscreteTimeIntegrator12;     /* '<S11>/Discrete-Time Integrator12' */
  real_T DiscreteTimeIntegrator13;     /* '<S11>/Discrete-Time Integrator13' */
  real_T DiscreteTimeIntegrator14;     /* '<S11>/Discrete-Time Integrator14' */
  real_T DiscreteTimeIntegrator6;      /* '<S11>/Discrete-Time Integrator6' */
  real_T DiscreteTimeIntegrator7;      /* '<S11>/Discrete-Time Integrator7' */
  real_T DiscreteTimeIntegrator8;      /* '<S11>/Discrete-Time Integrator8' */
  real_T DiscreteTimeIntegrator9;      /* '<S11>/Discrete-Time Integrator9' */
  real_T scale;
  real_T invpa;
  real_T k;
  real_T Gain2;                        /* '<S36>/Gain2' */
  real_T Gain5;                        /* '<S36>/Gain5' */
  real_T Gain3;                        /* '<S36>/Gain3' */
  real_T Gain2_k;                      /* '<S8>/Gain2' */
  real_T Gain1_k;                      /* '<S8>/Gain1' */
  real_T Gain_c;                       /* '<S8>/Gain' */
  real_T Gain2_b;                      /* '<S35>/Gain2' */
  real_T Gain5_h;                      /* '<S35>/Gain5' */
  real_T Gain3_c;                      /* '<S35>/Gain3' */
  real_T GyroData_b;
  real_T ac2;
  real_T ad2;
  real_T bc2;
  real_T bd2;
  real_T cd2;
  real_T aasq;
  real_T n;
  real_T y_p;
  real_T b_x;
  real_T absx;
  real_T u1;
  real_T c_x;
  real_T absx_c;
  real_T b_x_f;
  real_T absx_g;
  uint8_T b_RegisterValue[7];
  uint8_T output_raw[7];
  uint8_T b_RegisterValue_g[6];
  uint8_T output_raw_m[6];
  int32_T i;
  int32_T idx;
  int32_T b_ii;
  int32_T ii_data_n;
  int32_T xpageoffset;
  int32_T i_p;
  uint8_T temp[3];
  uint8_T output_raw_l[3];
  uint8_T x_tmp[3];
} B_test_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  beagleboneblue_bbblueMPU9250__T obj; /* '<S8>/MPU9250' */
  beagleboneblue_bbblueI2CMas_j_T obj_p;/* '<S36>/I2C Master Read5' */
  beagleboneblue_bbblueI2CMas_j_T obj_pp;/* '<S36>/I2C Master Read4' */
  beagleboneblue_bbblueI2CMas_j_T obj_g;/* '<S36>/I2C Master Read3' */
  beagleboneblue_bbblueI2CMas_j_T obj_k;/* '<S36>/I2C Master Read2' */
  beagleboneblue_bbblueI2CMas_j_T obj_m;/* '<S36>/I2C Master Read1' */
  beagleboneblue_bbblueI2CMas_j_T obj_f;/* '<S36>/I2C Master Read' */
  beagleboneblue_bbblueI2CMas_j_T obj_my;/* '<S35>/I2C Master Read5' */
  beagleboneblue_bbblueI2CMas_j_T obj_d;/* '<S35>/I2C Master Read4' */
  beagleboneblue_bbblueI2CMas_j_T obj_pl;/* '<S35>/I2C Master Read3' */
  beagleboneblue_bbblueI2CMas_j_T obj_du;/* '<S35>/I2C Master Read2' */
  beagleboneblue_bbblueI2CMas_j_T obj_pu;/* '<S35>/I2C Master Read1' */
  beagleboneblue_bbblueI2CMas_j_T obj_c;/* '<S35>/I2C Master Read' */
  beagleboneblue_bbblueI2CMaste_T obj_km;/* '<S9>/I2C Master Write1' */
  beagleboneblue_bbblueDigitalW_T obj_l;/* '<Root>/Digital Write1' */
  beagleboneblue_bbblueDigitalW_T obj_ma;/* '<Root>/Digital Write' */
  real_T Delay_DSTATE;                 /* '<Root>/Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
  real_T Delay_DSTATE_g;               /* '<S19>/Delay' */
  real_T Delay1_DSTATE;                /* '<S19>/Delay1' */
  real_T Delay2_DSTATE;                /* '<S19>/Delay2' */
  real_T Delay_DSTATE_l;               /* '<S21>/Delay' */
  real_T Delay1_DSTATE_k;              /* '<S21>/Delay1' */
  real_T Delay2_DSTATE_c;              /* '<S21>/Delay2' */
  real_T DiscreteTimeIntegrator_DSTATE_b;/* '<S11>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S11>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator2_DSTATE;/* '<S11>/Discrete-Time Integrator2' */
  real_T DiscreteTimeIntegrator3_DSTATE;/* '<S11>/Discrete-Time Integrator3' */
  real_T DiscreteTimeIntegrator4_DSTATE;/* '<S11>/Discrete-Time Integrator4' */
  real_T DiscreteTimeIntegrator5_DSTATE;/* '<S11>/Discrete-Time Integrator5' */
  real_T DiscreteTimeIntegrator10_DSTATE;/* '<S11>/Discrete-Time Integrator10' */
  real_T DiscreteTimeIntegrator11_DSTATE;/* '<S11>/Discrete-Time Integrator11' */
  real_T DiscreteTimeIntegrator12_DSTATE;/* '<S11>/Discrete-Time Integrator12' */
  real_T DiscreteTimeIntegrator13_DSTATE;/* '<S11>/Discrete-Time Integrator13' */
  real_T DiscreteTimeIntegrator14_DSTATE;/* '<S11>/Discrete-Time Integrator14' */
  real_T DiscreteTimeIntegrator6_DSTATE;/* '<S11>/Discrete-Time Integrator6' */
  real_T DiscreteTimeIntegrator7_DSTATE;/* '<S11>/Discrete-Time Integrator7' */
  real_T DiscreteTimeIntegrator8_DSTATE;/* '<S11>/Discrete-Time Integrator8' */
  real_T DiscreteTimeIntegrator9_DSTATE;/* '<S11>/Discrete-Time Integrator9' */
  real_T RateTransition_Buffer0;       /* '<Root>/Rate Transition' */
  struct {
    void *LoggedData;
  } Scope_time2_PWORK;                 /* '<Root>/Scope_time2' */

  struct {
    void *LoggedData;
  } Scope_time3_PWORK;                 /* '<Root>/Scope_time3' */

  struct {
    void *LoggedData;
  } Scope_accel_PWORK;                 /* '<Root>/Scope_accel' */

  struct {
    void *LoggedData;
  } Scope_angles_PWORK;                /* '<Root>/Scope_angles' */

  struct {
    void *LoggedData;
  } Scope_time_PWORK;                  /* '<Root>/Scope_time' */

  int8_T DiscreteTimeIntegrator_PrevRese;/* '<Root>/Discrete-Time Integrator' */
  int8_T Running_SubsysRanBC;          /* '<S4>/Running' */
  int8_T Intialization_SubsysRanBC;    /* '<S4>/Intialization' */
  int8_T IfActionSubsystem3_SubsysRanBC;/* '<S5>/If Action Subsystem3' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S5>/If Action Subsystem1' */
  int8_T IfActionSubsystem2_SubsysRanBC;/* '<S5>/If Action Subsystem2' */
  DW_I2CMasterWrite_test_T I2CMasterWrite_p;/* '<S10>/I2C Master Write' */
  DW_I2CMasterWrite_test_T I2CMasterWrite;/* '<S10>/I2C Master Write' */
} DW_test_T;

/* Parameters (default storage) */
struct P_test_T_ {
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S2>/Constant'
                                      */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S1>/Constant'
                                       */
  real_T Constant_Value;               /* Expression: 80
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 3
                                        * Referenced by: '<S9>/Constant1'
                                        */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S11>/Out1'
                                        */
  real_T Out2_Y0;                      /* Computed Parameter: Out2_Y0
                                        * Referenced by: '<S11>/Out2'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S11>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S11>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                           * Referenced by: '<S11>/Discrete-Time Integrator1'
                           */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<S11>/Discrete-Time Integrator1'
                                        */
  real_T DiscreteTimeIntegrator2_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator2_gainval
                           * Referenced by: '<S11>/Discrete-Time Integrator2'
                           */
  real_T DiscreteTimeIntegrator2_IC;   /* Expression: 0
                                        * Referenced by: '<S11>/Discrete-Time Integrator2'
                                        */
  real_T DiscreteTimeIntegrator3_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator3_gainval
                           * Referenced by: '<S11>/Discrete-Time Integrator3'
                           */
  real_T DiscreteTimeIntegrator3_IC;   /* Expression: 0
                                        * Referenced by: '<S11>/Discrete-Time Integrator3'
                                        */
  real_T DiscreteTimeIntegrator4_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator4_gainval
                           * Referenced by: '<S11>/Discrete-Time Integrator4'
                           */
  real_T DiscreteTimeIntegrator4_IC;   /* Expression: 0
                                        * Referenced by: '<S11>/Discrete-Time Integrator4'
                                        */
  real_T DiscreteTimeIntegrator5_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator5_gainval
                           * Referenced by: '<S11>/Discrete-Time Integrator5'
                           */
  real_T DiscreteTimeIntegrator5_IC;   /* Expression: 0
                                        * Referenced by: '<S11>/Discrete-Time Integrator5'
                                        */
  real_T DiscreteTimeIntegrator10_gainva;
                          /* Computed Parameter: DiscreteTimeIntegrator10_gainva
                           * Referenced by: '<S11>/Discrete-Time Integrator10'
                           */
  real_T DiscreteTimeIntegrator10_IC;  /* Expression: 0
                                        * Referenced by: '<S11>/Discrete-Time Integrator10'
                                        */
  real_T DiscreteTimeIntegrator11_gainva;
                          /* Computed Parameter: DiscreteTimeIntegrator11_gainva
                           * Referenced by: '<S11>/Discrete-Time Integrator11'
                           */
  real_T DiscreteTimeIntegrator11_IC;  /* Expression: 0
                                        * Referenced by: '<S11>/Discrete-Time Integrator11'
                                        */
  real_T DiscreteTimeIntegrator12_gainva;
                          /* Computed Parameter: DiscreteTimeIntegrator12_gainva
                           * Referenced by: '<S11>/Discrete-Time Integrator12'
                           */
  real_T DiscreteTimeIntegrator12_IC;  /* Expression: 0
                                        * Referenced by: '<S11>/Discrete-Time Integrator12'
                                        */
  real_T DiscreteTimeIntegrator13_gainva;
                          /* Computed Parameter: DiscreteTimeIntegrator13_gainva
                           * Referenced by: '<S11>/Discrete-Time Integrator13'
                           */
  real_T DiscreteTimeIntegrator13_IC;  /* Expression: 0
                                        * Referenced by: '<S11>/Discrete-Time Integrator13'
                                        */
  real_T DiscreteTimeIntegrator14_gainva;
                          /* Computed Parameter: DiscreteTimeIntegrator14_gainva
                           * Referenced by: '<S11>/Discrete-Time Integrator14'
                           */
  real_T DiscreteTimeIntegrator14_IC;  /* Expression: 0
                                        * Referenced by: '<S11>/Discrete-Time Integrator14'
                                        */
  real_T DiscreteTimeIntegrator6_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator6_gainval
                           * Referenced by: '<S11>/Discrete-Time Integrator6'
                           */
  real_T DiscreteTimeIntegrator6_IC;   /* Expression: 0
                                        * Referenced by: '<S11>/Discrete-Time Integrator6'
                                        */
  real_T DiscreteTimeIntegrator7_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator7_gainval
                           * Referenced by: '<S11>/Discrete-Time Integrator7'
                           */
  real_T DiscreteTimeIntegrator7_IC;   /* Expression: 0
                                        * Referenced by: '<S11>/Discrete-Time Integrator7'
                                        */
  real_T DiscreteTimeIntegrator8_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator8_gainval
                           * Referenced by: '<S11>/Discrete-Time Integrator8'
                           */
  real_T DiscreteTimeIntegrator8_IC;   /* Expression: 0
                                        * Referenced by: '<S11>/Discrete-Time Integrator8'
                                        */
  real_T DiscreteTimeIntegrator9_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator9_gainval
                           * Referenced by: '<S11>/Discrete-Time Integrator9'
                           */
  real_T DiscreteTimeIntegrator9_IC;   /* Expression: 0
                                        * Referenced by: '<S11>/Discrete-Time Integrator9'
                                        */
  real_T MPU6050Bias_Y0;               /* Computed Parameter: MPU6050Bias_Y0
                                        * Referenced by: '<S5>/MPU6050 Bias'
                                        */
  real_T MPU9250Bias_Y0;               /* Computed Parameter: MPU9250Bias_Y0
                                        * Referenced by: '<S5>/MPU9250 Bias'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/30
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/30
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T EulerAngles_Y0;               /* Computed Parameter: EulerAngles_Y0
                                        * Referenced by: '<S6>/Euler Angles'
                                        */
  real_T AccelI_Y0;                    /* Computed Parameter: AccelI_Y0
                                        * Referenced by: '<S6>/Accel//I'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 1/2
                                        * Referenced by: '<S23>/Gain'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 1/2
                                        * Referenced by: '<S26>/Gain'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 0.1
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S19>/Delay'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S19>/Delay1'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S19>/Delay2'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: 0.9
                                        * Referenced by: '<S13>/Gain1'
                                        */
  real_T Delay_InitialCondition_f;     /* Expression: 0.0
                                        * Referenced by: '<S21>/Delay'
                                        */
  real_T Delay1_InitialCondition_p;    /* Expression: 0.0
                                        * Referenced by: '<S21>/Delay1'
                                        */
  real_T Delay2_InitialCondition_l;    /* Expression: 0.0
                                        * Referenced by: '<S21>/Delay2'
                                        */
  real_T Gain2_Gain;                   /* Expression: 0
                                        * Referenced by: '<S13>/Gain2'
                                        */
  real_T I2CMasterRead_SampleTime;     /* Expression: 0.1
                                        * Referenced by: '<S35>/I2C Master Read'
                                        */
  real_T I2CMasterRead1_SampleTime;    /* Expression: 0.1
                                        * Referenced by: '<S35>/I2C Master Read1'
                                        */
  real_T I2CMasterRead2_SampleTime;    /* Expression: 0.1
                                        * Referenced by: '<S35>/I2C Master Read2'
                                        */
  real_T I2CMasterRead3_SampleTime;    /* Expression: 0.1
                                        * Referenced by: '<S35>/I2C Master Read3'
                                        */
  real_T I2CMasterRead4_SampleTime;    /* Expression: 0.1
                                        * Referenced by: '<S35>/I2C Master Read4'
                                        */
  real_T I2CMasterRead5_SampleTime;    /* Expression: 0.1
                                        * Referenced by: '<S35>/I2C Master Read5'
                                        */
  real_T Constant3_Value;              /* Expression: 65536
                                        * Referenced by: '<S35>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S35>/Constant4'
                                        */
  real_T Constant6_Value;              /* Expression: 65536
                                        * Referenced by: '<S35>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 0
                                        * Referenced by: '<S35>/Constant7'
                                        */
  real_T Constant_Value_a;             /* Expression: 65536
                                        * Referenced by: '<S35>/Constant'
                                        */
  real_T Constant1_Value_a;            /* Expression: 0
                                        * Referenced by: '<S35>/Constant1'
                                        */
  real_T I2CMasterRead_SampleTime_e;   /* Expression: 0.1
                                        * Referenced by: '<S36>/I2C Master Read'
                                        */
  real_T I2CMasterRead1_SampleTime_c;  /* Expression: 0.1
                                        * Referenced by: '<S36>/I2C Master Read1'
                                        */
  real_T I2CMasterRead2_SampleTime_i;  /* Expression: 0.1
                                        * Referenced by: '<S36>/I2C Master Read2'
                                        */
  real_T I2CMasterRead3_SampleTime_m;  /* Expression: 0.1
                                        * Referenced by: '<S36>/I2C Master Read3'
                                        */
  real_T I2CMasterRead4_SampleTime_h;  /* Expression: 0.1
                                        * Referenced by: '<S36>/I2C Master Read4'
                                        */
  real_T I2CMasterRead5_SampleTime_h;  /* Expression: 0.1
                                        * Referenced by: '<S36>/I2C Master Read5'
                                        */
  real_T Constant3_Value_a;            /* Expression: 65536
                                        * Referenced by: '<S36>/Constant3'
                                        */
  real_T Constant4_Value_f;            /* Expression: 0
                                        * Referenced by: '<S36>/Constant4'
                                        */
  real_T Constant6_Value_a;            /* Expression: 65536
                                        * Referenced by: '<S36>/Constant6'
                                        */
  real_T Constant7_Value_i;            /* Expression: 0
                                        * Referenced by: '<S36>/Constant7'
                                        */
  real_T Constant_Value_d;             /* Expression: 65536
                                        * Referenced by: '<S36>/Constant'
                                        */
  real_T Constant1_Value_n;            /* Expression: 0
                                        * Referenced by: '<S36>/Constant1'
                                        */
  real_T MPU9250_SampleTime;           /* Expression: 0.1
                                        * Referenced by: '<S8>/MPU9250'
                                        */
  real_T Pitch_desired_Value;          /* Expression: 28.3746
                                        * Referenced by: '<Root>/Pitch_desired'
                                        */
  real_T RateTransition_InitialCondition;/* Expression: 0
                                          * Referenced by: '<Root>/Rate Transition'
                                          */
  real_T DeadZone_Start;               /* Expression: -5
                                        * Referenced by: '<Root>/Dead Zone'
                                        */
  real_T DeadZone_End;                 /* Expression: 5
                                        * Referenced by: '<Root>/Dead Zone'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 15
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Delay_InitialCondition_p;     /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay'
                                        */
  real_T DiscreteTimeIntegrator_gainva_p;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_p
                           * Referenced by: '<Root>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_a;  /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1000
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Step_Time;                    /* Expression: 31
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Mass_desired_Value;           /* Expression: 0.21905
                                        * Referenced by: '<Root>/Mass_desired'
                                        */
  real_T Time_desired_Value;           /* Expression: 30
                                        * Referenced by: '<Root>/Time_desired'
                                        */
  real_T Gain2_Gain_m;                 /* Expression: 250/32768
                                        * Referenced by: '<S36>/Gain2'
                                        */
  real_T Gain5_Gain;                   /* Expression: 250/32768
                                        * Referenced by: '<S36>/Gain5'
                                        */
  real_T Gain3_Gain;                   /* Expression: 250/32768
                                        * Referenced by: '<S36>/Gain3'
                                        */
  real_T Gain2_Gain_o;                 /* Expression: 9.81*2/32768
                                        * Referenced by: '<S35>/Gain2'
                                        */
  real_T Gain5_Gain_d;                 /* Expression: 9.81*2/32768
                                        * Referenced by: '<S35>/Gain5'
                                        */
  real_T Gain3_Gain_k;                 /* Expression: 9.81*2/32768
                                        * Referenced by: '<S35>/Gain3'
                                        */
  real_T Constant_Value_j[3];          /* Expression: [22.73,70.49,-38.6495]
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Gain2_Gain_f;                 /* Expression: 1/45.3705
                                        * Referenced by: '<S8>/Gain2'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: 1/45.01
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 1/44.45
                                        * Referenced by: '<S8>/Gain'
                                        */
  int16_T Switch_Threshold;            /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S36>/Switch'
                                        */
  int16_T Switch2_Threshold;           /* Computed Parameter: Switch2_Threshold
                                        * Referenced by: '<S36>/Switch2'
                                        */
  int16_T Switch1_Threshold;           /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<S36>/Switch1'
                                        */
  int16_T Switch_Threshold_j;          /* Computed Parameter: Switch_Threshold_j
                                        * Referenced by: '<S35>/Switch'
                                        */
  int16_T Switch2_Threshold_k;        /* Computed Parameter: Switch2_Threshold_k
                                       * Referenced by: '<S35>/Switch2'
                                       */
  int16_T Switch1_Threshold_j;        /* Computed Parameter: Switch1_Threshold_j
                                       * Referenced by: '<S35>/Switch1'
                                       */
  int8_T Gain_Gain_g;                  /* Computed Parameter: Gain_Gain_g
                                        * Referenced by: '<S36>/Gain'
                                        */
  int8_T Gain4_Gain;                   /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S36>/Gain4'
                                        */
  int8_T Gain1_Gain_c;                 /* Computed Parameter: Gain1_Gain_c
                                        * Referenced by: '<S36>/Gain1'
                                        */
  int8_T Gain_Gain_f;                  /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S35>/Gain'
                                        */
  int8_T Gain4_Gain_d;                 /* Computed Parameter: Gain4_Gain_d
                                        * Referenced by: '<S35>/Gain4'
                                        */
  int8_T Gain1_Gain_i;                 /* Computed Parameter: Gain1_Gain_i
                                        * Referenced by: '<S35>/Gain1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_test_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint16_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_test_T test_P;

/* Block signals (default storage) */
extern B_test_T test_B;

/* Block states (default storage) */
extern DW_test_T test_DW;

/* External function called from main */
extern void test_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void test_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void test_initialize(void);
extern void test_step(int_T tid);
extern void test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_test_T *const test_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'test'
 * '<S1>'   : 'test/Compare To Constant'
 * '<S2>'   : 'test/Compare To Constant1'
 * '<S3>'   : 'test/MATLAB Function'
 * '<S4>'   : 'test/Sensor Fusion// MPU9250 MPU6050'
 * '<S5>'   : 'test/Sensor Fusion// MPU9250 MPU6050/Intialization'
 * '<S6>'   : 'test/Sensor Fusion// MPU9250 MPU6050/Running'
 * '<S7>'   : 'test/Sensor Fusion// MPU9250 MPU6050/Subsystem'
 * '<S8>'   : 'test/Sensor Fusion// MPU9250 MPU6050/Subsystem1'
 * '<S9>'   : 'test/Sensor Fusion// MPU9250 MPU6050/Intialization/If Action Subsystem1'
 * '<S10>'  : 'test/Sensor Fusion// MPU9250 MPU6050/Intialization/If Action Subsystem2'
 * '<S11>'  : 'test/Sensor Fusion// MPU9250 MPU6050/Intialization/If Action Subsystem3'
 * '<S12>'  : 'test/Sensor Fusion// MPU9250 MPU6050/Running/Acceleration in Inertial Frame'
 * '<S13>'  : 'test/Sensor Fusion// MPU9250 MPU6050/Running/Orientation Measure'
 * '<S14>'  : 'test/Sensor Fusion// MPU9250 MPU6050/Running/Remove Bias'
 * '<S15>'  : 'test/Sensor Fusion// MPU9250 MPU6050/Running/Acceleration in Inertial Frame/Gravity Measure B frame'
 * '<S16>'  : 'test/Sensor Fusion// MPU9250 MPU6050/Running/Acceleration in Inertial Frame/Gravity Measure_I frame'
 * '<S17>'  : 'test/Sensor Fusion// MPU9250 MPU6050/Running/Acceleration in Inertial Frame/Gravity Measure B frame/MATLAB Function'
 * '<S18>'  : 'test/Sensor Fusion// MPU9250 MPU6050/Running/Acceleration in Inertial Frame/Gravity Measure_I frame/MATLAB Function'
 * '<S19>'  : 'test/Sensor Fusion// MPU9250 MPU6050/Running/Orientation Measure/Gyro 9250 Angles'
 * '<S20>'  : 'test/Sensor Fusion// MPU9250 MPU6050/Running/Orientation Measure/Mag Accel Angles'
 * '<S21>'  : 'test/Sensor Fusion// MPU9250 MPU6050/Running/Orientation Measure/Subsystem2'
 * '<S22>'  : 'test/Sensor Fusion// MPU9250 MPU6050/Running/Orientation Measure/Gyro 9250 Angles/MATLAB Function'
 * '<S23>'  : 'test/Sensor Fusion// MPU9250 MPU6050/Running/Orientation Measure/Mag Accel Angles/Combine Accel'
 * '<S24>'  : 'test/Sensor Fusion// MPU9250 MPU6050/Running/Orientation Measure/Mag Accel Angles/Combine Accel and Mag'
 * '<S25>'  : 'test/Sensor Fusion// MPU9250 MPU6050/Running/Orientation Measure/Mag Accel Angles/Combine Accel and Mag1'
 * '<S26>'  : 'test/Sensor Fusion// MPU9250 MPU6050/Running/Orientation Measure/Mag Accel Angles/Combine Accel2'
 * '<S27>'  : 'test/Sensor Fusion// MPU9250 MPU6050/Running/Orientation Measure/Mag Accel Angles/MATLAB Function2'
 * '<S28>'  : 'test/Sensor Fusion// MPU9250 MPU6050/Running/Orientation Measure/Mag Accel Angles/Combine Accel and Mag/MATLAB Function'
 * '<S29>'  : 'test/Sensor Fusion// MPU9250 MPU6050/Running/Orientation Measure/Mag Accel Angles/Combine Accel and Mag/MATLAB Function1'
 * '<S30>'  : 'test/Sensor Fusion// MPU9250 MPU6050/Running/Orientation Measure/Mag Accel Angles/Combine Accel and Mag/MATLAB Function2'
 * '<S31>'  : 'test/Sensor Fusion// MPU9250 MPU6050/Running/Orientation Measure/Mag Accel Angles/Combine Accel and Mag1/MATLAB Function'
 * '<S32>'  : 'test/Sensor Fusion// MPU9250 MPU6050/Running/Orientation Measure/Mag Accel Angles/Combine Accel and Mag1/MATLAB Function1'
 * '<S33>'  : 'test/Sensor Fusion// MPU9250 MPU6050/Running/Orientation Measure/Mag Accel Angles/Combine Accel and Mag1/MATLAB Function2'
 * '<S34>'  : 'test/Sensor Fusion// MPU9250 MPU6050/Running/Orientation Measure/Subsystem2/MATLAB Function'
 * '<S35>'  : 'test/Sensor Fusion// MPU9250 MPU6050/Subsystem/MPU6050_Accelerometer'
 * '<S36>'  : 'test/Sensor Fusion// MPU9250 MPU6050/Subsystem/MPU6050_Gyroscope'
 */
#endif                                 /* RTW_HEADER_test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
