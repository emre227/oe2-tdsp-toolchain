/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: tdsp_model_wrapper.c
 *
 * Code generated for Simulink model 'tdsp_model_wrapper'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Mon Oct 26 16:02:05 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "tdsp_model_wrapper.h"
#include <string.h>
#include "hrtf_v5_fest_olhead_ed1_38_R_L_2025a.h"

/* External inputs (root inport signals with default storage) */
ExtU_tdsp_model_wrapper_T tdsp_model_wrapper_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_tdsp_model_wrapper_T tdsp_model_wrapper_Y;

/* Real-time model */
static RT_MODEL_tdsp_model_wrapper_T tdsp_model_wrapper_M_;
RT_MODEL_tdsp_model_wrapper_T *const tdsp_model_wrapper_M =
  &tdsp_model_wrapper_M_;

/* Model step function */
void tdsp_model_wrapper_step(void)
{
  /* ModelReference: '<Root>/Model1' incorporates:
   *  Inport: '<Root>/audio_in'
   *  Inport: '<Root>/data_container'
   *  Outport: '<Root>/audio_out'
   */
  hrtf_v5_fest_olhead_ed1_38_R_L_(&tdsp_model_wrapper_U.audio_in,
    &tdsp_model_wrapper_U.data_container.channel_select,
    &tdsp_model_wrapper_Y.audio_out);
}

/* Model initialize function */
void tdsp_model_wrapper_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(tdsp_model_wrapper_M, (NULL));

  /* external inputs */
  (void)memset(&tdsp_model_wrapper_U, 0, sizeof(ExtU_tdsp_model_wrapper_T));

  /* external outputs */
  tdsp_model_wrapper_Y.audio_out = 0;

  /* Model Initialize function for ModelReference Block: '<Root>/Model1' */
  hrtf_v5_fest_olhead__initialize(rtmGetErrorStatusPointer(tdsp_model_wrapper_M));

  /* SystemInitialize for ModelReference: '<Root>/Model1' incorporates:
   *  Inport: '<Root>/audio_in'
   *  Inport: '<Root>/data_container'
   *  Outport: '<Root>/audio_out'
   */
  hrtf_v5_fest_olhead_ed1_38_Init();
}

/* Model terminate function */
void tdsp_model_wrapper_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
