#include "stm32f10x.h"
#include "stm32f10x_it.h"
#include "BSP_SysTick.h"
#include "BSP_Motor.h"
#include "BSP_TIM_Base.h"
#include "BSP_USART.h"

int main()
{
	SysTick_Init();
	TIM1_Init();
	USART1_Init();
	TB6612FNG_GPIO_Init();
	Motor_PWM_Init();
	Motor_A_Encoder_Init();
	Motor_B_Encoder_Init();
	Motor_Direction();
	
	printf("Hello");
	
	unsigned int uMotorSpeed = 0;
	
	while(1){
		for(uMotorSpeed = 0; uMotorSpeed < 100; uMotorSpeed++)
		{
			TIM_SetCompare3(TIM2, uMotorSpeed);
			TIM_SetCompare4(TIM2, uMotorSpeed);
			Delay_Ms(500);
		}
		Delay_Ms(10000);
		for(uMotorSpeed = 100; uMotorSpeed > 0; uMotorSpeed--)
		{
			TIM_SetCompare3(TIM2, uMotorSpeed);
			TIM_SetCompare4(TIM2, uMotorSpeed);
			Delay_Ms(500);
		}
		Delay_Ms(10000);
	}
}
