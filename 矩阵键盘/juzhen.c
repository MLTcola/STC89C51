#include<reg51.h>

unsigned char code table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f
};

void keyscan();
void display(int num);
void delay(int c);

int ankey,flag,num=0;
sbit beep=P2^5;
sbit lsa=P2^0;
sbit lsb=P2^1;
sbit lsc=P2^2;

void main()
{
	TMOD=0X11;
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	TH1=0XFD;
	TL1=0XFD;
	EA=1;
	ET0=1;
	ET1=1;
	TR0=0;
	TR1=1;
	while(1)
	{
		if(ankey==9)
		{
			TR0=1;
			display(num);
		}
		if(ankey==2)
		{
			num=0;
			while(ankey==2)
			{
				beep=1;
				delay(3);
				beep=0;
				delay(3);
			}
		}
	}
}
void time1() interrupt 1
{
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	flag++;
	if(flag==20)
	{
		 num++;
		 if(num==60)
		 {
		 	num=0;
		 }
		 flag=0;
	}
}

void time2() interrupt 3
{
	TH1=0XFD;
	TL1=0XFD;
	keyscan();	
}

void display(int num)
{
	unsigned char j;
	int shi,ge;
	shi=num/10;
	ge=num%10;
	lsa=1;lsb=0;lsc=0;
	P0=table[ge];
	j=10;
	while(j--);
	P0=0x00;	
	lsa=0;lsb=0;lsc=0;
	P0=table[shi];
	 j=10;
	while(j--);
	P0=0x00;			
}


void keyscan()
{
	unsigned char temp;
	P1=0xfe;                                                  // L1-L4:P10-P13       R1-R4:P14-P17
	temp=P1;
	temp=temp&0xf0;
	if(temp!=0xf0)
	{
		temp=P1;                                         //P1=0xfe;第一排
		switch(temp)
		{                                                //0xfd  第二排
			case 0xee:ankey=0;break;//1               //0xfb  san
			case 0xde:ankey=1;break;//2
			case 0xbe:ankey=2;break;//3                   //0xf7   si
			case 0x7e:ankey=3;break;//4
		}
		while(temp!=0xf0)
		{
			temp=P1;
			temp=temp&0xf0;
		}
	}

	P1=0xfd;                                                  // L1-L4:P10-P13       R1-R4:P14-P17
	temp=P1;
	temp=temp&0xf0;
	if(temp!=0xf0)
	{
		temp=P1;                                         //P1=0xfe;第一排
		switch(temp)
		{                                                //0xfd  第二排
			case 0xed:ankey=4;break;//1               //0xfb  san
			case 0xdd:ankey=5;break;//2
			case 0xbd:ankey=6;break;//3                   //0xf7   si
			case 0x7d:ankey=7;break;//4
		}
		while(temp!=0xf0)
		{
			temp=P1;
			temp=temp&0xf0;
		}
	}


	P1=0xfb;                                                  // L1-L4:P10-P13       R1-R4:P14-P17
	temp=P1;
	temp=temp&0xf0;
	if(temp!=0xf0)
	{
		temp=P1;                                         //P1=0xfe;第一排
		switch(temp)
		{                                                //0xfd  第二排
			case 0xeb:ankey=8;break;//1               //0xfb  san
			case 0xdb:ankey=9;break;//2
			case 0xbb:ankey=10;break;//3                   //0xf7   si
			case 0x7b:ankey=11;break;//4
		}
		while(temp!=0xf0)
		{
			temp=P1;
			temp=temp&0xf0;
		}
	}

	P1=0xf7;                                                  // L1-L4:P10-P13       R1-R4:P14-P17
	temp=P1;
	temp=temp&0xf0;
	if(temp!=0xf0)
	{
		temp=P1;                                         //P1=0xfe;第一排
		switch(temp)
		{                                                //0xfd  第二排
			case 0xe7:ankey=12;break;//1               //0xfb  san
			case 0xd7:ankey=13;break;//2
			case 0xb7:ankey=14;break;//3                   //0xf7   si
			case 0x77:ankey=15;break;//4
		}
		while(temp!=0xf0)
		{
			temp=P1;
			temp=temp&0xf0;
		}
	}
}

void delay(int c)
{
	int a,b;
	for(a=c;a>0;a--)
		for(b=110;b>0;b--);
}