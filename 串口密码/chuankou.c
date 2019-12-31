#include <reg51.h>
#include <intrins.h>
#define uchar unsigned char 
#define uint unsigned int

unsigned char flag,a,i,x,miao=0,temp=0,aa;
int num;
sbit lsa=P2^0;
sbit lsb=P2^1;
sbit lsc=P2^2;
unsigned char  code duan[]={0xfe,0xfd,0xfb,0xf7};
unsigned char  code wei[]={0x3f,0x06,0x5b,0x4f,
			0x66,0x6d,0x7d,0x07,
			0x7f,0x6f,0x77,0x7c,
			0x39,0x5e,0x79,0x71}; //记得取反                  数码管
unsigned char code table1[]="秒表";
unsigned char code table3[]="流水灯";
unsigned char code table2[]="0123456789";
unsigned char jieshou[3];
unsigned char code table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f
};

void init_chuankou();
void display(int num);
void delay(int c);

void main()
{
	init_chuankou();
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	EA=1;
	ET0=1;
   while(1)
   {
   		if(flag==1)
		{
			ES=0;
			if(jieshou[1]=='0'&&jieshou[2]=='1')
			{
				for(i=0;i<4;i++)
				{
					SBUF=table1[i];
					while(!TI);
					TI=0;
				}
				TR0=1;
				while(jieshou[1]=='0'&&jieshou[2]=='1')
				{
					display(num);
					ES=1;
				}
				num=0;
				TR0=0;
				ES=0;
			}
			if(jieshou[1]=='0'&&jieshou[2]=='2')
			{
				for(i=0;i<6;i++)
				{
					SBUF=table3[i];
					while(!TI);
					TI=0;
				}
				aa=0x01;
				while(jieshou[1]=='0'&&jieshou[2]=='2')
				{
					P1=aa;
					aa=_crol_(aa,1);
					delay(500);
					ES=1;
				}
			}
			ES=1;
			flag=0;
		}
   }
}

void ser() interrupt 4
{
	RI=0;
	jieshou[x]=SBUF;
	x++;
	if(x==3)x=0;
	flag=1;
}

void time1() interrupt 1
{
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	miao++;
	if(miao==20)
	{
		 num++;
		 SBUF=table2[num/10];
		 while(!TI);
		 TI=0;

		 SBUF=table2[num%10];
		 while(!TI);
		 TI=0;
		 if(num==60)
		 {
		 	num=0;
		 }
		 miao=0;
	}
}

void display(int num)
{
	int j;
	int shi,ge;
	shi=num/10;
	ge=num%10;
	P2=duan[0];
	P0=~wei[shi];
	j=500;
	while(j--);
	P0=0x00;
	
	P2=duan[1];
	P0=~wei[ge];
	j=500;
	while(j--);
	P0=0x00;			
}

void init_chuankou()
{
	TMOD=0X21;
	TH1=0XFD;
	TL1=0XFD;
	TR1=1;
	REN=1;
	SM0=0;
	SM1=1;
	EA=1;
	ES=1;
}

void delay(int c)
{
	int a,b;
	for(a=c;a>0;a--)
		for(b=110;b>0;b--);
}













//#include <reg51.h>
//#define uchar unsigned char 
//#define uint unsigned int
//
//unsigned char flag,a,i;
//unsigned char code table[]="i get";
//
//void init_chuankou();
//
//void main()
//{
//	init_chuankou();
//   while(1)
//   {
//   		if(flag==1)
//		{
//			ES=0;
//			for(i=0;i<6;i++)
//			{
//				SBUF=table[i];
//				while(!TI);
//				TI=0;
//			}
//			SBUF=a;
//			while(!TI);
//			TI=0;
//			ES=1;
//			flag=0;
//		}
//   }
//}
//
//void ser() interrupt 4
//{
//	RI=0;
//	a=SBUF;
//	flag=1;
//}
//
//void init_chuankou()
//{
//	TMOD=0X20;
//	TH1=0XFD;
//	TL1=0XFD;
//	TR1=1;
//	REN=1;
//	SM0=0;
//	SM1=1;
//	EA=1;
//	ES=1;
//}