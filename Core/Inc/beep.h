#ifndef _BEEP_H_
#define _BEEP_H_
#include "stm32f4xx_hal.h"


//GPIO口定义
#define BEEP_PIN GPIO_PIN_8 // 定义蜂鸣器的引脚
#define BEEP_PORT GPIOF // 定义蜂鸣器的端口

void BEEP_Init(void);//初始化GPIO口


#endif
