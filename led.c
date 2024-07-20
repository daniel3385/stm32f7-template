
#include<stdint.h>
#include "led.h"


extern uint8_t var[8];

void delay(uint32_t count)
{
  for(uint32_t i = 0 ; i < count ; i++);
}

#include  "led.h"
#include "stm32f767xx.h"


void user_leds_init(void)
{
	RCC->AHB1ENR |= GPIOB_CLK_EN;

	__BKPT(5);

	//Set PB0 as output
	GPIOB->MODER |= (1U<<0);
	GPIOB->MODER &= ~(1U<<1);

	//Set PB7 as output
	GPIOB->MODER |= (1U<<14);
	GPIOB->MODER &= ~(1U<<15);

	//Set PB14 as output
	GPIOB->MODER |= (1U<<28);
	GPIOB->MODER &= ~(1U<<29);
}


void all_leds_on(void)
{
	GPIOB->ODR |=(RED_LED | GREEN_LED|BLUE_LED);
}


void all_leds_off(void)
{
	GPIOB->ODR &=~(RED_LED | GREEN_LED|BLUE_LED);
}

void all_leds_toggle(void)
{
	GPIOB->ODR ^=(RED_LED | GREEN_LED|BLUE_LED);
}

void led_toggle(ledType led)
{
	GPIOB->ODR ^=led;
}


void led_on(ledType led)
{
	GPIOB->ODR |=led;
}

void led_off(ledType led)
{
	GPIOB->ODR &=~led;
}


