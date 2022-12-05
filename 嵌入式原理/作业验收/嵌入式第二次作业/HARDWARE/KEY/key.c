#include "key.h"
#include "delay.h"
#include "led.h"
#include "timer.h"
extern int arr,psc;
extern TIM_HandleTypeDef TIM3_Handler;      //定时器句柄 

//按键初始化函数
void KEY_Init(void)
{
    GPIO_InitTypeDef GPIO_Initure;

    __HAL_RCC_GPIOC_CLK_ENABLE();           //开启GPIOC时钟
    
		GPIO_Initure.Pin=GPIO_PIN_9; //PC8,9
    GPIO_Initure.Mode=GPIO_MODE_INPUT;      //输入
    GPIO_Initure.Pull=GPIO_PULLUP;          //上拉
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;     //高速
    HAL_GPIO_Init(GPIOC,&GPIO_Initure);
    
}

//按键处理函数
void KEY_Scan(void)
{	 	  
	if(KEY1==0)//PC9
	{
		HAL_TIM_Base_Stop(&TIM3_Handler);//停止定时器
		delay_ms(10);//去抖动 
		while(KEY1==0);
		arr=arr*2;
		TIM3_Init(arr - 1, psc - 1);
	}  
}
