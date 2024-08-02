/*
	功能：TIM1延时
	硬件连接：无
	作者：W_ML
	时间：2024.08.01
	说明：配置10ms进入一次TIM1中断
*/

#ifndef __BSP_TIM_BASE__
#define __BSP_TIM_BASE__

#include "stm32f10x.h"

#define TIM1_Com							TIM1

#define TIM1_Clock						RCC_APB2Periph_TIM1

#define TIM1_NVIC_PriorityGroupConfig							NVIC_PriorityGroup_1
#define TIM1_NVIC_IRQChannel											TIM1_UP_IRQn
#define TIM1_NVIC_IRQChannelPreemptionPriority		0x01
#define TIM1_NVIC_IRQChannelSubPriority						0x01

#define TIM1_Period							(10000-1)
#define TIM1_Prescaler					(72-1)
#define TIM1_ClockDivision			TIM_CKD_DIV1
#define TIM1_CounterMode				TIM_CounterMode_Up
#define TIM1_FLAG								TIM_FLAG_Update
#define TIM1_IT_Source					TIM_IT_Update

void TIM1_Init(void); // TIM2初始化

#endif
