/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: hrtf_v5_fest_olhead_ed1_38_R_L_2025a.h
 *
 * Code generated for Simulink model 'hrtf_v5_fest_olhead_ed1_38_R_L_2025a'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Mon Oct 26 16:02:01 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef hrtf_v5_fest_olhead_ed1_38_R_L_2025a_h_
#define hrtf_v5_fest_olhead_ed1_38_R_L_2025a_h_
#ifndef hrtf_v5_fest_olhead_ed1_38_R_L_2025a_COMMON_INCLUDES_
#define hrtf_v5_fest_olhead_ed1_38_R_L_2025a_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif               /* hrtf_v5_fest_olhead_ed1_38_R_L_2025a_COMMON_INCLUDES_ */

#include "hrtf_v5_fest_olhead_ed1_38_R_L_2025a_types.h"
#include <string.h>

extern void hrtf_v5_fest_olhead_ed1_38_Init(void);
extern void hrtf_v5_fest_olhead_ed1_38_R_L_(const int16_T *rtu_audio_in, const
  uint32_T *rtu_channel_select, int16_T *rty_audio_out);

/* Model reference registration function */
extern void hrtf_v5_fest_olhead__initialize(const char_T **rt_errorStatus);

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
 * '<Root>' : 'hrtf_v5_fest_olhead_ed1_38_R_L_2025a'
 * '<S1>'   : 'hrtf_v5_fest_olhead_ed1_38_R_L_2025a/DelayBlock'
 */
#endif                             /* hrtf_v5_fest_olhead_ed1_38_R_L_2025a_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
