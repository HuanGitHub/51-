
#ifndef __LCD_1602_H__
#define __LCD_1602_H__
#include <reg52.h>
#include <stdio.h>
#include <INTRINS.H>
#include "datatype.h"  //���������Զ���

#define LCD_DATA P0 //LCD1602���ݶ˿�
void LCD_write_char(INT8U cd,INT8U ab);
void LCD_set_xy( INT8U x, INT8U y );
void LCD_byte(INT8U abc);				  

//д����ֵ��X YΪ���꣬FΪ��ֵ
LCD_value(INT8U x,INT8U y,FP32 f);

//д���ַ���X YΪ���꣬*s���ַ����׵�ַ
void LCD_write_str(INT8U X,INT8U Y,INT8U *s);
LCD_value0(INT8U x,INT8U y,FP32 f);
void Init_Lcd(); //LCD ��ʼ��;

#endif