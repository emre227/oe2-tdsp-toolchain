/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: HRTF_IIR_Baris_FixedPoint_v2.h
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

#ifndef HRTF_IIR_Baris_FixedPoint_v2_h_
#define HRTF_IIR_Baris_FixedPoint_v2_h_
#ifndef HRTF_IIR_Baris_FixedPoint_v2_COMMON_INCLUDES_
#define HRTF_IIR_Baris_FixedPoint_v2_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                       /* HRTF_IIR_Baris_FixedPoint_v2_COMMON_INCLUDES_ */

#include "HRTF_IIR_Baris_FixedPoint_v2_types.h"
#include <string.h>

extern void HRTF_IIR_Baris_FixedPoint__Init(void);
extern void HRTF_IIR_Baris_FixedPoint_v2(const int16_T *rtu_audio_in, const
  uint32_T *rtu_channel_select, int16_T *rty_audio_out);

/* Model reference registration function */
extern void HRTF_IIR_Baris_Fixed_initialize(const char_T **rt_errorStatus);

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
 * '<Root>' : 'HRTF_IIR_Baris_FixedPoint_v2'
 * '<S1>'   : 'HRTF_IIR_Baris_FixedPoint_v2/DelayBlock'
 */
#endif                                 /* HRTF_IIR_Baris_FixedPoint_v2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
