/*************************************************************************
*��Ŀ����������ƣ� ����STM32+0V7670+NRF24L01��������Ƶ����С��
*�������ڣ�         2011.4.9
*������:            ��־ǿ
*ģ�鹦�ܣ�         MAIN2.c
*�޸����ڣ�
*�����ĵ���          IJG JPEG LIBRARY
*�ر�˵��:   	     ��ѹ���㷨��Դ��(JPEG Group's software)IJG JPEG LIBRARY��
                    www.ouravr.com��VERYVERY���Ѷ����������ֲ���Ҷ��������
                    �Ż����޸ģ�
                                       
*************************************************************************/
#include "jinclude.h"			 //ͼ��ѹ����ͷ�ļ�
#include "jcapi.h"				 
#include "test.h"
/*************************************************************************
*����������ȫ�ֱ�����λ����
*������ڣ�
*��������:
*����˵��:   
*************************************************************************/
unsigned char JPG_enc_buf[20000];//jpeg ���
volatile unsigned int pt_buf;//������ָ��
//__no_init  
unsigned char inbuf_buf[960];//���뻺��
//ע�⣺ԭʼRGB565���ݺ����뻺����ͬһ������RAM�����������ǽ�ʡ�ռ�!!
jpeg_compress_info info1;
JQUANT_TBL  JQUANT_TBL_2[2];   //������
JHUFF_TBL   JHUFF_TBL_4[4];	   //��������
unsigned char dcttab[3][512];  //DCT�任��
//ѹ��


void GBRTORGB24(char *buf,int line)
{
	int i;
	for(i=0;i<320;i += 2)
	{
		switch(line%2)
		{
			case 0:
				inbuf_buf[i*3] = buf[(line+1)*320+1+i] ;inbuf_buf[i*3+1] = buf[line*320+1+i] ;inbuf_buf[i*3+2] = buf[line*320+i] ;
				break;
			case 1:
				inbuf_buf[i*3] = buf[line*320] ;inbuf_buf[i*3+1] = buf[line*320] ;inbuf_buf[i*3+2] = buf[line*320] ;
				break;
		}
	}
	
		for(i=1;i<320;i += 2)
	{
		switch(line%2)
		{
			case 0:
				inbuf_buf[i*3] = buf[(line+1)*320+i] ;inbuf_buf[i*3+1] = buf[line*320+i] ;inbuf_buf[i*3+2] = buf[line*320+i-1] ;
				break;
			case 1:
				inbuf_buf[i*3] = buf[line*320] ;inbuf_buf[i*3+1] = buf[line*320] ;inbuf_buf[i*3+2] = buf[line*320] ;
				break;
		}
	}
}


void Compression(int width,int height,float quality) 
{
  jpeg_compress_info *cinfo;
	int  i;
  pt_buf=0;
  cinfo=jpeg_create_compress();			   //cinfo:ͼ��������Ϣ
  cinfo->image_width=width;//�趨ͼƬ��С
  cinfo->image_height=height;
  cinfo->output=JPG_enc_buf;//�趨�������λ��
  jpeg_set_default(cinfo,quality);  
  jpeg_start_compress(cinfo);
	
  while(cinfo->next_line<cinfo->image_height)//һ��һ�е�ɨ������뻺���� 
  {
    jpeg_write_scanline(cinfo,&inbuf_buf[0]);
  }
  jpeg_finish_compress(cinfo);
}


