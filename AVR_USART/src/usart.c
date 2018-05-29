#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <avr/interrupt.h>

#include "usart.h"
#include "stdutils.h"



//	initialize
void usart_init(){
	 UBRR0H = (M_UBRR >> 8);	//	set baud rate
	 UBRR0L = M_UBRR;	//	set baud rate
	 sbit(UCSR0B,TXEN0);	// 	enable transmitter
	 sbit(UCSR0B,RXEN0);	// 	enable receiver
	 sbit(UCSR0B,RXCIE0);	// 	enable receiver interrupt
	 sbit(UCSR0C,USBS0);	//	enable 2 stop bit
	 sbit(UCSR0C,UCSZ00);	//	enable 8 bit character size
	 sbit(UCSR0C,UCSZ01);	// 	enable 8 bit character size
}

//	send character
void send_char(char byte){
	 while (!(UCSR0A & (bit(UDRE0))));	//	wait until the register is empty
	 UDR0 = byte;	//	put a char in the UDR0 register
 }

//	send string
void send_string(char* string){
	 int i;
	 int len = strlen(string);
	 	for (i=0; i<len; i++){
	 		send_char(string[i]);
	 	}
}

//	get character
char get_char(){
 	while(!(UCSR0A & (bit(RXC0))));	// wait until all data in receive buffer is read
 	return UDR0;
}


























