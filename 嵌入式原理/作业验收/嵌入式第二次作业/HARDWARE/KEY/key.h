#ifndef _KEY_H
#define _KEY_H
#include "sys.h"

//����ķ�ʽ��ͨ��ֱ�Ӳ���HAL�⺯����ʽ��ȡIO
#define KEY0        HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_8)  //KEY0����PC8
#define KEY1        HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_9)  //KEY1����PC9

void KEY_Init(void);
void KEY_Scan(void);
#endif
