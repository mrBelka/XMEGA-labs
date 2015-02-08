#define F_CPU 20000000
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	
	PORTE.DIR = 0b11011111;
	
	int dir = 0;
	
	PORTE.OUT = 0b00011111;
	while(1) {
		if(PORTE.IN & 0b00100000){
			while(PORTE.IN & 0b00100000);
			_delay_ms(10);
			dir = 1 - dir;
		}
		if(dir)PORTE.OUT = 0b00011111;
		else PORTE.OUT = 0b00000000;
		_delay_ms(10);
	}
}
