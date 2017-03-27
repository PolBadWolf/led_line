/* 
* ws2812.cpp
*
* Created: 23.03.2017 22:05:05
* Author: User
*/


#include "ws2812.h"

#define WS2812_Hi	PORTB |=  (1<<0)
#define WS2812_Lo	PORTB &= ~(1<<0)
#define WS2812_Tg	PORTB ^=   1<<0)

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
	__delay_us(100);
}

#define  SENDBIT { WS2812_Hi;  __delay_us10(3); WS2812_Lo; } else { WS2812_Hi; WS2812_Lo; }

void WS2812::Interrupt()
{
	CRITICAL_SECTION
	{
		uint8_t mG, mR, mB;
		for (uint8_t i=0; i<lenLine; i++)
		{
			mG = mass[i].green;
			mR = mass[i].red;
			mB = mass[i].blue;
			//
			if ( mG & (1<<7) ) SENDBIT
			if ( mG & (1<<6) ) SENDBIT
			if ( mG & (1<<5) ) SENDBIT
			if ( mG & (1<<4) ) SENDBIT
			if ( mG & (1<<3) ) SENDBIT
			if ( mG & (1<<2) ) SENDBIT
			if ( mG & (1<<1) ) SENDBIT
			if ( mG & (1<<0) ) SENDBIT
			//
			if ( mR & (1<<7) ) SENDBIT
			if ( mR & (1<<6) ) SENDBIT
			if ( mR & (1<<5) ) SENDBIT
			if ( mR & (1<<4) ) SENDBIT
			if ( mR & (1<<3) ) SENDBIT
			if ( mR & (1<<2) ) SENDBIT
			if ( mR & (1<<1) ) SENDBIT
			if ( mR & (1<<0) ) SENDBIT
			//
			if ( mB & (1<<7) ) SENDBIT
			if ( mB & (1<<6) ) SENDBIT
			if ( mB & (1<<5) ) SENDBIT
			if ( mB & (1<<4) ) SENDBIT
			if ( mB & (1<<3) ) SENDBIT
			if ( mB & (1<<2) ) SENDBIT
			if ( mB & (1<<1) ) SENDBIT
			if ( mB & (1<<0) ) SENDBIT
		}
		Reset();
		//WS2812_Hi;
	}
}
