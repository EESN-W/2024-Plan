/*
	功能：TIM2_CH2输出PWM
	硬件连接：PB3接LED
	作者：W_ML
	时间：2024.08.01
	说明：配置PB3输出PWM，频率为50Hz
*/

#ifndef __BSP_TIM_PWM__
#define __BSP_TIM_PWM__

#include "stm32f10x.h"

#define TIM2_Com								TIM2

#define TIM2_Clock1							(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO)
#define TIM2_Clock2							RCC_APB1Periph_TIM2

#define TIM2_Pin								GPIO_Pin_3
#define TIM2_Mode								GPIO_Mode_AF_PP
#define TIM2_Speed							GPIO_Speed_50MHz
#define TIM2_Port								GPIOB											

#define TIM2_Period							(20000-1)
#define TIM2_Prescaler					(72-1)
#define TIM2_ClockDivision			TIM_CKD_DIV1
#define TIM2_CounterMode				TIM_CounterMode_Up

#define TIM2_OCMode							TIM_OCMode_PWM1
#define TIM2_OutputState				TIM_OutputState_Enable
#define TIM2_Pulse							0
#define TIM2_OCPolarity					TIM_OCPolarity_High

void TIM2_PWM_Init(void);		// TIM2_CH2输出PWM初始化

#endif
