# Control LED SysTick

[TOC]

教程简要说明使用SysTick控制LED闪烁。

## SysTick

SysTick是Cortex-M处理器内部集成的向下计数的24位定时器；当计数值为0时，会触发SysTick中断，用于产生周期性中断和延时等。

### SysTick寄存器

| 地址        | 符号      | SysTick寄存器           |
| ----------- | --------- | ----------------------- |
| 0xE000 E010 | STK_CTRL  | SysTick控制和状态寄存器 |
| 0xE000 E014 | STK_LOAD  | SysTick重装载寄存器     |
| 0xE000 E018 | STK_VAL   | SysTick当前值寄存器     |
| 0xE000 E01C | STK_CALIB | SysTick校准值寄存器     |

```
参考PM0056_STM32_Cortex_M3编程手册.pdf
```

### SysTick使用

标准库提供了专门的函数配置SysTick：

```
static __INLINE uint32_t SysTick_Config(uint32_t ticks)
```

- ticks：SysTick重装载值 → 决定触发中断时间

以系统时钟频率72MHz举例：计数一次1/72000000秒

```c
SysTick_Config(SystemCoreClock / 1000000)  	// 重装载值(72) → 1us触发一次SysTick中断
SysTick_Config(SystemCoreClock / 1000)		// 重装载值(72000) → 1ms触发一次SysTick中断
```

## 控制实现

### STM32F103C8T6/RCT6

#### 代码

##### BSP_SysTick.h

```
#ifndef __BSP_SYSTICK_H__
#define __BSP_SYSTICK_H__

#include "stm32f10x.h"

extern unsigned int SysTick_Delay;

void SysTick_Init(void);
void Delay_us(unsigned int uTime);
void Delay_ms(unsigned int uTime);

#endif
```

##### BSP_SysTick.c

```c
#include "BSP_SysTick.h"

unsigned int SysTick_Delay;

void SysTick_Init(void)
{
	while(SysTick_Config(SystemCoreClock / 1000000)); 	// Reload value (72) → 1us enters a SysTick interrupt
	SysTick->CTRL &= ~(SysTick_CTRL_ENABLE_Msk); 		// Disable SysTick
}

void Delay_us(unsigned int uTime)
{
	SysTick_Delay = uTime;
	SysTick->CTRL |= (SysTick_CTRL_ENABLE_Msk);		// Enable SysTick
	while(SysTick_Delay);
	SysTick->CTRL &= ~(SysTick_CTRL_ENABLE_Msk); 	// Disable SysTick
}

void Delay_ms(unsigned int uTime)
{
	while(uTime--)
	{
		Delay_us(1000);
	}
}
```

#### stm32f10x_it.c

```c
void SysTick_Handler(void)
{
	if(SysTick_Delay != 0)
	{
		SysTick_Delay--;
	}
}
```

