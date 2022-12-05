#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "beep.h"
#include "key.h"

int BeepFlag=-1;
int BeepSE=-1;
int flow=1;//1�������£�-1��������

int main(void)
{

    HAL_Init();                    	//��ʼ��HAL��
    Stm32_Clock_Init(RCC_PLL_MUL9); //����ʱ��,72M
    delay_init(72);                 //��ʼ����ʱ����
    LED_Init();                     //��ʼ��LED
    KEY_Init();						//��ʼ������
    BEEP_Init();					//��ʼ��BEEP

    while (1)
    {
			if(BeepFlag==1 && BeepSE==1)
				{
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
					for(int i=0;i<100;i++)
						{
							if(i%2==0)	delay_ms(10);
							else KEY_Scan(); 
						}
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
					for(int i=0;i<100;i++)
						{
							if(i%2==0)	delay_ms(10);
							else KEY_Scan(); 
						}
				}
			if(flow==1) LED_EightFlow1();
					else if(flow==-1) LED_EightFlow2();
      KEY_Scan(); //�õ���ֵ
    }
}

