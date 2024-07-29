/*
	功能：TIM3输出PWM
	硬件连接：PB0接LED
	作者：W_ML
	时间：2024.08.01
	说明：配置PB0输出PWM，频率为50Hz
*/

#ifndef __BSP_TIM_PWM__
#define __BSP_TIM_PWM__

#include "stm32f10x.h"

#define TIM3_Com								TIM3

#define TIM3_Clock1							RCC_APB2Periph_GPIOB
#define TIM3_Clock2							RCC_APB1Periph_TIM3

#define TIM3_Pin								GPIO_Pin_0
#define TIM3_Mode								GPIO_Mode_AF_PP
#define TIM3_Speed							GPIO_Speed_50MHz
#define TIM3_Port								GPIOB											

#define TIM3_Period							(20000-1)
#define TIM3_Prescaler					(72-1)
#define TIM3_ClockDivision			TIM_CKD_DIV1
#define TIM3_CounterMode				TIM_CounterMode_Up

#define TIM3_OCMode							TIM_OCMode_PWM1
#define TIM3_OutputState				TIM_OutputState_Enable
#define TIM3_Pulse							0
#define TIM3_OCPolarity					TIM_OCPolarity_High

void TIM3_PWM_Init(void);		// TIM3_CH3输出PWM初始化

#endif
