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

typedef struct {
	uint32_t GPIO_Clock;
	GPIO_TypeDef* GPIO_Port;
	uint16_t GPIO_Pin;
	GPIOMode_TypeDef GPIO_Mode;
	GPIOSpeed_TypeDef GPIO_Speed;
} KEY_Info;

static KEY_Info KEY[] = {
	{KEY_Clock, KEY_Port, KEY_Pin, KEY_Mode}
};

void KEY_Init(void);
int KEY_Check(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#endif
