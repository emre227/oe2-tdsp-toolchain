#include <stdint.h>
#include <xtensa/tie/hifi3z_lark.h>
#include <xtensa/xtruntime.h>
#include "hrtf_filter.h"

#define DS_IRQ_ID 4
#define DS_INPUT_EQ 12

volatile uint32_t live_flag;
volatile uint32_t channel_select = 0xFFFFFFFF;
volatile uint32_t source_select  = 0xFFFFFFFF;

///
volatile int16_t  peak = 0;

/// MATLAB MODEL ///
static RT_MODEL_hrtf_filter_T hrtf_filter_M_;
static RT_MODEL_hrtf_filter_T *const hrtf_filter_MPtr = &hrtf_filter_M_;/* Real-time model */
static DW_hrtf_filter_T hrtf_filter_DW;/* Observable states */

/* '<Root>/audio_in' */
static int16_T hrtf_filter_U_audio_in;

/* '<Root>/channel' */
static uint8_T hrtf_filter_U_channel;

/* '<Root>/source' */
static uint8_T hrtf_filter_U_source;

/* '<Root>/audio_out' */
static int16_T hrtf_filter_Y_audio_out;



/*
/// cycle measurement
volatile uint32_t cycle_start = 0;
volatile uint32_t cycle_step = 0;
volatile uint32_t cycle_max = 0;
volatile uint64_t cycle_sum = 0;
volatile uint32_t cycle_mean = 0;

/// errors
volatile int errors = 0;
volatile int idx_first_error = -1;
volatile int16_t first_error_ist_wert = 0;
volatile int16_t first_error_soll_wert = 0;
*/

void ds_handler(void *arg);

int main(void)
{

		if (channel_select == 0) {
			live_flag = 0xDEADBEEF;
		} else if(channel_select == 1) {
			live_flag = 0xDEADDEAD;
		}
		else { live_flag = 0x000000E3; for(;;){} }

		/// INIT MATLAB MODEL
	  	/* Pack model data into RTM */
	    hrtf_filter_MPtr->dwork = &hrtf_filter_DW;

	    /* Initialize model */
	    hrtf_filter_initialize(hrtf_filter_MPtr, &hrtf_filter_U_audio_in, &hrtf_filter_U_channel, &hrtf_filter_U_source, &hrtf_filter_Y_audio_out);


		_xtos_set_interrupt_handler_arg(DS_IRQ_ID, ds_handler, NULL);
		_xtos_interrupt_enable(DS_IRQ_ID);

		source_select = 0; //set first source
	  	for (;;) { }
		return 0;
	}


void ds_handler(void *arg)
{
	// give out one sample
	LKUPMEMST(0x80, ((uint32_t)hrtf_filter_Y_audio_out) << 8 );
	// read audio sample
	hrtf_filter_U_audio_in = (int16_t)(LKUPMEMLD(DS_INPUT_EQ) >> 8);

	/// peak meas
	int16_t a = (hrtf_filter_U_audio_in < 0) ? -hrtf_filter_U_audio_in : hrtf_filter_U_audio_in;
	if (a > peak) peak = a;
	/// step filter
	hrtf_filter_step(hrtf_filter_MPtr, hrtf_filter_U_audio_in, (uint8_t)channel_select, (uint8_t)source_select,&hrtf_filter_Y_audio_out);
}
