/*
 * main.c
 * author: Rufusy Idachi
 * see the LICENCE file
*/

#include <avr/io.h>
#include <util/delay.h>

#include "stdutils.h"
#include "gpio.h"

#define LED      PB_5
#define DELAYTIME 1000

int main(void) {

  // Init
  GPIO_PinDirection(LED, OUTPUT);

  while (1) {
    GPIO_PinWrite(LED, HIGH);
    _delay_ms(DELAYTIME);
    GPIO_PinWrite(LED, LOW);
    _delay_ms(DELAYTIME);
  }
  return 0;                                         
}

