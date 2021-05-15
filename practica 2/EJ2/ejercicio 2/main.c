#include <avr/io.h>
#include "lcd.h"
#include "key.h"


#include <util/delay.h>

void testearTeclado(void)
{
		LCDinit();
		LCDGotoXY(0,0);
		while (1)
		{
			uint8_t tecla=0;
			//programa de testeo del KEYPAD_scan
			if(KEYPAD_Update(&tecla)){
				LCDsendChar(tecla);
			}
			_delay_ms(10);
		}
	
}

int main(void)
{
	testearTeclado();
	return 0;
}




