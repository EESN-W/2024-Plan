/*
	功能：TIM2输出PWM
	硬件连接：PB0接LED
	作者：W_ML
	时间：2024.08.01
	说明：配置PA1 PA2 PA3输出PWM
	RGB灯模块				STM32F103C8T6
	GND	<--------->	GND
	R		<--------->	PA1
	G		<--------->	PA2
	B		<--------->	PA3
*/

#ifndef __BSP_TIM_PWM__
#define __BSP_TIM_PWM__

#include "stm32f10x.h"

#define TIM2_Com								TIM2

#define TIM2_Clock1							RCC_APB2Periph_GPIOA
#define TIM2_Clock2							RCC_APB1Periph_TIM2

#define TIM2_Pin								(GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3)
#define TIM2_Mode								GPIO_Mode_AF_PP
#define TIM2_Speed							GPIO_Speed_50MHz
#define TIM2_Port								GPIOA											

#define TIM2_Period							(25600-1)
#define TIM2_Prescaler					(72-1)
#define TIM2_ClockDivision			TIM_CKD_DIV1
#define TIM2_CounterMode				TIM_CounterMode_Up

#define TIM2_OCMode							TIM_OCMode_PWM1
#define TIM2_OutputState				TIM_OutputState_Enable
#define TIM2_Pulse							0
#define TIM2_OCPolarity					TIM_OCPolarity_High

void TIM2_PWM_Init(void);		// TIM3_CH3输出PWM初始化

#endif
