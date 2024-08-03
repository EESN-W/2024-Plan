/*
	功能：配置USART1接收中断
	作者：W_ML
	时间：2024.08.01
	说明：配置USART1接收中断并发送数据
*/

#ifndef __BSP_USART_IT_H__
#define __BSP_USART_IT_H__

#include "stm32f10x.h"
#include "stdio.h"
	
#define Printf_USART_Com 							USART1

#define	USART1_Com										USART1
#define USART1_Clock 									(RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1)
#define USART1_Port 									GPIOA
#define USART1_Pin_Tx									GPIO_Pin_9
#define USART1_Pin_Rx									GPIO_Pin_10
#define USART1_Speed									GPIO_Speed_50MHz
#define USART1_Mode_Tx								GPIO_Mode_AF_PP
#define USART1_Mode_Rx								GPIO_Mode_IN_FLOATING

#define USART1_NVIC_PriorityGroupConfig							NVIC_PriorityGroup_0
#define USART1_NVIC_IRQChannel											USART1_IRQn
#define USART1_NVIC_IRQChannelPreemptionPriority		0x00
#define USART1_NVIC_IRQChannelSubPriority						0x01
#define USART1_IT_Sources														USART_IT_RXNE

#define USART1_BaudRate								115200
#define USART1_WordLength							USART_WordLength_8b
#define USART1_StopBits								USART_StopBits_1
#define USART1_Parity									USART_Parity_No
#define USART1_HardwareFlowControl		USART_HardwareFlowControl_None
#define USART1_Mode										(USART_Mode_Rx | USART_Mode_Tx)

void USART1_IT_Init(void);		// USART1初始化
int fputc (int c, FILE *pt);	// Printf重定向

#endif
