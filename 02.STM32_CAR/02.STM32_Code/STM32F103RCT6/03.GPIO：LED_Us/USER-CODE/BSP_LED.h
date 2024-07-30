/*
	功能：驱动LED
	硬件连接：LED引脚连接PB3
	作者：W_ML
	时间：2024.08.01
	说明：适用LED阳极开发板引脚，LED阴极接开发板GND
*/

#ifndef __BSP_LED_H__
#define __BSP_LED_H__

#include "stm32f10x.h"

#define	LED_Clock 	(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO)
#define	LED_Port		GPIOB
#define	LED_Pin 		GPIO_Pin_3
#define	LED_Speed 	GPIO_Speed_50MHz
#define	LED_Mode 		GPIO_Mode_Out_PP

void LED_Init(void);	// LED初始化

#endif
