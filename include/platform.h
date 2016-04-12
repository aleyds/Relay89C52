#ifndef __PLATFOEM_H__
#define __PLATFOEM_H__
#include "REG51.h"
#define STC89C52

#ifdef STC89C52
sfr WDG_REGISTER			0xe1
sbit LED0=P0^0;
sbit LED1=P0^1;
sbit LED2=P0^2;
#endif

#endif