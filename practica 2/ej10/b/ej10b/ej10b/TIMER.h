/*
 * CFile1.c
 *
 * Created: 10/6/2021 14:09:16
 *  Author: UNLP
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#ifndef F_CPU
#define F_CPU 8000000L
#endif
void TIMER_retardo_ms(uint8_t Tiempo_a_cumplir); //Genera un retardo de x mili segundos