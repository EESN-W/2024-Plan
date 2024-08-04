#include "BSP_Servo_PWM.h"

void Servo_Init(void)
{
	// 定义GPIO结构体
	GPIO_InitTypeDef GPIO_InitStructure;
	// 定义TIM_Base结构体
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	// 定义TIM_OC结构体
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	// 使能GPIOB时钟
	RCC_APB2PeriphClockCmd(Servo_Clock1, ENABLE);
	// 使能Servo时钟
	RCC_APB1PeriphClockCmd(Servo_Clock2, ENABLE);
	
	// 配置GPIO结构体参数
	GPIO_InitStructure.GPIO_Pin 	= Servo_Pin;			// 配置GPIO引脚
	GPIO_InitStructure.GPIO_Mode 	= Servo_Mode;		// 配置引脚模式为通用推挽输出
	GPIO_InitStructure.GPIO_Speed = Servo_Speed;		// 配置引脚速率为50MHz
	GPIO_Init(Servo_Port, &GPIO_InitStructure);		// 初始化GPIO结构体
	
	// 配置TIM_Base结构体参数
	TIM_TimeBaseStructure.TIM_Period = Servo_Period;									// 配置定时器周期:20000-1
	TIM_TimeBaseStructure.TIM_Prescaler = Servo_Prescaler;           // 配置预分频器:72-1
	TIM_TimeBaseStructure.TIM_ClockDivision = Servo_ClockDivision;   // 配置时钟分频:1
	TIM_TimeBaseStructure.TIM_CounterMode = Servo_CounterMode;       // 配置计数模式:向上计数
	TIM_TimeBaseInit(Servo_Com, &TIM_TimeBaseStructure);             // 初始化TIM_Base结构体参数

	// 配置TIM_OC结构体参数
	TIM_OCInitStructure.TIM_OCMode = Servo_OCMode;								// 配置比较输出模式
	TIM_OCInitStructure.TIM_OutputState = Servo_OutputState;			// 配置比较输出使能
	TIM_OCInitStructure.TIM_Pulse = Servo_Pulse;									// 配置比较输出脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = Servo_OCPolarity;				// 配置输出极性
	TIM_OC3Init(Servo_Com, &TIM_OCInitStructure);								// 初始化TIM_OC结构体参数
	
	TIM_OC3PreloadConfig(Servo_Com, TIM_OCPreload_Enable); // 配置Servo的比较输出通道3
	TIM_ARRPreloadConfig(Servo_Com, ENABLE);								// 使能Servo自动重加载寄存器
	
	TIM_Cmd(Servo_Com, ENABLE);		// 使能Servo
}

