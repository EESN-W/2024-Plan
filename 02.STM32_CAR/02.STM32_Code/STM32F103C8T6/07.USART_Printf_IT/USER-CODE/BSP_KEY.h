#ifndef __BSP_KEY_H__
#define __BSP_KEY_H__

#include "stm32f10x.h"
#include "BSP_SysTick.h"

#define	KEY_Clock 	RCC_APB2Periph_GPIOA
#define	KEY_Port		GPIOA
#define	KEY_Pin 		GPIO_Pin_8
#define	KEY_Mode 		GPIO_Mode_IPU

#define	Press_Button		1
#define	Release_Button	0

void KEY_Init(void);
int KEY_Check(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#endif
