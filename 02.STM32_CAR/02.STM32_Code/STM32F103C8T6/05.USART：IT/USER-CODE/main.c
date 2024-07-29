#include "stm32f10x.h"
#include "BSP_SysTick.h"
#include "BSP_USART_IT.h"

int main()
{
	SysTick_Init();
	USART1_IT_Init();
	
	printf("Hello!\n");
	
	while(1)
	{
		
	}
}
