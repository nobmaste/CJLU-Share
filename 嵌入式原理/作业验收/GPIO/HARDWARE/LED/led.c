#include "led.h"
#include "delay.h"
#include "key.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK NANO STM32������
//LED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2018/3/27
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2018-2028
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////  
   
//LED IO��ʼ��
void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_Initure;

    __HAL_RCC_GPIOC_CLK_ENABLE();           	//����GPIOCʱ��
	
    GPIO_Initure.Pin=GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|
	                 GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;//PC0~7
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  	//�������
    GPIO_Initure.Pull=GPIO_PULLUP;          	//����
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;    	 	//����
	
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|
	GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7,GPIO_PIN_SET);	//PC0~7��1��Ĭ�ϳ�ʼ�������
	
    HAL_GPIO_Init(GPIOC,&GPIO_Initure);
	
}


void LED_SingleFlow(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)//һ��LED������
{
	for(int i =1;i<25;i++)//����
 {

		HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_SET); 
		delay_ms(i);
		HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_RESET); 
		delay_ms(25-i);
 }		
	for(int i =1;i<25;i++)//����
 {
		HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_RESET); 
		delay_ms(i);
		HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_SET); 
		delay_ms(25-i);	
 }		
}

void LED_EightFlow1(void)//��ˮ��
{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET);
		delay_ms(50);
	KEY_Scan();
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_SET);
		delay_ms(50);
	KEY_Scan();	
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET);
		delay_ms(50);
	KEY_Scan();
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
		delay_ms(50);
	KEY_Scan();
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET);
		delay_ms(50);
	KEY_Scan();
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);
		delay_ms(50);
	KEY_Scan();
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);
		delay_ms(50);
	KEY_Scan();
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET);
		delay_ms(50);
		KEY_Scan();
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);
		delay_ms(50);
		KEY_Scan();
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_RESET);
		delay_ms(50);
		KEY_Scan();
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET);
		delay_ms(50);
		KEY_Scan();
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);
		delay_ms(50);
		KEY_Scan();
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);
		delay_ms(50);
		KEY_Scan();
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);
		delay_ms(50);
		KEY_Scan();
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);
		delay_ms(50);
		KEY_Scan();
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_RESET);
		delay_ms(50);
KEY_Scan();		
}

void LED_EightFlow2(void)//��ˮ��
{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET);
		delay_ms(50);
	KEY_Scan();
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);
		delay_ms(50);
	KEY_Scan();
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);
		delay_ms(50);
	KEY_Scan();
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET);
		delay_ms(50);
	KEY_Scan();
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
		delay_ms(50);
	KEY_Scan();
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET);
		delay_ms(50);
	KEY_Scan();
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_SET);
		delay_ms(50);
	KEY_Scan();
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET);
		delay_ms(50);
		KEY_Scan();
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_RESET);
		delay_ms(50);
		KEY_Scan();
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);
		delay_ms(50);
		KEY_Scan();
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);
		delay_ms(50);
		KEY_Scan();
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);
		delay_ms(50);
		KEY_Scan();
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);
		delay_ms(50);
		KEY_Scan();
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET);
		delay_ms(50);
		KEY_Scan();
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_RESET);
		delay_ms(50);
		KEY_Scan();
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);
		delay_ms(50);
		KEY_Scan();
}
