#ifndef __BSP_USART_IT_H__
#define __BSP_USART_IT_H__

#include "stm32f10x.h"
#include "stdio.h"

#define	USART2_Com										USART2

#define USART2_Clock1 								RCC_APB2Periph_GPIOA
#define USART2_Clock2 								RCC_APB1Periph_USART2
#define USART2_Port 									GPIOA
#define USART2_Pin_Tx									GPIO_Pin_2
#define USART2_Pin_Rx									GPIO_Pin_3
#define USART2_Speed									GPIO_Speed_50MHz
#define USART2_Mode_Tx								GPIO_Mode_AF_PP
#define USART2_Mode_Rx								GPIO_Mode_IN_FLOATING

#define USART2_BaudRate								115200
#define USART2_WordLength							USART_WordLength_8b
#define USART2_StopBits								USART_StopBits_1
#define USART2_Parity									USART_Parity_No
#define USART2_Mode										(USART_Mode_Rx | USART_Mode_Tx)
#define USART2_HardwareFlowControl		USART_HardwareFlowControl_None

#define USART2_NVIC_PriorityGroupConfig							NVIC_PriorityGroup_0
#define USART2_NVIC_IRQChannel											USART2_IRQn
#define USART2_NVIC_IRQChannelPreemptionPriority		0x00
#define USART2_NVIC_IRQChannelSubPriority						0x01
#define USART2_IT_Sources														USART_IT_RXNE

void USART2_IT_Init(void);

#endif
