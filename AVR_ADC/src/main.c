/*
 * main.c
 *
 *  Created on: Mar 16, 2018
 *      Author: rufusy
 */


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "stdutils.h"
#include "adc.h"

int main(void){
	// Configure PORTB PIN5 as output
	DDRB |= (1<<DDB5);
	ADC_init();
	ADC_start_conversion();

	while(1){
		// check adc value, set LED accordingly
		if(ADCH > 128){
			PORTB |= (1<<PORTB5);
		}else{
			PORTB &= ~(1<<PORTB5);
		}

	}
}



