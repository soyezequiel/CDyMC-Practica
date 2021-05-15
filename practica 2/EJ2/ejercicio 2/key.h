#include <avr/io.h>
#include "lcd.h"

#define DDR DDRD
#define puerto PORTD
#define puerto_lectura PIND
#define parteEntrada 0x0F
#define parteSalida 0xF0

#define F_CPU 8000000L
#include <util/delay.h>

uint8_t KEYPAD_Update (uint8_t *pkey); // devuelve el ascii tecleado ferificando que no se repita cuando se mantiene precionada la tecla