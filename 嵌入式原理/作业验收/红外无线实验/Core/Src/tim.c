/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    tim.c
  * @brief   This file provides code for the configuration
  *          of the TIM instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "tim.h"

/* USER CODE BEGIN 0 */
#include "adc.h"
#include "gpio.h"//���������ҵ��
uint8_t beep_c=0;//beep
uint8_t key=0;
uint8_t adc_on=0;
uint8_t Remote_Scan(void);
uint32_t RmtRec=0;	//������յ�������
char flag=5;//�ɵ�led��ʼ����
//eeprom����
char ebuff[2]={0};
char f=0;	
int x;//eeprom����
extern uint8_t datatemp[2];
uint8_t out;
/* USER CODE END 0 */

TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

/* TIM2 init function */
void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 63;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 99;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}
/* TIM3 init function */
void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_IC_InitTypeDef sConfigIC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 63;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 10000;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_IC_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigIC.ICPolarity = TIM_INPUTCHANNELPOLARITY_RISING;
  sConfigIC.ICSelection = TIM_ICSELECTION_DIRECTTI;
  sConfigIC.ICPrescaler = TIM_ICPSC_DIV1;
  sConfigIC.ICFilter = 0x03;
  if (HAL_TIM_IC_ConfigChannel(&htim3, &sConfigIC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* tim_baseHandle)
{

  if(tim_baseHandle->Instance==TIM2)
  {
  /* USER CODE BEGIN TIM2_MspInit 0 */

  /* USER CODE END TIM2_MspInit 0 */
    /* TIM2 clock enable */
    __HAL_RCC_TIM2_CLK_ENABLE();

    /* TIM2 interrupt Init */
    HAL_NVIC_SetPriority(TIM2_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(TIM2_IRQn);
  /* USER CODE BEGIN TIM2_MspInit 1 */

  /* USER CODE END TIM2_MspInit 1 */
  }
}

void HAL_TIM_IC_MspInit(TIM_HandleTypeDef* tim_icHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(tim_icHandle->Instance==TIM3)
  {
  /* USER CODE BEGIN TIM3_MspInit 0 */

  /* USER CODE END TIM3_MspInit 0 */
    /* TIM3 clock enable */
    __HAL_RCC_TIM3_CLK_ENABLE();

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**TIM3 GPIO Configuration
    PB0     ------> TIM3_CH3
    */
    GPIO_InitStruct.Pin = GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* TIM3 interrupt Init */
    HAL_NVIC_SetPriority(TIM3_IRQn, 1, 0);
    HAL_NVIC_EnableIRQ(TIM3_IRQn);
  /* USER CODE BEGIN TIM3_MspInit 1 */

  /* USER CODE END TIM3_MspInit 1 */
  }
}

void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef* tim_baseHandle)
{

  if(tim_baseHandle->Instance==TIM2)
  {
  /* USER CODE BEGIN TIM2_MspDeInit 0 */

  /* USER CODE END TIM2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TIM2_CLK_DISABLE();

    /* TIM2 interrupt Deinit */
    HAL_NVIC_DisableIRQ(TIM2_IRQn);
  /* USER CODE BEGIN TIM2_MspDeInit 1 */

  /* USER CODE END TIM2_MspDeInit 1 */
  }
}

void HAL_TIM_IC_MspDeInit(TIM_HandleTypeDef* tim_icHandle)
{

  if(tim_icHandle->Instance==TIM3)
  {
  /* USER CODE BEGIN TIM3_MspDeInit 0 */

  /* USER CODE END TIM3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TIM3_CLK_DISABLE();

    /**TIM3 GPIO Configuration
    PB0     ------> TIM3_CH3
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_0);

    /* TIM3 interrupt Deinit */
    HAL_NVIC_DisableIRQ(TIM3_IRQn);
  /* USER CODE BEGIN TIM3_MspDeInit 1 */

  /* USER CODE END TIM3_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

//ң��������״̬
//[7]:�յ����������־
//[6]:�õ���һ��������������Ϣ
//[5]:����	
//[4]:����������Ƿ��Ѿ�������								   
//[3:0]:�����ʱ��
uint8_t 	RmtSta=0;	  	  
uint16_t Dval;		//�½���ʱ��������ֵ	   		    
uint8_t  RmtCnt=0;	//�������µĴ���

// ������������
// 0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F, .,ȫ��
uint8_t smg_num[] = {0xfc, 0x60, 0xda, 0xf2, 0x66, 0xb6, 0xbe, 0xe0, 0xfe, 0xf6, 0xee, 0x3e, 0x9c, 0x7a, 0x9e, 0x8e, 0x01, 0x00};
//ADC����
static uint16_t adcx = 0;
static uint16_t adcx1 = 0;
float temp = 0;
//����������
static  uint32_t T_count=0;
//��ˮ��
static signed char pin=0;
static char change;
//���ȿ���
static signed char light=0;
static uint16_t delay=0;
static char	period=255;
	

static uint16_t delay2=0;

uint8_t num = 0; //�����ֵ
uint8_t smg_wei = 0; //�����λѡ
	
//��ʱ�����£�������жϻص�����
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	//��ʱ���������ҵ�����
	if(htim->Instance==TIM3)
	{
 		if(RmtSta&0x80)//�ϴ������ݱ����յ���
		{	
			RmtSta&=~0X10;						//ȡ���������Ѿ���������
			if((RmtSta&0X0F)==0X00)RmtSta|=1<<6;//����Ѿ����һ�ΰ����ļ�ֵ��Ϣ�ɼ�
			if((RmtSta&0X0F)<14)RmtSta++;
			else
			{
				RmtSta&=~(1<<7);//���������ʶ
				RmtSta&=0XF0;	//��ռ�����	
			}						 	   	
		}	
	}
	//��ʱ����һ��ҵ����ȴ���,�ж�Ƶ��Ϊ1Khz
	if(htim->Instance==TIM2){
		T_count++;//����������
		key = Remote_Scan();		
		if(T_count%1000==0){
			{/*��ˮ��*/
				HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6, GPIO_PIN_SET);//led����
				PCout(pin)=0;
				if(key==2) change=0;
					else if(key==34) change=1;
				switch(change)
				{
					case 0 :
						pin--;
					break;
   
					case 1 :
						pin++;
					break;
				}
				if(pin>6) pin=0;
				if(pin<0) pin=6;
			}
		}
		{/*���ȿ���*/
			/*-----�ж���������ʱbegain----*/
			if(key==168){
			delay++;
			if(delay>=1200){
				flag++;
				if(flag>10){
					flag=10;
					beep_c=1;//
				}
				light=flag;
				delay=0;
				}
			}
			else if(key==224){
			delay++;
			if(delay>=1200){
				flag--;
				if(flag>10){
					flag=0;
					beep_c=1;//
				}
				delay=0;
				}
			}
			/*-----�ж���������ʱ--end-----*/
			/*--------����Ϊled���ƶ�------*/
			if(light){
				PCout(7)=0;	
				light--;
			}
			else PCout(7)=1;	
			period--;
			if(period==0){
				period=255;
				light=flag;
			}
		}
		/*adc*/
		if(key==98 && adc_on==0){
            adcx = Get_Adc_Average(ADC_CHANNEL_9, 50); //ADCԭʼֵ
            temp = (float)adcx * (3.3 / 4096); //ADC��ѹֵ
            adcx1 = temp;
            temp -= adcx1;
            temp *= 1000;
						adc_on=1;//��ӡ��ʾ
		}

		
	
	if(key==226){
		ebuff[0]=0;
		ebuff[1]=0;
		f=0;
	}
	if(key==48||key==24||key==122||key==16||key==56||key==90||key==66||key==74||key==82||key==104){
			delay2++;
			if(delay2>=1200){
				switch(key){
					case 48:
						ebuff[f]=1;
						break;
					case 24:
						ebuff[f]=2;
						break;
					case 122:
						ebuff[f]=3;
						break;
					case 16:
						ebuff[f]=4;
						break;
					case 56:
						ebuff[f]=5;
						break;
					case 90:
						ebuff[f]=6;
						break;
					case 66:
						ebuff[f]=7;
						break;
					case 74:
						ebuff[f]=8;
						break;
					case 82:
						ebuff[f]=9;
						break;
					case 104:
						ebuff[f]=0;
						break;
				}
				delay2=0;
				if(f<1)f++;
				}
			}
	if(key==144) {x=ebuff[0]*10+ebuff[1];f=0;out=x*datatemp[0]+datatemp[1];}
	
	
        switch (smg_wei)
        {
            //eeprom����
            case 0:
                if (out > 1000)num = smg_num[out / 1000];
                else         num = 0x00;

                break;

            case 1:
                if (out > 100) num = smg_num[out % 1000 / 100];
                else         num = 0x00;

                break;

            case 2:
                if (out > 10)  num = smg_num[out % 100 / 10];
                else         num = 0x00;

                break;

            case 3:
                num = smg_num[out % 10];
                break;

            case 4:
                num = 0x00;
                break;

            //ADC�����ĵ�ѹֵ
            case 5:
                num = smg_num[adcx1] | 0x01;
                break;

            case 6:
                num = smg_num[(uint16_t)temp / 100];
                break;

            case 7:
                num = smg_num[(uint16_t)temp % 100 / 10];
                break;
        }

        LED_Write_Data(num, smg_wei); //д���ݵ������
        LED_Refresh();//������ʾ
        smg_wei++;

        if (smg_wei == 8) smg_wei = 0;
			
		}
}

//��ʱ�����벶���жϻص�����
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)//�����жϷ���ʱִ��
{
	if(htim->Instance==TIM3)
	{
		if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0))//�����ز���
		{
			TIM_RESET_CAPTUREPOLARITY(&htim3,TIM_CHANNEL_3);   //һ��Ҫ�����ԭ�������ã���
			TIM_SET_CAPTUREPOLARITY(&htim3,TIM_CHANNEL_3,TIM_ICPOLARITY_FALLING);//CC1P=1 ����Ϊ�½��ز���
			__HAL_TIM_SET_COUNTER(&htim3,0);  	//��ն�ʱ��ֵ   	  
		  	RmtSta|=0X10;							//����������Ѿ�������
		}else //�½��ز���
		{
			Dval=HAL_TIM_ReadCapturedValue(&htim3,TIM_CHANNEL_3);//��ȡCCR2Ҳ������CC2IF��־λ
			TIM_RESET_CAPTUREPOLARITY(&htim3,TIM_CHANNEL_3);   	//һ��Ҫ�����ԭ�������ã���
			TIM_SET_CAPTUREPOLARITY(&htim3,TIM_CHANNEL_3,TIM_ICPOLARITY_RISING);//����TIM3ͨ��3�����ز���
			if(RmtSta&0X10)							//���һ�θߵ�ƽ���� 
			{
 				if(RmtSta&0X80)//���յ���������
				{
					
					if(Dval>300&&Dval<800)			//560Ϊ��׼ֵ,560us
					{
						RmtRec<<=1;					//����һλ.
						RmtRec|=0;					//���յ�0	   
					}else if(Dval>1400&&Dval<1800)	//1680Ϊ��׼ֵ,1680us
					{
						RmtRec<<=1;					//����һλ.
						RmtRec|=1;					//���յ�1
					}else if(Dval>2200&&Dval<2600)	//�õ�������ֵ���ӵ���Ϣ 2500Ϊ��׼ֵ2.5ms
					{
						RmtCnt++; 					//������������1��
						RmtSta&=0XF0;				//��ռ�ʱ��		
					}
 				}else if(Dval>4200&&Dval<4700)		//4500Ϊ��׼ֵ4.5ms
				{
					RmtSta|=1<<7;					//��ǳɹ����յ���������
					RmtCnt=0;						//�����������������
				}						 
			}
			RmtSta&=~(1<<4);
		}
	}
}

//����������
//����ֵ:
//	 0,û���κΰ�������
//����,���µİ�����ֵ.
uint8_t Remote_Scan(void)
{        
	uint8_t sta=0;       
	uint8_t t1,t2;  
	if(RmtSta&(1<<6))//�õ�һ��������������Ϣ��
	{ 
	    t1=RmtRec>>24;			//�õ���ַ��
	    t2=(RmtRec>>16)&0xff;	//�õ���ַ���� 
 	    if((t1==(uint8_t)~t2)&&t1==REMOTE_ID)//����ң��ʶ����(ID)����ַ 
	    { 
	        t1=RmtRec>>8;
	        t2=RmtRec; 	
	        if(t1==(uint8_t)~t2)sta=t1;//��ֵ��ȷ	 
		}   
		if((sta==0)||((RmtSta&0X80)==0))//�������ݴ���/ң���Ѿ�û�а�����
		{
		 	RmtSta&=~(1<<6);//������յ���Ч������ʶ
			RmtCnt=0;		//�����������������
		}
	}  
    return sta;
}
/* USER CODE END 1 */
