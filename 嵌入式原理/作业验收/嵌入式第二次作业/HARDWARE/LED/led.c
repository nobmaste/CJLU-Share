#include "led.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F103������
//LED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2017/5/25
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	
   
//LED IO��ʼ��
void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_Initure;

    __HAL_RCC_GPIOB_CLK_ENABLE();           	//����GPIOCʱ��
	
    GPIO_Initure.Pin=GPIO_PIN_9|GPIO_PIN_11;//PC0~7
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  	//�������
    GPIO_Initure.Pull=GPIO_PULLUP;          	//����
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;    	 	//����
	
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11|GPIO_PIN_9,GPIO_PIN_SET);	//PC0~7��1��Ĭ�ϳ�ʼ�������
	
    HAL_GPIO_Init(GPIOB,&GPIO_Initure);
	
}


