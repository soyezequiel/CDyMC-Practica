#include <avr/io.h>
//#include "lcd.h"

#define DDR DDRD
#define salida PORTD
#define entrada PIND
#define parteEntrada 0x0F
#define parteSalida 0xF0
 uint8_t KEYPAD_scan(uint8_t *key)
 {
	DDR=0xF0;
	salida&=0x0F;
	if((entrada&parteEntrada)&&(0xFF&parteEntrada)){return 0;}
	salida=0b11101111;
	uint8_t tempKey=0;
	while(1)  
	{
		//si en la entrada solo hay 1111 significa que es la fila incorrecta, por lo que se niega la condicion y se continua con la siguiente fila
		if(!(entrada&&parteEntrada))  
		{
			tempKey=(salida&parteSalida) || entrada&parteEntrada;
			
			switch (tempKey){
				case 0b01110111:*key='7';
				case 0b01111011:*key='8';
				case 0b01111101:*key='9';
				case 0b01111110:*key='/';
				
				case 0b10110111:*key='4';
				case 0b10111011:*key='5';
				case 0b10111101:*key='6';
				case 0b10111110:*key='*';
				
				case 0b11010111:*key='1';
				case 0b11011011:*key='2';
				case 0b11011101:*key='3';
				case 0b11011110:*key='-';
				
				case 0b11100111:*key='p';
				case 0b11101011:*key='0';
				case 0b11101101:*key='=';
				case 0b11101110:*key='+';
			}
			return 1;	
		}
		salida=salida<<1;
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
    /* Replace with your application code */
	LCDinit();
	LCDhome();
	
    while (1) 
    {
		uint8_t tecla=0;
		//KEYPAD_scan(&tecla);
		if(KEYPAD_Update(tecla)){
	//		LCDsendChar(tecla);		
		}
    }
	return 0;
}

