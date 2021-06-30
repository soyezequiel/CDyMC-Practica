/*
 * ej10b.c
 * Author : Ezequiel Alcayaga
 */ 

#include "TIMER.h"
#include <avr/io.h>
#include <avr/interrupt.h>
volatile uint8_t us_cumplido; //En cada interrupcion se incrementara el tiempo transcurrido en una unidad, en este caso una unidad es igual a 1us	

void TIMER0_modo_CTC_CLK_interno(){
	TCCR0A=0x02;
}

void TIMER0_preescaler_64(){ 
	TCCR0B=0x03;
}
void TIMER0_preescaler_8(){
	TCCR0B=0x02;
}
void TIMER0_no_preescaler(){
	TCCR0B=0x01;
}
long int calcular_ciclos_para_1us(){
		long int ciclos=F_CPU/1000;
		ciclos=ciclos/1000;
		ciclos/=8;
		return ciclos;
}
void TIMER0_activar_bandera_de_notificacion_en_overflow(){
	TIFR0=(1<< OCF0A);
}
void TIMER0_configurar_interrupcion_cuando_el_contador_llega_a_igualar_el_comparador(){
	TIMSK0=(1<< OCIE0A);
}
void TIMER0_interrupt_1us_init(uint8_t tiempo){
	TIMER0_modo_CTC_CLK_interno();
	TIMER0_preescaler_8();
	OCR0A=(uint8_t) calcular_ciclos_para_1us()*tiempo;  //OCR0A es el registro comparador que al igualarse con el contador se reinicia el contador
	TIMER0_activar_bandera_de_notificacion_en_overflow();
	TIMER0_configurar_interrupcion_cuando_el_contador_llega_a_igualar_el_comparador();	
}

void TIMER_retardo_us(uint8_t Tiempo_a_cumplir)
{
	TIMER0_interrupt_1us_init(Tiempo_a_cumplir);	
	sei();
	us_cumplido=1;
	while (us_cumplido){}			
}

ISR(TIMER0_COMPA_vect)	//El vector de interrupcion es la comparacion del "Canal A" del "Timer 0"
{
	us_cumplido=0;
}