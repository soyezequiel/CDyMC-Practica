//Incluciones
#include <avr/io.h>
#include <stdlib.h>
//Definiciones
#ifndef F_CPU
#define F_CPU 8000000L
#endif
#define resetCounterOn OCR1A
#define F_min 100
#define F_max 10000
#define F_defecto 6435

#define PORT PORTD
#define DDR DDRD
#define pin 2;

/*******************************************************************************************************************
Este "objeto" permite administrar una onda cuadrada, generada por el TIMER1,
esta onda es tiene una salida por el bit1 del puerto B, también llamado OC1A, del atmega328P
*******************************************************************************************************************/

//funciones públicas
void TIMER1_set_module(); //Configuración inicial del Timer1
uint8_t TIMER1_set_tiempo(uint8_t tiempo );// recibe la frecuencia por string que tendra la onda generada por el timer1, retorna 1 si esta entre 100 y 10000, 0 en caso contrario
void TIMER1_set_on(); //Al invocarse la función, comienza a producir un sonido.
void TIMER1_set_off(); //Al invocarse la función, parar de reproducir un sonido.
void TIMER1_reset_module(); //Deja de reproducir sonido y setea la frecuencia en la frecuencia por defecto.