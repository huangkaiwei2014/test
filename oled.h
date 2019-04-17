#ifndef __OLED_H_
#define __OLED_H_

//----------------LCD端口定义--------------- 

#define LCD_CE  LCD_CS
#define LCD_A0  LCD_RS
#define LCD_WR  LCD_WR		  
#define LCD_RD  LCD_RD
//#define LCD_RST PBout(6)	   
//PA0~7,作为数据线
#define DATAOUT(x) P4=(x)

#define LCD_CMD  0	//写命令
#define LCD_DAT  1	//写数据
//LCD控制用函数
void LCD_WR_Byte(unsigned char dat,unsigned char cmd);
void LCD_ShowChar(unsigned char x,unsigned char y,unsigned char chr,unsigned char size,unsigned char mode);
void LCD_Clear(void);
void LCD_DrawPoint(unsigned char x,unsigned char y,unsigned char t);
void LCD_ShowString(unsigned char x,unsigned char y,const unsigned char *p,unsigned char mode);
void LCD_Fill(unsigned char x1,unsigned char y1,unsigned char x2,unsigned char y2,unsigned char dot);	    
void LCD_Refresh_Gram(void);		   
void LCD_Display_On(void);     
void LCD_Display_Off(void);							   		    
void LCD_Init(void);
  
	 

#endif

