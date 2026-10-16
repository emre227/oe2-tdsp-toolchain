/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: tdsp_model_wrapper.c
 *
 * Code generated for Simulink model 'tdsp_model_wrapper'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Thu Oct 15 14:49:19 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "tdsp_model_wrapper.h"
#include <string.h>
#include "hrtf_filter.h"

/* Block states (default storage) */
DW_tdsp_model_wrapper_T tdsp_model_wrapper_DW;

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
  /* ModelReference: '<Root>/Model' incorporates:
   *  Inport: '<Root>/audio_in'
   *  Inport: '<Root>/data_container'
   *  Outport: '<Root>/audio_out'
   */
  hrtf_filter(&tdsp_model_wrapper_U.audio_in,
              &tdsp_model_wrapper_U.data_container.channel_select,
              &tdsp_model_wrapper_U.data_container.source_select,
              &tdsp_model_wrapper_Y.audio_out,
              &(tdsp_model_wrapper_DW.Model_InstanceData.rtdw));
}

/* Model initialize function */
void tdsp_model_wrapper_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(tdsp_model_wrapper_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&tdsp_model_wrapper_DW, 0,
                sizeof(DW_tdsp_model_wrapper_T));

  /* external inputs */
  (void)memset(&tdsp_model_wrapper_U, 0, sizeof(ExtU_tdsp_model_wrapper_T));

  /* external outputs */
  tdsp_model_wrapper_Y.audio_out = 0;

  /* Model Initialize function for ModelReference Block: '<Root>/Model' */
  hrtf_filter_initialize(rtmGetErrorStatusPointer(tdsp_model_wrapper_M),
    &(tdsp_model_wrapper_DW.Model_InstanceData.rtm),
    &(tdsp_model_wrapper_DW.Model_InstanceData.rtdw));

  /* SystemInitialize for ModelReference: '<Root>/Model' */
  hrtf_filter_Init(&(tdsp_model_wrapper_DW.Model_InstanceData.rtdw));
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
