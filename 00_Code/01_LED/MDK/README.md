
# 一 程序介绍

## 1.1 Abstract

**实验名称**：跑马灯实验
**硬件平台**：正点原子战舰 F103 开发板
**Author**：William Tau(TTR)

## 1.2 文件夹功能介绍

1. **Driver**

    该文件夹下面存放与硬件相关的驱动层代码，包括：
    1，BSP：正点原子提供的板级支持包驱动代码（原HARDWARE文件夹下的代码），如：LED、BEEP、KEY、EXTI、TIMER、WDG...等
    2，CMSIS：ARM提供的CMSIS代码（主要包括各种头文件和启动文件（.s文件），为了方便使用，减少占用空间，我们进行了精简）
    3，STM32F1xx_HAL_Driver：ST提供的F1xx HAL库驱动代码

2. **Middlewares**

    该文件夹下面存放中间层组件代码，包括：
    1，正点原子提供的中间层代码：USMART、MALLOC、TEXT、T9INPUT、PICTURE、GUI、MJPEG、各种ATK开头的LIB、NES、SMS、QR_ENCODE等
    2，第三方中间层代码：FATFS、USB、LWIP、各种OS、各种GUI等 

    注意：该文件夹下面，至少要到USMART实验，才会存放代码进来，在此之前的例程，没有用到类似的代码，但是我们会预留该文件夹，方便后续工程使用。

3. **Projects**

    该文件夹下面存放工程文件。

4. **User**

    用于存放用户编写的代码，如 main.c 等。

5. **Output**

    用于存放编译器编译工程输出的中间文件，比如 .hex、 .bin、 .o 文件等。在 MDK 软件中设置该文件夹为 Output 路径即可。

## 1.3 硬件资源及引脚分配

    DS0（RED）     : LED0 - PB5
    DS1（GREEN）   : LED1 - PE5

## 1.4 实验现象介绍

1. LED0和LED1交替闪烁，实现类似跑马灯的效果。
2. 按键可以控制 LED 闪烁变化。

## 1.5 版本迭代记录

**V1.0**:

基于正点原子程序版本进行修改。
