#ifndef SRC_USART_H_
#define SRC_USART_H_

/* USART MACROS */
#ifndef F_CPU
#define F_CPU 16000000
#endif
#define BAUD 9600	// baud rate
#define M_UBRR ((F_CPU/16/BAUD)-1)	//contents of UBRRnH and UBRRnL registers


/* FUNCTION PROTOTYPES */
void usart_init();
void send_char(char);
void send_string(char*);
char get_char();






#endif /* SRC_USART_H_ */
