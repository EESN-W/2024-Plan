#include "stm32f10x.h"
#include "stm32f10x_it.h"
#include "BSP_LED.h"
#include "BSP_KEY.h"
#include "BSP_USART.h"
#include "BSP_SysTick.h"
#include "BSP_KEY_EXTI.h"
#include "BSP_USART_IT.h"
#include "BSP_TIM_Base.h"
#include "BSP_TIM_PWM.h"

int main()
{
	SysTick_Init();
	LED_Init();
	KEY_Init();
	KEY_EXTI_Init();
	USART1_Init();
	USART2_IT_Init();
	TIM2_Init();
	TIM3_PWM_Init();
	
	printf("Hello!\n");
	
	unsigned int Compare_Value = 0;
	
	for(Compare_Value = 0; Compare_Value < 19999; Compare_Value++)
	{
		TIM_SetCompare3(TIM3, Compare_Value);
		Delay_Us(50);
	}
	for(Compare_Value = 19999; Compare_Value > 0; Compare_Value--)
	{
		TIM_SetCompare3(TIM3, Compare_Value);
		Delay_Us(50);
	}
	
	while(1)
	{
		if(uTimerCount == 5000)
		{
			uTimerCount = 0;
			GPIO_WriteBit(LED_Port, LED_Pin, (BitAction)!GPIO_ReadOutputDataBit(LED_Port, LED_Pin));
		}
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
