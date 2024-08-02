#include "BSP_SysTick.h"

unsigned int SysTick_Delay;

void SysTick_Init(void)
{
	while(SysTick_Config(SystemCoreClock / 1000000)); 	// 配置重装载值72
	SysTick->CTRL &= ~(SysTick_CTRL_ENABLE_Msk); 				// 失能SysTick
}

void Delay_Us(unsigned int uTime)
{
	SysTick_Delay = uTime;
	SysTick->CTRL |= (SysTick_CTRL_ENABLE_Msk);		// 使能SysTick
	while(SysTick_Delay);
	SysTick->CTRL &= ~(SysTick_CTRL_ENABLE_Msk); 	// 失能SysTick
}

void Delay_Ms(unsigned int uTime)
{
	while(uTime--)
	{
		Delay_Us(1000);
	}
}
