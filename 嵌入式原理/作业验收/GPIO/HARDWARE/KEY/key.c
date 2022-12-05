#include "key.h"
#include "delay.h"
#include "led.h"

extern int BeepSE;//BEEP�ܿ���
extern int BeepFlag;//Beep��������
extern int flow;//1�������£�-1��������
//������ʼ������
void KEY_Init(void)
{
    GPIO_InitTypeDef GPIO_Initure;
    
    __HAL_RCC_GPIOA_CLK_ENABLE();           //����GPIOAʱ��
    __HAL_RCC_GPIOC_CLK_ENABLE();           //����GPIOCʱ��
    __HAL_RCC_GPIOD_CLK_ENABLE();           //����GPIODʱ��
    
    GPIO_Initure.Pin=GPIO_PIN_0;            //PA0
    GPIO_Initure.Mode=GPIO_MODE_INPUT;      //����
    GPIO_Initure.Pull=GPIO_PULLDOWN;        //����
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;     //����
    HAL_GPIO_Init(GPIOA,&GPIO_Initure);
    
	GPIO_Initure.Pin=GPIO_PIN_8|GPIO_PIN_9; //PC8,9
    GPIO_Initure.Mode=GPIO_MODE_INPUT;      //����
    GPIO_Initure.Pull=GPIO_PULLUP;          //����
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;     //����
    HAL_GPIO_Init(GPIOC,&GPIO_Initure);
	
	GPIO_Initure.Pin=GPIO_PIN_2; //PD2
	HAL_GPIO_Init(GPIOD,&GPIO_Initure);
    
}

//����������
void KEY_Scan(void)
{	 	  
	if(KEY0==0||KEY1==0||KEY2==0||WK_UP==1)
	{
		delay_ms(10);//ȥ���� 
		if(KEY0==0)//KEY0  8����ˮ
			{
				BeepFlag=-1;
				LED0=1,LED1=1,LED2=1,LED3=1,LED4=1,LED5=1,LED6=1,LED7=1;//LEDȫ��
			while(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_8)==0);				
					flow=-flow;
				
			}
		else if(KEY1==0)//KEY1  ������ˮ
			{
				BeepFlag=-1;
				LED0=1,LED1=1,LED2=1,LED3=1,LED4=1,LED5=1,LED6=1,LED7=1;//LEDȫ��
				while(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_9)==0)
					LED_SingleFlow(GPIOC, GPIO_PIN_0);//һ��LED������
			}
		else if(KEY2==0)//KEY2  BEEP
			{
				while(KEY2==0);
					if(BeepSE != BeepFlag)
					{
						 BeepFlag=-1, BeepSE=-1;
					}
					BeepFlag=-BeepFlag,BeepSE=-BeepSE;
			}
	}  
}
