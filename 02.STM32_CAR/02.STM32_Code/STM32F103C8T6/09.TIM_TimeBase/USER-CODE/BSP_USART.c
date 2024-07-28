#include "BSP_USART.h"

void USART1_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	
	RCC_APB2PeriphClockCmd(USART1_Clock, ENABLE);

	GPIO_InitStructure.GPIO_Pin = USART1_Pin_Tx;
	GPIO_InitStructure.GPIO_Speed = USART1_Speed;
	GPIO_InitStructure.GPIO_Mode = USART1_Mode_Tx;
	GPIO_Init(USART1_Port, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = USART1_Pin_Rx;
	GPIO_InitStructure.GPIO_Mode = USART1_Mode_Rx;
	GPIO_Init(USART1_Port, &GPIO_InitStructure);
	
	USART_InitStructure.USART_BaudRate = USART1_BaudRate;
	USART_InitStructure.USART_WordLength = USART1_WordLength;
	USART_InitStructure.USART_StopBits = USART1_StopBits;
	USART_InitStructure.USART_Parity = USART1_Parity;
	USART_InitStructure.USART_Mode = USART1_Mode;
	USART_InitStructure.USART_HardwareFlowControl = USART1_HardwareFlowControl;
	USART_Init(USART1_Com, &USART_InitStructure);
	
	USART_Cmd(USART1_Com, ENABLE);
}

int fputc(int ch, FILE *f)
{
    while(USART_GetFlagStatus(Printf_USART_Com, USART_FLAG_TXE) == RESET);
    USART_SendData(Printf_USART_Com, ch);
    while(USART_GetFlagStatus(Printf_USART_Com, USART_FLAG_TC) == RESET);
    return ch;
}