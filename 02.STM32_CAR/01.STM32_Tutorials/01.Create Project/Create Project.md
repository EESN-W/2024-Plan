# 创建工程

教程基于STM32标准固件库（STM32F10x_StdPeriph_Lib_V3.6.0）修改的模板工程。

```
建议对比STM32标准固件库模板工程观察目录中文件来源
```

## 工程框架

### CMSIS-DRIVER：内核/外设驱动

- CMSIS
  - CoreSupport
    - core_cm3.c
    - core_cm3.h
  - DeviceSupport
    - stm32f10x.h
    - system_stm32f10x.c
    - system_stm32f10x.h
    - startup
      - startup_stm32f10x_cl.s
      - startup_stm32f10x_hd.s
      - startup_stm32f10x_hd_vl.s
      - startup_stm32f10x_ld.s
      - startup_stm32f10x_ld_vl.s
      - startup_stm32f10x_md.s
      - startup_stm32f10x_md_vl.s
      - startup_stm32f10x_xl.s

- STM32F10x_StdPeriph_Driver
  - inc
    - misc.h
    - stm32f10x_adc.h
    - stm32f10x_bkp.h
    - stm32f10x_can.h
    - stm32f10x_cec.h
    - stm32f10x_crc.h
    - stm32f10x_dac.h
    - stm32f10x_dbgmcu.h
    - stm32f10x_dma.h
    - stm32f10x_exti.h
    - stm32f10x_flash.h
    - stm32f10x_fsmc.h
    - stm32f10x_gpio.h
    - stm32f10x_i2c.h
    - stm32f10x_iwdg.h
    - stm32f10x_pwr.h
    - stm32f10x_rcc.h
    - stm32f10x_rtc.h
    - stm32f10x_sdio.h
    - stm32f10x_spi.h
    - stm32f10x_tim.h
    - stm32f10x_usart.h
    - stm32f10x_wwdg.h
  - src
    - misc.c
    - stm32f10x_adc.c
    - stm32f10x_bkp.c
    - stm32f10x_can.c
    - stm32f10x_cec.c
    - stm32f10x_crc.c
    - stm32f10x_dac.c
    - stm32f10x_dbgmcu.c
    - stm32f10x_dma.c
    - stm32f10x_exti.c
    - stm32f10x_flash.c
    - stm32f10x_fsmc.c
    - stm32f10x_gpio.c
    - stm32f10x_i2c.c
    - stm32f10x_iwdg.c
    - stm32f10x_pwr.c
    - stm32f10x_rcc.c
    - stm32f10x_rtc.c
    - stm32f10x_sdio.c
    - stm32f10x_spi.c
    - stm32f10x_tim.c
    - stm32f10x_usart.c
    - stm32f10x_wwdg.c

### MDK-ARM：工程位置

### USER-CODE:用户代码

- main.c
- stm32f10x_conf.h
- stm32f10x_it.c
- stm32f10x_it.h

## 工程文件说明

以下差异均是比较与STM32标准固件库（STM32F10x_StdPeriph_Lib_V3.6.0）

### CMSIS-DRIVER

- 修改的工程模板路径

```
STM32标准固件库模板路径
```

- STM32F10x_StdPeriph_Lib_V3.6.0\CMSIS-DRIVER\CMSIS\CoreSupport

```
STM32F10x_StdPeriph_Lib_V3.6.0\Libraries\CMSIS\CM3\CoreSupport
```

- STM32F10x_StdPeriph_Lib_V3.6.0\CMSIS-DRIVER\CMSIS\DeviceSupport

```
STM32F10x_StdPeriph_Lib_V3.6.0\Libraries\CMSIS\CM3\DeviceSupport\ST\STM32F10x
```

- STM32F10x_StdPeriph_Lib_V3.6.0\CMSIS-DRIVER\CMSIS\DeviceSupport\startup

```
STM32F10x_StdPeriph_Lib_V3.6.0.zip\STM32F10x_StdPeriph_Lib_V3.6.0\Libraries\CMSIS\CM3\DeviceSupport\ST\STM32F10x\startup\arm
```

- STM32F10x_StdPeriph_Lib_V3.6.0\CMSIS-DRIVER\STM32F10x_StdPeriph_Driver\inc

```
STM32F10x_StdPeriph_Lib_V3.6.0\Libraries\STM32F10x_StdPeriph_Driver\inc
```

- STM32F10x_StdPeriph_Lib_V3.6.0\CMSIS-DRIVER\STM32F10x_StdPeriph_Driver\src

```
STM32F10x_StdPeriph_Lib_V3.6.0\Libraries\STM32F10x_StdPeriph_Driver\src
```

### USER-CODE

- STM32F10x_StdPeriph_Lib_V3.6.0\USER-CODE

```
STM32F10x_StdPeriph_Lib_V3.6.0\Project\STM32F10x_StdPeriph_Template
```

### MDK-ARM

该文件夹由MDK-ARM软件自动生成，不介绍！

## 工程注意事项

### Manage Progect Ltems

建议按照文件夹目录路径添加文件。

#### 启动文件

标准工程模板的启动文件夹放置了所有容量的启动文件，但是`Manage Progect Ltems`只可以导入和STM32F103系列芯片相同容量的启动文件，不然编译会报错。

```
文件路径：STM32F10x_StdPeriph_Lib_V3.6.0\CMSIS-DRIVER\CMSIS\DeviceSupport\startup
```

### Options for Target...

#### Device

芯片选型

#### Target

勾选`Use MicroLIB`

#### Output

勾选`Create HEX File`

#### C/C++

Define：添加USE_STDPERIPH_DRIVER

Include Paths：将工程所有文件夹路径添加进去（MDK-ARM文件夹不添加）

#### Debug

若有仿真器，可以勾选对应仿真器

```
需要有对应设备驱动才可以被正确识别
```

##### Flash Download

勾选`Reset and Run`

##### ST-LINK闪退

安装最新ST-LINK驱动点击`ST-Link Debugger`闪退，更换STLinkUSBDriver.dll文件

```
ST-LINK驱动所在安装位置：C:\Keil_v5\ARM\STLink
```

## ARM Compiler

从MDK5.37版本开始，AC5(ARMCC)编译器不再默认安装，需要独立安装。

```
使用标准库创建的工程需要用到该编译器
```

解压ARMCompiler_5.zip文件并安装C:\Keil_v5\ARM\ARMCC文件夹下（ARMCC文件夹需要自己新建）。

### 添加AC5编译器

`Manage Progect Ltems` → `Folders/Extensions` → `Use ARM Compiler` → 添加AC5编译器

### 选择编译器

`Options for Target...` → `Target`  → `ARM Compiler`  → 选择AC5编译器
