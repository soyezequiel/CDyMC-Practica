/*
 * ej10.c
 *invierte el PB0 utilizando interrupcion de TIMER 0
 *
 * Created: 6/6/2021 13:32:40
 * Author : Ezequiel alcayaga
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int main()
{
	DDRB |= 0x20;	
	
	OCR0A=125;				//Comparador, cuando el contador sea igual a 125 ocurre la señal del comparador
	TCCR0A=0x02;			//Modo CTC, clk interno, con preescalador
	TCCR0B=0x03;
	
	TIMSK0=(1<< OCIE0A);	//Habilita la interrupcion cuando el contador llega a igualar el comparador 
	sei();
	
	DDRC=0x00;
	DDRD=0xFF;
    while (1){}			//Super loop

}

	ISR(TIMER0_COMPA_vect)	//El vector de interrupcion es la comparacion del "Canal A" del "Timer 0"
	{
		PORTB^= 0x01;		// OR exclusiba el bit 0 del puerto B
	}