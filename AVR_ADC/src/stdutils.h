/*
 * stdutils.h
 *
 *  Created on: May 4, 2018
 *      Author: rufusy
 */

#ifndef STDUTILS_H_
#define STDUTILS_H_

/*****************************************************
 * MACROS FOR BIT MANIPULATION
 * **************************************************/
// bit
#define bit(n) (1 << n)
// Set bit
#define sbit(v, n) v |= (1 << n)
// Clear bit
#define cbit(v, n) v &= !(1 << n)



#endif /* STDUTILS_H_ */
