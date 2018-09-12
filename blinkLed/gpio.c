/*
 * gpio.c
 * author: Rufusy Idachi
 * see the LICENCE file
*/

#include <avr/io.h>
#include "stdutils.h"
#include "gpio.h"


/***************************************************************************************************
                  void GPIO_PinDirection(GPIO_Pins PinNumber, uint8_t PinDirn)
 ***************************************************************************************************
 * I/P Arguments: 
                PinNumber: pin number which needs to be updated.
                           Refer the gpio.h for pin numbering.
                PinDirn: Direction to be configured ie. INPUT/OUTPUT.
                              
 * Return value    : none

 * description :This function sets the specified direction as INPUT/OUTPUT.  
 ***************************************************************************************************/
void GPIO_PinDirection(GPIO_Pins PinNumber, uint8_t PinDirn)
{
	uint8_t GPIO_PortVal, GPIO_PinNumber;
    GPIO_PortVal = (PinNumber >> 3);    // divide by 8. get port number
    GPIO_PinNumber = PinNumber & 0x07;  // lower 3 bits represent bits of a number
                                        // limit bit number from 0..7

	switch (GPIO_PortVal)
	{
		#ifdef DDRA        
    	case 0:
        	util_UpdateBit(DDRA,GPIO_PinNumber,PinDirn);
        	break;
		#endif  
       	#ifdef DDRB       
    	case 1:
        	util_UpdateBit(DDRB,GPIO_PinNumber,PinDirn);
        	break;
		#endif 
		#ifdef DDRC        
    	case 2:
        	util_UpdateBit(DDRC,GPIO_PinNumber,PinDirn);
        	break;
		#endif   
        #ifdef DDRD        
    	case 3:
        	util_UpdateBit(DDRD,GPIO_PinNumber,PinDirn);
        	break;
		#endif  
        #ifdef DDRE       
    	case 4:
        	util_UpdateBit(DDRE,GPIO_PinNumber,PinDirn);
        	break;
		#endif  
        #ifdef DDRF       
    	case 5:
        	util_UpdateBit(DDRF,GPIO_PinNumber,PinDirn);
        	break;
		#endif 
		#ifdef DDRG        
    	case 6:
        	util_UpdateBit(DDRG,GPIO_PinNumber,PinDirn);
        	break;
		#endif
		#ifdef DDRH       
    	case 7:
        	util_UpdateBit(DDRH,GPIO_PinNumber,PinDirn);
        	break;
		#endif    
		#ifdef DDRJ        
    	case 8:
        	util_UpdateBit(DDRJ,GPIO_PinNumber,PinDirn);
        	break;
		#endif
		#ifdef DDRK        
    	case 9:
        	util_UpdateBit(DDRK,GPIO_PinNumber,PinDirn);
        	break;
		#endif    
		#ifdef DDRL       
    	case 10:
        	util_UpdateBit(DDRL,GPIO_PinNumber,PinDirn);
        	break;
		#endif   
	}
}



/***************************************************************************************************
            void GPIO_PinWrite(GPIO_Pins PinNumber, uint8_t PinDirn)
 ***************************************************************************************************
 * I/P Arguments: 
                PinNumber : pin number which needs to be updated.
                             Refer the gpio.h for pin numbering.
                PinDirn: Value to be updated(LOW/HIGH) on the selected pin.
                             
 * Return value    : none

 * description :This function updates the specified value on the selected pin.  
                Before updating the pins status, the pin function should be selected and then
                the pin should be configured as OUTPUT 
***************************************************************************************************/

void GPIO_PinWrite(GPIO_Pins PinNumber, uint8_t PinDirn)
{
    
    uint8_t GPIO_PortVal, GPIO_PinNumber;
    GPIO_PortVal = (PinNumber >> 3);    // divide by 8. get port number
    GPIO_PinNumber = PinNumber & 0x07;  // lower 3 bits represent bits of a number
                                        // limit bit number from 0..7

	switch (GPIO_PortVal)
	{
		#ifdef PORTA        
    	case 0:
        	util_UpdateBit(PORTA,GPIO_PinNumber,PinDirn);
        	break;
		#endif  
       	#ifdef PORTB       
    	case 1:
        	util_UpdateBit(PORTB,GPIO_PinNumber,PinDirn);
        	break;
		#endif 
		#ifdef PORTC        
    	case 2:
        	util_UpdateBit(PORTC,GPIO_PinNumber,PinDirn);
        	break;
		#endif   
        #ifdef PORTD        
    	case 3:
        	util_UpdateBit(PORTD,GPIO_PinNumber,PinDirn);
        	break;
		#endif  
        #ifdef PORTE       
    	case 4:
        	util_UpdateBit(PORTE,GPIO_PinNumber,PinDirn);
        	break;
		#endif  
        #ifdef PORTF      
    	case 5:
        	util_UpdateBit(PORTF,GPIO_PinNumber,PinDirn);
        	break;
		#endif 
		#ifdef PORTG        
    	case 6:
        	util_UpdateBit(PORTG,GPIO_PinNumber,PinDirn);
        	break;
		#endif
		#ifdef PORTH       
    	case 7:
        	util_UpdateBit(PORTH,GPIO_PinNumber,PinDirn);
        	break;
		#endif    
		#ifdef PORTJ        
    	case 8:
        	util_UpdateBit(PORTJ,GPIO_PinNumber,PinDirn);
        	break;
		#endif
		#ifdef PORTK        
    	case 9:
        	util_UpdateBit(PORTK,GPIO_PinNumber,PinDirn);
        	break;
		#endif    
		#ifdef PORTL       
    	case 10:
        	util_UpdateBit(PORTL,GPIO_PinNumber,PinDirn);
        	break;
		#endif 
	}
}




/***************************************************************************************************
                    uint8_t GPIO_PinRead(GPIO_Pins PinNumber)
 ***************************************************************************************************
 * I/P Arguments: 
             	PinNumber : pin number which needs to be read.
                             Refer the gpio.h for pin numbering.

 * Return value    : 
                 uint8_t:    Status of the specified pin.

 * description :This function returns the status of the selected pin.
                Before reading the pins status, the pin should be configured as INPUT 
 ***************************************************************************************************/

uint8_t GPIO_PinRead(GPIO_Pins PinNumber)
{
	uint8_t GPIO_PortVal, GPIO_PinNumber;
    GPIO_PortVal = (PinNumber >> 3);    // divide by 8. get port number
    GPIO_PinNumber = PinNumber & 0x07;  // lower 3 bits represent bits of a number
                                        // limit bit number from 0..7
	uint8_t PinStatus = 0;
	
	switch (GPIO_PortVal)
	{
		#ifdef PORTA        
    	case 0:
    		PinStatus = util_IsBitSet(PORTA,GPIO_PinNumber);
        	break;
		#endif  
       	#ifdef PORTB       
    	case 1:
    	   	PinStatus = util_IsBitSet(PORTB,GPIO_PinNumber);
        	break;
		#endif 
		#ifdef PORTC        
    	case 2:
    	   	PinStatus = util_IsBitSet(PORTC,GPIO_PinNumber);
        	break;
		#endif   
        #ifdef PORTD        
    	case 3:
    	   	PinStatus = util_IsBitSet(PORTD,GPIO_PinNumber);
        	break;
		#endif  
        #ifdef PORTE       
    	case 4:
    	   	PinStatus = util_IsBitSet(PORTE,GPIO_PinNumber);
        	break;
		#endif  
        #ifdef PORTF      
    	case 5:
    	   	PinStatus = util_IsBitSet(PORTF,GPIO_PinNumber);
        	break;
		#endif 
		#ifdef PORTG        
    	case 6:
    	   	PinStatus = util_IsBitSet(PORTG,GPIO_PinNumber);
        	break;
		#endif
		#ifdef PORTH       
    	case 7:
    	   	PinStatus = util_IsBitSet(PORTH,GPIO_PinNumber);
        	break;
		#endif    
		#ifdef PORTJ        
    	case 8:
    	   	PinStatus = util_IsBitSet(PORTJ,GPIO_PinNumber);
        	break;
		#endif
		#ifdef PORTK        
    	case 9:
    	   	PinStatus = util_IsBitSet(PORTK,GPIO_PinNumber);
        	break;
		#endif    
		#ifdef PORTL       
    	case 10:
    	   	PinStatus = util_IsBitSet(PORTL,GPIO_PinNumber);
        	break;
		#endif 	
	}
	return PinStatus;	
}




/***************************************************************************************************
            void GPIO_PinToggle(GPIO_Pins PinNumber)
 ***************************************************************************************************
 * I/P Arguments: 
                PinNumber : pin number which needs to be updated.
                             Refer the gpio.h for pin numbering.
                             
 * Return value    : none

 * description :This function toggles the selected pin HIGH and LOW  
                Before toggling the pin, the pin function should be selected and then
                the pin should be configured as OUTPUT 
***************************************************************************************************/
void GPIO_PinToggle(GPIO_Pins PinNumber)
{
	uint8_t GPIO_PortVal, GPIO_PinNumber;
	GPIO_PortVal = (PinNumber >> 3);    // divide by 8. get port number
	GPIO_PinNumber = PinNumber & 0x07;  // lower 3 bits represent bits of a number
										// limit bit number from 0..7
										
	switch(GPIO_PortVal)
	{
		#ifdef PORTA
		case 0:
			util_BitToggle(PORTA, GPIO_PinNumber); 
			break;
		#endif
		#ifdef PORTB
		case 1:
			util_BitToggle(PORTB, GPIO_PinNumber);
			break;
		#endif
		#ifdef PORTC
		case 2:
			util_BitToggle(PORTC, GPIO_PinNumber);
			break;
		#endif
		#ifdef PORTD
		case 3:
			util_BitToggle(PORTD, GPIO_PinNumber);
			break;
		#endif
		#ifdef PORTE
		case 4:
			util_BitToggle(PORTE, GPIO_PinNumber);
			break;
		#endif
		#ifdef PORTF
		case 5:
			util_BitToggle(PORTF, GPIO_PinNumber);
			break;
		#endif
		#ifdef PORTG
		case 6:
			util_BitToggle(PORTG, GPIO_PinNumber);
			break;
		#endif
		#ifdef PORTH
		case 7:
			util_BitToggle(PORTH, GPIO_PinNumber);
			break;
		#endif
		#ifdef PORTJ
		case 8:
			util_BitToggle(PORTJ, GPIO_PinNumber);
			break;
		#endif
		#ifdef PORTK
		case 9:
			util_BitToggle(PORTK, GPIO_PinNumber);
			break;
		#endif
		#ifdef PORTL
		case 10:
			util_BitToggle(PORTL, GPIO_PinNumber);
			break;
		#endif	
	}
}
