#ifndef __PLATFOEM_H__
#define __PLATFOEM_H__
#include "REG51.H"
#define STC89C52

#ifdef STC89C52
sfr WDG_REGISTER=0xe1;
sbit DIS_LED0=P1^0;
sbit DIS_LED1=P1^1;
sbit DIS_LED2=P1^2;
#endif

#endif