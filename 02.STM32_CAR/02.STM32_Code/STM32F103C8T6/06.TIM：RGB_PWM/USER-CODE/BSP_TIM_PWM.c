#include "BSP_TIM_PWM.h"

void TIM2_PWM_Init(void)
{
	// 定义GPIO结构体
	GPIO_InitTypeDef GPIO_InitStructure;
	// 定义TIM_Base结构体
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	// 定义TIM_OC结构体
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	// 使能GPIOB时钟
	RCC_APB2PeriphClockCmd(TIM2_Clock1, ENABLE);
	// 使能TIM3时钟
	RCC_APB1PeriphClockCmd(TIM2_Clock2, ENABLE);
	
	// 配置GPIO结构体参数
	GPIO_InitStructure.GPIO_Pin 	= TIM2_Pin;			// 配置GPIO引脚
	GPIO_InitStructure.GPIO_Mode 	= TIM2_Mode;		// 配置引脚模式为通用推挽输出
	GPIO_InitStructure.GPIO_Speed = TIM2_Speed;		// 配置引脚速率为50MHz
	GPIO_Init(TIM2_Port, &GPIO_InitStructure);		// 初始化GPIO结构体
	
	// 配置TIM_Base结构体参数
	TIM_TimeBaseStructure.TIM_Period = TIM2_Period;									// 配置定时器周期:20000-1
	TIM_TimeBaseStructure.TIM_Prescaler = TIM2_Prescaler;           // 配置预分频器:72-1
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM2_ClockDivision;   // 配置时钟分频:1
	TIM_TimeBaseStructure.TIM_CounterMode = TIM2_CounterMode;       // 配置计数模式:向上计数
	TIM_TimeBaseInit(TIM2_Com, &TIM_TimeBaseStructure);             // 初始化TIM_Base结构体参数

	// 配置TIM_OC结构体参数
	TIM_OCInitStructure.TIM_OCMode = TIM2_OCMode;								// 配置比较输出模式
	TIM_OCInitStructure.TIM_OutputState = TIM2_OutputState;			// 配置比较输出使能
	TIM_OCInitStructure.TIM_Pulse = TIM2_Pulse;									// 配置比较输出脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = TIM2_OCPolarity;				// 配置输出极性
	TIM_OC2Init(TIM2_Com, &TIM_OCInitStructure);								// 初始化TIM_OC结构体参数
	TIM_OC3Init(TIM2_Com, &TIM_OCInitStructure);								// 初始化TIM_OC结构体参数
	TIM_OC4Init(TIM2_Com, &TIM_OCInitStructure);								// 初始化TIM_OC结构体参数
	
	TIM_OC2PreloadConfig(TIM2_Com, TIM_OCPreload_Enable); // 配置TIM2的比较输出通道2
	TIM_OC3PreloadConfig(TIM2_Com, TIM_OCPreload_Enable); // 配置TIM2的比较输出通道3
	TIM_OC4PreloadConfig(TIM2_Com, TIM_OCPreload_Enable); // 配置TIM2的比较输出通道4
	TIM_ARRPreloadConfig(TIM2_Com, ENABLE);								// 使能TIM2自动重加载寄存器
	
	TIM_Cmd(TIM2_Com, ENABLE);		// 使能TIM2
}

