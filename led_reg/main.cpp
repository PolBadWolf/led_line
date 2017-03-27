/*
 * led_reg.cpp
 *
 * Created: 23.03.2017 20:44:05
 * Author : User
 */ 

#include "system/path.h"
#include "ws2812.h"

#define line1_len 18
sRGB line1_mass[line1_len];
WS2812* line1;

int main(void)
{
	//__port(DDRB).bit7 = 1;
	line1 = new WS2812(line1_len, line1_mass, &DDRB, &PORTB, 1<<1 );
    while (1) 
    {
		//__port(PORTB).bit7 = 0;
		//__delay_ms(500);
		//__port(PORTB).bit7 = 1;
		//__delay_ms(500);
		//
		line1_mass[ 0] = { 255, 000, 000 };
		line1_mass[ 1] = { 000, 255, 000 };
		line1_mass[ 2] = { 000, 000, 255 };
		line1_mass[ 3] = { 255, 255, 000 };
		line1_mass[ 4] = { 255, 000, 255 };
		line1_mass[ 5] = { 000, 255, 255 };
		line1_mass[ 6] = { 128, 128, 128 };
		line1_mass[ 7] = { 064, 255, 128 };
		line1_mass[ 8] = { 255, 000, 000 };
		line1_mass[ 9] = { 000, 255, 000 };
		line1_mass[10] = { 255, 000, 000 };
		line1_mass[11] = { 000, 255, 000 };
		line1_mass[12] = { 255, 000, 000 };
		line1_mass[13] = { 000, 255, 000 };
		line1_mass[14] = { 255, 000, 000 };
		line1_mass[15] = { 000, 255, 000 };
		line1_mass[16] = { 128, 255, 128 };
		line1->Interrupt();
    }
}

