#include"base_type.h"
#include "timer.h"
#include "led.h"
#include "tools.h"

#define TH0HIGHT		(0x1A)   //16MHz����  ��ʽ0 ��ʱ1ms
#define TH0LOW			(0xCB)

struct TimerSt{
	H_U32 init;
	H_U32 counter;
	TimerCallback call;
};

typedef struct TimerManage{
	struct TimerSt timer0;
}_TimerManage_t;

static _TimerManage_t g_timer_manage;

/*
static void _Timer0Callback(void)
{
	wy_led_display(_LED_0, H_TRUE);
	wy_delay(500);
	wy_led_display(_LED_0, H_FAUSE);
}
*/

void wy_timer0(void) interrupt 1
{
	TH0 = TH0HIGHT; //(8192-N)/32  N=t(us)/(12*1/����Ƶ��Hz) ���ö�ʱ��0��ֵ 5ms
	TL0 = TH0LOW;	//(8192-N)%32
	//TODO:��ʱ��T0�ж�
	if(g_timer_manage.timer0.counter == 0)
	{
		g_timer_manage.timer0.counter = g_timer_manage.timer0.init;
		if(g_timer_manage.timer0.call != H_NULL)
		{
			g_timer_manage.timer0.call();
		
		}
	}
	g_timer_manage.timer0.counter--;
}

static void _Timer0Open(H_U32 ms, TimerCallback call)
{
	TR0=0;//�ȹرն�ʱ��0
	TMOD = 0x00;//��ʱ�������ڷ�ʽ0
	TH0 = TH0HIGHT; //���ö�ʱ��0��ֵ 5ms
	TL0 = TH0LOW;
	ET0=1;//������ʱ��0�ж�
	TR0=1;//������ʱ��0
	g_timer_manage.timer0.init = ms;
	g_timer_manage.timer0.counter = g_timer_manage.timer0.init;
	g_timer_manage.timer0.call = call;
}



static void _Timer0Close(void)
{
	TR0=0;//�ȹرն�ʱ��0
}

H_U32 wy_timer_open(_TimerType_e type, H_U32 time, TimerCallback call)
{
	switch(type)
	{
		case _TIMER0:
			_Timer0Open(time,call);
			break;
		default:
			break;
	}
	return H_SUCCESS;
}

H_U32 wy_timer_close(_TimerType_e type)
{
	switch(type)
	{
		case _TIMER0:
			_Timer0Close();
			break;
		default:
			break;
	}
	return H_SUCCESS;
}