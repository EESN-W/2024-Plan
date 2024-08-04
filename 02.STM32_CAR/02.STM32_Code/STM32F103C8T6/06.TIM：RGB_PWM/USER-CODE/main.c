#include "stm32f10x.h"
#include "stm32f10x_it.h"
#include "BSP_SysTick.h"
#include "BSP_TIM_PWM.h"

int main()
{
	SysTick_Init();
	TIM2_PWM_Init();
	
	while(1)
	{
		unsigned int Compare_Value = 0;

		for(Compare_Value = 0; Compare_Value < 25600; Compare_Value++)
		{
			TIM_SetCompare2(TIM2, Compare_Value);
			TIM_SetCompare3(TIM2, Compare_Value);
			TIM_SetCompare4(TIM2, Compare_Value);
			Delay_Us(25);
		}
		for(Compare_Value = 25600; Compare_Value > 0; Compare_Value--)
		{
			TIM_SetCompare2(TIM2, Compare_Value);
			TIM_SetCompare3(TIM2, Compare_Value);
			TIM_SetCompare4(TIM2, Compare_Value);
			Delay_Us(25);
		}
	}
}
