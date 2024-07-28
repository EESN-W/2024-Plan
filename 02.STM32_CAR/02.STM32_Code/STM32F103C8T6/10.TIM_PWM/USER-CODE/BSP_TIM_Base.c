#include "BSP_TIM_Base.h"

void TIM2_Init(void)
{
	RCC_APB1PeriphClockCmd(TIM2_Clock, ENABLE);
	
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_PriorityGroupConfig(TIM2_NVIC_PriorityGroupConfig);
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_NVIC_IRQChannel;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = TIM2_NVIC_IRQChannelPreemptionPriority;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = TIM2_NVIC_IRQChannelSubPriority;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_TimeBaseStructure.TIM_Period = TIM2_Period;
	TIM_TimeBaseStructure.TIM_Prescaler = TIM2_Prescaler;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM2_ClockDivision;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM2_CounterMode;
	TIM_TimeBaseInit(TIM2_Com, &TIM_TimeBaseStructure);
	
	TIM_ClearFlag(TIM2_Com, TIM2_FLAG);
	TIM_ITConfig(TIM2_Com, TIM2_IT_Source, ENABLE);

	TIM_Cmd(TIM2_Com, ENABLE);
	
//	RCC_APB1PeriphClockCmd(TIM2_Clock, DISABLE);
}
