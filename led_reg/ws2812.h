/* 
* ws2812.h
*
* Created: 23.03.2017 22:05:05
* Author: User
*/


#ifndef __WS2812_H__
#define __WS2812_H__
#include "system/path.h"

typedef struct 
{
	unsigned green : 8;
	unsigned red   : 8;
	unsigned blue  : 8;
} sRGB;

class WS2812
{
public:
	WS2812(uint8_t len, sRGB* mass, volatile uint8_t* ddr, volatile uint8_t* port, uint8_t mask);
	void Interrupt();
	uint8_t lenLine;
private:
	sRGB* mass;
	volatile uint8_t* port;
	uint8_t pMask;
	void Reset();
};


#endif //__WS2812_H__
