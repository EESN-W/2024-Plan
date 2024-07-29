#include "BSP_TIM_PWM.h"

void TIM3_PWM_Init(void)
{
	// 定义GPIO结构体
	GPIO_InitTypeDef GPIO_InitStructure;
	// 定义TIM_Base结构体
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	// 定义TIM_OC结构体
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	// 使能GPIOB时钟
	RCC_APB2PeriphClockCmd(TIM3_Clock1, ENABLE);
	// 使能TIM3时钟
	RCC_APB1PeriphClockCmd(TIM3_Clock2, ENABLE);
	
	// 配置GPIO结构体参数
	GPIO_InitStructure.GPIO_Pin 	= TIM3_Pin;			// 配置GPIO引脚
	GPIO_InitStructure.GPIO_Mode 	= TIM3_Mode;		// 配置引脚模式为通用推挽输出
	GPIO_InitStructure.GPIO_Speed = TIM3_Speed;		// 配置引脚速率为50MHz
	GPIO_Init(TIM3_Port, &GPIO_InitStructure);		// 初始化GPIO结构体
	
	// 配置TIM_Base结构体参数
	TIM_TimeBaseStructure.TIM_Period = TIM3_Period;									// 配置定时器周期:20000-1
	TIM_TimeBaseStructure.TIM_Prescaler = TIM3_Prescaler;           // 配置预分频器:72-1
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM3_ClockDivision;   // 配置时钟分频:1
	TIM_TimeBaseStructure.TIM_CounterMode = TIM3_CounterMode;       // 配置计数模式:向上计数
	TIM_TimeBaseInit(TIM3_Com, &TIM_TimeBaseStructure);             // 初始化TIM_Base结构体参数

	// 配置TIM_OC结构体参数
	TIM_OCInitStructure.TIM_OCMode = TIM3_OCMode;								// 配置比较输出模式
	TIM_OCInitStructure.TIM_OutputState = TIM3_OutputState;			// 配置比较输出使能
	TIM_OCInitStructure.TIM_Pulse = TIM3_Pulse;									// 配置比较输出脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = TIM3_OCPolarity;				// 配置输出极性
	TIM_OC3Init(TIM3_Com, &TIM_OCInitStructure);								// 初始化TIM_OC结构体参数
	
	TIM_OC3PreloadConfig(TIM3_Com, TIM_OCPreload_Enable); // 配置TIM3的比较输出通道3
	TIM_ARRPreloadConfig(TIM3_Com, ENABLE);								// 使能TIM3自动重加载寄存器
	
	TIM_Cmd(TIM3_Com, ENABLE);		// 使能TIM3
}

