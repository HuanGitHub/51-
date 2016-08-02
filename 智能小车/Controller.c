#include "Config.c"
#include "Controller.h"
#include "LCD.h"
#include "L298N.h"
unsigned char Value[6];
void Controller_Out0_Config()
{
	EA|=1;
	IT0=1;
	EX0=1;
}
void De()		//@11.0592MHz  //����ˢ����ʾ
{
	char i, j, k;
	i = 6;
	j = 130;
	k = 111;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void Red_line()
{
	unsigned char j,k;
	unsigned int err,Time;
	Time=0;					 
	DelayMs(70);
		if(IN==0)		//ȷ���Ƿ���Ľ��յ���ȷ���ź�
		{	 
			err=1000;				//1000*10us=10ms,����˵�����յ�������ź�
			while((IN==0)&&(err>0))	//�ȴ�ǰ��9ms�ĵ͵�ƽ��ȥ  		
			{			
				DelayMs(1);
				err--;
			} 
			if(IN==1)			//�����ȷ�ȵ�9ms�͵�ƽ
			{
				err=500;
				while((IN==1)&&(err>0))		 //�ȴ�4.5ms����ʼ�ߵ�ƽ��ȥ
				{
					DelayMs(1);
					err--;
				}
				for(k=0;k<4;k++)		//����4������
				{				
					for(j=0;j<8;j++)	//����һ������
					{
	
						err=60;		
						while((IN==0)&&(err>0))//�ȴ��ź�ǰ���560us�͵�ƽ��ȥ
						{
							DelayMs(1);
							err--;
						}
						err=500;
						while((IN==1)&&(err>0))	 //����ߵ�ƽ��ʱ�䳤�ȡ�
						{
							DelayMs(1);//0.14ms
							Time++;
							err--;
							if(Time>30)
							{
								EX0=1;
								return;
							}
						}
						Value[k]>>=1;	     //k��ʾ�ڼ�������
						if(Time>=8)			//����ߵ�ƽ���ִ���565us����ô��1
						{
							Value[k]|=0x80;
						}
						Time=0;		//����ʱ��Ҫ���¸�ֵ							
					}
				}
			}
			if(Value[2]!=~Value[3])
			{
				for(j=0;j<4;j++)
				{
					Value[j]=0;
				}
				return;
			}
		}
}
void Controller_out()
{	int i,t;
	LCD_init();
    	for(i=0;i<8;i++){
			 	t=Value[2]&0x01;
				Write_dat(t+48);	
				Value[2]>>=1;	
		    }		 
		De();
		Write_com(0x01); 	
}
void  Controller_test()			   //����LCD1602 ��ʾ��ֵ��
{
    Controller_Out0_Config();
	while(1){
		Controller_out();
	}
}
int Controller_Com(){    //���� Value[2] ��ֵ 
	return Value[2];
}

void DelayMs(unsigned int x)   //0.14ms��� 0us
{
	unsigned char i;
	while(x--)
	{
		for (i = 0; i<13; i++);	
	}
}
