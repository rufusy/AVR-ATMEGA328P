/*
 * stdutils.h
 * author: Rufusy Idachi
 * see the LICENCE file
*/

#ifndef _STD_UTIL_H_
#define	_STD_UTIL_H_

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

/***************************************************************************************************
    Basic data types for 8051/PIC/AVR 8bit controllers
 ***************************************************************************************************/

/**----------char 8-bit--------
     char (-128 to 127)
     signed char (-128 to 127)
     unsigned char (0 - 255)
	-----------------------------*/

/**---------int 16-bit----------
	 int (-32768 to 32767)
	 signed int (-32768 to 32767)
     unsigned int (0 to 65535)
	 -----------------------------*/

typedef signed char     sint8_t;
typedef unsigned char   uint8_t;

typedef signed int      sint16_t;
typedef unsigned int    uint16_t;

typedef signed long int    sint32_t;
typedef unsigned long int  uint32_t;



/***************************************************************************************************
                           Port Direction configurations
 ***************************************************************************************************/
#define C_PinOutput_U8     0x01u
#define C_PinInput_U8      0x00u
#define C_PortOutput_U8    0xFFu
#define C_PortInput_U8     0x00u

#define INPUT              C_PinInput_U8
#define OUTPUT             C_PinOutput_U8
#define LOW                0x00u
#define HIGH               0x01u
/**************************************************************************************************/


/***************************************************************************************************
                           Definition of common Bit-Masks
 ***************************************************************************************************/
#define  Mask_BIT0   0x0001u
#define  Mask_BIT1   0x0002u
#define  Mask_BIT2   0x0004u
#define  Mask_BIT3   0x0008u
#define  Mask_BIT4   0x0010u
#define  Mask_BIT5   0x0020u
#define  Mask_BIT6   0x0040u
#define  Mask_BIT7   0x0080u
#define  Mask_BIT8   0x0100u
#define  Mask_BIT9   0x0200u
#define  Mask_BIT10  0x0400u
#define  Mask_BIT11  0x0800u
#define  Mask_BIT12  0x1000u
#define  Mask_BIT13  0x2000u
#define  Mask_BIT14  0x4000u
#define  Mask_BIT15  0x8000u
/**************************************************************************************************/



/***************************************************************************************************
                                Macros for Bit Manipulation
 ****************************************************************************************************/
#define  util_GetBitMask(bit)          (1<<(bit))
#define  util_BitSet(x,bit)            ((x) |=  util_GetBitMask(bit))
#define  util_BitClear(x,bit)          ((x) &= ~util_GetBitMask(bit))
#define  util_BitToggle(x,bit)         ((x) ^=  util_GetBitMask(bit))
#define  util_UpdateBit(x,bit,val)     ((val)? util_BitSet(x,bit): util_BitClear(x,bit))


#define  util_GetBitStatus(x,bit)      (((x)&(util_GetBitMask(bit)))!=0u)
#define  util_IsBitSet(x,bit)          (((x)&(util_GetBitMask(bit)))!=0u)
#define  util_IsBitCleared(x,bit)      (((x)&(util_GetBitMask(bit)))==0u)


#define  util_AreAllBitsSet(x,BitMask) (((x)&(BitMask))==BitMask)
#define  util_AreAnyBitsSet(x,BitMask) (((x)&(BitMask))!=0x00u)
/**************************************************************************************************/



/***************************************************************************************************
                              Commonly used constants
 **************************************************************************************************/
#define C_ZERO_U8          0x00u
#define C_NULL_U8          0x00u
#define NULL_CHAR          0x00u

#define FALSE              0x00u
#define TRUE               0x01u

/**************************************************************************************************/
#endif