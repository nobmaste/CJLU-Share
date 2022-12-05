#include "timer.h"
#include "led.h"
#include "delay.h"
static char count_clk=0;
static char rog=0;
extern char t;
TIM_HandleTypeDef TIM3_Handler;      //��ʱ����� 

//ͨ�ö�ʱ��3�жϳ�ʼ��
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//��ʱ�����ʱ����㷽��:Tout=((arr+1)*(psc+1))/Ft us.
//Ft=��ʱ������Ƶ��,��λ:Mhz
//����ʹ�õ��Ƕ�ʱ��3!
void TIM3_Init(u16 arr,u16 psc)
{  
    TIM3_Handler.Instance=TIM3;                          //ͨ�ö�ʱ��3
    TIM3_Handler.Init.Prescaler=psc;                     //��Ƶϵ��
    TIM3_Handler.Init.CounterMode=TIM_COUNTERMODE_UP;    //���ϼ�����
    TIM3_Handler.Init.Period=arr;                        //�Զ�װ��ֵ
    TIM3_Handler.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;//ʱ�ӷ�Ƶ����
	TIM3_Handler.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;//ʹ���Զ�����
    HAL_TIM_Base_Init(&TIM3_Handler);
    
    HAL_TIM_Base_Start_IT(&TIM3_Handler); //ʹ�ܶ�ʱ��3�Ͷ�ʱ��3�����жϣ�TIM_IT_UPDATE   
}

//��ʱ���ײ�����������ʱ�ӣ������ж����ȼ�
//�˺����ᱻHAL_TIM_Base_Init()��������
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
    if(htim->Instance==TIM3)
	{
		__HAL_RCC_TIM3_CLK_ENABLE();            //ʹ��TIM3ʱ��
		HAL_NVIC_SetPriority(TIM3_IRQn,1,3);    //�����ж����ȼ�����ռ���ȼ�1�������ȼ�3
		HAL_NVIC_EnableIRQ(TIM3_IRQn);          //����ITM3�ж�   
	}
}

//��ʱ��3�жϷ�����
void TIM3_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&TIM3_Handler);
}

//�ص���������ʱ���жϷ���������
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim==(&TIM3_Handler))
    {
			if(rog==0 && count_clk==0)
			{
				rog=1;
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,GPIO_PIN_SET);//PB9clk��
				HAL_TIM_Base_Stop(&TIM3_Handler);//ֹͣ��ʱ��
				delay_ms(2);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_SET);//PB11rog��
				delay_ms(1);
				HAL_TIM_Base_Start(&TIM3_Handler);//��ʼ��ʱ��
			}
			if(count_clk==10)
			{
				rog=0;
				count_clk=0;
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_RESET);//PB11rog��
			}	
			if(rog==1 && count_clk<=10)
			{
				PBout(9)=!PBout(9);        
				count_clk+=1;
			}
        
    }
}
