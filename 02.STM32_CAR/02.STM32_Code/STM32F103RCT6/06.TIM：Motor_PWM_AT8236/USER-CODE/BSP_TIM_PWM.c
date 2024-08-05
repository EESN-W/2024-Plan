#include "BSP_TIM_PWM.h"

unsigned int uEncoderACounter = 0;
unsigned int uEncoderBCounter = 0;

void TIM8_PWM_Init(void)	// PC6 PC7 PC8 PC9
{
	// 定义GPIO结构体
	GPIO_InitTypeDef GPIO_InitStructure;
	// 定义TIM_Base结构体
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	// 定义TIM_OC结构体
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	// 使能GPIOC和TIM8时钟
	RCC_APB2PeriphClockCmd(TIM8_Clock, ENABLE);
	
	// 配置GPIO结构体参数
	GPIO_InitStructure.GPIO_Pin 	= TIM8_Pin;			// 配置GPIO引脚
	GPIO_InitStructure.GPIO_Mode 	= TIM8_Mode;		// 配置引脚模式为复用推挽输出
	GPIO_InitStructure.GPIO_Speed = TIM8_Speed;		// 配置引脚速率为50MHz
	GPIO_Init(TIM8_Port, &GPIO_InitStructure);		// 初始化GPIO结构体
	
	// 配置TIM_Base结构体参数
	TIM_TimeBaseStructure.TIM_Period = TIM8_Period;									// 配置定时器周期:100-1
	TIM_TimeBaseStructure.TIM_Prescaler = TIM8_Prescaler;           // 配置预分频器:72-1
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM8_ClockDivision;   // 配置时钟分频:1
	TIM_TimeBaseStructure.TIM_CounterMode = TIM8_CounterMode;       // 配置计数模式:向上计数
	TIM_TimeBaseInit(TIM8_Com, &TIM_TimeBaseStructure);             // 初始化TIM_Base结构体参数

	// 配置TIM_OC结构体参数
	TIM_OCInitStructure.TIM_OCMode = TIM8_OCMode;								// 配置比较输出模式
	TIM_OCInitStructure.TIM_OutputState = TIM8_OutputState;			// 配置比较输出使能
	TIM_OCInitStructure.TIM_Pulse = TIM8_Pulse;									// 配置比较输出脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = TIM8_OCPolarity;				// 配置输出极性
	TIM_OC1Init(TIM8_Com, &TIM_OCInitStructure);								// 初始化TIM_OC结构体参数
	TIM_OC2Init(TIM8_Com, &TIM_OCInitStructure);								// 初始化TIM_OC结构体参数
	TIM_OC3Init(TIM8_Com, &TIM_OCInitStructure);								// 初始化TIM_OC结构体参数
	TIM_OC4Init(TIM8_Com, &TIM_OCInitStructure);								// 初始化TIM_OC结构体参数
	
	TIM_OC1PreloadConfig(TIM8_Com, TIM_OCPreload_Enable); // 配置TIM8的比较输出通道1
	TIM_OC2PreloadConfig(TIM8_Com, TIM_OCPreload_Enable); // 配置TIM8的比较输出通道2
	TIM_OC3PreloadConfig(TIM8_Com, TIM_OCPreload_Enable); // 配置TIM8的比较输出通道3
	TIM_OC4PreloadConfig(TIM8_Com, TIM_OCPreload_Enable); // 配置TIM8的比较输出通道4
	TIM_ARRPreloadConfig(TIM8_Com, ENABLE);								// 使能TIM8自动重加载寄存器
	
	TIM_CtrlPWMOutputs(TIM8,ENABLE);	// 使能TIM8的PWM输出(TIM1和TIM8需要)
	TIM_Cmd(TIM8_Com, ENABLE);				// 使能TIM8
}

void Motor_Encoder_A_Init(void)	// PA7 PA6
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

void Motor_Encoder_B_Init(void)	// PB7 PB6
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

//void Motor_Direction(int iLeftWheel, int iRighttWheel)
//{
//	if(iLeftWheel > 0)
//	{
//		
//	}
//	TIM_SetCompare1(TIM8_Com, 0);
//	TIM_SetCompare2(TIM8_Com, 75);
//	TIM_SetCompare3(TIM8_Com, 75);
//	TIM_SetCompare4(TIM8_Com, 0);
//}
