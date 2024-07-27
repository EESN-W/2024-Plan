#include "stm32f10x.h"
#include "BSP_LED.h"
#include "BSP_KEY.h"
#include "BSP_SysTick.h"
#include "BSP_KEY_EXTI.h"

int main()
{
	SysTick_Init();
	LED_Init();
	KEY_Init();
	KEY_EXTI_Init();

	while(1)
	{
		if(KEY_Check(KEY_Port, KEY_Pin) == Press_Button)
		{
			GPIO_WriteBit(LED_Port, LED_Pin, (BitAction)!GPIO_ReadOutputDataBit(LED_Port, LED_Pin));
		}
	}
}
