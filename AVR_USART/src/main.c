#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <avr/interrupt.h>

#include "usart.h"
#include "stdutils.h"

char input;
char* msg = "hello";

int main(){
	usart_init();
	sei();
	for(;;){

		send_char(input);
		_delay_ms(1000);


		/*************************************************
		// uncomment below block to send the string msg
		**************************************************/

		/*
		send_string(msg);
		_delay_ms(1000);
		*/

	}
	return 0;
}


// receive characters via interrupts
ISR(USART_RX_vect){
	input = get_char();
}

