/*
 * delay_priv.h
 *
 *  Created on: Feb 3, 2019
 *      Author: OMDA
 */

#ifndef DELAY_PRIV_H_
#define DELAY_PRIV_H_


/* This Value is for the Input Context Switching Delay   									     */
#define InContext        3
/* This Value is for the Out Context Switching           									     */
#define OutContext       2
/* This Value is for the Pre-Calculations before delay plus the initiation delay of the for loop */
#define OperationsDelay  88


/* This Value is for converting the milli to micro value  										 */
#define Milli2Micro      1000
/* This Value is for the single for loop delay            										 */
#define MIC2MILL         1000


/* Variable to be adjusted to control the 1 milli loop 											 */
#define MAX_TO_1m        590



/* Used Datatypes 																				 */
typedef char u8;
typedef unsigned short int u16;
typedef unsigned long  int u32;




#endif /* DELAY_PRIV_H_ */
