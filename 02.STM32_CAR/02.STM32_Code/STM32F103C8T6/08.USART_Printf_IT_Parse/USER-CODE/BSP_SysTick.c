#include "BSP_SysTick.h"

unsigned int SysTick_Delay;

void SysTick_Init(void)
{
	while(SysTick_Config(SystemCoreClock / 1000000)); 	// Reload value (72) → 1us enters a SysTick interrupt
	SysTick->CTRL &= ~(SysTick_CTRL_ENABLE_Msk); 				// Disable SysTick
}

void Delay_Us(unsigned int uTime)
{
	SysTick_Delay = uTime;
	SysTick->CTRL |= (SysTick_CTRL_ENABLE_Msk);		// Enable SysTick
	while(SysTick_Delay);
	SysTick->CTRL &= ~(SysTick_CTRL_ENABLE_Msk); 	// Disable SysTick
}

void Delay_Ms(unsigned int uTime)
{
	while(uTime--)
	{
		Delay_Us(1000);
	}
}
