#include <reg51.h>
 
sbit clk = P1^0;
sbit cs = P1^1;
sbit LSA=P1^4;
sbit LSB=P1^5;
sbit LSC=P1^6;
sbit din=P1^2;
sbit dout=P1^3;

unsigned char code table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f
};

unsigned char DisplayData[8];

void delay(int c);
void write_cmd(unsigned char cmd);
unsigned int read_dat();
void init();
unsigned int  read_ad_data(unsigned char cmd);
void DigDisplay(void);


void main()
{
  	unsigned int temp,count;
	init();
	while(1)
	{
	  if(count==50)
	  {
	  	count=0; 
		temp = read_ad_data(0x94);		//   AIN0 ��λ��		ͨ����ַ	001
	  }
	  count++;
	  

	  DisplayData[4]=table[temp%10000/1000];
	  DisplayData[5]=table[temp%1000/100];
	  DisplayData[6]=table[temp%100/10];
	  DigDisplay();
	}
}

void write_cmd(unsigned char cmd)
{
	unsigned char i;
	clk=0;
	for(i=0;i<8;i++)
	{
		din=cmd>>7;
		cmd=cmd<<1;
		clk=0;
		clk=1;
	}
}

unsigned int read_dat()
{
	unsigned char i;
	unsigned int dat=0;
	clk=0;
	for(i=0;i<12;i++)
	{
		dat=dat<<1;

		clk=1;
		clk=0;

	   	dat=dat|dout;
	}
	return dat;
}

void init()
{
	clk=0;//	CLK = 0;
	cs=1;//CS  = 1;
	din=1;//DIN = 1;
	clk=1;//CLK = 1;
	cs=0;//	CS  = 0;
}

unsigned int read_ad_data(unsigned char cmd)
{
	unsigned char i;
	unsigned int value;
	clk=0;
	cs=0;
	write_cmd(cmd);
	for(i=6;i>0;i--);
	clk=1;
	delay(20);
	clk=0;
	delay(20);
	value=read_dat();
	cs=1;
	return value;
}

void DigDisplay(void)
{
		unsigned char i;
	unsigned int j;
	for(i=0;i<8;i++)
	{
		switch(i)	 //λѡ��ѡ�����������ܣ�
		{
			case(0):
				LSA=0;LSB=0;LSC=0; break;//��ʾ��0λ
			case(1):
				LSA=1;LSB=0;LSC=0; break;//��ʾ��1λ
			case(2):
				LSA=0;LSB=1;LSC=0; break;//��ʾ��2λ
			case(3):
				LSA=1;LSB=1;LSC=0; break;//��ʾ��3λ
			case(4):
				LSA=0;LSB=0;LSC=1; break;//��ʾ��4λ
			case(5):
				LSA=1;LSB=0;LSC=1; break;//��ʾ��5λ
			case(6):
				LSA=0;LSB=1;LSC=1; break;//��ʾ��6λ
			case(7):
				LSA=1;LSB=1;LSC=1; break;//��ʾ��7λ	
		}
		P0=DisplayData[i];//���Ͷ���
		j=50;						 //ɨ����ʱ���趨
		while(j--);	
		P0=0x00;//����
	}
}

void delay(int c)
{
	int a,b;
	for(a=c;a>0;a--)
		for(b=110;b>0;b--);
}
