/*
	功能：检测KEY
	硬件连接：KEY引脚连接PA5
	作者：W_ML
	时间：2024.08.01
	说明：适用KEY一端接PA5引脚，另一端接GND
*/

#ifndef __BSP_KEY_H__
#define __BSP_KEY_H__

#include "stm32f10x.h"
#include "BSP_SysTick.h"

#define	KEY_Clock 	RCC_APB2Periph_GPIOA
#define	KEY_Port		GPIOA
#define	KEY_Pin 		GPIO_Pin_5
#define	KEY_Mode 		GPIO_Mode_IPU

#define	Press_Button		1
#define	Release_Button	0

void KEY_Init(void);		// KEY初始化
int KEY_Check(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);	// 按键检测

#endif
