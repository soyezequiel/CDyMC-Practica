/*
 * MefAntiRebote.c
 *
 * Created: 16/6/2021 13:48:50
 * Author : UNLP
 */ 

#include <avr/io.h>
#include "button.h"
#define F_CPU 8000000L
#include <util/delay.h>

void encender_Led(){
	PORTB|=(1<<PB2);
}
void apagar_Led(){
	PORTB&=~(1<<PB2);
}

int main(void)
{
    BUTTON_Init();
    while (1) 
    {
		
		DDRB|=(1<<PB2);
		BUTTON_Update();
		if(BUTTON_Presionado()){
			encender_Led();
		}else {
			apagar_Led();
		}
		_delay_ms(1);
		
    }
}

