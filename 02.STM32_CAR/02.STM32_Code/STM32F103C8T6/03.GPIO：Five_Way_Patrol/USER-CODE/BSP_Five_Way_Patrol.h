/*
	功能：配置五路循迹模块
	硬件连接:五路巡线模块的OUT1-5分别接PA1-5
	作者：W_ML
	时间：2024.08.03
	说明：读取五路循迹模块的引脚电平，并通过串口打印检测信息
*/

#ifndef __BSP_FIVE_WAY_PATROL_H__
#define __BSP_FIVE_WAY_PATROL_H__

#include "stm32f10x.h"

#define Five_Way_Patrol_Clock		RCC_APB2Periph_GPIOA
#define Five_Way_Patrol_Pin			(GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5)
#define Five_Way_Patrol_Mode		GPIO_Mode_IPU
#define Five_Way_Patrol_Port		GPIOA

#define	X1_State								GPIO_ReadInputDataBit(Five_Way_Patrol_Port, GPIO_Pin_1)
#define	X2_State								GPIO_ReadInputDataBit(Five_Way_Patrol_Port, GPIO_Pin_2)
#define	X3_State								GPIO_ReadInputDataBit(Five_Way_Patrol_Port, GPIO_Pin_3)
#define	X4_State								GPIO_ReadInputDataBit(Five_Way_Patrol_Port, GPIO_Pin_4)
#define	X5_State								GPIO_ReadInputDataBit(Five_Way_Patrol_Port, GPIO_Pin_5)

void Five_Way_Patrol_Init(void);	// 五路循迹模块初始化

#endif
