/*
 * Main.c
 *
 * Created: 10/6/2021 14:16:46
 *  Author: UNLP
 */ 

#include "TIMER.h"
#define F_CPU 8000000L
int main(void){
	DDRB=0x01;
	
	while(1){
		TIMER_retardo_us(100);
		PORTB^=0x01;
	}
	
}