#include "stm32f10x.h"
#include "BSP_LED.h"
#include "BSP_SysTick.h"

int main()
{
	SysTick_Init();
	LED_Init();
	
	while(1){
		Delay_ms(1000);
//		Delay_us(1000000);
		GPIO_WriteBit(LED_Info[0].GPIO_Port, LED_Info[0].GPIO_Pin, (BitAction)!GPIO_ReadOutputDataBit(LED_Info[0].GPIO_Port, LED_Info[0].GPIO_Pin));
	}
}
