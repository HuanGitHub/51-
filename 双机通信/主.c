#include <reg52.h>
#include "LCD.h"
void UartInit(void);
char res;
void main()
{
	UartInit();
	LCD_init();
	while(1){

	}


}
void UartInit(void)		//9600bps@11.0592MHz
{
	SM0=0;
	SM1=1;
	REN=1;

	TMOD &= 0x0F;		//�趨��ʱ��1Ϊ16λ�Զ���װ��ʽ
	TL1 = 0xEd;		//�趨��ʱ��ֵ
	TH1 = 0xFd;		//�趨��ʱ��ֵ
	ET1 = 0;		//��ֹ��ʱ��1�ж�
	TR1 = 1;		//������ʱ��1
	ES=1;
	EA=1;
}
void Time1() interrupt 4
{
	TL1 = 0xEd;		
	TH1 = 0xFd;
	RI=0;
	if(RI){
		res=SBUF;
		RI=0;
		Write_dat('');	
	}
		

}