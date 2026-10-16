/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: tdsp_model_wrapper.h
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

#ifndef tdsp_model_wrapper_h_
#define tdsp_model_wrapper_h_
#ifndef tdsp_model_wrapper_COMMON_INCLUDES_
#define tdsp_model_wrapper_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* tdsp_model_wrapper_COMMON_INCLUDES_ */

#include "tdsp_model_wrapper_types.h"
#include "tdsp_data_container.h"
#include "hrtf_filter.h"
#include <stddef.h>
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  ((const char_T **)(&((rtm)->errorStatus)))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  MdlrefDW_hrtf_filter_T Model_InstanceData;/* '<Root>/Model' */
} DW_tdsp_model_wrapper_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  int16_T audio_in;                    /* '<Root>/audio_in' */
  tdsp_data_container data_container;  /* '<Root>/data_container' */
} ExtU_tdsp_model_wrapper_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  int16_T audio_out;                   /* '<Root>/audio_out' */
} ExtY_tdsp_model_wrapper_T;

/* Real-time Model Data Structure */
struct tag_RTM_tdsp_model_wrapper_T {
  const char_T *errorStatus;
};

/* Block states (default storage) */
extern DW_tdsp_model_wrapper_T tdsp_model_wrapper_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_tdsp_model_wrapper_T tdsp_model_wrapper_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_tdsp_model_wrapper_T tdsp_model_wrapper_Y;

/* Model entry point functions */
extern void tdsp_model_wrapper_initialize(void);
extern void tdsp_model_wrapper_step(void);
extern void tdsp_model_wrapper_terminate(void);

/* Real-time Model object */
extern RT_MODEL_tdsp_model_wrapper_T *const tdsp_model_wrapper_M;

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
 * '<Root>' : 'tdsp_model_wrapper'
 */
#endif                                 /* tdsp_model_wrapper_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
