#include "base_type.h"
#include "keyboard.h"
#include "platform.h"

#define KEYVALUE_MASK		(0x1F) //P2口低五位

H_U32 _KeyBoardTime(void)
{
	H_U8 KeyValue = 0;
	H_U32 OutTime = 0;
	
	KeyValue = P2&KEYVALUE_MASK;
	if(!(KeyValue&0x1))
	{
		OutTime += 100;
	}
	if(!(KeyValue&0x02))
	{
		OutTime += 200;
	}
	if(!(KeyValue&0x04))
	{
		OutTime += 300;
	}
	if(!(KeyValue&0x08))
	{
		OutTime += 400;
	}
	if(!(KeyValue&0x10))
	{
		OutTime += 500;
	}
	if(!(KeyValue&0x20))
	{
		OutTime += 600;
	}
	return ((OutTime == 0)?100:OutTime);
}

/*
static KeyBoard_Type _KeyBoardScan(void)
{
	KeyBoard_Type _KeyType = _KEYBOARD_MAX;
	
	if(KEYBOARD_T1&0x1)
	{
		_KeyType = _KEYBOARD_T1;
	}else if(KEYBOARD_T2&0x1)
	{
		_KeyType = _KEYBOARD_T2;
	}else if(KEYBOARD_T3&0x1)
	{
		_KeyType = _KEYBOARD_T3;
	}else if(KEYBOARD_T4&0x1)
	{
		_KeyType = _KEYBOARD_T4;
	}else if(KEYBOARD_T5&0x1)
	{
		_KeyType = _KEYBOARD_T5;
	}else if(KEYBOARD_T6&0x1)
	{
		_KeyType = _KEYBOARD_T6;
	}else if(KEYBOARD_T7&0x1)
	{
		_KeyType = _KEYBOARD_T7;
	}else if(KEYBOARD_T8&0x1)
	{
		_KeyType = _KEYBOARD_T8;
	}else if(KEYBOARD_T9&0x1)
	{
		_KeyType = _KEYBOARD_T9;
	}else if(KEYBOARD_T10&0x1)
	{
		_KeyType = _KEYBOARD_T10;
	}else if(KEYBOARD_T11&0x1)
	{
		_KeyType = _KEYBOARD_T11;
	}else if(KEYBOARD_T12&0x1)
	{
		_KeyType = _KEYBOARD_T12;
	}else if(KEYBOARD_T13&0x1)
	{
		_KeyType = _KEYBOARD_T13;
	}else if(KEYBOARD_T14&0x1)
	{
		_KeyType = _KEYBOARD_T14;
	}else if(KEYBOARD_T15&0x1)
	{
		_KeyType = _KEYBOARD_T15;
	}
	return _KeyType;
}

*/
