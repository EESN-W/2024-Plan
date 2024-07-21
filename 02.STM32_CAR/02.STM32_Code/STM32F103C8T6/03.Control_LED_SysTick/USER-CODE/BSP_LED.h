#ifndef __BSP_LED_H__
#define __BSP_LED_H__

#include "stm32f10x.h"

#define	LED_Clock 	RCC_APB2Periph_GPIOC
#define	LED_Port		GPIOC
#define	LED_Pin 		GPIO_Pin_13
#define	LED_Speed 	GPIO_Speed_50MHz
#define	LED_Mode 		GPIO_Mode_Out_PP

typedef struct {
	uint32_t GPIO_Clock;
	GPIO_TypeDef* GPIO_Port;
	uint16_t GPIO_Pin;
	GPIOMode_TypeDef GPIO_Mode;
	GPIOSpeed_TypeDef GPIO_Speed;
} LED_Info;

static LED_Info LED[] = {
	{LED_Clock, LED_Port, LED_Pin, LED_Mode, LED_Speed}
};

void LED_Init(void);

#endif
