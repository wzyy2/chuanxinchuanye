#include "application.h" 

#include "MotorCtl.h"   // �������
//#include "24l01.h" 
#include "lcd.h"
#include "key.h"  
#include "counter.h"   //������
#include "uart_state.h"
#include "oled.h"

u32 device_init()
{
  LCD_Init();  //��ʼLCD

	
	return 0;
}
u32 application_init()
{
	device_init();
	UartState_init();  //״̬����ʼ��
	OLED_Init();
	return 0;
}

void loop_work()
{
	u8 cmd=0;
	UartProcessData(3,NULL,&cmd); //״̬����ȡ
	if(cmd)
		LCD_ShowxNum(156,300,cmd,3,16,0);//��ʾADC��ֵ
	//OLED_SDA=1;
	OLED_SDA=1;
	OLED_SCL=1;
	OLED_DC=1;
	OLED_RST=1;
	//OLED_Setxy(0,0);
	//OLED_Fill(0xff);
	switch(cmd)
	{
		case 0x01:   //�ص�
			GPIO_SetBits(GPIOA, GPIO_Pin_8);
			break;
		case 0x02:   //����
			GPIO_ResetBits(GPIOA, GPIO_Pin_8);
			break;
		case 0x03:   //���ȹ�
			GPIO_SetBits(GPIOA, GPIO_Pin_9);
			GPIO_SetBits(GPIOA, GPIO_Pin_10);
			break;
		case 0x04:   //����һ��
			GPIO_ResetBits(GPIOA, GPIO_Pin_9);		
 	  	GPIO_SetBits(GPIOA, GPIO_Pin_10);
			break;
		case 0x05:   //���ȶ���
			GPIO_SetBits(GPIOA, GPIO_Pin_9);
			GPIO_ResetBits(GPIOA, GPIO_Pin_10);
			break;
		case 0x06:   //״̬��ȡ
			break;
	}
#ifdef DEBUG
//printf("%d");
//LCD_ShowxNum(156,300,image[76798],3,16,0);//��ʾADC��ֵ		
//visual_scope(1,2,3,4,USART2); // ���ڲ�����ʾ
#endif 
}

