		实验八红外通信实验
一．实验简介
	1.利用红外遥控器发射38K载波的红外信号发射
	2.利用红外接收管对38K的信号进行接收，并解调后显示
	3.对遥控器不同键码完成不同功能
	4.利用红外发射管进行38K调制，完成红外发射实验
二．实验目的
	1.学会红外对管的发射接收的基本原理；
	2.学会利用cortex-M3进行综合性较强项目的开发；
三．实验内容
	通常红外遥控为了提高抗干扰性能和降低电源消耗，红外遥控器常用载波的
	方式传送二进制编码，常用的载波频率为38kHz，这是由发射端所使用的455kHz
	晶振来决定的。在发射端要对晶振进行整数分频，分频系数一般取12，所以
	455kHz÷12≈37.9kHz≈38kHz。也有一些遥控系统采用36kHz、40kHz、56kHz
	等，一般由发射端晶振的振荡频率来决定。所以，通常的红外遥控器是将遥控信
	号（二进制脉冲码）调制在38KHz的载波上，经缓冲放大后送至红外发光二极
	管，转化为红外信号发射出去的。
	二进制脉冲码的形式有多种，其中最为常用的是PWM码（脉冲宽度调制码）
	和PPM码（脉冲位置调制码，脉冲串之间的时间间隔来实现信号调制）。如果
	要开发红外接收设备，一定要知道红外遥控器的编码方式和载波频率，我们才可
	以选取一体化红外接收头和制定解码方案。
	数据格式包括了引导码、用户码、数据码和数据码反码，编码总占32位。数
	据反码是数据码反相后的编码，编码时可用于对数据的纠错。注意：第二段的用
	户码也可以在遥控应用电路中被设置成第一段用户码的反码。
	用户码或数据码中的每一个位可以是位‘1’，也可以是位‘0’。区分‘0’
	和‘1’是利用脉冲的时间间隔来区分，这种编码方式称为脉冲位置调制方式，
	英文简写PPM
实验内容:
(完成)1.利用红外遥控器发送相应的键码，并将键码值通过printf重定向发送给电
	脑显示（串口调试助手，注意是4个字节的键码值，例如显示：00ff18e7）；
	
(完成)2.利用红外遥控器的任意两个键实现对一颗LED亮度的控制，一颗负责亮
	度增加，一颗负责亮度减小。每按一次相应调整一次亮度（LED亮度从灭
	到全亮分10个等级）（‘-’按键减小，键值：224；‘+’按键增大，键值：168）
	
(完成)3.在2的基础上，当已经到最大亮度或最小亮度时，再次增加或减小时亮度
	不变，同时蜂鸣器报警，当调节至非极值时，蜂鸣器停止报警；
	
(完成)4.利用红外遥控器的任意两个键控制LED流水灯，一个键左移，另一个键
	右移（‘<<’按键左移，键值：34；‘>>’按键右移，键值：2）
	
(完成)5.利用红外遥控器的某个按键实现ADC转换实验，每按一次，ADC转换滑
	变电压值50次，取平均后将电压值结果显示在数码管，并同时将电压值
	通过printf发送给串口调试助手；（'ch'按键98）
	
	6.先在at24c02任意两个单元写入y=ax+b的系数a和b，利用红外遥控器的
	按键功能，例如先按下一个键，进入计算阶段，利用至少两个按键输入2
	位十进制数（同时在数码管上显示），按确认键后在数码管上显示经y=ax+b
	计算后的结果，并通过printf上传至串口调试助手。（‘EQ:144确认计算’）
	ch+ 226开始
1：48
2：24
3：122
4：16
5：56
6：90
7：66
8：74
9:82
0:104
