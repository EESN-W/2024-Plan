#include "BSP_Motor.h"

void TB6612FNG_GPIO_Init(void)
{
	// 定义GPIO结构体
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// 使能GPIOA时钟
	RCC_APB2PeriphClockCmd(Motor_GPIO_Clock, ENABLE);
	
	// 配置GPIO结构体参数
	GPIO_InitStructure.GPIO_Pin 	= Motor_GPIO_Pin;		// 配置GPIO引脚
	GPIO_InitStructure.GPIO_Mode 	= Motor_GPIO_Mode;	// 配置引脚模式为通用推挽输出
	GPIO_InitStructure.GPIO_Speed = Motor_GPIO_Speed;	// 配置引脚速率为50MHz
	GPIO_Init(Motor_GPIO_Port, &GPIO_InitStructure);	// 初始化GPIO结构体
}

void Motor_PWM_Init(void)
{
	// 定义GPIO结构体
	GPIO_InitTypeDef GPIO_InitStructure;
	// 定义TIM_Base结构体
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	// 定义TIM_OC结构体
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	// 使能GPIOA时钟
	RCC_APB2PeriphClockCmd(Motor_PWMA_Clock1, ENABLE);
	// 使能TIM2时钟
	RCC_APB1PeriphClockCmd(Motor_PWMA_Clock2, ENABLE);
	
	// 配置GPIO结构体参数
	GPIO_InitStructure.GPIO_Pin 	= Motor_PWM_Pin;		// 配置GPIO引脚
	GPIO_InitStructure.GPIO_Mode 	= Motor_PWM_Mode;		// 配置引脚模式为通用推挽输出
	GPIO_InitStructure.GPIO_Speed = Motor_PWM_Speed;	// 配置引脚速率为50MHz
	GPIO_Init(Motor_PWM_Port, &GPIO_InitStructure);		// 初始化GPIO结构体
	
	// 配置TIM_Base结构体参数
	TIM_TimeBaseStructure.TIM_Period = Motor_PWM_Period;								// 配置定时器周期:100-1
	TIM_TimeBaseStructure.TIM_Prescaler = Motor_PWM_Prescaler;         	// 配置预分频器:72-1
	TIM_TimeBaseStructure.TIM_ClockDivision = Motor_PWM_ClockDivision; 	// 配置时钟分频:1
	TIM_TimeBaseStructure.TIM_CounterMode = Motor_PWM_CounterMode;     	// 配置计数模式:向上计数
	TIM_TimeBaseInit(Motor_PWM_Com, &TIM_TimeBaseStructure);           	// 初始化TIM_Base结构体参数

	// 配置TIM_OC结构体参数
	TIM_OCInitStructure.TIM_OCMode = Motor_PWM_OCMode;						// 配置比较输出模式
	TIM_OCInitStructure.TIM_OutputState = Motor_PWM_OutputState;	// 配置比较输出使能
	TIM_OCInitStructure.TIM_Pulse = Motor_PWM_Pulse;							// 配置比较输出脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = Motor_PWM_OCPolarity;		// 配置输出极性
	TIM_OC3Init(Motor_PWM_Com, &TIM_OCInitStructure);							// 初始化TIM_OC结构体参数
	TIM_OC4Init(Motor_PWM_Com, &TIM_OCInitStructure);							// 初始化TIM_OC结构体参数
	
	TIM_OC3PreloadConfig(Motor_PWM_Com, TIM_OCPreload_Enable); 	// 配置Motor_PWMA的比较输出通道1
	TIM_OC4PreloadConfig(Motor_PWM_Com, TIM_OCPreload_Enable); 	// 配置Motor_PWMA的比较输出通道3
	TIM_ARRPreloadConfig(Motor_PWM_Com, ENABLE);								// 使能Motor_PWMA自动重加载寄存器
	
	TIM_Cmd(Motor_PWM_Com, ENABLE);		// 使能Motor_PWMA
}

void Motor_A_Encoder_Init(void)
{
	// 定义GPIO结构体
	GPIO_InitTypeDef GPIO_InitStructure;
	// 定义TIM_IC结构体
	TIM_ICInitTypeDef TIM_ICInitStructure;
	// 定义TIM_Base结构体
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	// 使能GPIOA时钟
	RCC_APB2PeriphClockCmd(Motor_A_Encoder_Clock1, ENABLE);
	// 使能TIM3时钟
	RCC_APB1PeriphClockCmd(Motor_A_Encoder_Clock2, ENABLE);
	
	// 配置GPIO结构体参数
	GPIO_InitStructure.GPIO_Pin 	= Motor_A_Encoder_Pin;				// 配置GPIO引脚
	GPIO_InitStructure.GPIO_Mode 	= Motor_A_Encoder_GPIO_Mode;	// 配置引脚模式为浮空输入
	GPIO_Init(Motor_A_Encoder_Port, &GPIO_InitStructure);				// 初始化GPIO结构体
	
	// 配置TIM_Base结构体参数
	TIM_TimeBaseStructure.TIM_Period = Motor_A_Encoder_Period;								// 配置定时器周期:100-1
	TIM_TimeBaseStructure.TIM_Prescaler = Motor_A_Encoder_Prescaler;         	// 配置预分频器:72-1
	TIM_TimeBaseStructure.TIM_ClockDivision = Motor_A_Encoder_ClockDivision; 	// 配置时钟分频:1
	TIM_TimeBaseStructure.TIM_CounterMode = Motor_A_Encoder_CounterMode;     	// 配置计数模式:向上计数
	TIM_TimeBaseInit(Motor_A_Encoder_Com, &TIM_TimeBaseStructure);           	// 初始化TIM_Base结构体参数
	
	// 配置定时器的编码器模式和输入捕获极性
	TIM_EncoderInterfaceConfig(Motor_A_Encoder_Com, Motor_A_Encoder_Mode, Motor_A_Encoder_IC1Polarity, Motor_A_Encoder_IC2Polarity);
	
	TIM_ICStructInit(&TIM_ICInitStructure);												// TIM_IC结构体初始化
  TIM_ICInitStructure.TIM_ICFilter = Motor_A_Encoder_ICFilter;	// 配置输入捕获信号的滤波器系数
  TIM_ICInit(Motor_A_Encoder_Com, &TIM_ICInitStructure);				// 初始化TIM_IC结构体参数
	
	TIM_SetCounter(Motor_A_Encoder_Com , 0);	// 定时器计数值清零
	TIM_Cmd(Motor_A_Encoder_Com, ENABLE);			// 使能Motor_Encoder
}

void Motor_B_Encoder_Init(void)
{
	// 定义GPIO结构体
	GPIO_InitTypeDef GPIO_InitStructure;
	// 定义TIM_IC结构体
	TIM_ICInitTypeDef TIM_ICInitStructure;
	// 定义TIM_Base结构体
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	// 使能GPIOB时钟
	RCC_APB2PeriphClockCmd(Motor_B_Encoder_Clock1, ENABLE);
	// 使能TIM4时钟
	RCC_APB1PeriphClockCmd(Motor_B_Encoder_Clock2, ENABLE);
	
	// 配置GPIO结构体参数
	GPIO_InitStructure.GPIO_Pin 	= Motor_B_Encoder_Pin;		// 配置GPIO引脚
	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_IN_FLOATING;	// 配置引脚模式为浮空输入
	GPIO_Init(Motor_B_Encoder_Port, &GPIO_InitStructure);		// 初始化GPIO结构体
	
	// 配置TIM_Base结构体参数
	TIM_TimeBaseStructure.TIM_Period = Motor_B_Encoder_Period;								// 配置定时器周期:100-1
	TIM_TimeBaseStructure.TIM_Prescaler = Motor_B_Encoder_Prescaler;         	// 配置预分频器:72-1
	TIM_TimeBaseStructure.TIM_ClockDivision = Motor_B_Encoder_ClockDivision; 	// 配置时钟分频:1
	TIM_TimeBaseStructure.TIM_CounterMode = Motor_B_Encoder_CounterMode;     	// 配置计数模式:向上计数
	TIM_TimeBaseInit(Motor_B_Encoder_Com, &TIM_TimeBaseStructure);           	// 初始化TIM_Base结构体参数
	
	// 配置定时器的编码器模式和输入捕获极性
	TIM_EncoderInterfaceConfig(Motor_B_Encoder_Com, Motor_B_Encoder_Mode, Motor_B_Encoder_IC1Polarity, Motor_B_Encoder_IC2Polarity);
	
	TIM_ICStructInit(&TIM_ICInitStructure);	// TIM_IC结构体初始化
  TIM_ICInitStructure.TIM_ICFilter = Motor_B_Encoder_ICFilter;	// 配置输入捕获信号的滤波器系数
  TIM_ICInit(Motor_B_Encoder_Com, &TIM_ICInitStructure);				// 初始化TIM_IC结构体参数
	
	TIM_SetCounter(Motor_B_Encoder_Com , 0);	// 定时器计数值清零
	TIM_Cmd(Motor_B_Encoder_Com, ENABLE);			// 使能Motor_Encoder
}


void Motor_Direction(void)
{
	STBY_HIGH;
	AIN1_HIGH;
	AIN2_LOW;
	BIN1_HIGH;
	BIN2_LOW;
}
