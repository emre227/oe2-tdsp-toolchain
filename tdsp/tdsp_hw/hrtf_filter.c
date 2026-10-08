/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: hrtf_filter.c
 *
 * Code generated for Simulink model 'hrtf_filter'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Wed Sep 30 14:02:14 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Custom Processor->Custom Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "hrtf_filter.h"
#include "rtwtypes.h"
#include <string.h>
#include "hrtf_filter_private.h"

/* Model step function */
void hrtf_filter_step(RT_MODEL_hrtf_filter_T *const hrtf_filter_M, int16_T
                      hrtf_filter_U_audio_in, uint8_T hrtf_filter_U_channel,
                      uint8_T hrtf_filter_U_source, int16_T
                      *hrtf_filter_Y_audio_out)
{
  DW_hrtf_filter_T *hrtf_filter_DW = hrtf_filter_M->dwork;
  int32_T acc1;
  int32_T cff;
  int32_T j;
  int32_T tableOffset;
  uint8_T tmp;
  uint8_T tmp_0;

  /* LookupNDDirect: '<Root>/Direct Lookup Table (n-D)' incorporates:
   *  Inport: '<Root>/channel'
   *  Inport: '<Root>/source'
   *
   * About '<Root>/Direct Lookup Table (n-D)':
   *  3-dimensional Direct Look-Up returning a Vector,
   *  which is contiguous for column-major array
   *     Remove protection against out-of-range input in generated code: 'off'
   *   */
  if (hrtf_filter_U_source <= 1) {
    tmp = hrtf_filter_U_source;
  } else {
    tmp = 1U;
  }

  if (hrtf_filter_U_channel <= 1) {
    tmp_0 = hrtf_filter_U_channel;
  } else {
    tmp_0 = 1U;
  }

  tableOffset = tmp * 400 + tmp_0 * 200;

  /* DiscreteFir: '<Root>/HRIR-FIR' incorporates:
   *  Inport: '<Root>/audio_in'
   *  LookupNDDirect: '<Root>/Direct Lookup Table (n-D)'
   *
   * About '<Root>/Direct Lookup Table (n-D)':
   *  3-dimensional Direct Look-Up returning a Vector,
   *  which is contiguous for column-major array
   *     Remove protection against out-of-range input in generated code: 'off'
   *   */
  acc1 = hrtf_filter_U_audio_in *
    hrtf_filter_ConstP.DirectLookupTablenD_table[tableOffset];
  cff = 1;
  for (j = hrtf_filter_DW->HRIRFIR_circBuf; j < 199; j++) {
    acc1 += hrtf_filter_ConstP.DirectLookupTablenD_table[cff + tableOffset] *
      hrtf_filter_DW->HRIRFIR_states[j];
    cff++;
  }

  for (j = 0; j < hrtf_filter_DW->HRIRFIR_circBuf; j++) {
    acc1 += hrtf_filter_ConstP.DirectLookupTablenD_table[cff + tableOffset] *
      hrtf_filter_DW->HRIRFIR_states[j];
    cff++;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  DiscreteFir: '<Root>/HRIR-FIR'
   */
  tableOffset = acc1 >> 15;
  if (tableOffset > 32767) {
    tableOffset = 32767;
  } else if (tableOffset < -32768) {
    tableOffset = -32768;
  }

  /* Outport: '<Root>/audio_out' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  *hrtf_filter_Y_audio_out = (int16_T)tableOffset;

  /* Update for DiscreteFir: '<Root>/HRIR-FIR' incorporates:
   *  Inport: '<Root>/audio_in'
   */
  /* Update circular buffer index */
  hrtf_filter_DW->HRIRFIR_circBuf--;
  if (hrtf_filter_DW->HRIRFIR_circBuf < 0) {
    hrtf_filter_DW->HRIRFIR_circBuf = 198;
  }

  /* Update circular buffer */
  hrtf_filter_DW->HRIRFIR_states[hrtf_filter_DW->HRIRFIR_circBuf] =
    hrtf_filter_U_audio_in;

  /* End of Update for DiscreteFir: '<Root>/HRIR-FIR' */
}

/* Model initialize function */
void hrtf_filter_initialize(RT_MODEL_hrtf_filter_T *const hrtf_filter_M, int16_T
  *hrtf_filter_U_audio_in, uint8_T *hrtf_filter_U_channel, uint8_T
  *hrtf_filter_U_source, int16_T *hrtf_filter_Y_audio_out)
{
  DW_hrtf_filter_T *hrtf_filter_DW = hrtf_filter_M->dwork;

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)hrtf_filter_DW, 0,
                sizeof(DW_hrtf_filter_T));

  /* external inputs */
  *hrtf_filter_U_audio_in = 0;
  *hrtf_filter_U_channel = 0U;
  *hrtf_filter_U_source = 0U;

  /* external outputs */
  *hrtf_filter_Y_audio_out = 0;

  /* InitializeConditions for DiscreteFir: '<Root>/HRIR-FIR' */
  hrtf_filter_DW->HRIRFIR_circBuf = 0;
  memset(&hrtf_filter_DW->HRIRFIR_states[0], 0, 199U * sizeof(int16_T));
}

/* Model terminate function */
void hrtf_filter_terminate(RT_MODEL_hrtf_filter_T *const hrtf_filter_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(hrtf_filter_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
