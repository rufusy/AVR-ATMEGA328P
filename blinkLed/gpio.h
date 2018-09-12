/*
 * gpio.h
 * author: Rufusy Idachi
 * see the LICENCE file
*/

#ifndef _GPIO_H
#define _GPIO_H

typedef enum
{	
	/* GPIO pins */
	PA_0,PA_1,PA_2,PA_3,PA_4,PA_5,PA_6,PA_7,
    PB_0,PB_1,PB_2,PB_3,PB_4,PB_5,PB_6,PB_7,
    PC_0,PC_1,PC_2,PC_3,PC_4,PC_5,PC_6,PC_7,
    PD_0,PD_1,PD_2,PD_3,PD_4,PD_5,PD_6,PD_7,
    PE_0,PE_1,PE_2,PE_3,PE_4,PE_5,PE_6,PE_7,
    PF_0,PF_1,PF_2,PF_3,PF_4,PF_5,PF_6,PF_7,
    PG_0,PG_1,PG_2,PG_3,PG_4,PG_5,PG_6,PG_7,
    PH_0,PH_1,PH_2,PH_3,PH_4,PH_5,PH_6,PH_7,
    PJ_0,PJ_1,PJ_2,PJ_3,PJ_4,PJ_5,PJ_6,PJ_7,
    PK_0,PK_1,PK_2,PK_3,PK_4,PK_5,PK_6,PK_7,
    PL_0,PL_1,PL_2,PL_3,PL_4,PL_5,PL_6,PL_7
}GPIO_Pins;



/***************************************************************************************************
                             Function prototypes
***************************************************************************************************/
void GPIO_PinDirection(GPIO_Pins PinNumber, uint8_t PinDirn);
void GPIO_PinWrite(GPIO_Pins PinNumber, uint8_t PinValue);
uint8_t GPIO_PinRead(GPIO_Pins PinNumber);
void GPIO_PinToggle(GPIO_Pins PinNumber);
/**************************************************************************************************/


#endif