#include "base_type.h"
#include "wdg.h"
#include "led.h"
#include "tools.h"
#include "timer.h"
#include "keyboard.h"
#include "REG51.H"

sbit Led1 = P1^0;
sbit Led2 = P1^ 1;
sbit Led3 = P1^ 2;
sbit Led4 = P1^ 3;

static char g_StartSonser = 0;

#define SONNER_TRIGGER			(10)
static char g_SonserSatausLow = 0;
static char g_SonserStatusHi = 0;


static void _InterruptOpen(void)
{
	EA=1;
}

static void _InterruptClose(void)
{
	EA=0;
}

static void _Timer0Callback(void)
{
	if(!(SONSER_VDET&0x1))//传感器信号为低电平
	{
		//TODO:无电机转动，断开继电器停止向工控板供电
		g_SonserSatausLow++;
		g_SonserStatusHi = 0;
		RELAY_CONTROL=0;
		
	}else if((SONSER_VDET&0x1))
	{
		g_SonserStatusHi++;
		g_SonserSatausLow = 0;
	}
	
	if((g_SonserStatusHi > SONNER_TRIGGER) || (g_SonserSatausLow > SONNER_TRIGGER))
	{
		wy_led_display(_LED_1, H_TRUE);
		wy_timer_close(_TIMER0);
		g_SonserStatusHi = 0;
		g_SonserSatausLow = 0;
	}
}

#if 1
//Project running Main
void main()
{
	
	H_U32 CheckTime = 0;
	H_U32 CurrentCheckTime = 0;
	H_U32 TimerTime = 0;
	
	//Step1:Interrupt Init 
	_InterruptOpen();
	
	if((PCON&0x10) != 0)
	{
		wy_SysReset();
		
	}else
	{
		PCON = 	PCON | 0x10;
	}
	//Step2:wait check click
	wy_led_display(_LED_0,H_TRUE);//电源指示灯,绿色
	wy_led_display(_LED_1, H_FAUSE);//继电器指示灯，关
	//RELAY_CONTROL=1;
	while(1)
	{
		
		if(!(START_VDET&0x1))//检测开始信号后开始检测传感器信号
		{
			g_StartSonser = 1;
		
		}

		if(g_StartSonser == 1)
		{
			CheckTime = _KeyBoardTime();
			if(CurrentCheckTime != CheckTime)
			{
				CurrentCheckTime = CheckTime;
				wy_timer_close(_TIMER0);
				wy_timer_open(_TIMER0, CheckTime, _Timer0Callback);
			}
		}
		
		
	}
}

#else

#endif

