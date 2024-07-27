#ifndef __BSP_KEY_EXTI_H__
#define __BSP_KEY_EXTI_H__

#include "stm32f10x.h"

#define	KEY2_Clock 			(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO)
#define	KEY2_Port				GPIOA
#define	KEY2_Pin 				GPIO_Pin_0
#define	KEY2_Mode 			GPIO_Mode_IPU

#define KEY2_EXTI_PortSource	GPIO_PortSourceGPIOA
#define KEY2_EXTI_PinSource		GPIO_PinSource0
#define KEY2_EXTI_Line				EXTI_Line0
#define KEY2_EXTI_Mode				EXTI_Mode_Interrupt
#define KEY2_EXTI_Trigger			EXTI_Trigger_Falling

#define KEY2_NVIC_IRQChannel											EXTI0_IRQn
#define KEY2_NVIC_IRQChannelPreemptionPriority		0x0F
#define KEY2_NVIC_IRQChannelSubPriority						0x0F

#define	Press_Button		1
#define	Release_Button	0

void KEY_EXTI_Init(void);

#endif
