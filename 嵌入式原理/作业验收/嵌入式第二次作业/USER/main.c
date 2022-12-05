#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "timer.h"

char rog=0,count_clk=0;
int arr=10,psc=7200;

int main(void)
{
    HAL_Init();                    	//��ʼ��HAL��
    Stm32_Clock_Init(RCC_PLL_MUL9); //����ʱ��,72M
    delay_init(72);                 //��ʼ����ʱ����
    uart_init(9600);				//��ʼ������
    LED_Init();                     //��ʼ��LED
    TIM3_Init(arr - 1, psc - 1);  //���Զ�ʱ��3��Ƶ��Ϊ72M/7200=10K���Զ���װ��Ϊ10-1����ô��ʱ�����ھ���1ms
		KEY_Init();
    while (1)
    {
        KEY_Scan();
    }
}

