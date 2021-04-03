/************************************************************************************/
/* Description : This is an Program file that contains the public definitions and   */
/*               public functions implementations needed to use the LMD Component   */
/* 				 in high efficiency													*/
/*																					*/
/* Created on  : FEB 11, 2019 														*/
/* Author      : OMDA																*/
/************************************************************************************/

#include "STD_TYPE.h"
#include "DIO_Interface.h"
#include "delay_milli_Interface.h"

#include "LMD_Interface.h"
#include "LMD_config.h"
#include "LMD_priv.h"






/*************************************************************************************************************************/
/* Description: Turns the LMD On                                                                                         */
/*																					                                     */
/* Inputs:  Copy_u8PinNB     -> LMD Pin Number to be turned on						                                     */
/* Outputs: u8Error : Error State													                                     */
/*																					                                     */

u8 LMD_u8Display(u8 Copy_u8Color , u8 * Copy_Au8ImageArray) {

	u8 Local_u8ErrorState = ERROR_OK ;

		switch(LMD_ACTIVE_TYPE){

			case LMD_ACTIVE_LOW:
				for (u8 count = LMD_COUNT_INIT_VAL ; count < LMA_ACTIVE_PIN_Nb ; count ++){
					if ( DIO_u8SetPortValue( LMD_ACTIVE_PORT , ~LMD_u8ActiveValueHigh[count] ) ){
						Local_u8ErrorState = ERROR_NOK ;
					}
					if ( DIO_u8SetPortValue( LMA_COLOR_PORT[Copy_u8Color] , Copy_Au8ImageArray[count] ) ){
						Local_u8ErrorState = ERROR_NOK ;
					}

					delay_milliSecond(DELAY) ;
				}
				break ;

			case LMD_ACTIVE_HIGH:
				for (u8 count = LMD_COUNT_INIT_VAL ; count < LMA_ACTIVE_PIN_Nb ; count ++){

					if ( DIO_u8SetPortValue( LMD_ACTIVE_PORT , LMD_u8ActiveValueHigh[count] ) ){
						Local_u8ErrorState = ERROR_NOK ;
					}
					if ( DIO_u8SetPortValue( LMA_COLOR_PORT[Copy_u8Color] , ~Copy_Au8ImageArray[count] ) ){
						Local_u8ErrorState = ERROR_NOK ;
					}

					delay_milliSecond(DELAY) ;

				}

		}

	return Local_u8ErrorState;
}

/*																					                                     */
/*************************************************************************************************************************/


