/*
 * Author : Ezequiel alcayaga
 * funciona correctamente con una frecuencia de clock de 8Mhz
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer0.h"

int main()
{
	TIMER0_init_10hz();
}

