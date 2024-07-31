#include "stm32f10x.h"
#include "stm32f10x_it.h"
#include "BSP_SysTick.h"
#include "BSP_Motor.h"
#include "BSP_TIM_Base.h"
#include "BSP_USART.h"

int main()
{
	SysTick_Init();
	TIM2_Init();
	USART1_Init();
	Motor_Init();
	Motor_Encoder_Init();
	
	STBY_HIGH;
	AIN1_HIGH;
	AIN2_LOW;
	
	unsigned int uMotorSpeed = 0;
	
	while(1){
		for(uMotorSpeed = 0; uMotorSpeed < 100; uMotorSpeed++)
		{
			TIM_SetCompare3(TIM3, uMotorSpeed);
			Delay_Ms(100);
		}
		Delay_Ms(5000);
		for(uMotorSpeed = 100; uMotorSpeed > 0; uMotorSpeed--)
		{
			TIM_SetCompare3(TIM3, uMotorSpeed);
			Delay_Ms(100);
		}
		Delay_Ms(5000);
	}
}
