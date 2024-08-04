#include "stm32f10x.h"
#include "stm32f10x_it.h"
#include "BSP_SysTick.h"
#include "BSP_HC_SR04.h"
#include "BSP_USART_IT.h"

int main()
{
	SysTick_Init();
	USART1_IT_Init();
	TIM2_Init();
	HC_SR04_TRIG_ECHO_Init();
	
	printf("Hello\n");
	
	unsigned int uTimeCounter = 0;
	float fDistance = 0.0;
	
	while(1){
		GPIO_WriteBit(HC_SR04_Port, HC_SR04_TRIG_Pin, Bit_SET);
		Delay_Us(10);
		GPIO_WriteBit(HC_SR04_Port, HC_SR04_TRIG_Pin, Bit_RESET);
		
		while(GPIO_ReadInputDataBit(HC_SR04_Port, HC_SR04_ECHO_Pin) == Bit_RESET);
		TIM_Cmd(TIM2_Com, ENABLE);
		TIM_SetCounter(TIM2_Com, 0);
		while(GPIO_ReadInputDataBit(HC_SR04_Port, HC_SR04_ECHO_Pin) == Bit_SET);
		TIM_Cmd(TIM2_Com, DISABLE);
		uTimeCounter = TIM_GetCounter(TIM2_Com);
		fDistance = uTimeCounter*340*0.000001*100/2;
		printf("Distance = %.2f cm\n", fDistance);
		
		Delay_Ms(500);
	}
}
