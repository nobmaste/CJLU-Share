实验器材:
	NANO STM32F103开发板V1版本
	
实验目的:
	学习GPIO作为输入的使用
	
硬件资源:
	1,DS0(连接在PC0),DS1(连接在PC1)
	2,蜂鸣器（PB8）
	3,按键KEY0(PC8)/KEY1(PC9)/KEY2(PD2)/KEY_UP(PA0,也称之为WK_UP)
	
	
实验现象:
	本实验通过开发板上载有的4个按钮（KEY_UP、KEY0、KEY1、KEY2），来控制板上的2个LED（DS0、DS1）和蜂鸣器，
	其中KEY0控制DS0，按一次亮，再按一次，就灭。KEY1控制DS1，效果同KEY0。KEY2控制蜂鸣器的开和关。KEY_UP
	则同时控制DS0和DS1，按一次，他们的状态就翻转一次。
	
注意事项: 无 
	

					正点原子@ALIENTEK
					2018-3-28
					广州市星翼电子科技有限公司
					电话：020-38271790
					传真：020-36773971
					购买：http://shop62103354.taobao.com
					http://shop62057469.taobao.com
					公司网站：www.alientek.com
					技术论坛：www.openedv.com
