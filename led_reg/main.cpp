/*
 * led_reg.cpp
 *
 * Created: 23.03.2017 20:44:05
 * Author : User
 */ 

#include "system/path.h"
#include "ws2812.h"


int main(void)
{
	//DDRB = 0xff;
	//PORTB = 0;
	__port(DDRB).bit7 = 1;
	//ws2812::Init();
    /* Replace with your application code */
    while (1) 
    {
		__port(PORTB).bit7 = 0;
		__delay_ms(500);
		__port(PORTB).bit7 = 1;
		__delay_ms(500);
		//ws2812::SendBit((uint8_t)1);
    }
}

