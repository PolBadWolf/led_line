/*
 * led_reg.cpp
 *
 * Created: 23.03.2017 20:44:05
 * Author : User
 */ 

#include "system/path.h"
#include "ws2812.h"

#define line1_len 8
sRGB line1_mass[line1_len];
WS2812* line1;

int main(void)
{
	__port(DDRB).bit7 = 1;
	line1 = new WS2812(line1_len, line1_mass, &DDRB, &PORTB, 1<<0 );
    while (1) 
    {
		__port(PORTB).bit7 = 0;
		__delay_ms(500);
		__port(PORTB).bit7 = 1;
		__delay_ms(500);
		//
		line1_mass[0] = { 255, 255, 255 };
		line1_mass[1] = { 255, 255, 255 };
		line1_mass[2] = { 000, 255, 000 };
		line1_mass[3] = { 000, 255, 000 };
		line1_mass[4] = { 255, 000, 000 };
		line1_mass[5] = { 255, 000, 000 };
		line1_mass[6] = { 000, 000, 255 };
		line1_mass[7] = { 000, 000, 255 };
		line1->Interrupt();
    }
}

