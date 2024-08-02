#include "stm32f10x.h"
#include "BSP_SysTick.h"
#include "BSP_Motor.h"

int main()
{
	SysTick_Init();
	Motor_Init();
	
	STBY_HIGH;
	AIN1_HIGH;
	AIN2_LOW;
	
	unsigned int uMotorSpeed = 0;
	
	while(1){
		for(uMotorSpeed = 0; uMotorSpeed < 100; uMotorSpeed++)
		{
			TIM_SetCompare3(TIM3, uMotorSpeed);
			Delay_Ms(50);
		}
		for(uMotorSpeed = 100; uMotorSpeed > 0; uMotorSpeed--)
		{
			TIM_SetCompare3(TIM3, uMotorSpeed);
			Delay_Ms(50);
		}
	}
}
