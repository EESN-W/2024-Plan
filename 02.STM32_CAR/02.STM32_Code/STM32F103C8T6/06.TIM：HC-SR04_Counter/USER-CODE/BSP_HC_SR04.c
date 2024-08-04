#include "BSP_HC_SR04.h"

void TIM2_Init(void)
{
	// 定义TIM结构体
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	// 使能TIM2时钟
	RCC_APB1PeriphClockCmd(TIM2_Clock, ENABLE);
	
	// 配置TIM_Base结构体参数
	TIM_TimeBaseStructure.TIM_Period = TIM2_Period;									// 配置定时器周期:0xFFFF-1
	TIM_TimeBaseStructure.TIM_Prescaler = TIM2_Prescaler;						// 配置预分频器:72-1
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM2_ClockDivision;		// 配置时钟分频:1
	TIM_TimeBaseStructure.TIM_CounterMode = TIM2_CounterMode;				// 配置计数模式:向上计数
	TIM_TimeBaseInit(TIM2_Com, &TIM_TimeBaseStructure);							// 初始化TIM_Base结构体参数
	
	TIM_ClearFlag(TIM2_Com, TIM2_FLAG);									// 清除TIM2中断标志位
	TIM_ITConfig(TIM2_Com, TIM2_IT_Source, ENABLE);			// 使能TIM2中断

	TIM_Cmd(TIM2_Com, ENABLE);		// 使能TIM2
}


void HC_SR04_TRIG_ECHO_Init(void)
{
	// 定义GPIO结构体
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// 使能LED时钟
  RCC_APB2PeriphClockCmd(HC_SR04_TRIG_Clock, ENABLE);
	
	// 配置GPIO结构体参数
	GPIO_InitStructure.GPIO_Pin 	= HC_SR04_TRIG_Pin;			// 配置GPIO引脚
	GPIO_InitStructure.GPIO_Mode 	= HC_SR04_TRIG_Mode;		// 配置引脚模式为通用推挽输出
	GPIO_InitStructure.GPIO_Speed = HC_SR04_TRIG_Speed;		// 配置引脚速率为50MHz
	GPIO_Init(HC_SR04_Port, &GPIO_InitStructure);		// 初始化GPIO结构体
	
	GPIO_InitStructure.GPIO_Pin 	= HC_SR04_ECHO_Pin;			// 配置GPIO引脚
	GPIO_InitStructure.GPIO_Mode 	= HC_SR04_ECHO_Mode;		// 配置引脚模式为浮空输入
	GPIO_Init(HC_SR04_Port, &GPIO_InitStructure);		// 初始化GPIO结构体
}
