/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: hrtf_filter.h
 *
 * Code generated for Simulink model 'hrtf_filter'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Wed Oct 14 12:20:48 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Custom Processor->Custom Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef hrtf_filter_h_
#define hrtf_filter_h_
#ifndef hrtf_filter_COMMON_INCLUDES_
#define hrtf_filter_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* hrtf_filter_COMMON_INCLUDES_ */

#include "hrtf_filter_types.h"
#include <string.h>

/* Block states (default storage) for model 'hrtf_filter' */
typedef struct {
  int32_T HRIRFIR_circBuf;             /* '<Root>/HRIR-FIR' */
  int16_T HRIRFIR_states[199];         /* '<Root>/HRIR-FIR' */
} DW_hrtf_filter_f_T;

/* Real-time Model Data Structure */
struct tag_RTM_hrtf_filter_T {
  const char_T **errorStatus;
};

typedef struct {
  DW_hrtf_filter_f_T rtdw;
  RT_MODEL_hrtf_filter_T rtm;
} MdlrefDW_hrtf_filter_T;

/* Model reference registration function */
extern void hrtf_filter_initialize(const char_T **rt_errorStatus,
  RT_MODEL_hrtf_filter_T *const hrtf_filter_M, DW_hrtf_filter_f_T *localDW);
extern void hrtf_filter_Init(DW_hrtf_filter_f_T *localDW);
extern void hrtf_filter(const int16_T *rtu_audio_in, const uint32_T *rtu_channel,
  const uint32_T *rtu_source, int16_T *rty_audio_out, DW_hrtf_filter_f_T
  *localDW);

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
 * '<Root>' : 'hrtf_filter'
 */
#endif                                 /* hrtf_filter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
