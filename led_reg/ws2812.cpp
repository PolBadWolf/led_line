/* 
* ws2812.cpp
*
* Created: 23.03.2017 22:05:05
* Author: User
*/


#include "ws2812.h"

#define WS2812_Data_DDR  __port(DDRB).bit1
#define WS2812_Data_PORT __port(PORTB).bit1

#define WS2812_Hi	WS2812_Data_PORT=1
#define WS2812_Lo	WS2812_Data_PORT=0
#define WS2812_In	WS2812_Data_PORT=1-WS2812_Data_PORT

#define delayLong	__builtin_avr_delay_cycles(C_Fosc * 8 / 1e7)
#define delaySmall	__builtin_avr_delay_cycles(C_Fosc * 5 / 1e7)

namespace ws2812
{
	//
	void SendByte(uint8_t byte)
	{
		uint8_t mask = 1 << 7;
		for (uint8_t i=0; i<8; i++)
		{
			if (byte & mask)
			{
				WS2812_Hi;
				delayLong;
				WS2812_Lo;
				delaySmall;
			}
			else
			{
				WS2812_Hi;
				delaySmall;
				WS2812_Lo;
				delayLong;
			}
			mask >>= 1;
		}
	}
	void SendObj(uint8_t r, uint8_t g, uint8_t b)
	{
		SendByte(g);
		SendByte(r);
		SendByte(b);
	}
	// ======================
	void Init()
	{
		WS2812_Data_PORT = 1;
		WS2812_Data_DDR = 1;
		//
		for (uint8_t i=0; i<256; i++)
			SendObj(i, i, i);
		SendByte(11);
	}
}