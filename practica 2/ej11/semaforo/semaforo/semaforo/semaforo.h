/*
 * semafoto.h
 *
 * Created: 16/6/2021 11:04:13
 *  Author: Ezequiel
 */ 
#include <avr/io.h>


//posibles estados del sistema
typedef enum {RED,RED_AMBER,GREEN,AMBER} eLight_State;
	
// tiempo de duracion de cada estado
//tiempo en segundos
#define RED_DURATION 20
#define RED_AMBER_DURATION 5
#define GREEN_DURATION 30
#define	AMBER_DURATION 5

//Puerto a utilizar
#define PORT_CONF DDRB
#define PORT PORTB 

//Numero de puerto para cada color
#define PORT_RED 5
#define PORT_AMBER 6
#define PORT_GREEN 7

//funciones publicas
void TRAFIC_LIGHT_Init(eLight_State START_STATE);
void TRAFIC_LIGHT_Update(void);