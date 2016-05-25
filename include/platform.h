#ifndef __PLATFOEM_H__
#define __PLATFOEM_H__
#include "REG51.H"
#define STC89C52

#ifdef STC89C52
sfr WDG_REGISTER=0xe1;//看门狗
sfr ISP_CONTR=0xe7; //ISP/IAP功能及软件复位
sbit DIS_LED0=P1^3; //LED GREEN  P1^3
sbit DIS_LED1=P1^4; //LED RED	 P1^4
sbit DIS_LED2=P1^2;
/*
sbit KEYBOARD_T1=P1^0; //按键1
sbit KEYBOARD_T2=P1^1; //按键2
sbit KEYBOARD_T3=P1^5; //按键3
sbit KEYBOARD_T4=P1^6; //按键4
sbit KEYBOARD_T5=P1^7; //按键5
sbit KEYBOARD_T6=P3^3; //按键6
sbit KEYBOARD_T7=P3^4; //按键7
sbit KEYBOARD_T8=P2^7; //按键8
sbit KEYBOARD_T9=P2^6; //按键9
sbit KEYBOARD_T10=P2^5; //按键10
sbit KEYBOARD_T11=P2^4; //按键11
sbit KEYBOARD_T12=P2^3; //按键12
sbit KEYBOARD_T13=P2^2; //按键13
sbit KEYBOARD_T14=P2^1; //按键14
sbit KEYBOARD_T15=P2^0; //按键15*/
sbit KEYBOARD_T1=P2^0; //按键1
sbit KEYBOARD_T2=P2^1; //按键2
sbit KEYBOARD_T3=P2^2; //按键3
sbit KEYBOARD_T4=P2^3; //按键4
sbit KEYBOARD_T5=P2^4; //按键5
sbit KEYBOARD_T6=P2^5; //按键6


sbit START_VDET=P0^4; //开始检测传感器控制信号
sbit SONSER_VDET=P0^5;//传感器检测端口，低电平说明有电机转动
sbit RELAY_CONTROL=P2^7;//电源开�
#endif

#endif