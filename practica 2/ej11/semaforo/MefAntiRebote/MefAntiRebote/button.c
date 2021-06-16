/*
 * button.c
 *
 * Created: 16/6/2021 13:49:37
 *  Author: UNLP
 */ 
#include "button.h"
//privada
	//variables
	volatile eButton_Estate Button_Estate;
	volatile uint8_t tiempo;
	
	volatile uint8_t isPresionado;
	
	//funciones
	//con pull up activado
	uint8_t isBottonBajo(){		
			if(PIN&(1<<NUM_PIN)){
				return 0;
			} else return 1;
	}
void conf_PORTB(){
	PORT_CONF&=~(1<<NUM_PIN);
	PORT|=(1<<NUM_PIN); //activo pull-up
}

//publicas
	//funciones
	void BUTTON_Init(void){
		conf_PORTB();
		Button_Estate=UP;
		isPresionado=0;
		tiempo=0;
	}

	void BUTTON_Update(void){
		switch(Button_Estate){
			case UP:
				if(isBottonBajo()){
					Button_Estate=FALLING;
					isPresionado=0;			
				}
			break;
			
			case FALLING:
				if((++tiempo==BUTTON_DURATION)&(isBottonBajo())){				
					Button_Estate=DOWN;	
					isPresionado=1;
					tiempo=0;	
				}
			break;
			
			case DOWN:
				if(~(isBottonBajo())){
					Button_Estate=RAISING;
					isPresionado=1;
				}
			break;
			
			case RAISING:
				if((++tiempo==BUTTON_DURATION)&(~(isBottonBajo()))){
					Button_Estate=UP;
					isPresionado=0;
					tiempo=0;
				}
			break;
		}
	}
	
	uint8_t BUTTON_Presionado(){
		return isPresionado;
	}