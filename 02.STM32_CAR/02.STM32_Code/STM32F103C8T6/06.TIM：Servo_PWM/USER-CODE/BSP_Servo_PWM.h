/*
	功能：TIM3输出PWM控制舵机
	硬件连接：PB0接SIG
	作者：W_ML
	时间：2024.08.01
	说明：配置PB0输出PWM，频率为50Hz
	舵机				STM32F103C8T6
	VCC	<----->	5v
	SIG	<----->	PB0
	GND	<----->	GND
*/

#ifndef __BSP_SERVO_PWM__
#define __BSP_SERVO_PWM__

#include "stm32f10x.h"

#define Servo_Com									TIM3

#define Servo_Clock1							RCC_APB2Periph_GPIOB
#define Servo_Clock2							RCC_APB1Periph_TIM3

#define Servo_Pin									GPIO_Pin_0
#define Servo_Mode								GPIO_Mode_AF_PP
#define Servo_Speed								GPIO_Speed_50MHz
#define Servo_Port								GPIOB											

#define Servo_Period							(20000-1)
#define Servo_Prescaler						(72-1)
#define Servo_ClockDivision				TIM_CKD_DIV1
#define Servo_CounterMode					TIM_CounterMode_Up

#define Servo_OCMode							TIM_OCMode_PWM1
#define Servo_OutputState					TIM_OutputState_Enable
#define Servo_Pulse								0
#define Servo_OCPolarity					TIM_OCPolarity_High

void Servo_Init(void);		// TIM3_CH3输出PWM初始化

#endif
