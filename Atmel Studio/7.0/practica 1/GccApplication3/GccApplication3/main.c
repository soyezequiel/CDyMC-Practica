#include <avr/io.h>
#define F_CPU 8000000L
#include <util/delay.h>


/*Funcion de retardo en ms */
void delay(unsigned char tiemp)
{
	/*se establece las repeticiones que debe de realizar el bucle for*/
	volatile unsigned long i,tiempo=((F_CPU/10000)/4.2001)*tiemp;
	for (i = 0; i < tiempo; i++) {;}
}

void delay100ms()
{
	/*se establece las repeticiones que debe de realizar el bucle for*/
	volatile unsigned long i,tiempo=((F_CPU/100)/4.2001);
	for (i = 0; i < tiempo; i++) {;}
}
int main(void)
{
	/*setup*/
	/*se establece el puerto B como salida*/
	DDRB=0xFF;
	/*se configura en bajo todos los pines del puerto B*/
	PORTB=0x0;
	/*variable que irá poniendo en alto los pines*/
	while (1)
	{
		/*función de espera */
		_delay_ms(100);
		/*corrimiento de bits hacia la izquierda*/
		PORTB= PORTB <<1;
		/*en caso de estar todos los bits apagados, se enciende el menos significativo*/
		if(PINB==0x0) {PORTB=0x1;}
	}
	return 0;
}




#include <avr/io.h>
#define F_CPU 8000000L
#include <util/delay.h>

int main(void)
{
	/*setup*/
	/*se establece el puerto B como salida*/
	DDRB=0xFF;
	/*se configura en bajo todos los pines del puerto B*/
	PORTB=0x0;
	/*variable que irá poniendo en alto los pines*/
	while (1)
	{
		/*función de espera */
		_delay_ms(100);
		/*corrimiento de bits hacia la izquierda*/
		PORTB= PORTB <<1;
		/*en caso de estar todos los bits apagados, se enciende el menos significativo*/
		if(PINB==0x0) {PORTB=0x1;}
	}
	return 0;
}