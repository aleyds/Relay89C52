#include "base_type.h"
#include "wdg.h"
#include "led.h"
#include "intrins.h"
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


void Delay1us()		//@11.0592MHz
{
	_nop_();
	_nop_();
	_nop_();
}


void Delay1ms()		//@11.0592MHz
{
	unsigned char i, j;

	_nop_();
	_nop_();
	_nop_();
	i = 11;
	j = 190;
	do
	{
		while (--j);
	} while (--i);
}

void Delayms(int ms){
	while(ms--){
		Delay1ms();
	}
}

void wy_SysReset(void)
{
	PCON = PCON & 0xef;
	ISP_CONTR = 0x60;
}

static void _InterruptOpen(void)
{
	EA=1;
}

static void displayGreenLed(H_U8 status)
{
	if(status)
	{
		DIS_LED0 = 0;
	}else
	{
		DIS_LED0 = 1;
	}
}

static void displayRedLed(H_U8 status)
{
	if(status)
	{
		DIS_LED1 = 0;
	}else
	{
		DIS_LED1 = 1;
	}
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
		displayRedLed(1);
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
	displayGreenLed(1);//电源指示灯,绿色
	displayRedLed(0);//继电器指示灯，关
	//RELAY_CONTROL=1;
	while(1)
	{
		
		if(!(START_VDET&0x1) && (g_StartSonser == 0))//检测开始信号后开始检测传感器信号
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

