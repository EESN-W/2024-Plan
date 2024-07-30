#include "BSP_KEY.h"

void KEY_Init(void)
{
	// 定义GPIO结构体
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// 使能KEY时钟
	RCC_APB2PeriphClockCmd(KEY_Clock, ENABLE);

	// 配置GPIO结构体参数
	GPIO_InitStructure.GPIO_Pin		= KEY_Pin;		// 配置GPIO引脚
	GPIO_InitStructure.GPIO_Mode 	= KEY_Mode;		// 配置引脚模式为上拉输入
	GPIO_Init(KEY_Port, &GPIO_InitStructure);		// 初始化GPIO结构体
}

int KEY_Check(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == Bit_RESET)
	{
		Delay_Ms(20); // 按键消抖
		if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == Bit_RESET)
		{
			while(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == Bit_RESET);
			return Press_Button;
		}
		return Release_Button;
	}
	else
	{
		return Release_Button;
	}
}
