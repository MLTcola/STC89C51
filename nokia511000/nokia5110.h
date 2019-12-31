#ifndef __NOKIA5110_H__
#define __NOKIA5110_H__
#include "reg51.h"

sbit    sce = P2^0;  //片选
sbit    res = P2^1;  //复位,0复位
sbit    dc  = P2^2;  //1写数据，0写指令
sbit    sdin = P2^3;  //数据
sbit    sclk = P2^4;  //时钟


void delay_1ms(void);
void LCD_write_byte(unsigned char dt, unsigned char command);
void LCD_init(void);
void LCD_set_XY(unsigned char X, unsigned char Y);
void LCD_clear(void);
void LCD_write_shu(unsigned char row, unsigned char page,unsigned char c); //row:列 page:页 dd:字符
void LCD_write_hanzi(unsigned char row, unsigned char page,unsigned char c); //row:列 page:行 dd:数组中第几个



#endif


/*unsigned char k;
	res=0;
	for(k=0;k<250;k++);
	res=1;	  	
  	LCD_init();  //初始化LCD模块 
	LCD_clear(); //清屏幕*/




/*	LCD_write_hanzi(8,0,0);  //宁	
	LCD_write_hanzi(2,0,1);  //波
	LCD_write_hanzi(4,0,2);  //单
	LCD_write_hanzi(6,0,3);  //片
	LCD_write_hanzi(0,0,4);  //机
	
	LCD_write_hanzi(1,2,5);  //开
	LCD_write_hanzi(4,2,6);  //发
	LCD_write_hanzi(7,2,7);  //网
				
	LCD_write_shu(1,4,23);   //n
	LCD_write_shu(2,4,11); 	 //b
	LCD_write_shu(3,4,13); 	 //d
	LCD_write_shu(4,4,25); 	 //p
	LCD_write_shu(5,4,19); 	 //j
	LCD_write_shu(6,4,45); 	 //.
	LCD_write_shu(7,4,12); 	 //c
	LCD_write_shu(8,4,24); 	 //o
	LCD_write_shu(9,4,22); 	 //m*/