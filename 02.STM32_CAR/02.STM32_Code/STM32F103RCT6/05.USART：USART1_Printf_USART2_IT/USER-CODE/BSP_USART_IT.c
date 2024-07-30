#include "BSP_USART_IT.h"

void USART2_IT_Init(void)
{
	// 定义GPIO结构体
	GPIO_InitTypeDef GPIO_InitStructure;
	// 定义NVIC结构体
	USART_InitTypeDef USART_InitStructure;
	// 定义USART结构体
	NVIC_InitTypeDef NVIC_InitStructure;
	
	// 使能USART2时钟
	RCC_APB2PeriphClockCmd(USART2_Clock1, ENABLE);
	RCC_APB1PeriphClockCmd(USART2_Clock2, ENABLE);

	// 配置GPIO结构体参数
	GPIO_InitStructure.GPIO_Pin = USART2_Pin_Tx;			// 配置GPIO引脚
	GPIO_InitStructure.GPIO_Speed = USART2_Speed;     // 配置引脚速率为50MHz
	GPIO_InitStructure.GPIO_Mode = USART2_Mode_Tx;    // 配置引脚模式为复用推挽输出
	GPIO_Init(USART2_Port, &GPIO_InitStructure);      // 初始化GPIO结构体
	                                                  
	GPIO_InitStructure.GPIO_Pin = USART2_Pin_Rx;      // 配置GPIO引脚
	GPIO_InitStructure.GPIO_Mode = USART2_Mode_Rx;    // 配置引脚模式为浮空输入
	GPIO_Init(USART2_Port, &GPIO_InitStructure);      // 初始化GPIO结构体
	
	// 配置NVIC结构体参数
	NVIC_PriorityGroupConfig(USART2_NVIC_PriorityGroupConfig);			// 配置中断群组:0
	NVIC_InitStructure.NVIC_IRQChannel = USART2_NVIC_IRQChannel;    // 配置中断通道:USART2中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = USART2_NVIC_IRQChannelPreemptionPriority;	// 配置抢占优先级:0x00
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = USART2_NVIC_IRQChannelSubPriority;                // 配置子优先级:0x01
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;		// 使能中断通道
	NVIC_Init(&NVIC_InitStructure);										// 初始化NVIC结构体参数

	USART_InitStructure.USART_BaudRate = USART2_BaudRate;															// 配置波特率:115200
	USART_InitStructure.USART_WordLength = USART2_WordLength;                         // 配置数据字长:8
	USART_InitStructure.USART_StopBits = USART2_StopBits;                             // 配置停止位:1
	USART_InitStructure.USART_Parity = USART2_Parity;                                 // 配置校验位:无
	USART_InitStructure.USART_Mode = USART2_Mode;                                     // 配置硬件流控制:无
	USART_InitStructure.USART_HardwareFlowControl = USART2_HardwareFlowControl;       // 配置工作模式:收发
	USART_Init(USART2_Com, &USART_InitStructure);			// 初始化USART结构体参数
	
	USART_ITConfig(USART2_Com, USART2_IT_Sources, ENABLE);	// 使能USART2接收中断

	USART_Cmd(USART2_Com, ENABLE); 	// 使能USART2
}
