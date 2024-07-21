#include "BSP_KEY.h"

void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(KEY[0].GPIO_Clock, ENABLE);

	GPIO_InitStructure.GPIO_Pin		= KEY[0].GPIO_Pin;
	GPIO_InitStructure.GPIO_Mode 	= KEY[0].GPIO_Mode;
	GPIO_Init(KEY[0].GPIO_Port, &GPIO_InitStructure);
}

int KEY_Check(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == Bit_RESET)
	{
		Delay_Ms(20);
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
