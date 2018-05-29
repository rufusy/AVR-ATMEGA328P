#ifndef SRC_STDUTILS_H_
#define SRC_STDUTILS_H_


/*****************************************************
 * MACROS FOR BIT MANIPULATION
 * **************************************************/

#define bit(n) (1 << n)	// is bit **n** set?
#define sbit(v, n) v |= (1 << n)	// set bit **n** in register **v**
#define cbit(v, n) v &= !(1 << n)	// clear bit **n** in register **v**


#endif /* SRC_STDUTILS_H_ */
