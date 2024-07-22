#include "stm32f10x.h"
#include "BSP_LED.h"
#include "BSP_KEY.h"
#include "BSP_SysTick.h"

int main()
{
	SysTick_Init();
	LED_Init();
	KEY_Init();

	while(1)
	{
		if(KEY_Check(KEY[0].GPIO_Port, KEY[0].GPIO_Pin) == Press_Button)
		{
			GPIO_WriteBit(LED[0].GPIO_Port, LED[0].GPIO_Pin, (BitAction)!GPIO_ReadOutputDataBit(LED[0].GPIO_Port, LED[0].GPIO_Pin));
		}
	}
}
