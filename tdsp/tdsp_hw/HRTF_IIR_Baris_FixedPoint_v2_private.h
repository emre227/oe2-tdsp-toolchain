/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: HRTF_IIR_Baris_FixedPoint_v2_private.h
 *
 * Code generated for Simulink model 'HRTF_IIR_Baris_FixedPoint_v2'.
 *
 * Model version                  : 1.27
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Wed Oct 28 14:34:49 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef HRTF_IIR_Baris_FixedPoint_v2_private_h_
#define HRTF_IIR_Baris_FixedPoint_v2_private_h_
#include "rtwtypes.h"
#include "HRTF_IIR_Baris_FixedPoint_v2_types.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */

/* Block states (default storage) for model 'HRTF_IIR_Baris_FixedPoint_v2' */
typedef struct {
  int32_T DiscreteTransferFcn_states[16];/* '<Root>/Discrete Transfer Fcn' */
  int32_T Delay_DSTATE[480];           /* '<S1>/Delay' */
  uint32_T CircBufIdx;                 /* '<S1>/Delay' */
  int32_T DiscreteTransferFcn_tmp;     /* '<Root>/Discrete Transfer Fcn' */
} DW_HRTF_IIR_Baris_FixedPoin_f_T;

/* Real-time Model Data Structure */
struct tag_RTM_HRTF_IIR_Baris_FixedP_T {
  const char_T **errorStatus;
};

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
#define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

typedef struct {
  RT_MODEL_HRTF_IIR_Baris_Fixed_T rtm;
} MdlrefDW_HRTF_IIR_Baris_Fixed_T;

extern const int32_T rtCP_pooled_ipIdEyszf3kY[34];
extern const int32_T rtCP_pooled_IQzfHecpam72[34];
extern const uint32_T rtCP_pooled_eevNIaisYY3q[2];
extern const uint32_T rtCP_pooled_1wl0o1SFteiT[2];

#define rtCP_Beta_table                rtCP_pooled_ipIdEyszf3kY  /* Computed Parameter: rtCP_Beta_table
                                                                  * Referenced by: '<Root>/Beta'
                                                                  */
#define rtCP_Alpha_table               rtCP_pooled_IQzfHecpam72  /* Computed Parameter: rtCP_Alpha_table
                                                                  * Referenced by: '<Root>/Alpha'
                                                                  */
#define rtCP_DeltaT_table              rtCP_pooled_eevNIaisYY3q  /* Computed Parameter: rtCP_DeltaT_table
                                                                  * Referenced by: '<Root>/DeltaT'
                                                                  */
#define rtCP_Amplitude_table           rtCP_pooled_1wl0o1SFteiT  /* Computed Parameter: rtCP_Amplitude_table
                                                                  * Referenced by: '<Root>/Amplitude'
                                                                  */

extern MdlrefDW_HRTF_IIR_Baris_Fixed_T HRTF_IIR_Baris_FixedPo_MdlrefDW;

/* Block states (default storage) */
extern DW_HRTF_IIR_Baris_FixedPoin_f_T HRTF_IIR_Baris_FixedPoint_v2_DW;

#endif                             /* HRTF_IIR_Baris_FixedPoint_v2_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
