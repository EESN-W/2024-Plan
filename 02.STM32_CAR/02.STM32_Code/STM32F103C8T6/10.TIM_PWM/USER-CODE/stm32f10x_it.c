/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.6.0
  * @date    20-September-2021
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2011 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
#include "BSP_KEY_EXTI.h"
#include "BSP_SysTick.h"
#include "BSP_USART.h"
#include "BSP_LED.h"

/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

uint8_t uData_Buffer[5];
uint8_t uRx_Buffer[5];
uint8_t uData_Flag = 0;
uint8_t uRx_Index = 0;

uint32_t uTimerCount = 0;

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
	if(SysTick_Delay != 0)
	{
		SysTick_Delay--;
	}
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

void EXTI0_IRQHandler(void)
{
	if(EXTI_GetITStatus(KEY2_EXTI_Line) != RESET)
	{
		GPIO_WriteBit(LED_Port, LED_Pin, (BitAction)!GPIO_ReadOutputDataBit(LED_Port, LED_Pin));
		EXTI_ClearITPendingBit(KEY2_EXTI_Line);
	}
}

void USART2_IRQHandler(void)
{
	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
	{
		uRx_Buffer[uRx_Index] = USART_ReceiveData(USART2);

		if(uRx_Buffer[uRx_Index] == 0xEF)
		{
			memset(uRx_Buffer, 0, sizeof(uRx_Buffer));
			uRx_Buffer[0] = 0xEF;
			uRx_Index = 1;
			uData_Flag = 1;
		}
		else if(uRx_Buffer[uRx_Index] == 0xFE && uData_Flag == 1)
		{
			if(uRx_Buffer[1] + uRx_Buffer[2] == uRx_Buffer[3])
			{
				memset(uData_Buffer, 0, sizeof(uData_Buffer));
				memcpy(uData_Buffer, uRx_Buffer, sizeof(uRx_Buffer));
				memset(uRx_Buffer, 0, sizeof(uRx_Buffer));
				printf("Check right!\n");
				printf("Function Bit: %d\n", uData_Buffer[1]);
				printf("Data Bit: %d\n", uData_Buffer[2]);
				printf("Check Bit: %d\n", uData_Buffer[3]);
			}
			else
			{
				printf("Check Fail!\n");
			}
			memset(uRx_Buffer, 0, sizeof(uRx_Buffer));
			uRx_Index = 0;
			uData_Flag = 2;
		}
		else if(uRx_Buffer[uRx_Index] != 0xFE && uData_Flag == 1)
		{
			uRx_Index++;
			if(uRx_Index >= 5)
			{
				uRx_Index = 0;
				uData_Flag = 0;
				memset(uRx_Buffer, 0, sizeof(uRx_Buffer));
			}
		}
	}
}

void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
	{
		uTimerCount++;
		TIM_ClearITPendingBit(TIM2 , TIM_FLAG_Update);
	}
}

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


