#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include<stdio.h>

#include"main.h"
#include "led.h"

uint32_t var_1 = 50;
uint8_t var_2 = 20;
uint8_t var_3;

int main(void)
{

	user_leds_init();

	while(1)
	{
		all_leds_toggle();
		for(int i=0;i<1000000;i++){}

		all_leds_toggle();
		for(int i=0;i<1000000;i++){}
	}
}

