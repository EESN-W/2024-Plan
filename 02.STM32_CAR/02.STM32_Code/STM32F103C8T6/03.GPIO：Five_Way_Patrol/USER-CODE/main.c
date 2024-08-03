#include "stm32f10x.h"
#include "BSP_SysTick.h"
#include "BSP_USART_IT.h"
#include "BSP_Five_Way_Patrol.h"

int main()
{
	SysTick_Init();
	USART1_IT_Init();
	Five_Way_Patrol_Init();
	
	printf("Hello!\n");
	
	while(1)
	{
		if(X1_State == Bit_SET)
		{
			printf("X1_State check white line!\n");
		}
		if(X2_State == Bit_SET)
		{
			printf("X2_State check white line!\n");
		}
		if(X3_State == Bit_SET)
		{
			printf("X3_State check white line!\n");
		}
		if(X4_State == Bit_SET)
		{
			printf("X4_State check white line!\n");
		}
		if(X5_State == Bit_SET)
		{
			printf("X5_State check white line!\n");
		}
	}
}
