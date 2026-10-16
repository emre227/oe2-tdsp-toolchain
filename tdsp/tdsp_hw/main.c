#include <stdint.h>
#include <xtensa/tie/hifi3z_lark.h>
#include <xtensa/xtruntime.h>
#include "tdsp_model_wrapper.h"
#include "tdsp_data_container.h"

#define DS_IRQ_ID 4
#define DS_INPUT_EQ 12

volatile tdsp_data_container tdsp_data_container_instance;

void ds_handler(void *arg);

int main(void)
{
		tdsp_model_wrapper_initialize();

		_xtos_set_interrupt_handler_arg(DS_IRQ_ID, ds_handler, NULL);
		_xtos_interrupt_enable(DS_IRQ_ID);

		// isr setup done
		tdsp_data_container_instance.isr_ready = 1;

	  	for (;;) { }
		return 0;
	}


void ds_handler(void *arg)
{
	tdsp_data_container_instance.isr_count++;
	uint32_t ts = tdsp_data_container_instance.time_stamp;

	if(ts != tdsp_data_container_instance.last_time_stamp){
		//overwrite if new data
		tdsp_model_wrapper_U.data_container = tdsp_data_container_instance;
		tdsp_data_container_instance.last_time_stamp = ts;
	}

	// read audio sample
	tdsp_model_wrapper_U.audio_in = (int16_t)(LKUPMEMLD(DS_INPUT_EQ) >> 8);

	/// step filter
	tdsp_model_wrapper_step();

	// give out one sample
	LKUPMEMST(0x80, ((uint32_t)tdsp_model_wrapper_Y.audio_out) << 8 );
}
