#include "BSP_LED.h"

void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
  RCC_APB2PeriphClockCmd(LED[0].GPIO_Clock, ENABLE); 
	
	/* JTAG-DP Disabled and SW-DP Enabled */
  GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin 	= LED[0].GPIO_Pin;
	GPIO_InitStructure.GPIO_Mode 	= LED[0].GPIO_Mode;
	GPIO_InitStructure.GPIO_Speed = LED[0].GPIO_Speed;
	GPIO_Init(LED[0].GPIO_Port, &GPIO_InitStructure);
}
