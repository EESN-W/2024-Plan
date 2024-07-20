#ifndef __BSP_LED_H__
#define __BSP_LED_H__

#include "stm32f10x.h"

#define	LED_Clock 	RCC_APB2Periph_GPIOC
#define	LED_Port		GPIOC
#define	LED_Pin 		GPIO_Pin_13

typedef struct {
	uint32_t GPIO_Clock;
	GPIO_TypeDef* GPIO_Port;
	uint16_t GPIO_Pin;
} GPIO_Info;

static GPIO_Info LED_Info[] = {
	{LED_Clock, LED_Port, LED_Pin}
};

void LED_Init(void);

#endif
