/************************************************************************************/
/* Description : This is an Program file that contains the public definitions and   */
/*               public functions implementations needed to use the Seven Segments  */
/*               Component in high efficiency									    */
/* 				                     												*/
/*																					*/
/* Created on  : Jan 29, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/

/* File Guard         */
#ifndef IR_PROG
#define IR_PROG


#include "STD_TYPE.h"

#include "DIO_Interface.h"
#include "IR_Config.h"
#include "IR_Interface.h"
#include "IR_priv.h"




/*************************************************************************************************/
/* Description: Write a Number on the Seven Segments 								             */
/*																				            	 */
/* Inputs : Copy_u8PortNB    -> Port No of the desired Seven Segments 			                 */
/* 			Copy_u8DisplayNB -> The Number to be Displayed										 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

u8 IR_u8GetIRState(u8 Copy_u8IRIndex , u8 * Copy_u8IRState) {

	u8 Local_u8ErrorState = ERROR_OK ;


	if ( (IR_TYPE) == (IR_DETECT_LOW) ){

		if ( DIO_u8GetPinValue(IR_Au8PinDefinitions[Copy_u8IRIndex], Copy_u8IRState ) ){
			Local_u8ErrorState = ERROR_NOK ;
		}

		if( *Copy_u8IRState == PRIV_PIN_HIGH ){
			*Copy_u8IRState = IR_NO_DETECT ;
		}
		else {
			*Copy_u8IRState = IR_DETECT ;
		}

	}

	else if ( (IR_TYPE) == (IR_DETECT_HIGH) ){

		if ( DIO_u8GetPinValue(IR_Au8PinDefinitions[Copy_u8IRIndex], Copy_u8IRState ) ){
			Local_u8ErrorState = ERROR_NOK ;
		}
		if( *Copy_u8IRState == PRIV_PIN_LOW ){
			*Copy_u8IRState = IR_NO_DETECT ;
		}
		else {
			*Copy_u8IRState = IR_DETECT ;
		}

	}

	return Local_u8ErrorState ;
}

/*																								 */
/*************************************************************************************************/









#endif
