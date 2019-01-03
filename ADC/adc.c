/*
 * adc.c
 * Author : rufusy
 * see the license file
 */ 
#include <avr/io.h>
#include <util/delay.h>

#include "stdutils.h"
#include "adc.h"


/***************************************************************************************************
                  inline void InitAdc(void)
 ***************************************************************************************************
 * I/P Arguments: none
                              
 * Return value    : none

 * description :This function iniatializes the ADC  
 ***************************************************************************************************/
inline void InitAdc()
{		
	util_BitSet(ADMUX,REFS0); /* reference voltage on AVCC */
	util_BitSet(ADCSRA, ADIE); /* enable interrupts */
	ADCSRA |= (1 << ADPS0) | (1 << ADPS1) | (1 <<ADPS2); /* prescaler 128 */	
	util_BitSet(ADCSRA,ADEN); /* enable ADC */
	util_BitSet(ADCSRA,ADSC); /* start the first conversion */
}


/***************************************************************************************************
                  inline uint16_t ReadAdcVal(ADC_Channel Channel)
 ***************************************************************************************************
 * I/P Arguments: 
                channel: adc channel.
                              
 * Return value    : 10 bit adc value

 * description :This function configures the channel.  
 ***************************************************************************************************/

inline uint16_t ReadAdcVal(GPIO_Pins channel)
{
	uint8_t adc_channel;
	adc_channel = channel & 0x07;	// lower 3 bits represent bits of a number
                                    // maximum of 6 adc channels
	switch(adc_channel)
	{
		case 0: /* channel 0*/
			ADMUX &= ~(1 << MUX0) | (1 << MUX1) | (1 << MUX2);
			_delay_ms(1);	/* wait for channel to get selected */
			break;
		case 1:	/* channel 1*/
			ADMUX |= (1 << MUX0);
			ADMUX &= ~(1 << MUX1) | (1 << MUX2);
			_delay_ms(1);
			break;
		default:
			/* default code */	
			break;
	}

	util_BitSet(ADCSRA,ADSC); /* start conversion */
	while(util_IsBitSet(ADCSRA,ADSC)); /* spin wait until bit is cleared */
	uint8_t ADCL_Val = ADCL; /* access ADCL first */
	return ADCH << 8 | ADCL_Val;
}




