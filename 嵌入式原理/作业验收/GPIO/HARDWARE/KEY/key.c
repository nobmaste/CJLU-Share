#include "key.h"
#include "delay.h"
#include "led.h"

extern int BeepSE;//BEEP总开关
extern int BeepFlag;//Beep工作开关
extern int flow;//1从上往下，-1从下往上
//按键初始化函数
void KEY_Init(void)
{
    GPIO_InitTypeDef GPIO_Initure;
    
    __HAL_RCC_GPIOA_CLK_ENABLE();           //开启GPIOA时钟
    __HAL_RCC_GPIOC_CLK_ENABLE();           //开启GPIOC时钟
    __HAL_RCC_GPIOD_CLK_ENABLE();           //开启GPIOD时钟
    
    GPIO_Initure.Pin=GPIO_PIN_0;            //PA0
    GPIO_Initure.Mode=GPIO_MODE_INPUT;      //输入
    GPIO_Initure.Pull=GPIO_PULLDOWN;        //下拉
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;     //高速
    HAL_GPIO_Init(GPIOA,&GPIO_Initure);
    
	GPIO_Initure.Pin=GPIO_PIN_8|GPIO_PIN_9; //PC8,9
    GPIO_Initure.Mode=GPIO_MODE_INPUT;      //输入
    GPIO_Initure.Pull=GPIO_PULLUP;          //上拉
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;     //高速
    HAL_GPIO_Init(GPIOC,&GPIO_Initure);
	
	GPIO_Initure.Pin=GPIO_PIN_2; //PD2
	HAL_GPIO_Init(GPIOD,&GPIO_Initure);
    
}

//按键处理函数
void KEY_Scan(void)
{	 	  
	if(KEY0==0||KEY1==0||KEY2==0||WK_UP==1)
	{
		delay_ms(10);//去抖动 
		if(KEY0==0)//KEY0  8灯流水
			{
				BeepFlag=-1;
				LED0=1,LED1=1,LED2=1,LED3=1,LED4=1,LED5=1,LED6=1,LED7=1;//LED全灭
			while(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_8)==0);				
					flow=-flow;
				
			}
		else if(KEY1==0)//KEY1  单灯流水
			{
				BeepFlag=-1;
				LED0=1,LED1=1,LED2=1,LED3=1,LED4=1,LED5=1,LED6=1,LED7=1;//LED全灭
				while(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_9)==0)
					LED_SingleFlow(GPIOC, GPIO_PIN_0);//一个LED呼吸灯
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
