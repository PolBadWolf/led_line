/*
 * path.h
 *
 * Created: 27.08.2016 19:56:54
 *  Author: User
 */ 

#ifndef PATH_H_
#define PATH_H_

#include <avr/io.h>
//#include <avr/pgmspace.h>
//#include <avr/eeprom.h>
#include <util/atomic.h>
#include <stddef.h>
#include <stdio.h>

//#include "path_mega128.h"

#define C_Fosc 8000000

typedef struct
{
	unsigned bit0:1;
	unsigned bit1:1;
	unsigned bit2:1;
	unsigned bit3:1;
	unsigned bit4:1;
	unsigned bit5:1;
	unsigned bit6:1;
	unsigned bit7:1;
} BYTE_BITFIELD;

typedef struct
{
	unsigned Low:4;
	unsigned High:4;
} BYTE_TETRA;

#define __delay_ms(__ms) __builtin_avr_delay_cycles(((C_Fosc) / 1e3) * __ms)
#define __delay_us(__us) __builtin_avr_delay_cycles(((C_Fosc) / 1e6) * __us)

#define  CRITICAL_SECTION ATOMIC_BLOCK(ATOMIC_RESTORESTATE)

#define __port(x) (*((volatile BYTE_BITFIELD*)(&x)))
void *operator new(size_t);
void *operator new[](size_t);

void operator delete(void *);
void operator delete[](void *);
//*****************************

#endif /* PATH_H_ */
