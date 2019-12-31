#ifndef __NOKIA5110_H__
#define __NOKIA5110_H__
#include "reg51.h"

sbit    sce = P2^0;  //Ƭѡ
sbit    res = P2^1;  //��λ,0��λ
sbit    dc  = P2^2;  //1д���ݣ�0дָ��
sbit    sdin = P2^3;  //����
sbit    sclk = P2^4;  //ʱ��


void delay_1ms(void);
void LCD_write_byte(unsigned char dt, unsigned char command);
void LCD_init(void);
void LCD_set_XY(unsigned char X, unsigned char Y);
void LCD_clear(void);
void LCD_write_shu(unsigned char row, unsigned char page,unsigned char c); //row:�� page:ҳ dd:�ַ�
void LCD_write_hanzi(unsigned char row, unsigned char page,unsigned char c); //row:�� page:�� dd:�����еڼ���



#endif


/*unsigned char k;
	res=0;
	for(k=0;k<250;k++);
	res=1;	  	
  	LCD_init();  //��ʼ��LCDģ�� 
	LCD_clear(); //����Ļ*/




/*	LCD_write_hanzi(8,0,0);  //��	
	LCD_write_hanzi(2,0,1);  //��
	LCD_write_hanzi(4,0,2);  //��
	LCD_write_hanzi(6,0,3);  //Ƭ
	LCD_write_hanzi(0,0,4);  //��
	
	LCD_write_hanzi(1,2,5);  //��
	LCD_write_hanzi(4,2,6);  //��
	LCD_write_hanzi(7,2,7);  //��
				
	LCD_write_shu(1,4,23);   //n
	LCD_write_shu(2,4,11); 	 //b
	LCD_write_shu(3,4,13); 	 //d
	LCD_write_shu(4,4,25); 	 //p
	LCD_write_shu(5,4,19); 	 //j
	LCD_write_shu(6,4,45); 	 //.
	LCD_write_shu(7,4,12); 	 //c
	LCD_write_shu(8,4,24); 	 //o
	LCD_write_shu(9,4,22); 	 //m*/