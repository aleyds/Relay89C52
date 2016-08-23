#ifndef __PLATFOEM_H__
#define __PLATFOEM_H__
#include "REG51.H"
#define STC89C52

#ifdef STC89C52
sfr WDG_REGISTER=0xe1;//看门狗
sfr ISP_CONTR=0xe7; //ISP/IAP功能及软件复位
sbit DIS_LED0=P1^6; //LED GREEN 
sbit DIS_LED1=P1^7; //LED RED	 


sbit KEYBOARD_T1=P2^0; //按键1
sbit KEYBOARD_T2=P2^1; //按键2
sbit KEYBOARD_T3=P2^2; //按键3
sbit KEYBOARD_T4=P2^3; //按键4
sbit KEYBOARD_T5=P2^4; //按键5
sbit KEYBOARD_T6=P2^5; //按键6


sbit START_VDET=P3^3; //开始检测传感器控制信号
sbit SONSER_VDET=P1^5;//传感器检测端口，低电平说明有电机转动
sbit RELAY_CONTROL=P3^4;//电源
#endif

#endif
