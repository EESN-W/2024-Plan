/*
	功能：配置SysTick定时器
	作者：W_ML
	时间：2024.08.01
	说明：SysTick中断函数位于stm32f10x_it.c文件
*/

#ifndef __BSP_SYSTICK_H__
#define __BSP_SYSTICK_H__

#include "stm32f10x.h"

extern unsigned int SysTick_Delay;

void SysTick_Init(void);						// SysTick初始化
void Delay_Us(unsigned int uTime);	// 微秒级延时
void Delay_Ms(unsigned int uTime);	// 毫秒级延时

#endif
