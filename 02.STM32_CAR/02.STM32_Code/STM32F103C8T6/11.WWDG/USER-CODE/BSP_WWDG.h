/*
	功能：配置窗口看门狗
	作者：W_ML
	时间：2024.08.05
	说明：喂狗时间间隔5s
*/

#ifndef __BSP_IWDG_H__
#define __BSP_IWDG_H__

#include "stm32f10x.h"
#include "BSP_USART_IT.h"

void WWDG_Init(void);		// 窗口看门狗初始化

#endif
