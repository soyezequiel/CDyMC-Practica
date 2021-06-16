/*
 * semaforo.c
 *
 * Created: 16/6/2021 11:02:34
 * Author : UNLP
 */ 


#include "semaforo.h"
#define F_CPU 8000000L
#include <util/delay.h>


int main(void)
{
	TRAFIC_LIGHT_Init(RED); //inicializa la MEF
	while(1){
		TRAFIC_LIGHT_Update();
		_delay_ms(1000);
	}
}

