#include "stm32f10x.h"
#include "BSP_LED.h"

int main()
{
	LED_Init();
	
	while(1){
		GPIO_WriteBit(LED[0].GPIO_Port, LED[0].GPIO_Pin, Bit_SET);
	}
}
