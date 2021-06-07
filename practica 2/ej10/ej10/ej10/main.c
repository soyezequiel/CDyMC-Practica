/*
 * ej10.c
 *invierte el PB0 utilizando interrupcion de TIMER 0
 *
 * Created: 6/6/2021 13:32:40
 * Author : Ezequiel alcayaga
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
volatile uint8_t cont;

int main()
{
	DDRB |= 0x01;	
	cont=0;
	//OCR0A=125;				//Comparador, cuando el contador sea igual a 125 ocurre la señal del comparador
	//TCCR0A=0x02;			//Modo CTC, clk interno, con preescalador
	TCCR0A=0x00;			//Modo Normal, CLK interno, con preescalador de 1024
	TCCR0B=0x05;
	TIFR0=0x01;				//notificacion cuando hay overflow
	
	//TIMSK0=(1<< OCIE0A);	//Habilita la interrupcion cuando el contador llega a igualar el comparador 
	TIMSK0=(1<< TOIE0);		//Habilita la interrupcion cuando el contador hace overflow
	sei();
	
	DDRC=0x00;
	DDRD=0xFF;
    while (1){
		 if(cont>=3){
			 cont=0;
			 PORTB^=0x01; // OR exclusiba el bit 0 del puerto B
		 }	
	}			//Super loop

}

	ISR(TIMER0_OVF_vect)	//El vector de interrupcion es la comparacion del "Canal A" del "Timer 0"
	{
		 cont=cont+1;		
	}