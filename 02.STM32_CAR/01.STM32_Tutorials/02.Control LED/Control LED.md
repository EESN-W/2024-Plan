# Control LED

教程简要说明GPIO控制LED思路和实现。

## 开发思路

硬件连接（硬件原理图） → 引脚驱动（数据手册）→ 外设控制（参考手册）

## 控制实现

### BSP_LED.h

```c
#ifndef __BSP_LED_H__
#define __BSP_LED_H__

#include "stm32f10x.h"

#define	LED_Clock 	RCC_APB2Periph_GPIOB
#define	LED_Port		GPIOB
#define	LED_Pin 		GPIO_Pin_3

typedef struct {
	uint32_t GPIO_Clock;
	GPIO_TypeDef* GPIO_Port;
	uint16_t GPIO_Pin;
} GPIO_Info;

static GPIO_Info LED_Info[] = {
	{LED_Clock, LED_Port, LED_Pin}
};

void LED_Init(void);

#endif
```

### BSP_LED.c

```C
#include "BSP_LED.h"

void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE); 
	
	/* JTAG-DP Disabled and SW-DP Enabled */
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = LED_Info[0].GPIO_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(LED_Info[0].GPIO_Port, &GPIO_InitStructure);

	GPIO_WriteBit(LED_Info[0].GPIO_Port, LED_Info[0].GPIO_Pin, Bit_RESET);
}
```

