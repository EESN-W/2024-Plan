#include "BSP_USART_IT.h"

void USART1_IT_Init(void)
{
	// 定义GPIO结构体
	GPIO_InitTypeDef GPIO_InitStructure;
	// 定义NVIC结构体
	NVIC_InitTypeDef NVIC_InitStructure;
	// 定义USART结构体
	USART_InitTypeDef USART_InitStructure;
	
	// 使能USART1时钟
	RCC_APB2PeriphClockCmd(USART1_Clock, ENABLE);

	// 配置GPIO结构体参数
	GPIO_InitStructure.GPIO_Pin = USART1_Pin_Tx;		// 配置GPIO引脚
	GPIO_InitStructure.GPIO_Speed = USART1_Speed;		// 配置引脚速率为50MHz
	GPIO_InitStructure.GPIO_Mode = USART1_Mode_Tx;	// 配置引脚模式为复用推挽输出
	GPIO_Init(USART1_Port, &GPIO_InitStructure);		// 初始化GPIO结构体
	
	GPIO_InitStructure.GPIO_Pin = USART1_Pin_Rx;		// 配置GPIO引脚
	GPIO_InitStructure.GPIO_Mode = USART1_Mode_Rx;	// 配置引脚模式为浮空输入
	GPIO_Init(USART1_Port, &GPIO_InitStructure);		// 初始化GPIO结构体
	
	// 配置NVIC结构体参数
	NVIC_PriorityGroupConfig(USART1_NVIC_PriorityGroupConfig);			// 配置中断群组:0
	NVIC_InitStructure.NVIC_IRQChannel = USART1_NVIC_IRQChannel;		// 配置中断通道:USART1中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = USART1_NVIC_IRQChannelPreemptionPriority;	// 配置抢占优先级:0x00
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = USART1_NVIC_IRQChannelSubPriority;								// 配置子优先级:0x01
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;		// 使能中断通道
	NVIC_Init(&NVIC_InitStructure);										// 初始化NVIC结构体参数
	
	// 配置USART结构体参数
	USART_InitStructure.USART_BaudRate = USART1_BaudRate;													// 配置波特率:115200
	USART_InitStructure.USART_WordLength = USART1_WordLength;											// 配置数据字长:8
	USART_InitStructure.USART_StopBits = USART1_StopBits;													// 配置停止位:1
	USART_InitStructure.USART_Parity = USART1_Parity;															// 配置校验位:无
	USART_InitStructure.USART_HardwareFlowControl = USART1_HardwareFlowControl;		// 配置硬件流控制:无
	USART_InitStructure.USART_Mode = USART1_Mode;																	// 配置工作模式:收发
	USART_Init(USART1_Com, &USART_InitStructure);		// 初始化USART结构体参数
	
	USART_ITConfig(USART1_Com, USART1_IT_Sources, ENABLE); // 使能USART1接收中断
	
	USART_Cmd(USART1_Com, ENABLE);		// 使能USART1
}

int fputc(int ch, FILE *f)
{
    while(USART_GetFlagStatus(Printf_USART_Com, USART_FLAG_TXE) == RESET);
    USART_SendData(Printf_USART_Com, ch);
    while(USART_GetFlagStatus(Printf_USART_Com, USART_FLAG_TC) == RESET);
    return ch;
}
