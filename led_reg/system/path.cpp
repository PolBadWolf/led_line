/*
 * path.cpp
 *
 * Created: 27.08.2016 20:00:31
 *  Author: User
 */ 

#include "path.h"
#include <stdlib.h>
#include <avr/interrupt.h>

void *operator new(size_t s)
{
 return malloc(s);
}

void *operator new[](size_t s)
{
 return malloc(s);
}

void operator delete(void *m)
{
 free(m);
}

void operator delete[](void *m)
{
 free(m);
}

