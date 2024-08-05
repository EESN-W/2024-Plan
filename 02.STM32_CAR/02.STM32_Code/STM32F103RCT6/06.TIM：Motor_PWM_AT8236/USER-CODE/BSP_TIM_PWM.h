/*
	功能：AT8236驱动双路电机
	作者：W_ML
	时间：2024.08.05
	说明：需严格按照接线操作
	AT8236				STM32F103RCT6				MotorA				MotorB				外接电源
	VM		<------------------------------------------------------>	12V
	VCC		<----->	5V
	GND		<----->	GND
	GND		<------------------------------------------------------>	GND
								5V	<------------->	VCC
								GND	<------------->	GND
								5V	<--------------------------->	VCC
								GND	<--------------------------->	GND
	AOUT1	<------------------------->	M+
	AOUT2	<------------------------->	M-
	BOUT1	<--------------------------------------->	M+
	BOUT2	<--------------------------------------->	M-
	AIN1	<----->	PC6
	AIN2	<----->	PC7
	BIN1	<----->	PC8
	BIN2	<----->	PC9
								PA6	<------------->	A
								PA7	<------------->	B
								PB6	<--------------------------->	A
								PB7	<--------------------------->	B
*/

#ifndef __BSP_TIM_PWM__
#define __BSP_TIM_PWM__

#include "stm32f10x.h"

#define TIM8_Com								TIM8

#define TIM8_Clock							(RCC_APB2Periph_GPIOC | RCC_APB2Periph_TIM8 | RCC_APB2Periph_AFIO)

#define TIM8_Pin								(GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9)
#define TIM8_Mode								GPIO_Mode_AF_PP
#define TIM8_Speed							GPIO_Speed_50MHz
#define TIM8_Port								GPIOC										

#define TIM8_Period							(100-1)
#define TIM8_Prescaler					(72-1)
#define TIM8_ClockDivision			TIM_CKD_DIV1
#define TIM8_CounterMode				TIM_CounterMode_Up

#define TIM8_OCMode							TIM_OCMode_PWM1
#define TIM8_OutputState				TIM_OutputState_Enable
#define TIM8_Pulse							0
#define TIM8_OCPolarity					TIM_OCPolarity_High

#define Motor_A_Encoder_Com						TIM3
#define Motor_B_Encoder_Com						TIM4

#define Motor_A_Encoder_Clock1				RCC_APB2Periph_GPIOA
#define Motor_A_Encoder_Clock2				RCC_APB1Periph_TIM3
#define Motor_B_Encoder_Clock1				RCC_APB2Periph_GPIOB
#define Motor_B_Encoder_Clock2				RCC_APB1Periph_TIM4

#define Motor_A_Encoder_Pin						(GPIO_Pin_6 | GPIO_Pin_7)
#define Motor_B_Encoder_Pin						(GPIO_Pin_6 | GPIO_Pin_7)
#define Motor_A_Encoder_GPIO_Mode			GPIO_Mode_IN_FLOATING
#define Motor_B_Encoder_GPIO_Mode			GPIO_Mode_IN_FLOATING
#define Motor_A_Encoder_Port					GPIOA
#define Motor_B_Encoder_Port					GPIOB

#define Motor_A_Encoder_Period				(0xFFFF)
#define Motor_A_Encoder_Prescaler			(1-1)
#define Motor_B_Encoder_Period				(0xFFFF)
#define Motor_B_Encoder_Prescaler			(1-1)
#define Motor_A_Encoder_ClockDivision	TIM_CKD_DIV1
#define Motor_B_Encoder_ClockDivision	TIM_CKD_DIV1
#define Motor_A_Encoder_CounterMode		TIM_CounterMode_Up
#define Motor_B_Encoder_CounterMode		TIM_CounterMode_Up

#define Motor_A_Encoder_Mode					TIM_EncoderMode_TI12
#define Motor_A_Encoder_IC1Polarity		TIM_ICPolarity_Rising
#define Motor_A_Encoder_IC2Polarity		TIM_ICPolarity_Rising
#define Motor_A_Encoder_ICFilter			10
#define Motor_B_Encoder_Mode					TIM_EncoderMode_TI12
#define Motor_B_Encoder_IC1Polarity		TIM_ICPolarity_Rising
#define Motor_B_Encoder_IC2Polarity		TIM_ICPolarity_Rising
#define Motor_B_Encoder_ICFilter			10

extern unsigned int uEncoderACounter;
extern unsigned int uEncoderBCounter;

void TIM8_PWM_Init(void);		// TIM8 4通道输出PWM初始化
void Motor_Encoder_A_Init(void);	// 电机A编码器初始化
void Motor_Encoder_B_Init(void);	// 电机B编码器初始化
void Motor_Direction(void);				// 控制电机正转
void Get_Motor_Speed(void);				// 控制电机转向

#endif
