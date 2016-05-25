#include"base_type.h"
#include "timer.h"
#include "led.h"
#include "tools.h"

struct TimerSt{
	H_U16 init;
	H_U16 counter;
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
	TH0=(8192-6666)/32; //(8192-N)/32  N=t(us)/(12*1/����Ƶ��Hz) ���ö�ʱ��0��ֵ 5ms
	TL0=(8192-6666)%32;	//(8192-N)%32
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

void wy_timer1(void) interrupt 3
{
	//TODO:��ʱ��T1�ж�
}

void wy_timer2(void) interrupt 5
{
	//TODO:��ʱ��T2�ж�
}

static void _Timer0Open(H_U32 ms, TimerCallback call)
{
	TR0=0;//�ȹرն�ʱ��0
	TMOD=0x00;//��ʱ�������ڷ�ʽ0
	TH0=(8192-6666)/32; //���ö�ʱ��0��ֵ 5ms
	TL0=(8192-6666)%32;
	ET0=1;//������ʱ��0�ж�
	TR0=1;//������ʱ��0
	g_timer_manage.timer0.init = ms/5;
	g_timer_manage.timer0.counter = g_timer_manage.timer0.init;
	g_timer_manage.timer0.call = call;
}

static void _Timer1Open(H_U32 ms)
{
	
}

static void _Timer2Open(H_U32 ms)
{
	
}

static void _Timer0Close(void)
{
	TR0=0;//�ȹرն�ʱ��0
}

static void _Timer1Close(void)
{
	
}

static void _Timer2Close(void)
{
	
}


H_U32 wy_timer_open(_TimerType_e type, H_U32 time, TimerCallback call)
{
	switch(type)
	{
		case _TIMER0:
			_Timer0Open(time,call);
			break;
		case _TIMER1:
			_Timer1Open(time);
			break;
		case _TIMER2:
			_Timer2Open(time);
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
		case _TIMER1:
			_Timer1Close();
			break;
		case _TIMER2:
			_Timer2Close();
			break;
		default:
			break;
	}
	return H_SUCCESS;
}