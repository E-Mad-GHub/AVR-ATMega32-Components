/************************************************************************************/
/* Description : This is an Program file that contains the public definitions and   */
/*               public functions implementations needed to use the DIO Component   */
/* 				 in high efficiency													*/
/*																					*/
/* Created on  : Jan 29, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/


/* File Guard                       */
#ifndef DIO_PORG
#define DIO_PROG


/**** External and General Files ****/
/* 									*/

#include "STD_TYPE.h"
#include "BIT_CALC.c"
#include "DIO_interface.h"
#include "DIO_Config.h"
#include "DIO_priv.h"

/*									*/
/************************************/




/*************************************************************************************/
/* Description: Initialize the PINs Direction and output value (if output direction) */
/*																					 */
/* Inputs:  u8PinNB : Void															 */
/* Outputs: u8Error : Error State													 */
/*																					 */

u8 DIO_u8Init(void){

	if( DIO_u8SetPortDirection( LOCAL_PORTA_CHOICE , DIO_PORTA_INIT_DIRECTION ) || \
		DIO_u8SetPortDirection( LOCAL_PORTB_CHOICE , DIO_PORTB_INIT_DIRECTION ) || \
		DIO_u8SetPortDirection( LOCAL_PORTC_CHOICE , DIO_PORTC_INIT_DIRECTION ) || \
		DIO_u8SetPortDirection( LOCAL_PORTD_CHOICE , DIO_PORTD_INIT_DIRECTION ) || \

		DIO_u8SetPortValue( LOCAL_PORTA_CHOICE , DIO_PORTA_INIT_VAL ) 		  || \
		DIO_u8SetPortValue( LOCAL_PORTB_CHOICE , DIO_PORTB_INIT_VAL ) 		  || \
		DIO_u8SetPortValue( LOCAL_PORTC_CHOICE , DIO_PORTC_INIT_VAL ) 		  || \
		DIO_u8SetPortValue( LOCAL_PORTD_CHOICE , DIO_PORTD_INIT_VAL )			    )
	{
		return ERROR_NOK;
	}
	else {
		return ERROR_OK ;
	}


}

/*																					 */
/*************************************************************************************/




/*************************************************************************************/
/* Description: Set the PINs Direction ( Input or Output )							 */
/*																					 */
/* Inputs:  u8PinNB      : The Number of Pin		         						 */
/* 		    u8Direction  : The Direction of the chosen Pin	            			 */
/* Outputs: u8Error      : Error State												 */
/*																					 */

extern u8 DIO_u8SetPinDirection(u8 Copy_u8PinNB , u8 Copy_u8Direction ) {

	u8 Local_u8Error   ;
	u8 Local_u8PORT_ID ;
	u8 Local_u8Pin_ID  ;

	if( (Copy_u8PinNB > LOCAL_DIO_MAXPINNB) || ( (Copy_u8Direction>DIO_OUTPUT)&&(Copy_u8Direction!=DIO_INPUT) ) ){
		Local_u8Error = ERROR_NOK ;
	}
	else {

		Local_u8PORT_ID = Copy_u8PinNB / LOCAL_NB_OF_PINS_IN_PORT ;
		Local_u8Pin_ID  = Copy_u8PinNB % LOCAL_NB_OF_PINS_IN_PORT;


		/* Setting the Desired Pin Direction */
		switch (Local_u8PORT_ID){
		case LOCAL_PORTA_CHOICE:
			ASSIGN_BIT( ((Register*) LOCAL_DDRA_REG) -> ByteAccess , Local_u8Pin_ID , Copy_u8Direction);
			break;

		case LOCAL_PORTB_CHOICE:
			ASSIGN_BIT( ((Register*) LOCAL_DDRB_REG) -> ByteAccess , Local_u8Pin_ID , Copy_u8Direction);
			break;

		case LOCAL_PORTC_CHOICE:
			ASSIGN_BIT( ((Register*) LOCAL_DDRC_REG) -> ByteAccess , Local_u8Pin_ID , Copy_u8Direction);
			break;

		case LOCAL_PORTD_CHOICE:
			ASSIGN_BIT( ((Register*) LOCAL_DDRD_REG) -> ByteAccess , Local_u8Pin_ID , Copy_u8Direction);
			break;

		}

		Local_u8Error = ERROR_OK ;

	}


	return Local_u8Error;

}

/*																					 */
/*************************************************************************************/











/*************************************************************************************/
/* Description: Set the PINs Value ( High or Low )	        						 */
/*																					 */
/* Inputs:  u8PinNB      : The Number of Pin		         						 */
/* 		    u8Value      : The Value of the output on the chosen Pin	     		 */
/* Outputs: u8Error      : Error State												 */
/*																					 */

extern u8 DIO_u8SetPinValue(u8 Copy_u8PinNB , u8 Copy_u8Value ) {

	u8 Local_u8Error   ;
	u8 Local_u8PORT_ID ;
	u8 Local_u8Pin_ID  ;


	if( (Copy_u8PinNB > LOCAL_DIO_MAXPINNB) || ( (Copy_u8Value>DIO_PIN_HIGH)&&(Copy_u8Value!=DIO_PIN_LOW) ) ){
		Local_u8Error = ERROR_NOK ;
	}
	else {

		Local_u8PORT_ID = Copy_u8PinNB / LOCAL_NB_OF_PINS_IN_PORT ;
		Local_u8Pin_ID  = Copy_u8PinNB % LOCAL_NB_OF_PINS_IN_PORT;

		/* Setting the desired Value in required Pin */
		switch (Local_u8PORT_ID){
		case LOCAL_PORTA_CHOICE:
			ASSIGN_BIT( ((Register*) LOCAL_PORTA_REG) -> ByteAccess , Local_u8Pin_ID , Copy_u8Value);
			break;

		case LOCAL_PORTB_CHOICE:
			ASSIGN_BIT( ((Register*) LOCAL_PORTB_REG) -> ByteAccess , Local_u8Pin_ID , Copy_u8Value);
			break;

		case LOCAL_PORTC_CHOICE:
			ASSIGN_BIT( ((Register*) LOCAL_PORTC_REG) -> ByteAccess , Local_u8Pin_ID , Copy_u8Value);
			break;

		case LOCAL_PORTD_CHOICE:
			ASSIGN_BIT( ((Register*) LOCAL_PORTD_REG) -> ByteAccess , Local_u8Pin_ID , Copy_u8Value);
			break;

		}


		Local_u8Error = ERROR_OK ;
	}


	return Local_u8Error ;
}

/*																					 */
/*************************************************************************************/







/*************************************************************************************/
/* Description: Get the PINs Value ( High or Low )	        						 */
/*																					 */
/* Inputs:  u8PinNB      : The Number of Pin		         						 */
/* 		    *u8Value     : The Pointer to variable which will carry the received val.*/
/* Outputs: u8Error      : Error State												 */
/*																					 */

extern u8 DIO_u8GetPinValue(u8 Copy_u8PinNB , u8 * PCopy_u8Value ) {

	u8 Local_u8Error   ;
	u8 Local_u8PORT_ID ;
	u8 Local_u8Pin_ID  ;


	if( (Copy_u8PinNB > LOCAL_DIO_MAXPINNB) || ( PCopy_u8Value == NULL ) ){
		Local_u8Error = ERROR_NOK ;
	}
	else {

		Local_u8PORT_ID = Copy_u8PinNB / LOCAL_NB_OF_PINS_IN_PORT ;
		Local_u8Pin_ID  = Copy_u8PinNB % LOCAL_NB_OF_PINS_IN_PORT;

		/* Setting the desired Value in required Pin */
		switch (Local_u8PORT_ID){
		case LOCAL_PORTA_CHOICE:
			* PCopy_u8Value=GET_BIT(((Register*) LOCAL_PINA_REG) -> ByteAccess,Local_u8Pin_ID) ;
			break;

		case LOCAL_PORTB_CHOICE:
			* PCopy_u8Value=GET_BIT(((Register*) LOCAL_PINB_REG) -> ByteAccess,Local_u8Pin_ID) ;
			break;

		case LOCAL_PORTC_CHOICE:
			* PCopy_u8Value=GET_BIT(((Register*) LOCAL_PINC_REG) -> ByteAccess,Local_u8Pin_ID) ;
			break;

		case LOCAL_PORTD_CHOICE:
			* PCopy_u8Value=GET_BIT(((Register*) LOCAL_PIND_REG) -> ByteAccess,Local_u8Pin_ID) ;
			break;

		}


		Local_u8Error = ERROR_OK ;
	}


	return Local_u8Error ;
}

/*																					 */
/*************************************************************************************/






/*************************************************************************************/
/* Description: Set the PORTs Direction ( Input or Output )							 */
/*																					 */
/* Inputs:  u8PortNB     : The Number of Port		         						 */
/* 		    u8Direction  : The Direction of the chosen Pin	            			 */
/* Outputs: u8Error      : Error State												 */
/*																					 */

extern u8 DIO_u8SetPortDirection(u8 Copy_u8PortNB , u8 Copy_u8Direction ) {

	u8 Local_u8Error   ;


	if( (Copy_u8PortNB > LOCAL_DIO_PORT_MAXPINNB) ){
		Local_u8Error = ERROR_NOK ;
	}
	else {

		/* Setting the Desired Port Direction */

		switch (Copy_u8PortNB){
		case LOCAL_PORTA_CHOICE:
			((Register*) LOCAL_DDRA_REG) -> ByteAccess = Copy_u8Direction ;
			break;

		case LOCAL_PORTB_CHOICE:
			((Register*) LOCAL_DDRB_REG) -> ByteAccess = Copy_u8Direction ;
			break;

		case LOCAL_PORTC_CHOICE:
			((Register*) LOCAL_DDRC_REG) -> ByteAccess = Copy_u8Direction ;
			break;

		case LOCAL_PORTD_CHOICE:
			((Register*) LOCAL_DDRD_REG) -> ByteAccess = Copy_u8Direction ;
			break;

		}

		Local_u8Error = ERROR_OK ;

	}


	return Local_u8Error;

}

/*																					 */
/*************************************************************************************/







/*************************************************************************************/
/* Description: Set the PORTs Value ( High or Low )	        						 */
/*																					 */
/* Inputs:  u8PortNB     : The Number of Port		         						 */
/* 		    u8Value      : The Value of the output on the chosen Pin	     		 */
/* Outputs: u8Error      : Error State												 */
/*																					 */

extern u8 DIO_u8SetPortValue(u8 Copy_u8PortNB , u8 Copy_u8Value ) {

	u8 Local_u8Error   ;


	if( (Copy_u8PortNB > LOCAL_DIO_PORT_MAXPINNB) ){
		Local_u8Error = ERROR_NOK ;
	}
	else {

		/* Setting the Desired Port Direction */

		switch (Copy_u8PortNB){
		case LOCAL_PORTA_CHOICE:
			((Register*) LOCAL_PORTA_REG) -> ByteAccess = Copy_u8Value ;
			break;

		case LOCAL_PORTB_CHOICE:
			((Register*) LOCAL_PORTB_REG) -> ByteAccess = Copy_u8Value ;
			break;

		case LOCAL_PORTC_CHOICE:
			((Register*) LOCAL_PORTC_REG) -> ByteAccess = Copy_u8Value ;
			break;

		case LOCAL_PORTD_CHOICE:
			((Register*) LOCAL_PORTD_REG) -> ByteAccess = Copy_u8Value ;
			break;

		}

		Local_u8Error = ERROR_OK ;

	}


	return Local_u8Error;

}

/*																					 */
/*************************************************************************************/







/*************************************************************************************/
/* Description: Get the PORTs Value ( High or Low )	        						 */
/*																					 */
/* Inputs:  u8PortNB     : The Number of Port		         						 */
/* 		    *u8Value     : The Pointer to variable which will carry the received val.*/
/* Outputs: u8Error      : Error State												 */
/*																					 */

extern u8 DIO_u8GetPortValue(u8 Copy_u8PortNB , u8 * PCopy_u8Value ) {

	u8 Local_u8Error   ;



	if( (Copy_u8PortNB > LOCAL_DIO_PORT_MAXPINNB) || ( PCopy_u8Value == NULL ) ){
		Local_u8Error = ERROR_NOK ;
	}
	else {



		/* Setting the desired Value in required Pin */
		switch (Copy_u8PortNB){
		case LOCAL_PORTA_CHOICE:
			* PCopy_u8Value=((Register*) LOCAL_PINA_REG) -> ByteAccess ;
			break;

		case LOCAL_PORTB_CHOICE:
			* PCopy_u8Value=((Register*) LOCAL_PINB_REG) -> ByteAccess ;
			break;

		case LOCAL_PORTC_CHOICE:
			* PCopy_u8Value=((Register*) LOCAL_PINC_REG) -> ByteAccess ;
			break;

		case LOCAL_PORTD_CHOICE:
			* PCopy_u8Value=((Register*) LOCAL_PIND_REG) -> ByteAccess ;
			break;

		}



		Local_u8Error = ERROR_OK ;
	}


	return Local_u8Error ;
}

/*																					 */
/*************************************************************************************/



#endif


