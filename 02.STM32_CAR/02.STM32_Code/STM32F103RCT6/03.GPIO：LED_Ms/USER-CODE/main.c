#include "stm32f10x.h"
#include "BSP_SysTick.h"
#include "BSP_LED.h"

int main()
{
	SysTick_Init();
	LED_Init();
	
	while(1){
		// 延时1秒
		Delay_Ms(1000);
		// LED反转
		GPIO_WriteBit(LED_Port, LED_Pin, (BitAction)(1-GPIO_ReadOutputDataBit(LED_Port, LED_Pin)));
	}
}
