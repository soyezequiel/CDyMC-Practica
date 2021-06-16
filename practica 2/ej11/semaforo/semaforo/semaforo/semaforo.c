#include "semaforo.h"
//privadas
	//VARIABLES 
	static eLight_State Light_state; //Estado actual del sistema
	static long	Time_in_state; // tiempo en el estado
	//Funciones para las luces
	void light_On(uint8_t port_led){
		PORT |= (1<<port_led);
	}
	void light_Off(uint8_t port_led){
		PORT &= ~(1<<port_led);
	}
	void CONFIG_Light(){
		PORT_CONF|=((1<<PORT_RED)|(1<<PORT_AMBER)|(1<<PORT_GREEN));
		light_Off(PORT_RED);
		light_Off(PORT_AMBER);
		light_Off(PORT_GREEN);
	}
//Publicas
	//Funciones
	void TRAFIC_LIGHT_Init(eLight_State START_STATE){
		CONFIG_Light();
		Light_state=START_STATE; //poner un estado inicial	
		Time_in_state=0;
	}
	void TRAFIC_LIGHT_Update(void){
		switch(Light_state){
			case RED:
				//actualizar salida
				light_On(PORT_RED);
				light_Off(PORT_AMBER);
				light_Off(PORT_GREEN);
				//Cambio de estado
				if(++Time_in_state==RED_DURATION){
					Light_state=RED_AMBER;				
					Time_in_state=0;
				}
				break;
			case RED_AMBER:
				//actualizar salida
				light_On(PORT_RED);
				light_On(PORT_AMBER);
				light_Off(PORT_GREEN);
			
				if(++Time_in_state==RED_AMBER_DURATION){
					Light_state=GREEN;
					Time_in_state=0;
				}
				break;
			case GREEN:
				//actualizar salida
				light_Off(PORT_RED);
				light_Off(PORT_AMBER);

				light_On(PORT_GREEN);
				if(++Time_in_state==GREEN_DURATION){
					Light_state=AMBER;
					Time_in_state=0;
				}
				break;
			case AMBER:
				//actualizar salida
				light_Off(PORT_RED);
				light_On(PORT_AMBER);
				light_Off(PORT_GREEN);
				if(++Time_in_state==AMBER_DURATION){
					Light_state=RED;
					Time_in_state=0;
				}
				break;
		}
	}

