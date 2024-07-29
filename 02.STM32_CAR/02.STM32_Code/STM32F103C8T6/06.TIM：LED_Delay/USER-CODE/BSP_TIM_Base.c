#include "BSP_TIM_Base.h"

void TIM2_Init(void)
{
	// 定义NVIC结构体
	NVIC_InitTypeDef NVIC_InitStructure;
	// 定义TIM结构体
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	// 使能TIM2时钟
	RCC_APB1PeriphClockCmd(TIM2_Clock, ENABLE);
	
	// 配置NVIC结构体参数
	NVIC_PriorityGroupConfig(TIM2_NVIC_PriorityGroupConfig);				// 配置中断群组:1
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_NVIC_IRQChannel;			// 配置中断通道:TIM2中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = TIM2_NVIC_IRQChannelPreemptionPriority;	// 配置抢占优先级:0x00
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = TIM2_NVIC_IRQChannelSubPriority;								// 配置子优先级:0x02
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;		// 使能中断通道
	NVIC_Init(&NVIC_InitStructure);										// 初始化NVIC结构体参数
	
	// 配置TIM_Base结构体参数
	TIM_TimeBaseStructure.TIM_Period = TIM2_Period;									// 配置定时器周期:1000-1
	TIM_TimeBaseStructure.TIM_Prescaler = TIM2_Prescaler;						// 配置预分频器:72-1
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM2_ClockDivision;		// 配置时钟分频:1
	TIM_TimeBaseStructure.TIM_CounterMode = TIM2_CounterMode;				// 配置计数模式:向上计数
	TIM_TimeBaseInit(TIM2_Com, &TIM_TimeBaseStructure);							// 初始化TIM_Base结构体参数
	
	TIM_ClearFlag(TIM2_Com, TIM2_FLAG);									// 清除TIM2中断标志位
	TIM_ITConfig(TIM2_Com, TIM2_IT_Source, ENABLE);			// 使能TIM2中断

	TIM_Cmd(TIM2_Com, ENABLE);		// 使能TIM2
	
//	RCC_APB1PeriphClockCmd(TIM2_Clock, DISABLE);
}
