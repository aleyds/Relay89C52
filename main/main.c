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
	if((SONSER_VDET&0x1))//传感器信号为高电平
	{
		//TODO:无电机转动，断开继电器停止向工控板供电
		RELAY_CONTROL=0;
		wy_led_display(_LED_1, H_TRUE);
		
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
	//Step2:wait check click
	wy_led_display(_LED_0,H_TRUE);//电源指示灯,绿色
	wy_led_display(_LED_1, H_FAUSE);//继电器指示灯，关
	//RELAY_CONTROL=1;
	while(1)
	{
		/*
		wy_delay(1000);
		wy_led_display(_LED_1, H_TRUE);
		wy_delay(1000);
		wy_led_display(_LED_1, H_FAUSE);
		continue;
   */

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
//Test Main function
void main()
{
	//wy_wdg_start();
	wy_led_display(_LED_1, H_TRUE);
	//wy_led_display(_LED_1, H_TRUE);
	//wy_led_display(_LED_2, H_TRUE);
	//_InterruptOpen();
	//wy_timer_open(_TIMER0,10000);
	_LEDTest();
	while(1)
	{
		
		//wy_delay(1000);
		
		//Led1=1;
		//wy_led_display(_LED_1, H_FAUSE);
		//wy_delay(1000);
		//wy_SysReset();
		//wy_led_display(_LED_1, H_FAUSE);
		//wy_led_display(_LED_2, H_FAUSE);
	}
}
#endif

