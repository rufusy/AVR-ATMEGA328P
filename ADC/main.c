/*
 * main.c
 * Author : rufusy
 * see the license file
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "stdutils.h"
#include "gpio.h"
#include "adc.h"

#define BlueLED PD_6
#define GreenLED PD_7

uint16_t GreenLedVal;
uint16_t BlueLedVal;

int main()
{
    GPIO_PinDirection(BlueLED, OUTPUT);
    GPIO_PinDirection(GreenLED, OUTPUT);
    sei(); /* enable global interrupts */
	InitAdc();

    while (1) 
    {
        if(BlueLedVal > 512)
            GPIO_PinWrite(BlueLED, HIGH);
        else
            GPIO_PinWrite(BlueLED, LOW);
        if(GreenLedVal > 512)
            GPIO_PinWrite(GreenLED, HIGH);
        else
            GPIO_PinWrite(GreenLED, LOW);
    }
	return 0;
}


ISR(ADC_vect)
{ 
    GreenLedVal = ReadAdcVal(PC_0);
    BlueLedVal = ReadAdcVal(PC_1);
}

