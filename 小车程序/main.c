#include "Config.c"
int temp,e;
int PWM_flag;
unsigned char Value[6];
void DelayMs(unsigned int x);
int i,t;
void main()
{	
	LCD_init();
	Time0_Config();
	T=0;
Write_dat('5');		Write_dat('5');

}


void Time0() interrupt 1
{
	TH0=0XFF;
	TL0=0XFE;
	PWM_flag==1?PWM_Left(30):PWM_Right(30);  //��PWM_flagΪ1����ת  0��ת
	temp++;
	if(temp==200){
		temp=0;
	}	
}
void Chao_Time0() interrupt 3	  
{
	TH1=0;
	TL1=0;
}

void res() interrupt 0
{
		unsigned char j,k;
		unsigned int err;
		e=0;					 
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
							e++;
							err--;
							if(e>30)
							{
								EX0=1;
								return;
							}
						}
						Value[k]>>=1;	     //k��ʾ�ڼ�������
						if(e>=8)			//����ߵ�ƽ���ִ���565us����ô��1
						{
							Value[k]|=0x80;
						}
						e=0;		//����ʱ��Ҫ���¸�ֵ							
					}
				}
			}
			if(Value[2]!=~Value[3])
			{
				Write_dat('x');
				return;
			}
		}			
	}







