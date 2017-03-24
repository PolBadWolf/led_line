/* 
* ws2812.cpp
*
* Created: 23.03.2017 22:05:05
* Author: User
*/


#include "ws2812.h"

#define WS2812_Hi	*port |=  pMask
#define WS2812_Lo	*port &= ~pMask
#define WS2812_Tg	*port ^=  pMask

#define __delay_us10(x)	__builtin_avr_delay_cycles(C_Fosc * x / 1e7)


WS2812::WS2812(uint8_t len, sRGB* mass, volatile uint8_t* ddr, volatile uint8_t* port, uint8_t mask)
{
	this->lenLine = len;
	this->mass = mass;
	pMask = mask;
	this->port = port;
	//
	*ddr |= pMask;
	WS2812_Hi;
}

void WS2812::Reset()
{
	WS2812_Lo;
	__delay_us(50);
}

void WS2812::Interrupt()
{
	CRITICAL_SECTION
	{
		Reset();
		uint8_t* mm = (uint8_t *)mass;
		for (uint8_t i=0; i<lenLine*3; i++)
		{
			uint8_t mask = 1<<7;
			while (mask)
			{
				if ( *mm & mask)
				{
					WS2812_Hi;
					mask >>= 1;
					__delay_us10(6);
					WS2812_Tg;
				}
				else
				{
					WS2812_Hi;
					WS2812_Tg;
					mask >>= 1;
				}
			}
			mm++;
		}
		WS2812_Hi;
	}
}
