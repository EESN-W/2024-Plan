/*
	功能：TIM3驱动电机(编码器)
	作者：W_ML
	时间：2024.08.01
	说明：驱动电机并串口打印转速
	硬件连接：
						电机A			TB6612FNG		STM32F103C8T6
						M+	<---->	AO1	
						M-	<---->	AO2
						VCC	<------------------>	5V
						GND	<---->	GND		<---->	GND
						A		<------------------>	PA7							
						B		<------------------>	PA6
												PWMA	<---->	PA2
												STBY	<---->	PA1
												AIN1	<---->	PA4
												AIN2	<---->	PA5
						电机B			TB6612FNG		STM32F103C8T6						
						M+	<---->	BO1	
						M-	<---->	BO2
						VCC	<------------------>	5V
						GND	<---->	GND		<---->	GND
						A		<------------------>	PB7						
						B		<------------------>	PB6
												PWMB	<---->	PA3
												BIN1	<---->	PA11
												BIN2	<---->	PA12
						
						
	TB6612FNG引脚说明：
	VM		<-------------->		驱动电压（12V）
	VCC		<-------------->		逻辑电平（3.3V/5V）
	GND		<-------------->		电源GND
	STBY	<-------------->		工作/待机控制端
	电机1:
	PWMA	<-------------->		PWMA信号输入端（速度控制）
	AIN1	<-------------->		电机控制输入端（方向控制）
	AIN2	<-------------->		电机控制输入端（方向控制）
	AO1		<-------------->		电机驱动输出端
	AO2		<-------------->		电机驱动输出端
	电机2:
	PWMB	<-------------->		PWMB信号输入端（速度控制）
	BIN1	<-------------->		电机控制输入端（方向控制）
	BIN2	<-------------->		电机控制输入端（方向控制）
	BO1		<-------------->		电机驱动输出端
	BO2		<-------------->		电机驱动输出端
*/

#ifndef __BSP_MOTOR_H__
#define __BSP_MOTOR_H__

#include "stm32f10x.h"

#define Motor_PWM_Com									TIM2
#define Motor_A_Encoder_Com						TIM3
#define Motor_B_Encoder_Com						TIM4

#define Motor_GPIO_Clock							RCC_APB2Periph_GPIOA
#define Motor_PWMA_Clock1							RCC_APB2Periph_GPIOA
#define Motor_PWMA_Clock2							RCC_APB1Periph_TIM2
#define Motor_A_Encoder_Clock1				RCC_APB2Periph_GPIOA
#define Motor_A_Encoder_Clock2				RCC_APB1Periph_TIM3
#define Motor_B_Encoder_Clock1				RCC_APB2Periph_GPIOB
#define Motor_B_Encoder_Clock2				RCC_APB1Periph_TIM4

#define Motor_PWM_Pin									(GPIO_Pin_2 | GPIO_Pin_3)
#define Motor_GPIO_Pin								(GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_11 | GPIO_Pin_12)
#define Motor_A_Encoder_Pin						(GPIO_Pin_6 | GPIO_Pin_7)
#define Motor_B_Encoder_Pin						(GPIO_Pin_6 | GPIO_Pin_7)
#define Motor_GPIO_Mode								GPIO_Mode_Out_PP
#define Motor_PWM_Mode								GPIO_Mode_AF_PP
#define Motor_A_Encoder_GPIO_Mode			GPIO_Mode_IN_FLOATING
#define Motor_B_Encoder_GPIO_Mode			GPIO_Mode_IN_FLOATING
#define Motor_GPIO_Speed							GPIO_Speed_50MHz
#define Motor_PWM_Speed								GPIO_Speed_50MHz
#define Motor_PWM_Port								GPIOA
#define Motor_GPIO_Port								GPIOA
#define Motor_A_Encoder_Port					GPIOA
#define Motor_B_Encoder_Port					GPIOB

#define Motor_PWM_Period							(100-1)
#define Motor_PWM_Prescaler						(72-1)
#define Motor_A_Encoder_Period				(0xFFFF)
#define Motor_A_Encoder_Prescaler			(1-1)
#define Motor_B_Encoder_Period				(0xFFFF)
#define Motor_B_Encoder_Prescaler			(1-1)
#define Motor_PWM_ClockDivision				TIM_CKD_DIV1
#define Motor_A_Encoder_ClockDivision	TIM_CKD_DIV1
#define Motor_B_Encoder_ClockDivision	TIM_CKD_DIV1
#define Motor_PWM_CounterMode					TIM_CounterMode_Up
#define Motor_A_Encoder_CounterMode		TIM_CounterMode_Up
#define Motor_B_Encoder_CounterMode		TIM_CounterMode_Up

#define Motor_PWM_OCMode							TIM_OCMode_PWM1
#define Motor_PWM_OutputState					TIM_OutputState_Enable
#define Motor_PWM_Pulse								0
#define Motor_PWM_OCPolarity					TIM_OCPolarity_High

#define Motor_A_Encoder_Mode					TIM_EncoderMode_TI12
#define Motor_A_Encoder_IC1Polarity		TIM_ICPolarity_Rising
#define Motor_A_Encoder_IC2Polarity		TIM_ICPolarity_Rising
#define Motor_A_Encoder_ICFilter			10
#define Motor_B_Encoder_Mode					TIM_EncoderMode_TI12
#define Motor_B_Encoder_IC1Polarity		TIM_ICPolarity_Rising
#define Motor_B_Encoder_IC2Polarity		TIM_ICPolarity_Rising
#define Motor_B_Encoder_ICFilter			10

#define STBY_HIGH 							GPIO_WriteBit(GPIOA, GPIO_Pin_1, Bit_SET)
#define STBY_LOW 								GPIO_WriteBit(GPIOA, GPIO_Pin_1, Bit_RESET)

#define AIN1_HIGH 							GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_SET)
#define AIN1_LOW 								GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_RESET)

#define AIN2_HIGH 							GPIO_WriteBit(GPIOA, GPIO_Pin_5, Bit_SET)
#define AIN2_LOW 								GPIO_WriteBit(GPIOA, GPIO_Pin_5, Bit_RESET)

#define BIN1_HIGH 							GPIO_WriteBit(GPIOA, GPIO_Pin_11, Bit_SET)
#define BIN1_LOW 								GPIO_WriteBit(GPIOA, GPIO_Pin_11, Bit_RESET)

#define BIN2_HIGH 							GPIO_WriteBit(GPIOA, GPIO_Pin_12, Bit_SET)
#define BIN2_LOW 								GPIO_WriteBit(GPIOA, GPIO_Pin_12, Bit_RESET)

void TB6612FNG_GPIO_Init(void);		// TB6612FNG普通引脚初始化
void Motor_PWM_Init(void);				// 电机PWM初始化
void Motor_A_Encoder_Init(void);	// 电机A编码器初始化
void Motor_B_Encoder_Init(void);	// 电机B编码器初始化
void Motor_Direction(void);				// 电机转向

#endif
