#include "stm32f10x.h"
#include "BSP_SysTick.h"
#include "BSP_USART_IT.h"
#include "BSP_IWDG.h"
#include "BSP_KEY.h"

int main()
{
	SysTick_Init();
	USART1_IT_Init();
	KEY_Init();
	IWDG_Init();
	
	while(1)
	{
		if(KEY_Check(KEY_Port, KEY_Pin) == SET)
		{
			// 喂狗
			IWDG_ReloadCounter();
			printf("IWDG Reload ...");
		}
	}
}
