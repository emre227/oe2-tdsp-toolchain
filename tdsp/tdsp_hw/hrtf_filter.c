/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: hrtf_filter.c
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

#include "hrtf_filter.h"
#include "rtwtypes.h"
#include <string.h>
#include "hrtf_filter_private.h"

/* System initialize for referenced model: 'hrtf_filter' */
void hrtf_filter_Init(DW_hrtf_filter_f_T *localDW)
{
  /* InitializeConditions for DiscreteFir: '<Root>/HRIR-FIR' */
  localDW->HRIRFIR_circBuf = 0;
  memset(&localDW->HRIRFIR_states[0], 0, 199U * sizeof(int16_T));
}

/* Output and update for referenced model: 'hrtf_filter' */
void hrtf_filter(const int16_T *rtu_audio_in, const uint32_T *rtu_channel, const
                 uint32_T *rtu_source, int16_T *rty_audio_out,
                 DW_hrtf_filter_f_T *localDW)
{
  int32_T acc1;
  int32_T cff;
  int32_T j;
  int32_T tableOffset;
  uint32_T tmp;
  uint32_T tmp_0;

  /* LookupNDDirect: '<Root>/Direct Lookup Table (n-D)'
   *
   * About '<Root>/Direct Lookup Table (n-D)':
   *  3-dimensional Direct Look-Up returning a Vector,
   *  which is contiguous for column-major array
   *     Remove protection against out-of-range input in generated code: 'off'
   *   */
  if (*rtu_source <= 1U) {
    tmp = *rtu_source;
  } else {
    tmp = 1U;
  }

  if (*rtu_channel <= 1U) {
    tmp_0 = *rtu_channel;
  } else {
    tmp_0 = 1U;
  }

  tableOffset = (int32_T)tmp * 400 + (int32_T)tmp_0 * 200;

  /* DiscreteFir: '<Root>/HRIR-FIR' incorporates:
   *  LookupNDDirect: '<Root>/Direct Lookup Table (n-D)'
   *
   * About '<Root>/Direct Lookup Table (n-D)':
   *  3-dimensional Direct Look-Up returning a Vector,
   *  which is contiguous for column-major array
   *     Remove protection against out-of-range input in generated code: 'off'
   *   */
  acc1 = *rtu_audio_in * rtCP_DirectLookupTablenD_table[tableOffset];
  cff = 1;
  for (j = localDW->HRIRFIR_circBuf; j < 199; j++) {
    acc1 += rtCP_DirectLookupTablenD_table[cff + tableOffset] *
      localDW->HRIRFIR_states[j];
    cff++;
  }

  for (j = 0; j < localDW->HRIRFIR_circBuf; j++) {
    acc1 += rtCP_DirectLookupTablenD_table[cff + tableOffset] *
      localDW->HRIRFIR_states[j];
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

  *rty_audio_out = (int16_T)tableOffset;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */

  /* Update for DiscreteFir: '<Root>/HRIR-FIR' */
  /* Update circular buffer index */
  localDW->HRIRFIR_circBuf--;
  if (localDW->HRIRFIR_circBuf < 0) {
    localDW->HRIRFIR_circBuf = 198;
  }

  /* Update circular buffer */
  localDW->HRIRFIR_states[localDW->HRIRFIR_circBuf] = *rtu_audio_in;

  /* End of Update for DiscreteFir: '<Root>/HRIR-FIR' */
}

/* Model initialize function */
void hrtf_filter_initialize(const char_T **rt_errorStatus,
  RT_MODEL_hrtf_filter_T *const hrtf_filter_M, DW_hrtf_filter_f_T *localDW)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(hrtf_filter_M, rt_errorStatus);

  /* states (dwork) */
  (void) memset((void *)localDW, 0,
                sizeof(DW_hrtf_filter_f_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
