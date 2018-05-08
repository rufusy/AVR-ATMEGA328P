#ifndef SRC_STDUTILS_H_
#define SRC_STDUTILS_H_


/*****************************************************
 * MACROS FOR BIT MANIPULATION
 * **************************************************/
// bit
#define bit(n) (1 << n)
// Set bit
#define sbit(v, n) v |= (1 << n)
// Clear bit
#define cbit(v, n) v &= !(1 << n)



#endif /* SRC_STDUTILS_H_ */
