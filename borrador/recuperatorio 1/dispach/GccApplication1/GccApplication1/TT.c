/*
 * CFile1.c
 *
 * Created: 14/7/2021 14:43:35
 *  Author: Alcayaga Ezequiel
 */ 
volatile unsigned char Flag_3=0,
volatile unsigned char Flag_2=0;
volatile unsigned char Flag_1=0;

static unsigned char cont3=0,
static unsigned char cont2=0;
static unsigned char cont1=0;

/* -------------------------*/
//ISR TIMER :  Cada 10 ms
/* -------------------------*/
ISR (Timer_OVF)
{
	SEOS_SCH_Tasks();
}

void SEOS_SCH_Tasks (void)
{
	if (++cont3==30) {
		Flag_3=1; 
		cont3=0;
	}
	if (++cont2==20) {
		Flag_2=1; 
		cont2=0;
	}
	if (++cont1==10) {
		Flag_1=1; /
		cont1=0;
	}
}
//Alcayaga ezequiel, continuacion del TT.c

void SEOS_Dispatch_Tasks (void) {
		if (Flag_1) {
			tarea1(); 
			Flag_1 =0;
		}
		if (Flag_2) {
			tarea2(); 
			Flag_2 =0;
		}
		if (Flag_3) {
			tarea3(); 
			Flag_3 =0;
		}
	}