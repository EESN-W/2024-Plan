#include "BSP_IWDG.h"

void IWDG_Init(void)
{
	// 判断引发重启的来源
	if(RCC_GetFlagStatus(RCC_FLAG_IWDGRST) != RESET)
	{
		printf("IWDG RST !!!\n");
		// 清楚标志位
		RCC_ClearFlag();
	}
	else
	{
		printf("Normal RST !!!\n");
	}
	// 使能LSI时钟
	RCC_LSICmd(ENABLE);
	// 等待LSI稳定
	while(RCC_GetFlagStatus(RCC_FLAG_LSIRDY) == RESET);
	// 允许访问IWDG_PR和IWDG_RLR寄存器
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	// 设置分频值:40K / 64 = 625Hz
	IWDG_SetPrescaler(IWDG_Prescaler_64);
	// 设置重装载值:喂狗需要在5s内	625 * 5 = 3125
	IWDG_SetReload(3125);
	// 加载计数器重装载值
	IWDG_ReloadCounter();
	/* 使能IWDG */
	IWDG_Enable();
}
