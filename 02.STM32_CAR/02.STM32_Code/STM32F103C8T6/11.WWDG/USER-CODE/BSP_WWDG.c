#include "BSP_WWDG.h"

void WWDG_Init(void)
{
	// 判断引发重启的来源
	if(RCC_GetFlagStatus(RCC_FLAG_WWDGRST) != RESET)
	{
		printf("WWDG RST !!!\n");
		// 清楚标志位
		RCC_ClearFlag();
	}
	else
	{
		printf("Normal RST !!!\n");
	}
	// 使能WWDG时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);
	
	// 设置分频值:36MHz / 4096 / 8 = 1099Hz(≈ 910 us)
	WWDG_SetPrescaler(WWDG_Prescaler_8);
	// 设置窗口上限值:910 us * (127-80) = 42.77 ms < refresh window < ~910 us * 64 = 58.25ms     
	WWDG_SetWindowValue(80);
	/* 使能WWDG */
	WWDG_Enable(127);
}
