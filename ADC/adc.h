/*
 * adc.h
 * Author : rufusy
 * see the license file
 */ 

#ifndef ADC_H_
#define ADC_H_
#include "gpio.h"

/***************************************************************************************************
                             Function prototypes
***************************************************************************************************/
inline void InitAdc(void);
inline uint16_t ReadAdcVal(GPIO_Pins Channel);
/**************************************************************************************************/

#endif /* ADC_H_ */ 