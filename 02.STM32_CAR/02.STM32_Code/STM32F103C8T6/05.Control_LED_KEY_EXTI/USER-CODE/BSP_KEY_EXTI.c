#include "BSP_KEY_EXTI.h"

void KEY_EXTI_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	
	RCC_APB2PeriphClockCmd(KEY_EXTI[0].GPIO_Clock, ENABLE);

	GPIO_InitStructure.GPIO_Pin		= KEY_EXTI[0].GPIO_Pin;
	GPIO_InitStructure.GPIO_Mode 	= KEY_EXTI[0].GPIO_Mode;
	GPIO_Init(KEY_EXTI[0].GPIO_Port, &GPIO_InitStructure);
	
	GPIO_EXTILineConfig(KEY_EXTI[0].GPIO_PortSource, KEY_EXTI[0].GPIO_PinSource);

	EXTI_InitStructure.EXTI_Line = KEY_EXTI[0].EXTI_Line;
	EXTI_InitStructure.EXTI_Mode = KEY_EXTI[0].EXTI_Mode;
	EXTI_InitStructure.EXTI_Trigger = KEY_EXTI[0].EXTI_Trigger;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = KEY_EXTI[0].NVIC_IRQChannel;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = KEY_EXTI[0].NVIC_IRQChannelPreemptionPriority;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = KEY_EXTI[0].NVIC_IRQChannelSubPriority;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);	
}
