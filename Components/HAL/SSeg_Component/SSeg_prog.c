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
#ifndef SSEG_PROG
#define SSEG_PROG



#include "DIO_Interface.h"
#include "SSeg_Interface.h"
#include "SSeg_config.h"
#include "SSeg_priv.h"


static u8 Local_Stu8SSDON_FLAG[SSD_NUMBER_OF_SSD]  ;


static u8 Local_Stu8SSD_OLDVAL[SSD_NUMBER_OF_SSD]  ;

//static u8 Local_Stu8SSDLastValue ;
//static u8 Local_Stu8SSDLastValue ;


/*************************************************************************************/
/* Description: Initialize the Seven Segment Port and  value (if needed)             */
/*																					 */
/* Inputs : Void															         */
/* Outputs: u8Error -> Error State													 */
/*																					 */

u8 SSeg_u8Init(void) {
	u8 Local_u8ErrorState = ERROR_OK ;



			for (u8 Local_u8SSDNb = 0 ; Local_u8SSDNb < SSD_NUMBER_OF_SSD ; Local_u8SSDNb ++){

				if ( SSD_Au8ArraySSDType[Local_u8SSDNb] == SSD_COM_CATH ){

					for (u8 Local_u8PinOrder = 0 ; Local_u8PinOrder < SSD_NB_OF_PINs ; Local_u8PinOrder ++){

						if(
								DIO_u8SetPinDirection( SSD_Au8ArrayToSSDPin[Local_u8SSDNb][Local_u8PinOrder] , SSD_PIN_DIR_OUTPUT  )   									   || \
								DIO_u8SetPinValue( SSD_Au8ArrayToSSDPin[Local_u8SSDNb][Local_u8PinOrder] , GET_BIT(SSD_Au8ArraySSDInitVal[Local_u8SSDNb],Local_u8PinOrder) )  )
						{
							Local_u8ErrorState = ERROR_NOK ;
						}

					}

				}

				else if ( SSD_Au8ArraySSDType[Local_u8SSDNb] == SSD_COM_ANODE ){

					for (u8 Local_u8PinOrder = 0 ; Local_u8PinOrder < SSD_NB_OF_PINs ; Local_u8PinOrder ++){

						if(
								DIO_u8SetPinDirection( SSD_Au8ArrayToSSDPin[Local_u8SSDNb][Local_u8PinOrder] , SSD_PIN_DIR_OUTPUT  )   									   || \
								DIO_u8SetPinValue( SSD_Au8ArrayToSSDPin[Local_u8SSDNb][Local_u8PinOrder] , ~GET_BIT(SSD_Au8ArraySSDInitVal[Local_u8SSDNb],Local_u8PinOrder) ) )
						{
							Local_u8ErrorState = ERROR_NOK ;
						}

					}

				}

			}


			for (u8 count = 0 ; count < SSD_NUMBER_OF_SSD ; count++ ){

				Local_Stu8SSDON_FLAG[count] = 1 ;

			}



	return Local_u8ErrorState ;
}


/*																					 */
/*************************************************************************************/







/*************************************************************************************************/
/* Description: Write a Number on the Seven Segments 								             */
/*																				            	 */
/* Inputs : Copy_u8PortNB    -> Port No of the desired Seven Segments 			                 */
/* 			Copy_u8DisplayNB -> The Number to be Displayed										 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

u8 SSeg_u8SetVal(u8 Copy_u8SSDNb , u8 Copy_u8Val) {

	u8 Local_u8ErrorState = ERROR_OK ;

	if ( Local_Stu8SSDON_FLAG[Copy_u8SSDNb] == 1 ){

		if ( SSD_Au8ArraySSDType[Copy_u8SSDNb] == SSD_COM_CATH ){

			for (u8 Local_u8PinOrder = 0 ; Local_u8PinOrder < SSD_NB_OF_PINs ; Local_u8PinOrder ++){

				if(  DIO_u8SetPinValue( SSD_Au8ArrayToSSDPin[Copy_u8SSDNb][Local_u8PinOrder] , GET_BIT(Private_Au8DecToBinaryMask[Copy_u8Val],Local_u8PinOrder) )  )
				{
					Local_u8ErrorState = ERROR_NOK ;
				}

			}

		}

		else if ( SSD_Au8ArraySSDType[Copy_u8SSDNb] == SSD_COM_ANODE ){

			for (u8 Local_u8PinOrder = 0 ; Local_u8PinOrder < SSD_NB_OF_PINs ; Local_u8PinOrder ++){

				if(  DIO_u8SetPinValue( SSD_Au8ArrayToSSDPin[Copy_u8SSDNb][Local_u8PinOrder] , ~GET_BIT(Private_Au8DecToBinaryMask[Copy_u8Val],Local_u8PinOrder) )  )
				{
					Local_u8ErrorState = ERROR_NOK ;
				}

			}

		}

		Local_Stu8SSD_OLDVAL[Copy_u8SSDNb] = Copy_u8Val ;

	}



	return Local_u8ErrorState ;
}

/*																								 */
/*************************************************************************************************/






/*************************************************************************************************/
/* Description: Turn Of a Seven Segment				 								             */
/*																				            	 */
/* Inputs : Copy_u8DisplayNB -> The Number to be Displayed			                 			 */
/* 													 											 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

u8 SSD_u8SSDOn(u8 Copy_u8SSDNb) {

	u8 Local_u8ErrorState = ERROR_OK ;

	if ( Copy_u8SSDNb > MAX_PIN_NB ){ Local_u8ErrorState = ERROR_NOK ; }

	else if ( SSD_Au8ArraySSDType[Copy_u8SSDNb] == SSD_COM_CATH ){


		SSeg_u8SetVal( Copy_u8SSDNb , SSD_NULL) ;
		DIO_u8SetPinValue( SSD_Au8ArrayToSSDPin[Copy_u8SSDNb][SSD_MSB] , SSD_GND_VAL  ) ;
		SSeg_u8SetVal( Copy_u8SSDNb , Local_Stu8SSD_OLDVAL[Copy_u8SSDNb]) ;

	}

	else if ( SSD_Au8ArraySSDType[Copy_u8SSDNb] == SSD_COM_ANODE ){

		SSeg_u8SetVal( Copy_u8SSDNb , SSD_NULL) ;
		DIO_u8SetPinValue( SSD_Au8ArrayToSSDPin[Copy_u8SSDNb][SSD_MSB] , SSD_VCC_VAL  ) ;
		SSeg_u8SetVal( Copy_u8SSDNb , Local_Stu8SSD_OLDVAL[Copy_u8SSDNb]) ;

	}

	Local_Stu8SSDON_FLAG[Copy_u8SSDNb] = 1 ;

	return Local_u8ErrorState ;
}


/*																								 */
/*************************************************************************************************/





/*************************************************************************************************/
/* Description: Turn Of a Seven Segment				 								             */
/*																				            	 */
/* Inputs : Copy_u8DisplayNB -> The Number to be Displayed			                 			 */
/* 													 											 */
/* Outputs: u8Error -> Error State													             */
/*																					             */

u8 SSD_u8SSDOff(u8 Copy_u8SSDNb) {

	u8 Local_u8ErrorState = ERROR_OK ;

	if ( Copy_u8SSDNb > MAX_PIN_NB ){ Local_u8ErrorState = ERROR_NOK ; }

	else if ( SSD_Au8ArraySSDType[Copy_u8SSDNb] == SSD_COM_CATH ){

		SSeg_u8SetVal( Copy_u8SSDNb , SSD_NULL) ;
		DIO_u8SetPinValue( SSD_Au8ArrayToSSDPin[Copy_u8SSDNb][SSD_MSB] , SSD_VCC_VAL  ) ;


	}

	else if ( SSD_Au8ArraySSDType[Copy_u8SSDNb] == SSD_COM_CATH ){

		SSeg_u8SetVal( Copy_u8SSDNb , SSD_NULL) ;
		DIO_u8SetPinValue( SSD_Au8ArrayToSSDPin[Copy_u8SSDNb][SSD_MSB] , SSD_GND_VAL  ) ;


	}

	Local_Stu8SSDON_FLAG[Copy_u8SSDNb] = 0 ;

	return Local_u8ErrorState ;
}

/*																					             */
/*************************************************************************************************/










#endif
