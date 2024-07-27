#include "stm32f10x.h"
#include "BSP_LED.h"
#include "BSP_SysTick.h"

int main()
{
	SysTick_Init();
	LED_Init();
	
	while(1){
		Delay_Ms(1000);
		Delay_Us(1000000);
		GPIO_WriteBit(LED_Port, LED_Pin, (BitAction)!GPIO_ReadOutputDataBit(LED_Port, LED_Pin));
	}
}
