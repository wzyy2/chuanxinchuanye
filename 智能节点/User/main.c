#include "MyF4Config.h"
#include "bsp.h"
#include "application.h"


int main(void)
{
	board_init(); //MCU�Ĵ����ĳ�ʼ��
	device_init(); //�豸
	application_init(); //�����ʼ��
	while(1)
	{		 
		loop_work();
	}  	
}

