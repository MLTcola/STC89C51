#include<reg52.h>
#define key P1

unsigned char code display[17]={
0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

void keyscan();
void delay(int c);

int   KeyValue;

void main()
{
	while(1)
	{
		 keyscan();
	}
}

void keyscan(void)
{
	key=0x0f;
	if(key!=0x0f) 
	{
		delay(10); 
		if(key!=0x0f) 
		{
			
		 
			key=0X0F;
			switch(key)
			{
				case(0X07):	KeyValue=0;break;
				case(0X0b):	KeyValue=4;break;
				case(0X0d): KeyValue=8;break;
				case(0X0e):	KeyValue=12;break;
			}
			 
			key=0XF0;
			switch(key)
			{
				case(0X70):	KeyValue=KeyValue+3;break;
				case(0Xb0):	KeyValue=KeyValue+2;break;
				case(0Xd0): KeyValue=KeyValue+1;break;
				case(0Xe0):	KeyValue=KeyValue;break;
			}
			delay(10);
			 
		}
	}
}

void delay(int c)
{
	int a,b;
	for(a=0;a<c;a++)
		for(b=0;b<110;b++);
}