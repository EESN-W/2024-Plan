#ifndef __BSP_LED_H__
#define __BSP_LED_H__

#include "stm32f10x.h"

#define	LED_Clock 	RCC_APB2Periph_GPIOC
#define	LED_Port		GPIOC
#define	LED_Pin 		GPIO_Pin_13
#define	LED_Speed 	GPIO_Speed_50MHz
#define	LED_Mode 		GPIO_Mode_Out_PP

void LED_Init(void);

#endif
