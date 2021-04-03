/************************************************************************************/
/* Description : This is a Private file that contains the private definitions and   */
/*               Private functions needed to use the Timers Component 		        */
/* 				 This Driver Supports AVR ATmel32                                   */
/*																					*/
/* Created on  : Jan 29, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/




#ifndef TIMERS_PRIV_H_
#define TIMERS_PRIV_H_



/*******************************  Timer  Registers Addresses   *********************************/
/*                                                                                             */
/*																						       */

/* Defining Timer0 Register              */
#define LOCAL_TCCR0	               0x53
#define LOCAL_TCNT0                0x52
#define LOCAL_OCR0   			   0x5C

/* Defining Timer1 Register              */
#define LOCAL_TCCR1 	           0x4E
#define LOCAL_TCNT1                0x4C
#define LOCAL_ICR				   0x46
#define LOCAL_OCR1_A			   0x4A
#define LOCAL_OCR1_B			   0x48


/* Defining Timer2 Register              */
#define LOCAL_TCCR2	               0x45
#define LOCAL_TCNT2                0x44
#define LOCAL_OCR2   			   0x43



#define LOCAL_TIMSK   			   0x59

/*																						       */
/***********************************************************************************************/



/**********************************   Guiding Definitions   ************************************/
/*                                                                                             */
/*																						       */

#define INTR_NB     			   (u8)6

/*																						       */
/***********************************************************************************************/




#endif /* KPD_COMPONENT_KPD_PRIV_H_ */
