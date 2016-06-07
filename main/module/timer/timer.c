#include"base_type.h"
#include "timer.h"
#include "led.h"
#include "tools.h"

#define TH0HIGHT		(0x1A)   //16MHz晶振  方式0 定时1ms
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
	TH0 = TH0HIGHT; //(8192-N)/32  N=t(us)/(12*1/晶振频率Hz) 设置定时器0初值 5ms
	TL0 = TH0LOW;	//(8192-N)%32
	//TODO:定时器T0中断
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
	TR0=0;//先关闭定时器0
	TMOD = 0x00;//定时器工作在方式0
	TH0 = TH0HIGHT; //设置定时器0初值 5ms
	TL0 = TH0LOW;
	ET0=1;//开启定时器0中断
	TR0=1;//开启定时器0
	g_timer_manage.timer0.init = ms;
	g_timer_manage.timer0.counter = g_timer_manage.timer0.init;
	g_timer_manage.timer0.call = call;
}



static void _Timer0Close(void)
{
	TR0=0;//先关闭定时器0
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