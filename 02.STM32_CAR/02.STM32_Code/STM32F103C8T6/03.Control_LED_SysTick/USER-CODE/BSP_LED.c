#include "BSP_LED.h"

void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); 
	
	GPIO_InitStructure.GPIO_Pin = LED_Info[0].GPIO_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(LED_Info[0].GPIO_Port, &GPIO_InitStructure);
	
	GPIO_WriteBit(LED_Info[0].GPIO_Port, LED_Info[0].GPIO_Pin, Bit_SET);
}
