#include "base_type.h"
#include "wdg.h"
#include "led.h"
#include "tools.h"
#include "timer.h"
#include "REG51.H"

sbit Led1 = P1^0;
sbit Led2 = P1^ 1;
sbit Led3 = P1^ 2;
sbit Led4 = P1^ 3;

static void _InterruptOpen(void)
{
	EA=1;
}

static void _InterruptClose(void)
{
	EA=0;
}

void main()
{
	//wy_wdg_start();
	wy_led_display(_LED_0, H_TRUE);
	//wy_led_display(_LED_1, H_TRUE);
	//wy_led_display(_LED_2, H_TRUE);
	//_InterruptOpen();
	//wy_timer_open(_TIMER0,10000);
	while(1)
	{
		wy_delay(1000);
		//Led1=1;
		wy_led_display(_LED_0, H_FAUSE);
		wy_delay(1000);
		wy_SysReset();
		//wy_led_display(_LED_1, H_FAUSE);
		//wy_led_display(_LED_2, H_FAUSE);
	}
}

