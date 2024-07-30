#include "stm32f10x.h"
#include "stm32f10x_it.h"
#include "BSP_TIM_Base.h"
#include "BSP_LED.h"

int main()
{
	LED_Init();
	TIM2_Init();
	
	while(1){
		if(uTimerCount == 1000)
		{
			uTimerCount = 0;
			GPIO_WriteBit(LED_Port, LED_Pin, (BitAction)!GPIO_ReadOutputDataBit(LED_Port, LED_Pin));
		}
	}
}
