#ifndef _KEY_H
#define _KEY_H
#include "sys.h"

//下面的方式是通过直接操作HAL库函数方式读取IO
#define KEY0        HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_8)  //KEY0按键PC8
#define KEY1        HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_9)  //KEY1按键PC9

void KEY_Init(void);
void KEY_Scan(void);
#endif
