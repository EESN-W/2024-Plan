#include "BSP_KEY_EXTI.h"

void KEY2_EXTI_Init(void)
{
	// 定义GPIO结构体
	GPIO_InitTypeDef GPIO_InitStructure;
	// 定义NVIC结构体
	NVIC_InitTypeDef NVIC_InitStructure;
	// 定义EXTI结构体
	EXTI_InitTypeDef EXTI_InitStructure;
	
	// 使能KEY2时钟
	RCC_APB2PeriphClockCmd(KEY2_Clock, ENABLE);

	// 配置GPIO结构体参数
	GPIO_InitStructure.GPIO_Pin		= KEY2_Pin;		// 配置GPIO引脚
	GPIO_InitStructure.GPIO_Mode 	= KEY2_Mode;	// 配置引脚模式为上拉输入
	GPIO_Init(KEY2_Port, &GPIO_InitStructure);	// 初始化GPIO结构体

	// 配置NVIC结构体参数
	NVIC_InitStructure.NVIC_IRQChannel = KEY2_NVIC_IRQChannel;																				// 配置中断通道:外部中断0
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = KEY2_NVIC_IRQChannelPreemptionPriority;		// 配置抢占优先级:0x0F
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = KEY2_NVIC_IRQChannelSubPriority;									// 配置子优先级:0x0F
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;																										// 使能中断通道
	NVIC_Init(&NVIC_InitStructure);			// 初始化NVIC结构体参数
	
	GPIO_EXTILineConfig(KEY2_EXTI_PortSource, KEY2_EXTI_PinSource); // 配置EXTI线路:PA0
	
	// 配置EXTI结构体参数
	EXTI_InitStructure.EXTI_Line = KEY2_EXTI_Line;				// 配置EXTI线路:外部中断0
	EXTI_InitStructure.EXTI_Mode = KEY2_EXTI_Mode;				// 配置EXTI模式:触发中断
	EXTI_InitStructure.EXTI_Trigger = KEY2_EXTI_Trigger;	// 配置EXTI触发方式:下降沿
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;							// 使能EXTI线路
	EXTI_Init(&EXTI_InitStructure);												// 初始化EXTI结构体
}
