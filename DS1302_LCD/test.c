#include <reg52.h>
#include <LCD.h>
#include <DS1302.h>

void LcdDisplay();

void main()
{   Lcd_init();
	DS_init();

		while(1){
				DS_Read_time();
			
			LcdDisplay();		
		}
	
}
void LcdDisplay()
{
	Lcd_Write_com(0x80+0X40);
	Lcd_Write_data('0');				//ʱ
	Lcd_Write_data('0');				 
	Lcd_Write_data('-');
	Lcd_Write_data('0');				//��
	Lcd_Write_data('0');	
	Lcd_Write_data('-');
	Lcd_Write_data('0');				//��
	Lcd_Write_data('0');

	Lcd_Write_com(0x80);
	Lcd_Write_data('2');
	Lcd_Write_data('0');
	Lcd_Write_data('0');			//��
	Lcd_Write_data('0');
	Lcd_Write_data('-');
	Lcd_Write_data('0');			//��
	Lcd_Write_data('0');
	Lcd_Write_data('-');
	Lcd_Write_data('0');			//��
	Lcd_Write_data('0');
	Lcd_Write_com(0x8D);
	Lcd_Write_data('0');	//����			 

}


