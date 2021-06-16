/*
 * button.h
 *
 * Created: 16/6/2021 13:49:46
 *  Author: UNLP
 */ 

#include <avr/io.h>
#define PIN PINB
#define PORT_CONF DDRB
#define PORT PORTB
#define NUM_PIN 1


//#define PULL UP

#define BUTTON_DURATION 20

typedef enum {UP,FALLING,DOWN,RAISING} eButton_Estate;
	
void BUTTON_Init(void);
void BUTTON_Update(void);
uint8_t BUTTON_Presionado();	