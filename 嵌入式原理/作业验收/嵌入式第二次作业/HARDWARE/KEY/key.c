#include "key.h"
#include "delay.h"
#include "led.h"
#include "timer.h"
extern int arr,psc;
extern TIM_HandleTypeDef TIM3_Handler;      //��ʱ����� 

//������ʼ������
void KEY_Init(void)
{
    GPIO_InitTypeDef GPIO_Initure;

    __HAL_RCC_GPIOC_CLK_ENABLE();           //����GPIOCʱ��
    
		GPIO_Initure.Pin=GPIO_PIN_9; //PC8,9
    GPIO_Initure.Mode=GPIO_MODE_INPUT;      //����
    GPIO_Initure.Pull=GPIO_PULLUP;          //����
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;     //����
    HAL_GPIO_Init(GPIOC,&GPIO_Initure);
    
}

//����������
void KEY_Scan(void)
{	 	  
	if(KEY1==0)//PC9
	{
		HAL_TIM_Base_Stop(&TIM3_Handler);//ֹͣ��ʱ��
		delay_ms(10);//ȥ���� 
		while(KEY1==0);
		arr=arr*2;
		TIM3_Init(arr - 1, psc - 1);
	}  
}
