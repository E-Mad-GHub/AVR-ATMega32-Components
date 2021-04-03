/************************************************************************************/
/* Description : This is an Interface file that contains the public definitions and */
/*               public functions needed to use the led Component in high efficiency*/
/* 				 This Driver Supports AVR ATmel32                                   */
/*																					*/
/* Created on  : Jan 29, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/


/* File Guard 								*/
#ifndef LMD_COMPONENT_LMD_INTERFACE_H_
#define LMD_COMPONENT_LMD_INTERFACE_H_





/**** Defining the Port Number in Numbers ***/
/*                                          */

#define LOCAL_PORTA_CHOICE	       0
#define LOCAL_PORTB_CHOICE	       1
#define LOCAL_PORTC_CHOICE	       2
#define LOCAL_PORTD_CHOICE	       3

/*                                          */
/********************************************/


/******** Defining the COLORS USED **********/
/*                                          */

#define LMD_RED_COLOR			   (u8)0
#define LMD_GREEN_COLOR			   (u8)1

/*                                          */
/********************************************/


/*************************************************************************************/
/* Description: Turns the LMD On Image                                               */
/*																					 */
/* Inputs:  Copy_u8Color          -> LMD Color to be turned	on	(LMD_RED_COLOR or    */
/* 																	LMD_RED_COLOR)	 */
/* 			*Copy_Au8ImageArray   -> Image Array to be Displayed 					 */
/* Outputs: u8Error : Error State													 */
/*																					 */

u8 LMD_u8Display(u8 Copy_u8Color , u8 * Copy_Au8ImageArray) ;

/*																					 */
/*************************************************************************************/





#endif /* LMD_COMPONENT_LMD_INTERFACE_H_ */
