#include"Lcd_1602.h"
#include "Config.c"

void  Delay_ms(INT16U t)
{
	INT16U i,j;
	for(i=0;i<t;i++)
		for(j=0;j<110;j++);
}
void Delay_us(INT16U t)
{
	while(t--);
}
void Init_Lcd() //LCD ��ʼ��
{
	LCD_write_char(0x38,0);
	Delay_ms(5);
	LCD_write_char(0x38,0);
	Delay_ms(5);
	LCD_write_char(0x38,0);
	Delay_ms(5);
	LCD_write_char(0x0c,0);
	Delay_ms(5);
	LCD_write_char(0x06,0);
	Delay_ms(5);
	LCD_write_char(0x0c,0);
	Delay_ms(5);
}
void LCD_write_str(INT8U x,INT8U Y,INT8U *s)
{
	LCD_write_char(0,' ');
	LCD_set_xy( x, Y ); //д��ַ
	while (*s) // д��ʾ�ַ�
	{
		LCD_write_char( 0, *s );
		s ++;
	}
}

void LCD_set_xy( INT8U x,INT8U y ) //д��ַ����
{
    INT8U address;
	if (y == 0) 
		address = 0x80 + x;
	else
		address = 0xc0 + x;
		LCD_write_char( address, 0 );
}

void LCD_en_write(void) //Һ��ʹ��
{
	Delay_ms(5);
	LCD_E=1;//EN=1
	Delay_ms(5);
	LCD_E=0;//EN=0
}
void LCD_write_char(INT8U cd,INT8U ab) // д����
{
	Delay_us(200);
	if(cd==0)
	{
		LCD_RS=1; //RS=1,д��ʾ����
		LCD_byte(ab);
	}
	else
	{
		LCD_RS=0; //RS=0��д����
		LCD_byte(cd);
	}
}

void LCD_byte(INT8U abc)
{
	RW = 0;
	LCD_E = 0;
	LCD_DATA = abc;
	LCD_en_write();
}

LCD_value(INT8U x,INT8U y,FP32 f)
{
	INT8U str[8]; //���ܶ���Ϊ char* str�����鳤��һ��Ҫ���ڸ���������λ��
	
	sprintf(str,"%.1f",f); //1 ��ʾС��λ�� С��̫�� �Զ���������
	LCD_write_str( x, y, str);
	return 0;
}
LCD_value0(INT8U x,INT8U y,FP32 f)
{
	INT8U str[8]; //���ܶ���Ϊ char* str�����鳤��һ��Ҫ���ڸ���������λ��	
	sprintf(str,"%.0f",f); //1 ��ʾС��λ�� С��̫�� �Զ���������
	LCD_write_str( x, y, str);
	return 0;
}
