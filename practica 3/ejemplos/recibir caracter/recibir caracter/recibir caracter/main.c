
#include <avr/io.h>


int main(void)
{
	volatile unsigned char dato;
	// Initialize the USART
	UCSR0A=0;			//queda en 0 porque no usaremos sus funciones
	UCSR0B=(1<<RXEN0)|(1<<TXEN0); //habilita el trasmisor
	UCSR0C=(1<<UCSZ01)|(1<<UCSZ00);//formato de la trasmision, en este caso establece que se enviaran 8bit osea Formato 8N1
	UBRR0L=103;  //baud rate =9600bps a 16MHz
	while (1)
	{
		while( !(UCSR0A & (1<<UDRE0)) ); //Espera hasta que UDR0 este vacio
		UDR0='G';		//Transmite 'G'
		
		while (! (UCSR0A & (1<<RXC0))); //wait until new data
		dato = UDR0;
	}
	return 0;
}
