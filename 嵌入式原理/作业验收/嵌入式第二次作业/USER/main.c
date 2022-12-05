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
    HAL_Init();                    	//初始化HAL库
    Stm32_Clock_Init(RCC_PLL_MUL9); //设置时钟,72M
    delay_init(72);                 //初始化延时函数
    uart_init(9600);				//初始化串口
    LED_Init();                     //初始化LED
    TIM3_Init(arr - 1, psc - 1);  //所以定时器3的频率为72M/7200=10K，自动重装载为10-1，那么定时器周期就是1ms
		KEY_Init();
    while (1)
    {
        KEY_Scan();
    }
}

