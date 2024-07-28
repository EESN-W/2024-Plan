#ifndef __BSP_SYSTICK_H__
#define __BSP_SYSTICK_H__

#include "stm32f10x.h"

extern unsigned int SysTick_Delay;

void SysTick_Init(void);
void Delay_Us(unsigned int uTime);
void Delay_Ms(unsigned int uTime);

#endif
