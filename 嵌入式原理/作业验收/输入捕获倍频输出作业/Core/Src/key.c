#include "key.h"
#include "tim.h"
extern int psc;
extern TIM_HandleTypeDef htim4;      //定时器句柄 

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
		HAL_TIM_Base_Stop(&htim4);//停止定时器
		HAL_Delay(100);//去抖动 
		while(KEY1==0);
		psc=psc*2;
		MX_TIM4_Init(64, psc - 1);
		HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_4);
	}  
}
