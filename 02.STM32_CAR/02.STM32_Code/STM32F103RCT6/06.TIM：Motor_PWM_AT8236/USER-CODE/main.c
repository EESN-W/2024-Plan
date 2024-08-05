#include "stm32f10x.h"
#include "stm32f10x_it.h"
#include "BSP_TIM_Base.h"
#include "BSP_USART_IT.h"
#include "BSP_SysTick.h"
#include "BSP_TIM_PWM.h"

int main()
{
	SysTick_Init();
	TIM1_Init();
	USART1_IT_Init();
	TIM8_PWM_Init();
	Motor_Encoder_A_Init();
	Motor_Encoder_B_Init();
	
//	// L:正转-慢衰减
//	TIM_SetCompare1(TIM8_Com, 25);
//	TIM_SetCompare2(TIM8_Com, 100);
//	// R:正转-慢衰减
//	TIM_SetCompare3(TIM8_Com, 100);
//	TIM_SetCompare4(TIM8_Com, 25);
//	// L:正转-快衰减
//	TIM_SetCompare1(TIM8_Com, 0);
//	TIM_SetCompare2(TIM8_Com, 75);
//	// R:正转-快衰减
//	TIM_SetCompare3(TIM8_Com, 75);
//	TIM_SetCompare4(TIM8_Com, 0);
	
//	// L:反转-慢衰减
//	TIM_SetCompare1(TIM8_Com, 100);
//	TIM_SetCompare2(TIM8_Com, 25);
//	// R:反转-慢衰减
//	TIM_SetCompare3(TIM8_Com, 25);
//	TIM_SetCompare4(TIM8_Com, 100);
//	// L:反转-快衰减
//	TIM_SetCompare1(TIM8_Com, 75);
//	TIM_SetCompare2(TIM8_Com, 0);
//	// R:反转-快衰减
//	TIM_SetCompare3(TIM8_Com, 0);
//	TIM_SetCompare4(TIM8_Com, 75);

	while(1)
	{
		
	}
}
