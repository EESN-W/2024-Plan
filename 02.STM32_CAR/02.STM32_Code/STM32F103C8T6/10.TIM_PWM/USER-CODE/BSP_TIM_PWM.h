#ifndef __BSP_TIM_PWM__
#define __BSP_TIM_PWM__

#include "stm32f10x.h"

#define TIM3_Com							TIM3

#define TIM3_Clock1						RCC_APB2Periph_GPIOB
#define TIM3_Clock2						RCC_APB1Periph_TIM3

#define TIM3_Pin							GPIO_Pin_0
#define TIM3_Mode							GPIO_Mode_AF_PP
#define TIM3_Speed						GPIO_Speed_50MHz
#define TIM3_Port							GPIOB											

#define TIM3_Period							(20000-1)
#define TIM3_Prescaler					(72-1)
#define TIM3_ClockDivision			TIM_CKD_DIV1
#define TIM3_CounterMode				TIM_CounterMode_Up

#define TIM3_OCMode							TIM_OCMode_PWM1
#define TIM3_OutputState				TIM_OutputState_Enable
#define TIM3_Pulse							0
#define TIM3_OCPolarity					TIM_OCPolarity_High

void TIM3_PWM_Init(void);

#endif
