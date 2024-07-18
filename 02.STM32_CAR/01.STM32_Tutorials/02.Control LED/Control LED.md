# Control LED

教程简要说明GPIO控制LED思路和实现代码。

## 开发思路

硬件连接（硬件原理图） → 引脚驱动（数据手册）→ 外设控制（参考手册）

#### 硬件连接

| 开发板        | 引脚 | 外设 | 硬件连接                                           |
| ------------- | ---- | ---- | -------------------------------------------------- |
| STM32F103C8T6 | PC13 | LED  | 发光二极管（LED）的阳极接VCC，阴极接开发板PC13引脚 |
| STM32F103RCT6 | PB3  | LED  | 发光二极管（LED）的阳极接PB3，阴极接开发板GND引脚  |

#### 引脚驱动

引脚的默认和复用功能对应不同的初始化方式。

| 开发板        | 引脚 | 主功能（复位后） | 默认复用功能 | 重定义功能                      |
| ------------- | ---- | ---------------- | ------------ | ------------------------------- |
| STM32F103C8T6 | PC13 | PC13             | TAMPER-RTC   |                                 |
| STM32F103RCT6 | PB3  | JTDO             |              | PB3/TRACESWO TIM2_CH2/ SPI1_SCK |

#### 外设控制

控制LED亮灭需要使用到GPIO的通用推挽输出功能。

> **STM32F103C8T6**

LED亮：PC13输出低电平

LED灭：PC13输出高电平

> **STM32F103RCT6**

LED亮：PC13输出高电平

LED灭：PC13输出低电平

## 控制实现

### STM32F103C8T6

#### 代码

##### BSP_LED.h

```c
#ifndef __BSP_LED_H__
#define __BSP_LED_H__

#include "stm32f10x.h"

#define	LED_Clock 	RCC_APB2Periph_GPIOC
#define	LED_Port	GPIOC
#define	LED_Pin 	GPIO_Pin_13

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

##### BSP_LED.c

```C
#include "BSP_LED.h"

void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); 
	
	GPIO_InitStructure.GPIO_Pin = LED_Info[0].GPIO_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(LED_Info[0].GPIO_Port, &GPIO_InitStructure);
	
	GPIO_WriteBit(LED_Info[0].GPIO_Port, LED_Info[0].GPIO_Pin, Bit_SET);
}
```

### STM32F103RCT6

#### 代码

##### BSP_LED.h

```c
#ifndef __BSP_LED_H__
#define __BSP_LED_H__

#include "stm32f10x.h"

#define	LED_Clock 	RCC_APB2Periph_GPIOB
#define	LED_Port	GPIOB
#define	LED_Pin 	GPIO_Pin_3

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

##### BSP_LED.c

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

