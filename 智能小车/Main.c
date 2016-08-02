#include <reg52.h>
#include "LCD.h"
#include "Ultrasound.h"
#include "Controller.h"
#include "PWM.h"
#include "L298N.h"
#include "Steering_engine.h"
static int ky=0;
void main()
{  	 int sp=80;
	//LCD_test();			 //LCD1602����
	//Controller_test();       //����ң�ز���
//	Steering_test();		 //�������
		 //����������
//	PWM_test();				//PWM����
	 
	while(1){
	 Go();		
	 Ultrasound_test();
	sp=Count();
	if(sp<10){
		Stop();
	}
	Delay250ms();
	} 
/*	Controller_Out0_Config();
	PWM_Time1_Config();
	Steering_Time0_Config();
	PWM_flag=0;						  //��ʼ��PWM_flag=0      PWM��־λ��
	while(1){
		ky=Controller_Com();
		switch(ky)
		{
			case 0x45:		PWM_flag=0;Go();    break;
			case 0x47:		PWM_flag=0;Back();  break;
			case 0x46:		PWM_flag=0;Stop();	break;
			case 0x44:		PWM_flag=-1;		break;
			case 0x40:		PWM_flag=0;			break;
			case 0x43:		PWM_flag=1;		    break;
			case 0x07:
			case 0x15:
			case 0x09:
			case 0x16:
			case 0x19:
			case 0x0D:
			case 0x0C:
			case 0x18:
			case 0x5E:
			case 0x08:
			case 0x1C:
			case 0x5A:
			case 0x42:
			case 0x52:
			case 0x4A:
			default:			Stop();	        break;
		}			
	}		 */	   	
}
void Time1() interrupt 3
{	
	PWM_time1();		//PWM����
}
void Time0() interrupt 1
{
	//Steering_Time0();		   //�������
	 Ultrasound_Time1();	  //����������
}
void Out0() interrupt 0
{  	
	Red_line();					 //�������
}

	
		