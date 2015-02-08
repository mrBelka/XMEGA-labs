#define  F_CPU    2000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void) {
	PORTE.DIRSET = 0b00000001;
	
	TCC0.INTCTRLA     =    TC_OVFINTLVL_LO_gc;
	PMIC.CTRL         =    PMIC_LOLVLEN_bm;
	sei();
	
	TCC0.CTRLB = TC_WGMODE_NORMAL_gc;
	TCC0.CTRLA = TC_CLKSEL_DIV2_gc;
	
	while(1) {
	}
}

ISR(TCC0_OVF_vect) {
	PORTE.OUTTGL = 0b00000001;
}
