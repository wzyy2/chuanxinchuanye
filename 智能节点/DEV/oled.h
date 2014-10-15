#ifndef __OLED_H
#define __OLED_H			  	 
#include "MyF4Config.h"
  

  
#define OLED_DC_PIN    15  
#define OLED_SDA_PIN   7  
#define OLED_SCL_PIN   14  
#define OLED_RST_PIN   11  
#define OLED_DC     PBout(OLED_DC_PIN)  
#define OLED_SDA    PBout(OLED_SDA_PIN)  
#define OLED_SCL    PBout(OLED_SCL_PIN)  
#define OLED_RST    PDout(OLED_RST_PIN)  
 
#define XLevelL     0x00  
#define XLevelH     0x10  
#define XLevel      ((XLevelH&0x0F)*16+XLevelL)  
#define Max_Column  128  
#define Max_Row     64  
#define Brightness  0xCF   
#define X_WIDTH 128  
#define Y_WIDTH 64  
//������ʵ�ֵĽӿں���  
void OLED_WRCMD(u8 com);  
void OLED_WRDATA(u8 dat);  
void OLED_Setxy(u8 x, u8 y);    //OLED ��������  
void OLED_Fill(u8 bmp_dat);   //bmp_dat=0x00ȫ����bmp_dat=0xffȫ����  
void OLED_Init(void); //OLED��ʼ��    
void OLED_6x8(u8 x,u8 y,u8 ch[]);//��ʾ6*8һ���׼ASCII�ַ���    ��ʾ�����꣨x,y����yΪҳ��Χ0��7  
void OLED_Cler_6x8(u8 x,u8 y,u8 n);//���N��6*8�ַ�  
void OLED_8x16(u8 x,u8 y,u8 ch[]);//��ʾ8*16һ���׼ASCII�ַ���   ��ʾ�����꣨x,y����yΪҳ��Χ0��7  
void OLED_Cler_8x16(u8 x,u8 y,u8 n); //���n��8*16�ַ�  
void OLED_16x16(u8 x,u8 y,u8 N);//��ʾ16*16����  ��ʾ�����꣨x,y����yΪҳ��Χ0��7  
void OLED_Cler_16x16(u8 x,u8 y,u8 n);//���n��16*16��  
void Draw_BMP(u8 x0,u8 y0,u8 x1,u8 y1,u8 BMP[]);//��ʾ��ʾBMPͼƬ128��64��ʼ������(x,y),x�ķ�Χ0��127��yΪҳ�ķ�Χ0��7*  
void OLED_Refresh_Gram(void);  
void OLED_DRAWPoint(u8 x,u8 y,u8 t);  
#endif  


