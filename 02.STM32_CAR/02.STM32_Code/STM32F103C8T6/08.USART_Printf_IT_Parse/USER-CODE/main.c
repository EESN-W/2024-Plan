#include "stm32f10x.h"
#include "BSP_LED.h"
#include "BSP_KEY.h"
#include "BSP_USART.h"
#include "BSP_SysTick.h"
#include "BSP_KEY_EXTI.h"
#include "BSP_USART_IT.h"
#include "stm32f10x_it.h"

int main()
{
	SysTick_Init();
	LED_Init();
	KEY_Init();
	KEY_EXTI_Init();
	USART1_Init();
	USART2_IT_Init();
	
	printf("Hello!\n");
	
	while(1)
	{
		if(uData_Flag == 2 && uData_Buffer[1] == 0x01)
		{
			switch(uData_Buffer[2])
			{
				case 0x00:GPIO_WriteBit(LED_Port, LED_Pin, Bit_RESET);break;
				case 0x01:GPIO_WriteBit(LED_Port, LED_Pin, Bit_SET);break;
			}
			uData_Buffer[1] = 0x00;
		}
		if(KEY_Check(KEY_Port, KEY_Pin) == Press_Button)
		{
			printf("LED Toggle\n");
			GPIO_WriteBit(LED_Port, LED_Pin, (BitAction)!GPIO_ReadOutputDataBit(LED_Port, LED_Pin));
		}
	}
}
