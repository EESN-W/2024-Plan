#include "BSP_KEY_EXTI.h"

void KEY_EXTI_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	
	RCC_APB2PeriphClockCmd(KEY2_Clock, ENABLE);

	GPIO_InitStructure.GPIO_Pin		= KEY2_Pin;
	GPIO_InitStructure.GPIO_Mode 	= KEY2_Mode;
	GPIO_Init(KEY2_Port, &GPIO_InitStructure);
	
	GPIO_EXTILineConfig(KEY2_EXTI_PortSource, KEY2_EXTI_PinSource);

	EXTI_InitStructure.EXTI_Line = KEY2_EXTI_Line;
	EXTI_InitStructure.EXTI_Mode = KEY2_EXTI_Mode;
	EXTI_InitStructure.EXTI_Trigger = KEY2_EXTI_Trigger;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = KEY2_NVIC_IRQChannel;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = KEY2_NVIC_IRQChannelPreemptionPriority;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = KEY2_NVIC_IRQChannelSubPriority;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);	
}
