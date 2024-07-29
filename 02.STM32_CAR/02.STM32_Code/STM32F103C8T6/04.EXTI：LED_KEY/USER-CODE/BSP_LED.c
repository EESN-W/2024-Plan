#include "BSP_LED.h"

void LED_Init(void)
{
	// 定义GPIO结构体
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// 使能LED时钟
  RCC_APB2PeriphClockCmd(LED_Clock, ENABLE);
	
	// 配置GPIO结构体参数
	GPIO_InitStructure.GPIO_Pin 	= LED_Pin;		// 配置GPIO引脚
	GPIO_InitStructure.GPIO_Mode 	= LED_Mode;		// 配置引脚模式为通用推挽输出
	GPIO_InitStructure.GPIO_Speed = LED_Speed;	// 配置引脚速率为50MHz
	GPIO_Init(LED_Port, &GPIO_InitStructure);		// 初始化GPIO结构体
}
