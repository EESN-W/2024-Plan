/*
	功能：TIM3驱动电机(无编码器)
	作者：W_ML
	时间：2024.08.01
	说明：驱动电机并串口打印转速
	硬件连接：电机			TB6612FNG		STM32F103C8T6
						M+	<---->	AO1	
						M-	<---->	AO2
						VCC	<------------------>	5V
						GND	<---->	GND		<---->	GND
						A						
						B
												PWMA	<---->	PB0(TIM3_CH3)
												STBY	<---->	PA1
												AIN1	<---->	PA2
												AIN2	<---->	PA3
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

#define Motor_PWMA_Com							TIM3

#define Motor_GPIO_Clock						RCC_APB2Periph_GPIOA
#define Motor_PWMA_Clock1						RCC_APB2Periph_GPIOB
#define Motor_PWMA_Clock2						RCC_APB1Periph_TIM3

#define Motor_PWMA_Pin							GPIO_Pin_0
#define Motor_GPIO_Pin							(GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3)
#define Motor_PWMA_Mode							GPIO_Mode_AF_PP
#define Motor_GPIO_Mode							GPIO_Mode_Out_PP
#define Motor_PWMA_Speed						GPIO_Speed_50MHz
#define Motor_GPIO_Speed						GPIO_Speed_50MHz
#define Motor_PWMA_Port							GPIOB
#define Motor_GPIO_Port							GPIOA

#define Motor_PWMA_Period						(100-1)
#define Motor_PWMA_Prescaler				(72-1)
#define Motor_PWMA_ClockDivision		TIM_CKD_DIV1
#define Motor_PWMA_CounterMode			TIM_CounterMode_Up

#define Motor_PWMA_OCMode						TIM_OCMode_PWM1
#define Motor_PWMA_OutputState			TIM_OutputState_Enable
#define Motor_PWMA_Pulse						0
#define Motor_PWMA_OCPolarity				TIM_OCPolarity_High

#define STBY_HIGH 							GPIO_WriteBit(GPIOA, GPIO_Pin_1, Bit_SET)
#define STBY_LOW 								GPIO_WriteBit(GPIOA, GPIO_Pin_1, Bit_RESET)

#define AIN1_HIGH 							GPIO_WriteBit(GPIOA, GPIO_Pin_2, Bit_SET)
#define AIN1_LOW 								GPIO_WriteBit(GPIOA, GPIO_Pin_2, Bit_RESET)

#define AIN2_HIGH 							GPIO_WriteBit(GPIOA, GPIO_Pin_3, Bit_SET)
#define AIN2_LOW 								GPIO_WriteBit(GPIOA, GPIO_Pin_3, Bit_RESET)

void Motor_Init(void);	// 电机初始化

#endif
