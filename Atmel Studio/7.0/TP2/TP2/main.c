#include <avr/io.h>
#include "lcd.h"

#define DDR DDRD
#define puerto PORTD
#define puerto_lectura PIND
#define parteEntrada 0x0F
#define parteSalida 0xF0

#define F_CPU 8000000L
#include <util/delay.h>

void actualizar_salida( uint8_t salida)
{
	// como la salida se encuentra en los bits mas significativos, se lo corre 4 veces y se le añade la entrada que debe de ser igual
	puerto= (salida<<4) | (puerto & 0x0F); 
}
uint8_t get_salida()
{
	return (puerto>>4);
}
uint8_t get_entrada()
{
	return (puerto_lectura|0xF0); 
}
uint8_t KEYPAD_scan(uint8_t *key)
{
	LCDsendChar('|');
	DDR=0xF0;
	puerto=0x0F;
	actualizar_salida(0);


   _delay_ms(100);
	if(get_entrada()==0xFF){return 0;}
	_delay_ms(100);		
	actualizar_salida(0b00001110);
	uint8_t lectura=0;
	while(1)
	{
		_delay_ms(100);
		//si en la entrada solo hay 1111 significa que es la fila incorrecta, por lo que se niega la condicion y se continua con la siguiente fila
		if(~get_entrada())
		{		
			lectura=(get_salida()<<4) | (get_entrada()&0x0F);
			switch (lectura)
			{
				case 0b01110111:*key='7';break;
				case 0b01111011:*key='8';break;
				case 0b01111101:*key='9';break;
				case 0b01111110:*key='/';break;
				
				case 0b10110111:*key='4';break;
				case 0b10111011:*key='5';;break;
				case 0b10111101:*key='6';break;
				case 0b10111110:*key='*';break;
				
				case 0b11010111:*key='1';break;
				case 0b11011011:*key='2';break;
				case 0b11011101:*key='3';break;
				case 0b11011110:*key='-';break;
				
				case 0b11100111:*key='p';break;
				case 0b11101011:*key='0';break;
				case 0b11101101:*key='=';break;
				case 0b11101110:*key='+';break;
				default: *key='D';
			}			
			return 1;
		}
		actualizar_salida(get_salida()<<1);
	}
	return 0;
}

uint8_t KEYPAD_Update (uint8_t *pkey)
{
	static uint8_t Old_key;
	uint8_t Key, Last_valid_key=0xFF; // no hay tecla presionada
	if(!KEYPAD_scan(&Key)) {
		Old_key=0xFF; // no hay tecla presionada
		Last_valid_key=0xFF;
		return 0;
	}
	if(Key==Old_key) { //2da verificación
		if(Key!=Last_valid_key){ //evita múltiple detección
			*pkey=Key;
			Last_valid_key = Key;
			return 1;
		}
	}
	Old_key=Key; //1era verificación
	return 0;
}


int main(void)
{
	LCDinit();
	LCDGotoXY(0,0);
	while (1)
	{	
		uint8_t tecla=0;
		//programa de testeo del KEYPAD_scan
		if(KEYPAD_scan(&tecla)){
					LCDsendChar(tecla);
		}				
	    _delay_ms(100);
	}
	return 0;


}




