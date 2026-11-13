/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: HRTF_IIR_Baris_FixedPoint_v2.c
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

#include "HRTF_IIR_Baris_FixedPoint_v2.h"
#include "rtwtypes.h"
#include "HRTF_IIR_Baris_FixedPoint_v2_private.h"
#include <string.h>

MdlrefDW_HRTF_IIR_Baris_Fixed_T HRTF_IIR_Baris_FixedPo_MdlrefDW;

/* Block states (default storage) */
DW_HRTF_IIR_Baris_FixedPoin_f_T HRTF_IIR_Baris_FixedPoint_v2_DW;

/* System initialize for referenced model: 'HRTF_IIR_Baris_FixedPoint_v2' */
void HRTF_IIR_Baris_FixedPoint__Init(void)
{
  /* InitializeConditions for DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn' */
  memset(&HRTF_IIR_Baris_FixedPoint_v2_DW.DiscreteTransferFcn_states[0], 0,
         sizeof(int32_T) << 4U);

  /* InitializeConditions for Delay: '<S1>/Delay' */
  HRTF_IIR_Baris_FixedPoint_v2_DW.CircBufIdx = 0U;
}

/* Output and update for referenced model: 'HRTF_IIR_Baris_FixedPoint_v2' */
void HRTF_IIR_Baris_FixedPoint_v2(const int16_T *rtu_audio_in, const uint32_T
  *rtu_channel_select, int16_T *rty_audio_out)
{
  int64_T theta_input2;
  int64_T tmp;
  int32_T u1[11];
  int32_T j;
  int32_T rtb_DiscreteTransferFcn;
  int32_T rtb_Product_Amplitude;
  int32_T xn;
  int32_T xtmp;
  int32_T yn;
  int32_T ytmp;
  uint32_T rtb_Tau;
  uint32_T rtb_delay_gain;
  boolean_T needToNegate;
  static const int32_T sincos_cordicLUT_n11_s32En30[11] = { 843314857, 497837829,
    263043837, 133525159, 67021687, 33543516, 16775851, 8388437, 4194283,
    2097149, 1048576 };

  /* LookupNDDirect: '<Root>/Alpha'
   *
   * About '<Root>/Alpha':
   *  2-dimensional Direct Look-Up returning a Column,
   *  which is contiguous for column-major array
   *     Remove protection against out-of-range input in generated code: 'off'
   *   */
  if (*rtu_channel_select <= 1U) {
    rtb_Tau = *rtu_channel_select;
  } else {
    rtb_Tau = 1U;
  }

  rtb_Product_Amplitude = (int32_T)rtb_Tau * 17;

  /* LookupNDDirect: '<Root>/Beta'
   *
   * About '<Root>/Beta':
   *  2-dimensional Direct Look-Up returning a Column,
   *  which is contiguous for column-major array
   *     Remove protection against out-of-range input in generated code: 'off'
   *   */
  if (*rtu_channel_select <= 1U) {
    rtb_Tau = *rtu_channel_select;
  } else {
    rtb_Tau = 1U;
  }

  rtb_DiscreteTransferFcn = (int32_T)rtb_Tau * 17;

  /* DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  LookupNDDirect: '<Root>/Alpha'
   *  LookupNDDirect: '<Root>/Beta'
   *
   * About '<Root>/Alpha':
   *  2-dimensional Direct Look-Up returning a Column,
   *  which is contiguous for column-major array
   *     Remove protection against out-of-range input in generated code: 'off'
   *   *
   * About '<Root>/Beta':
   *  2-dimensional Direct Look-Up returning a Column,
   *  which is contiguous for column-major array
   *     Remove protection against out-of-range input in generated code: 'off'
   *   */
  theta_input2 = (int64_T)(*rtu_audio_in << 3) << 24;
  for (j = 0; j < 16; j++) {
    theta_input2 -= (int64_T)rtCP_Alpha_table[(j + rtb_Product_Amplitude) + 1] *
      HRTF_IIR_Baris_FixedPoint_v2_DW.DiscreteTransferFcn_states[j];
  }

  HRTF_IIR_Baris_FixedPoint_v2_DW.DiscreteTransferFcn_tmp = (int32_T)
    (theta_input2 >> 24);
  theta_input2 = (int64_T)rtCP_Beta_table[rtb_DiscreteTransferFcn] *
    HRTF_IIR_Baris_FixedPoint_v2_DW.DiscreteTransferFcn_tmp;
  for (j = 0; j < 16; j++) {
    theta_input2 += (int64_T)rtCP_Beta_table[(j + rtb_DiscreteTransferFcn) + 1] *
      HRTF_IIR_Baris_FixedPoint_v2_DW.DiscreteTransferFcn_states[j];
  }

  rtb_DiscreteTransferFcn = (int32_T)(theta_input2 >> 20);

  /* End of DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn' */

  /* LookupNDDirect: '<Root>/DeltaT' incorporates:
   *  Gain: '<S1>/Half'
   *
   * About '<Root>/DeltaT':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   *   */
  if (*rtu_channel_select <= 1U) {
    rtb_Tau = *rtu_channel_select;
  } else {
    rtb_Tau = 1U;
  }

  rtb_delay_gain = rtCP_DeltaT_table[(int32_T)rtb_Tau];

  /* End of LookupNDDirect: '<Root>/DeltaT' */

  /* Product: '<S1>/Product_Tau' incorporates:
   *  Constant: '<S1>/Constant'
   *  Gain: '<S1>/Half'
   */
  rtb_Tau = (uint32_T)((rtb_delay_gain * 3298534883ULL) >> 54);

  /* Delay: '<S1>/Delay' incorporates:
   *  DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn'
   *  Product: '<Root>/Product_Amplitude'
   */
  if (rtb_Tau <= 0U) {
    rtb_Product_Amplitude = rtb_DiscreteTransferFcn;
  } else {
    if (rtb_Tau > 480U) {
      rtb_Tau = 480U;
    }

    if (rtb_Tau <= HRTF_IIR_Baris_FixedPoint_v2_DW.CircBufIdx) {
      rtb_Tau = HRTF_IIR_Baris_FixedPoint_v2_DW.CircBufIdx - rtb_Tau;
    } else {
      rtb_Tau = (HRTF_IIR_Baris_FixedPoint_v2_DW.CircBufIdx - rtb_Tau) + 480U;
    }

    rtb_Product_Amplitude = HRTF_IIR_Baris_FixedPoint_v2_DW.Delay_DSTATE[rtb_Tau];
  }

  /* End of Delay: '<S1>/Delay' */

  /* Trigonometry: '<S1>/Cos' incorporates:
   *  Gain: '<S1>/Half'
   *  Product: '<S1>/Product_Delay_Gain'
   */
  for (j = 0; j < 11; j++) {
    u1[j] = sincos_cordicLUT_n11_s32En30[j];
  }

  theta_input2 = (uint32_T)((rtb_delay_gain * 1381687061ULL) >> 30);
  needToNegate = false;
  tmp = theta_input2 >> 1;
  if ((int32_T)tmp > 843314857) {
    tmp = (tmp - 1686629713LL) << 2;
    theta_input2 = ((uint64_T)tmp & 4294967296ULL) != 0ULL ? tmp | -4294967296LL
      : (int64_T)((uint64_T)tmp & 4294967295ULL);
    needToNegate = true;
  } else {
    tmp = theta_input2 << 1;
    theta_input2 = ((uint64_T)tmp & 4294967296ULL) != 0ULL ? tmp | -4294967296LL
      : (int64_T)((uint64_T)tmp & 4294967295ULL);
  }

  yn = 0;
  xn = 652032978;
  xtmp = 652032978;
  ytmp = 0;
  for (j = 0; j < 11; j++) {
    if (theta_input2 < 0LL) {
      xn += ytmp;
      yn -= xtmp;
      theta_input2 = (int64_T)((int32_T)(theta_input2 >> 1) + u1[j]) << 1;
    } else {
      xn -= ytmp;
      yn += xtmp;
      theta_input2 = (int64_T)((int32_T)(theta_input2 >> 1) - u1[j]) << 1;
    }

    xtmp = xn >> (j + 1);
    ytmp = yn >> (j + 1);
  }

  if (needToNegate) {
    xn = -xn;
  }

  /* LookupNDDirect: '<Root>/Amplitude'
   *
   * About '<Root>/Amplitude':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   *   */
  if (*rtu_channel_select <= 1U) {
    rtb_Tau = *rtu_channel_select;
  } else {
    rtb_Tau = 1U;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<S1>/AddOne'
   *  LookupNDDirect: '<Root>/Amplitude'
   *  Product: '<Root>/Product_Amplitude'
   *  Product: '<S1>/Product_Delay_Gain2'
   *  Sum: '<S1>/Sum'
   *  Trigonometry: '<S1>/Cos'
   *
   * About '<Root>/Amplitude':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   *   */
  j = (int32_T)(((int64_T)(int32_T)(((int64_T)((uint32_T)(xn + 1073741824) << 1)
    * rtb_Product_Amplitude) >> 28) * rtCP_Amplitude_table[(int32_T)rtb_Tau]) >>
                30) >> 7;
  if (j > 32767) {
    j = 32767;
  } else if (j < -32768) {
    j = -32768;
  }

  *rty_audio_out = (int16_T)j;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */

  /* Update for DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn' */
  for (j = 0; j < 15; j++) {
    HRTF_IIR_Baris_FixedPoint_v2_DW.DiscreteTransferFcn_states[15 - j] =
      HRTF_IIR_Baris_FixedPoint_v2_DW.DiscreteTransferFcn_states[14 - j];
  }

  HRTF_IIR_Baris_FixedPoint_v2_DW.DiscreteTransferFcn_states[0] =
    HRTF_IIR_Baris_FixedPoint_v2_DW.DiscreteTransferFcn_tmp;

  /* End of Update for DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn' */

  /* Update for Delay: '<S1>/Delay' incorporates:
   *  DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn'
   */
  HRTF_IIR_Baris_FixedPoint_v2_DW.Delay_DSTATE[HRTF_IIR_Baris_FixedPoint_v2_DW.CircBufIdx]
    = rtb_DiscreteTransferFcn;
  if (HRTF_IIR_Baris_FixedPoint_v2_DW.CircBufIdx < 479U) {
    HRTF_IIR_Baris_FixedPoint_v2_DW.CircBufIdx++;
  } else {
    HRTF_IIR_Baris_FixedPoint_v2_DW.CircBufIdx = 0U;
  }

  /* End of Update for Delay: '<S1>/Delay' */
}

/* Model initialize function */
void HRTF_IIR_Baris_Fixed_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_HRTF_IIR_Baris_Fixed_T *const HRTF_IIR_Baris_FixedPoint_v2_M =
    &(HRTF_IIR_Baris_FixedPo_MdlrefDW.rtm);

  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(HRTF_IIR_Baris_FixedPoint_v2_M, rt_errorStatus);

  /* states (dwork) */
  (void) memset((void *)&HRTF_IIR_Baris_FixedPoint_v2_DW, 0,
                sizeof(DW_HRTF_IIR_Baris_FixedPoin_f_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
