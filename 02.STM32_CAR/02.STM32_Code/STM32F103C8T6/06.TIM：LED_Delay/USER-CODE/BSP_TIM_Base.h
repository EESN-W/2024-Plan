/*
	功能：TIM2延时
	硬件连接：无
	作者：W_ML
	时间：2024.08.01
	说明：配置1ms进入一次TIM2中断
*/

#ifndef __BSP_TIM_BASE__
#define __BSP_TIM_BASE__

#include "stm32f10x.h"

#define TIM2_Com							TIM2

#define TIM2_Clock						RCC_APB1Periph_TIM2

#define TIM2_NVIC_PriorityGroupConfig							NVIC_PriorityGroup_1
#define TIM2_NVIC_IRQChannel											TIM2_IRQn
#define TIM2_NVIC_IRQChannelPreemptionPriority		0x00
#define TIM2_NVIC_IRQChannelSubPriority						0x02
#define TIM2_IT_Sources														

#define TIM2_Period							(1000-1)
#define TIM2_Prescaler					(72-1)
#define TIM2_ClockDivision			TIM_CKD_DIV1
#define TIM2_CounterMode				TIM_CounterMode_Up
#define TIM2_FLAG								TIM_FLAG_Update
#define TIM2_IT_Source					TIM_IT_Update

void TIM2_Init(void); // TIM2初始化

#endif
