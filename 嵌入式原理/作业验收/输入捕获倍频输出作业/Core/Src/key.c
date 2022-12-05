#include "key.h"
#include "tim.h"
extern int psc;
extern TIM_HandleTypeDef htim4;      //��ʱ����� 

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
		HAL_TIM_Base_Stop(&htim4);//ֹͣ��ʱ��
		HAL_Delay(100);//ȥ���� 
		while(KEY1==0);
		psc=psc*2;
		MX_TIM4_Init(64, psc - 1);
		HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_4);
	}  
}
