/*
 * adc.c
 *
 *  Created on: May 4, 2018
 *      Author: rufusy
 */


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "stdutils.h"
#include "adc.h"

void ADC_init(){
	// set prescaler, division factor of 128, 125KHZ sample rate
	ADCSRA |= (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2);
	// set REf voltage to AVCC
	ADMUX |= (1<<REFS0);
	// select channel ADC5
	ADMUX |= (1<<MUX0) | (1<<MUX2);
	// left adjust the ADC value, for 8 bit precision
	ADMUX |= (1<<ADLAR);
	// enable the ADC
	ADCSRA |= (1<<ADEN);
	// enable ADC interrupt
	ADCSRA |= (1<<ADIE);
}

void ADC_start_conversion(){
	ADCSRA |= (1<<ADSC);
}
