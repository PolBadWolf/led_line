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
	ws2812::Init();
    /* Replace with your application code */
    while (1) 
    {
		//ws2812::SendBit((uint8_t)1);
    }
}

