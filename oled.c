#include <C8051F340.h>
#include <intrins.h>
#include "hardware.h"
#include "OLED.h"
#include "OLEDfont.h"

//unsigned char xdata LCD_GRAM[255][20];
//	 
//void LCD_Refresh_Gram(void)
//{
//	unsigned char i,n,m,imgx,dat0,dat1,dat2,byte0=0,byte1=0;
//	LCD_WR_Byte(0x30,LCD_CMD);//Ext=0 Set
//	LCD_WR_Byte(0x15,LCD_CMD);//Column Address Set  
//	LCD_WR_Byte(0x00,LCD_DAT);//
//	LCD_WR_Byte(0x54,LCD_DAT);//
//	LCD_WR_Byte(0x75,LCD_CMD);//Line Address Set 
//	LCD_WR_Byte(0x00,LCD_DAT);//
//	LCD_WR_Byte(0x7F,LCD_DAT);//
//	LCD_WR_Byte(0x5C,LCD_CMD);//Writing to Memory 
////	delay_us(10);
//	imgx=0;
//	for(i=0;i<20;i++)  //20*8=160
//	{  
//		for(m=0;m<8;m++)
//		{
//			for(n=0;n<85;n++)//3*85=255
//			{
//				imgx=3*n;
//				dat0=LCD_GRAM[imgx][i];
//				dat0=dat0<<m;
//				dat0=dat0&0x80;
//				imgx=3*n+1;
//				dat1=LCD_GRAM[imgx][i];
//				dat1=dat1<<m;
//				dat1=dat1&0x80;
//				imgx=3*n+2;
//				dat2=LCD_GRAM[imgx][i];
//				dat2=dat2<<m;
//				dat2=dat2&0x80;
//				byte0=dat0>>0|dat0>>1|dat0>>2|dat0>>3|dat0>>4|dat1>>5|dat1>>6|dat1>>7;
//				byte1=dat1>>0|dat1>>1|dat1>>2|dat2>>3|dat2>>4|dat2>>5|dat2>>6|dat2>>7;
//				LCD_WR_Byte(byte0,LCD_DAT);
//				LCD_WR_Byte(byte1,LCD_DAT);
//			}
//		}	 
//	}

//}
//Write 1 Byte Command/Data¡£
//DAT:Data/Command 
//CMD:0 For Command 1 For Data
void LCD_WR_Byte(unsigned char dat,unsigned char cmd)
{ 	
	LCD_CE=0;
 	LCD_A0=cmd;
	LCD_WR=0;
	LCD_WR=0;
	P4=dat;	   		 
	LCD_WR=1;  
	LCD_WR=1;  
	LCD_RD=1;
	LCD_CE=1; 
} 	    	    

//Draw Point 
//NOT USE ST7529's Gray Level Control Function
////X Y;t For THE Point's Gray Level,0 For Dark;1 For Bright (Maybe Wrong??)
void LCD_DrawPoint(unsigned char x,unsigned char y,unsigned char t)
{
//	unsigned char pos,bx,temp=0;
//	if(x>255||y>160)return;
//	pos=y/8;
//	bx=y%8;
//	temp=1<<(7-bx);
//	if(t)LCD_GRAM[x][pos]|=temp;
//	else LCD_GRAM[x][pos]&=~temp;	  
    
}

void LCD_ShowChar(unsigned char x,unsigned char y,unsigned char chr,unsigned char size,unsigned char mode)
{      		
  unsigned char i=0;	
	LCD_WR_Byte(0x30,LCD_CMD);//Ext=0 Set
	LCD_WR_Byte(0x15,LCD_CMD);//Column Address Set  
	LCD_WR_Byte(0x00,LCD_DAT);//
	LCD_WR_Byte(0x08,LCD_DAT);//
	LCD_WR_Byte(0x75,LCD_CMD);//Line Address Set 
	LCD_WR_Byte(0x00,LCD_DAT);//
	LCD_WR_Byte(0x10,LCD_DAT);//
	LCD_WR_Byte(0x5C,LCD_CMD);//Writing to Memory   
	for(i=0;i<(16*8);i++)
	{
				LCD_WR_Byte(0xff,LCD_DAT);
				LCD_WR_Byte(0xff,LCD_DAT);
		    LCD_WR_Byte(0xff,LCD_DAT);

	}
}

void LCD_ShowString(unsigned char x,unsigned char y,const unsigned char *p,unsigned char mode)
{
//#define MAX_CHAR_POSX 199
//#define MAX_CHAR_POSY 111          
//	while(*p!='\0')
//	{       
//			if(x>MAX_CHAR_POSX){x=0;y+=16;}
//			if(y>MAX_CHAR_POSY){y=x=0;}
//			LCD_ShowChar(x,y,*p,16,mode);	 
//			x+=8;
//			p++;
//	}  
}
	   	         
void LCD_Display_On(void)
{
	LCD_WR_Byte(0x30,LCD_CMD);	 //Ext in
	LCD_WR_Byte(0xAF,LCD_CMD);	 //Display On
}
     
void LCD_Display_Off(void)
{
	LCD_WR_Byte(0x30,LCD_CMD);	 //Ext in
	LCD_WR_Byte(0XAE,LCD_CMD);	 //Display Off
}		   			 
////Format GDRAM	 OxFF for 'White' Display 
void LCD_Clear(void)  
{  
//	unsigned char i,n;  
//	for(i=0;i<20;i++)
//	{		
//	     for(n=0;n<255;n++)
//				{
//					LCD_GRAM[n][i]=0x00;

//				}				
//	}		
	unsigned char m,n;
	LCD_WR_Byte(0x30,LCD_CMD);//Ext=0 Set
	LCD_WR_Byte(0x15,LCD_CMD);//Column Address Set  
	LCD_WR_Byte(0x00,LCD_DAT);//
	LCD_WR_Byte(0x54,LCD_DAT);//
	LCD_WR_Byte(0x75,LCD_CMD);//Line Address Set 
	LCD_WR_Byte(0x00,LCD_DAT);//
	LCD_WR_Byte(0x7F,LCD_DAT);//
	LCD_WR_Byte(0x5C,LCD_CMD);//Writing to Memory 
	for(m=0;m<128;m++)
	   {
			 for(n=0;n<255;n++)
			 {


				LCD_WR_Byte(0x00,LCD_DAT);
				LCD_WR_Byte(0x00,LCD_DAT);
		    LCD_WR_Byte(0x00,LCD_DAT);

			 }
		 }
}	  
					    
void LCD_Init(void)
{ 	 				 	 				   					  
	LCD_WR_Byte(0x30,LCD_CMD);//Ext in
	LCD_WR_Byte(0x94,LCD_CMD);//Sleep out
	LCD_WR_Byte(0XD1,LCD_CMD);//Internal OSC on
	LCD_WR_Byte(0x20,LCD_CMD);//Pwr Control
	LCD_WR_Byte(0x08,LCD_DAT);//Turn On Booster
//	delay_ms(1);
	LCD_WR_Byte(0X20,LCD_CMD);//Pwr Control
	LCD_WR_Byte(0x0B,LCD_DAT);//Turn on REF&VFLR
	//delay_us(1); 
	LCD_WR_Byte(0x81,LCD_CMD);//EC Control
	LCD_WR_Byte(0X24,LCD_DAT);//--
	LCD_WR_Byte(0X04,LCD_DAT);//OVER ALL Vol=14.8V
	//delay_us(1);
	LCD_WR_Byte(0xCA,LCD_CMD);//Display Control
	LCD_WR_Byte(0X04,LCD_DAT);//1/2x OSC||DO NOT change it to x1,or the Display will be gloomy.
	LCD_WR_Byte(0X26,LCD_DAT);//Drive Duty=128
	LCD_WR_Byte(0X04,LCD_DAT);//Change it To Find a Certain Value For Better Display Status.
	//delay_us(1);												    
	LCD_WR_Byte(0xA6,LCD_CMD);//Normal Display Mode
	//delay_us(1);
	LCD_WR_Byte(0xBB,LCD_CMD);//COM Scan Dir Set
	LCD_WR_Byte(0x01,LCD_DAT);//0~79&159~80
//  	LCD_WR_Byte(0x00,LCD_DAT);//0~79&80-159
	//delay_us(1);
	LCD_WR_Byte(0xBC,LCD_CMD);//Data Scan Dir Set
	LCD_WR_Byte(0x00,LCD_DAT);//Normal
	LCD_WR_Byte(0x00,LCD_DAT);//Normal
//	LCD_WR_Byte(0x01,LCD_DAT);//2B3P Data Mode
		LCD_WR_Byte(0x02,LCD_DAT);//3B3P Data Mode
	//delay_us(1);
	LCD_WR_Byte(0x75,LCD_CMD);//Line Addr Set  ÐÐ
	LCD_WR_Byte(0x00,LCD_DAT);//Start=0
	LCD_WR_Byte(0x40,LCD_DAT);//End=127
	//delay_us(1);
	LCD_WR_Byte(0x15,LCD_CMD);//Column Addr SetÁÐ
	LCD_WR_Byte(0x00,LCD_DAT);//Start=0
	LCD_WR_Byte(0x54,LCD_DAT);//End=84
	//delay_us(1);
	LCD_WR_Byte(0x431,LCD_CMD);//Ext=1
	//delay_us(1);0
	LCD_WR_Byte(0x32,LCD_CMD);//Analog Circuit Set
	LCD_WR_Byte(0x00,LCD_DAT);//OSC Freq=000   Default
	LCD_WR_Byte(0x01,LCD_DAT);//Booster Eff=01 Default
	LCD_WR_Byte(0x02,LCD_DAT);//Bias=1/12
	//delay_us(1);						   
	LCD_WR_Byte(0x34,LCD_CMD);//Software Init
	//delay_us(1);
	LCD_WR_Byte(0x30,LCD_CMD);//Return Ext=0 Mode
} 