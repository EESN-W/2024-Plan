#include "stm32f10x.h"
#include "stm32f10x_it.h"
#include "BSP_SysTick.h"
#include "BSP_Servo_PWM.h"

int main()
{
	SysTick_Init();
	Servo_Init();
	
	while(1)
	{
		TIM_SetCompare3(TIM3, 500);
		Delay_Ms(5000);
		TIM_SetCompare3(TIM3, 1000);
		Delay_Ms(5000);
		TIM_SetCompare3(TIM3, 1500);
		Delay_Ms(10000);
		TIM_SetCompare3(TIM3, 2000);
		Delay_Ms(5000);
		TIM_SetCompare3(TIM3, 2500);
		Delay_Ms(5000);
	}
}
