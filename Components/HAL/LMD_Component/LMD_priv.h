/************************************************************************************/
/* Description : This is a Private file that contains the private definitions and   */
/*               Private functions needed to use the led Component                  */
/* 				 This Driver Supports AVR ATmel32                                   */
/*																					*/
/* Created on  : Jan 29, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/


/* File Guard                                */
#ifndef LMD_COMPONENT_LMD_PRIV_H_
#define LMD_COMPONENT_LMD_PRIV_H_



/* Defining the type of the LMD              */
#define LMD_ACTIVE_LOW			   (u8)0
#define LMD_ACTIVE_HIGH			   (u8)1

#define LMD_ACTIVE_ROW 			   (u8)2
#define LMD_ACTIVE_COL	 		   (u8)3

#define LMD_COUNT_INIT_VAL		   (u8)0
#define LMA_ACTIVE_PIN_Nb		   (u8)8

#define DELAY					   (u32)2



u8 LMD_u8ActiveValueHigh[8] = {0b00000001 , 0b00000010 , 0b00000100 , 0b00001000 , 0b00010000 , 0b00100000 , 0b01000000 , 0b10000000} ;


#endif
