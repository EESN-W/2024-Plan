#include "BSP_Motor.h"

void Motor_Init(void)
{
	// 定义GPIO结构体
	GPIO_InitTypeDef GPIO_InitStructure;
	// 定义TIM_Base结构体
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	// 定义TIM_OC结构体
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	// 使能GPIOA时钟
	RCC_APB2PeriphClockCmd(Motor_GPIO_Clock, ENABLE);
	// 使能GPIOB时钟
	RCC_APB2PeriphClockCmd(Motor_PWMA_Clock1, ENABLE);
	// 使能TIM3时钟
	RCC_APB1PeriphClockCmd(Motor_PWMA_Clock2, ENABLE);
	
	// 配置GPIO结构体参数
	GPIO_InitStructure.GPIO_Pin 	= Motor_PWMA_Pin;		// 配置GPIO引脚
	GPIO_InitStructure.GPIO_Mode 	= Motor_PWMA_Mode;	// 配置引脚模式为通用推挽输出
	GPIO_InitStructure.GPIO_Speed = Motor_PWMA_Speed;	// 配置引脚速率为50MHz
	GPIO_Init(Motor_PWMA_Port, &GPIO_InitStructure);	// 初始化GPIO结构体
	
	// 配置TIM_Base结构体参数
	TIM_TimeBaseStructure.TIM_Period = Motor_PWMA_Period;								// 配置定时器周期:100-1
	TIM_TimeBaseStructure.TIM_Prescaler = Motor_PWMA_Prescaler;         // 配置预分频器:72-1
	TIM_TimeBaseStructure.TIM_ClockDivision = Motor_PWMA_ClockDivision; // 配置时钟分频:1
	TIM_TimeBaseStructure.TIM_CounterMode = Motor_PWMA_CounterMode;     // 配置计数模式:向上计数
	TIM_TimeBaseInit(Motor_PWMA_Com, &TIM_TimeBaseStructure);           // 初始化TIM_Base结构体参数

	// 配置TIM_OC结构体参数
	TIM_OCInitStructure.TIM_OCMode = Motor_PWMA_OCMode;							// 配置比较输出模式
	TIM_OCInitStructure.TIM_OutputState = Motor_PWMA_OutputState;		// 配置比较输出使能
	TIM_OCInitStructure.TIM_Pulse = Motor_PWMA_Pulse;								// 配置比较输出脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = Motor_PWMA_OCPolarity;			// 配置输出极性
	TIM_OC3Init(Motor_PWMA_Com, &TIM_OCInitStructure);							// 初始化TIM_OC结构体参数
	
	TIM_OC3PreloadConfig(Motor_PWMA_Com, TIM_OCPreload_Enable); // 配置Motor_PWMA的比较输出通道3
	TIM_ARRPreloadConfig(Motor_PWMA_Com, ENABLE);								// 使能Motor_PWMA自动重加载寄存器
	
	// 配置PA1 PA2 PA3 GPIO结构体参数
	GPIO_InitStructure.GPIO_Pin 	= Motor_GPIO_Pin;			// 配置GPIO引脚
	GPIO_InitStructure.GPIO_Mode 	= Motor_GPIO_Mode;		// 配置引脚模式为通用推挽输出
	GPIO_InitStructure.GPIO_Speed = Motor_GPIO_Speed;		// 配置引脚速率为50MHz
	GPIO_Init(Motor_GPIO_Port, &GPIO_InitStructure);		// 初始化GPIO结构体
	
	TIM_Cmd(Motor_PWMA_Com, ENABLE);		// 使能Motor_PWMA
}

void Motor_Encoder_Init(void)
{
	// 定义GPIO结构体
	GPIO_InitTypeDef GPIO_InitStructure;
	// 定义TIM_Base结构体
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	// 使能GPIOB时钟
	RCC_APB2PeriphClockCmd(Motor_Encoder_Clock1, ENABLE);
	// 使能TIM4时钟
	RCC_APB1PeriphClockCmd(Motor_Encoder_Clock2, ENABLE);
	
	// 配置GPIO结构体参数
	GPIO_InitStructure.GPIO_Pin 	= Motor_Encoder_Pin;		// 配置GPIO引脚
	GPIO_InitStructure.GPIO_Mode 	= Motor_Encoder_Mode;		// 配置引脚模式为浮空输入
	GPIO_Init(Motor_Encoder_Port, &GPIO_InitStructure);		// 初始化GPIO结构体
	
	// 配置TIM_Base结构体参数
	TIM_TimeBaseStructure.TIM_Period = Motor_Encoder_Period;								// 配置定时器周期:100-1
	TIM_TimeBaseStructure.TIM_Prescaler = Motor_Encoder_Prescaler;         	// 配置预分频器:72-1
	TIM_TimeBaseStructure.TIM_ClockDivision = Motor_Encoder_ClockDivision; 	// 配置时钟分频:1
	TIM_TimeBaseStructure.TIM_CounterMode = Motor_Encoder_CounterMode;     	// 配置计数模式:向上计数
	TIM_TimeBaseInit(Motor_Encoder_Com, &TIM_TimeBaseStructure);           	// 初始化TIM_Base结构体参数
	
	// 配置定时器的编码器模式和输入捕获极性
	TIM_EncoderInterfaceConfig(Motor_Encoder_Com, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
	
	TIM_SetCounter(Motor_Encoder_Com , 0);	// 定时器计数值清零
	TIM_Cmd(Motor_Encoder_Com, ENABLE);			// 使能Motor_Encoder
}
