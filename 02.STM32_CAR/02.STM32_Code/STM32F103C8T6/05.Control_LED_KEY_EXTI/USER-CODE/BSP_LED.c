#include "BSP_LED.h"

void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
  RCC_APB2PeriphClockCmd(LED_Clock, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin 	= LED_Pin;
	GPIO_InitStructure.GPIO_Mode 	= LED_Mode;
	GPIO_InitStructure.GPIO_Speed = LED_Speed;
	GPIO_Init(LED_Port, &GPIO_InitStructure);
}
