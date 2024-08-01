#include "BSP_TIM_Base.h"

void TIM1_Init(void)
{
	// 定义NVIC结构体
	NVIC_InitTypeDef NVIC_InitStructure;
	// 定义TIM结构体
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	// 使能TIM1时钟
	RCC_APB2PeriphClockCmd(TIM1_Clock, ENABLE);
	
	// 配置NVIC结构体参数
	NVIC_PriorityGroupConfig(TIM1_NVIC_PriorityGroupConfig);				// 配置中断群组:1
	NVIC_InitStructure.NVIC_IRQChannel = TIM1_NVIC_IRQChannel;			// 配置中断通道:TIM1更新中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = TIM1_NVIC_IRQChannelPreemptionPriority;	// 配置抢占优先级:0x01
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = TIM1_NVIC_IRQChannelSubPriority;								// 配置子优先级:0x01
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;		// 使能中断通道
	NVIC_Init(&NVIC_InitStructure);										// 初始化NVIC结构体参数
	
	// 配置TIM_Base结构体参数
	TIM_TimeBaseStructure.TIM_Period = TIM1_Period;									// 配置定时器周期:10000-1
	TIM_TimeBaseStructure.TIM_Prescaler = TIM1_Prescaler;						// 配置预分频器:72-1
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM1_ClockDivision;		// 配置时钟分频:1
	TIM_TimeBaseStructure.TIM_CounterMode = TIM1_CounterMode;				// 配置计数模式:向上计数
	TIM_TimeBaseInit(TIM1_Com, &TIM_TimeBaseStructure);							// 初始化TIM_Base结构体参数
	
	TIM_ClearFlag(TIM1_Com, TIM1_FLAG);									// 清除TIM1中断标志位
	TIM_ITConfig(TIM1_Com, TIM1_IT_Source, ENABLE);			// 使能TIM1中断

	TIM_Cmd(TIM1_Com, ENABLE);		// 使能TIM1
}
