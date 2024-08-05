#include "stm32f10x.h"
#include "BSP_SysTick.h"
#include "BSP_USART_IT.h"
#include "BSP_WWDG.h"
#include "BSP_KEY.h"

int main()
{
	SysTick_Init();
	USART1_IT_Init();
	KEY_Init();
	WWDG_Init();
	
	unsigned int uWWDGTime = 45;
	
	while(1)
	{
		Delay_Ms(uWWDGTime);
		// 喂狗
		WWDG_SetCounter(127);
	}
}
