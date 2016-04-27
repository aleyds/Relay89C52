#ifndef __PLATFOEM_H__
#define __PLATFOEM_H__
#include "REG51.H"
#define STC89C52

#ifdef STC89C52
sfr WDG_REGISTER=0xe1;//看门狗
sfr ISP_CONTR=0xe7; //ISP/IAP功能及软件复位
sbit DIS_LED0=P1^0;
sbit DIS_LED1=P1^1;
sbit DIS_LED2=P1^2;
sbit KEYBOARD_T1=P1^1 //按键0
sbit KEYBOARD_T2=P1^2 //按键0
sbit KEYBOARD_T3=P1^2 //按键0
sbit KEYBOARD_T4=P1^2 //按键0
sbit KEYBOARD_T5=P1^2 //按键0
sbit KEYBOARD_T6=P1^2 //按键0
sbit KEYBOARD_T7=P1^2 //按键0
sbit KEYBOARD_T8=P1^2 //按键0
sbit KEYBOARD_T9=P1^2 //按键0
sbit KEYBOARD_T10=P1^2 //按键0
sbit KEYBOARD_T11=P1^2 //按键0
sbit KEYBOARD_T12=P1^2 //按键0
sbit KEYBOARD_T13=P1^2 //按键0
sbit KEYBOARD_T14=P1^2 //按键0
sbit KEYBOARD_T15=P1^2 //按键0
#endif

#endif