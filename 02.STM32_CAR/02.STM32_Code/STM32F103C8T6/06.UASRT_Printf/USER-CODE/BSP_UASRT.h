#ifndef __BSP_UASRT_H__
#define __BSP_UASRT_H__

#include "stm32f10x.h"
#include "stdio.h"
	
#define Printf_USART_Com 							USART1

#define	UASRT1_Com										USART1
#define UASRT1_Clock 									(RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1)
#define UASRT1_Port 									GPIOA
#define UASRT1_Pin_Tx									GPIO_Pin_9
#define UASRT1_Pin_Rx									GPIO_Pin_10
#define UASRT1_Speed									GPIO_Speed_50MHz
#define UASRT1_Mode_Tx								GPIO_Mode_AF_PP
#define UASRT1_Mode_Rx								GPIO_Mode_IN_FLOATING
#define USART1_BaudRate								115200
#define USART1_WordLength							USART_WordLength_8b
#define USART1_StopBits								USART_StopBits_1
#define USART1_Parity									USART_Parity_No
#define USART1_Mode										(USART_Mode_Rx | USART_Mode_Tx)
#define USART1_HardwareFlowControl		USART_HardwareFlowControl_None

void UASRT1_Init(void);
int fputc (int c, FILE *pt);

#endif
