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
	while(1){
		send_string(msg);
		_delay_ms(5000);
	}
return 0;
}

/* Receive character using interrupt */
ISR(USART_RX_vect){
	//send_string(msg);
}
