#include "base_type.h"
#include "led.h"



void wy_External0(void) interrupt 0
{
	//TODO:�ⲿ�ж�INT0
}


void wy_External1(void) interrupt 2
{
	//TODO:�ⲿ�ж�INT1
}



void wy_uart(void) interrupt 4
{
	//TODO:�����ж�	   
	if(RI) // �����жϲ���
	{
		//�д������ݽ��� ,���RI��־
		RI = 0;
	}
}



void wy_External2(void) interrupt 6
{
	//TODO:�ⲿ�ж�INT2
}

void wy_External3(void) interrupt 7
{
	//TODO:�ⲿ�ж�INT3
}