#include "base_type.h"
#include "wdg.h"
#include "REG51.H"

sbit Led1 = P1^0;
sbit Led2 = P1^ 1;
sbit Led3 = P1^ 2;
sbit Led4 = P1^ 3;

void main()
{
	wy_wdg_start();
	Led1 = 0;
	Led2 = 0;
	Led3 = 0;
	Led4 = 0;
	while(1);
}

