
#include <avr/io.h>
/* Inclusión de bibliotecas de código */
#include <avr/io.h> // Registros del microcontrolador
#define F_CPU 8000000UL // Defino la frecuencia de oscilador en 8MHz
#include <util/delay.h> // Retardos por software
/* Función main */
int main (void)
{
	/* Setup */
	DDRC = 0b11111110; // Establece al bit 0 como entrada, el resto como salida
	PORTC = 1<<PINC1; // envia un valor alto por el bit 1
	DDRB = 0xFF; // establece al puerto B como salida
	/* Loop */
	while(1)
	{
		if (PINC & (1<<PINC0))   //si el primer bit de la entrada PINC esta en 0 entra
		{
			PORTB = 0b10101010; // enciende los bit pares
			_delay_ms(100); // espera por 100ms
			PORTB = 0x00; // apaga todos los bit del puerto B
			_delay_ms(100); // espera por 100ms
		}
		else // sino
		{
			PORTB = 0b01010101; // enciende los bit impares
			_delay_ms(100); // espera por 100ms
			PORTB = 0x00; //apaga todos los bit del puerto B
		_delay_ms(100); // espera por 100ms
		}
	}
	/* Punto de finalización del programa (NO se debe llegar a este lugar) */
	return 0;
}
