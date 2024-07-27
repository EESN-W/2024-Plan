#include "stm32f10x.h"
#include "BSP_LED.h"

int main()
{
	LED_Init();
	
	while(1){
		GPIO_WriteBit(LED_Port, LED_Pin, Bit_RESET);
	}
}
