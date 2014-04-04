#include "application.h" 

#include "MotorCtl.h"   // �������
//#include "24l01.h" 
#include "lcd.h"
#include "key.h"  
#include "counter.h"   //������
#include "uart_state.h"


u32 device_init()
{
  LCD_Init();  //��ʼLCD
	
	return 0;
}
u32 application_init()
{
	device_init();
	UartState_init();  //״̬����ʼ��
	return 0;
}

void loop_work()
{
	u8 cmd=0;
	UartProcessData(3,NULL,&cmd); //״̬����ȡ
	LCD_ShowxNum(156,300,cmd,3,16,0);//��ʾADC��ֵ
	switch(cmd)
	{
		case 0x01:   //�ص�
			GPIO_ResetBits(GPIOA, GPIO_Pin_8);
			break;
		case 0x02:   //����
			GPIO_SetBits(GPIOA, GPIO_Pin_8);
			break;
		case 0x03:   //���ȹ�
			GPIO_ResetBits(GPIOA, GPIO_Pin_9);
			GPIO_ResetBits(GPIOA, GPIO_Pin_10);
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

