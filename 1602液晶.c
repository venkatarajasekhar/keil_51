#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
uchar code table[]="I LOVE MCU";
uchar code table1[]="WWW.TXMCU.COM";
sbit lcden=P3^4;
sbit lcdrs=P3^5;
uchar num;
void delay(uint z)
{
   uint x,y;
   for(x=z;x>0;x--)
     for(y=110;y>0;y--);
}

void write_com(uchar com)
{
  lcdrs=0;
  P0=com;
  delay(5);
  lcdrs=1;
  delay(5);
  lcden=0;
}

void write_data(uchar date)
{
  lcdrs=1;
  P0=date;
  delay(5);
  lcden=1;
  delay(5);
  lcden=0;
}

void init()
{
  lcden=0;
  write_com(0x38);
  write_com(0x0c);
  write_com(0x06);
  write_com(0x01);
}

void main()
{
  init();
  write_com(0x80);
  for(num=0;num<11;num++)
  {
     write_date(table[num]);
	 delay(5);
  }
  write_com(0x80+0x40);
  for(num=0;num<13;num++)
  {
    write_date(table1[num]);
	delay(5);
  }
  while(1);
}

  
