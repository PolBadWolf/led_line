/* 
* TIMER0.cpp
*
* Created: 25.03.2017 15:40:14
* Author: User
*/


#include "TIMER0.h"
#include "system/path.h"
#include "avr/interrupt.h"

namespace ns_timer0
{
	void Init()
	{
		//TCCR0 = 0;
		//TCCR0 &= ~(1<<WGM10)
	}
	/*ISR (TIMER0_OVF_vect)
	{
	}*/
}
