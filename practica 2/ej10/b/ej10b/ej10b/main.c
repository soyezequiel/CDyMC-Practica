/*
 * ej10b.c
 *
 * Created: 8/6/2021 12:48:45
 * Author : UNLP
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
volatile uint8_t ms_transcurridos;

void TIMER0_init(){
	//Configuracion del TIMER0
	//Registros de configuracion
	TCCR0A=0x02;			//Modo CTC, clk interno
	//TCCR0A=0x00;			//Modo Normal, CLK interno, con preescalador de 1024
	TCCR0B=0x03;			// con preescalador en 64
	
	//registro de comparacion
	//OCR0A=125;				//Comparador, cuando el contador sea igual a 125 ocurre la señal del comparador; esto me generara una interrupcion cada 1 milisegundo
	
	OCR0A=124;				//use con 124 ciclos porque el lo que en la practica me dio mejores resultados
	
	//Bandera de notificacion
	TIFR0=(1<< OCF0A);				//notificacion cuando hay overflow
	
	//Configuracion de interrupciones
	TIMSK0=(1<< OCIE0A);	//Habilita la interrupcion cuando el contador llega a igualar el comparador
	//TIMSK0=(1<< TOIE0);		//Habilita la interrupcion cuando el contador hace overflow
}

void retardo(uint8_t Tiempo_a_cumplir)
{
	
	ms_transcurridos=0;
	TIMER0_init();	
	sei();
	while (ms_transcurridos < Tiempo_a_cumplir ){}			
	
}
int main()
{
	DDRB=0x01;
	while(1){
		retardo(255);
		PORTB^=0x01; // OR exclusiba el bit 0 del puerto B
	} //super loop
	

}
/*
ISR(TIMER0_OVF_vect)	//El vector de interrupcion es cuando el canal A tiene overflow
{
	cont=cont+1;
}
*/
ISR(TIMER0_COMPA_vect)	//El vector de interrupcion es la comparacion del "Canal A" del "Timer 0"
{
	ms_transcurridos+=1;
}