#include "BSP_USART_IT.h"

void USART2_IT_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB2PeriphClockCmd(USART2_Clock1, ENABLE);
	RCC_APB1PeriphClockCmd(USART2_Clock2, ENABLE);

	GPIO_InitStructure.GPIO_Pin = USART2_Pin_Tx;
	GPIO_InitStructure.GPIO_Speed = USART2_Speed;
	GPIO_InitStructure.GPIO_Mode = USART2_Mode_Tx;
	GPIO_Init(USART2_Port, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = USART2_Pin_Rx;
	GPIO_InitStructure.GPIO_Mode = USART2_Mode_Rx;
	GPIO_Init(USART2_Port, &GPIO_InitStructure);
	
	NVIC_PriorityGroupConfig(USART2_NVIC_PriorityGroupConfig);
	NVIC_InitStructure.NVIC_IRQChannel = USART2_NVIC_IRQChannel;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = USART2_NVIC_IRQChannelPreemptionPriority;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = USART2_NVIC_IRQChannelSubPriority;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	USART_InitStructure.USART_BaudRate = USART2_BaudRate;
	USART_InitStructure.USART_WordLength = USART2_WordLength;
	USART_InitStructure.USART_StopBits = USART2_StopBits;
	USART_InitStructure.USART_Parity = USART2_Parity;
	USART_InitStructure.USART_Mode = USART2_Mode;
	USART_InitStructure.USART_HardwareFlowControl = USART2_HardwareFlowControl;
	USART_Init(USART2_Com, &USART_InitStructure);
	
	USART_ITConfig(USART2_Com, USART2_IT_Sources, ENABLE);

	USART_Cmd(USART2_Com, ENABLE);
}
