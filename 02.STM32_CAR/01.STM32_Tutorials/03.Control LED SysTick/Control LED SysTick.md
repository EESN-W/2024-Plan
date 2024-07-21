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
