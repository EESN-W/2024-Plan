#include "BSP_TIM_PWM.h"

void TIM3_PWM_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	RCC_APB2PeriphClockCmd(TIM3_Clock1, ENABLE);
	RCC_APB1PeriphClockCmd(TIM3_Clock2, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin 	= TIM3_Pin;
	GPIO_InitStructure.GPIO_Mode 	= TIM3_Mode;
	GPIO_InitStructure.GPIO_Speed = TIM3_Speed;
	GPIO_Init(TIM3_Port, &GPIO_InitStructure);
	
	TIM_TimeBaseStructure.TIM_Period = TIM3_Period;
	TIM_TimeBaseStructure.TIM_Prescaler = TIM3_Prescaler;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM3_ClockDivision;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM3_CounterMode;
	TIM_TimeBaseInit(TIM3_Com, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM3_OCMode;
	TIM_OCInitStructure.TIM_OutputState = TIM3_OutputState;
	TIM_OCInitStructure.TIM_Pulse = TIM3_Pulse;
	TIM_OCInitStructure.TIM_OCPolarity = TIM3_OCPolarity;
	TIM_OC3Init(TIM3_Com, &TIM_OCInitStructure);
	
	TIM_OC3PreloadConfig(TIM3_Com, TIM_OCPreload_Enable); 
	TIM_ARRPreloadConfig(TIM3_Com, ENABLE);
	
	TIM_Cmd(TIM3_Com, ENABLE);
}

