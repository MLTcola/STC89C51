#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int

uchar code weixuan[]={/*0x7f,0xbf,0xdf,0xef,*/0xfe,0xfd,0xfb,0xf7};
uchar code duanxuan[17] = {0x3f,0x06,0x5b,0x4f,
							0x66,0x6d,0x7d,0x07,
							0x7f,0x6f,0x77,0x7c,
							0x39,0x5e,0x79,0x71};
uchar code duanxuan1[17] = {0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};						
void delay(int i)
{
	int j;
	for(i;i>0;i--)
	for(j=110;j>0;j--);
}

void main()
{
	while(1)
	{
		int a,b,c;
		for(a=0;a<150;a++)
		for(b=0;b<4;b++)
		{
			P2=weixuan[b];
			P0=~duanxuan[b];
			delay(4);
			P0=0x00;
		}
		c=0;
		for(a=0;a<150;a++)
		for(b=4,c=0;b<8;b++,c++)
		{		
			P2=weixuan[c];
			P0=~duanxuan[b];
			delay(4);
			P0=0x00;
			
		}
	}
}