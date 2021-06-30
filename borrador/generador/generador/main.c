#include <avr/io.h>
#include "Timer1.h"
#include <stdio.h>
#include <util/delay.h>
 /* Test se probara todas las frecuencias porque si */
 /*
void testTodasLasFrecuencias(){
	TIMER1_set_module();		
	uint16_t frecuencia=90;
	char frecuenciaStr[2];
	TIMER1_set_on();
	while (1)
	{	
		sprintf(frecuenciaStr, "%u", frecuencia++);
		TIMER1_set_frequency(frecuenciaStr);
		_delay_ms(100);
	}
}
*/
 /* Test sonido policia */
 /*
 void testPolicia(){
	 TIMER1_set_module();
	 int direccion=1;
	 uint16_t frecuencia=200;
	 char frecuenciaStr[2];
	 TIMER1_set_on();
	 while (1)
	 {
		 sprintf(frecuenciaStr, "%u", frecuencia);
		 if (frecuencia==2000){direccion=-1;}
		 if (frecuencia==1000){ direccion=1;} 
				  
			frecuencia+=direccion;
		 TIMER1_set_frequency(frecuenciaStr);
		 _delay_ms(1);
	 }
 }
 */
/* Test mSe probara una  frecuencias recibida por valor*/
void testUnaFrecuencia(uint16_t frecuencia){
	TIMER1_set_module();
//	char text[2];
	//sprintf(text, "%u", frecuencia);
	TIMER1_set_tiempo(frecuencia);
	TIMER1_set_on();
	//while (1);
}
int main(void)
{
	//testTodasLasFrecuencias();
	//testPolicia();
	testUnaFrecuencia(100);
}

