/*
	功能：超声波模块测距
	硬件连接：无
	作者：W_ML
	时间：2024.08.04
	说明：配置TIM2定时器计数功能，根据计数值计算距离
	
	HC_SR04				STM32F103C8T6
	VCC		<----->	5V
	TRIG	<----->	PA1
	ECHO	<----->	PA2
	GND		<----->	GND
*/

#ifndef __BSP_HC_SR04_H__
#define __BSP_HC_SR04_H__

#include "stm32f10x.h"

#define TIM2_Com							TIM2

#define TIM2_Clock						RCC_APB1Periph_TIM2													

#define TIM2_Period						(0xFFFF-1)
#define TIM2_Prescaler				(72-1)
#define TIM2_ClockDivision		TIM_CKD_DIV1
#define TIM2_CounterMode			TIM_CounterMode_Up
#define TIM2_FLAG							TIM_FLAG_Update
#define TIM2_IT_Source				TIM_IT_Update

#define	HC_SR04_TRIG_Clock 		RCC_APB2Periph_GPIOC
#define	HC_SR04_Port					GPIOA
#define	HC_SR04_TRIG_Pin 			GPIO_Pin_1
#define	HC_SR04_TRIG_Speed 		GPIO_Speed_50MHz
#define	HC_SR04_TRIG_Mode 		GPIO_Mode_Out_PP
#define	HC_SR04_ECHO_Pin 			GPIO_Pin_2
#define	HC_SR04_ECHO_Mode 		GPIO_Mode_IN_FLOATING

void TIM2_Init(void); // TIM2初始化
void HC_SR04_TRIG_ECHO_Init(void);	// TRIG和ECHO引脚初始化

#endif
