#include "BSP_Five_Way_Patrol.h"

void Five_Way_Patrol_Init(void)
{
	// 定义GPIO结构体
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// 使能LED时钟
  RCC_APB2PeriphClockCmd(Five_Way_Patrol_Clock, ENABLE);
	
	// 配置GPIO结构体参数
	GPIO_InitStructure.GPIO_Pin 	= Five_Way_Patrol_Pin;		// 配置GPIO引脚
	GPIO_InitStructure.GPIO_Mode 	= Five_Way_Patrol_Mode;		// 配置引脚模式为上拉输入
	GPIO_Init(Five_Way_Patrol_Port, &GPIO_InitStructure);		// 初始化GPIO结构体
}
