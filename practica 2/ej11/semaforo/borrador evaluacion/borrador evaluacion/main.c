/*
 * borrador evaluacion.c
 *
 * Created: 30/6/2021 14:29:46
 * Author :ezequiel alcayaga
 * Reemplazar simples lineas de configuracion de registros por funciones, es para que sea mas entendible y para abstraerse del HW
 */ 

#include <avr/io.h>

void indicador_para_la_realizacion_de_la_captura_en_modo_entrada(){
	DDRB&= ~(1<<PB0); 
}
void TIMER1_modo_normal(){
	TCCR1A=0;	
}
void TIMER1_modo_flanco_no_preescaler(){
	TCCR1B=(1<<ICES1)|(1<<CS10);
}
uint8_t indicador_de_captura_ya_realizada(){
	return TIFR1 & (1<<ICF1);
}
void reiniciar_indicador_de_captura_ya_realizada(){
	TIFR1=(1<<ICF1);
}
uint16_t get_resguardo_del_tiempo(){
	return ICR1;
}
int main(void)
{
	uint16_t ciclos_inicial,ciclos_final,ciclos_de_pulso;
	indicador_para_la_realizacion_de_la_captura_en_modo_entrada();
	TIMER1_modo_normal();
	TIMER1_modo_flanco_no_preescaler();	
	while (indicador_de_captura_ya_realizada()==0);	
	ciclos_inicial=get_resguardo_del_tiempo();
	reiniciar_indicador_de_captura_ya_realizada();
	while (indicador_de_captura_ya_realizada()==0);
	ciclos_final=get_resguardo_del_tiempo();
	ciclos_de_pulso=ciclos_final-ciclos_inicial;
	reiniciar_indicador_de_captura_ya_realizada();
	return ciclos_de_pulso;
}

