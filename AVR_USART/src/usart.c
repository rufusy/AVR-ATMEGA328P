#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <avr/interrupt.h>

#include "usart.h"
#include "stdutils.h"


/* Initialize usart */
void usart_init(){
	 UBRR0H = (M_UBRR >> 8);	// setting baud rate
	 UBRR0L = M_UBRR;
	 UCSR0B = (1<<TXEN0) | (1<<RXEN0) | (1<<RXCIE0);	// enable transmitter and receiver
	 UCSR0C = (1<<USBS0);	// 2 stop bit
	 UCSR0C = (1<<UCSZ00) | (1<<UCSZ01);
 }


/* Send character */
void send_char(char byte){
	 while (!(UCSR0A & (bit(UDRE0))));	// wait until the register is empty
	 UDR0 = byte;	// put a char in the UDR0 register
 }

/* Send character array  */
 void send_string(char* string){
	 int i;
	 int len = strlen(string);
	 	for (i=0; i<len; i++){
	 		send_char(string[i]);
	 	}
 }

/* Get character */
char get_char(){
	while(!(UCSR0A & (bit(RXC0))));	// wait until all data in receive buffer is read
	return UDR0;
}

char string[20];

char* get_string(){
	char x;
	int i=0;
	while((x = get_char()) != 13){
		string[i++] = x;
	}
	string[i] = '\0';
	return string;
}




