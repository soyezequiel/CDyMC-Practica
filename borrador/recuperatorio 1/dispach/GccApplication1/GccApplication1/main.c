/*
 * GccApplication1.c
 *
 * Created: 14/7/2021 14:41:43
 * Author : Alcayaga Ezequiel
 */ 

#include <avr/io.h>
#include "TT.h"
void main(void)
{
	// Inicializar MCU, RTC, y tareas
	while(1) {
		SEOS_Dispatch_Tasks();
		SEOS_Go_To_Sleep();
	}
